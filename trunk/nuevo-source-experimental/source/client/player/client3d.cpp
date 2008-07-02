//=============================================================================
// Ejemplo de picking y manejo de partículas con OpenGL
//-----------------------------------------------------------------------------
// Por Mariano M. Chouza - 10/5/2008
//=============================================================================

#include "client3d.h"

template<typename T>
T sqr(const T& a)
{
	return a * a;
}

template<typename T>
T random(T l, T h)
{
	return (T(rand()) / RAND_MAX) * (h - l) + l;
}

bool Client3d::cityRayIntersection(Pais& city, Point3 rayStart, Vector3 rayDir)
{
	Point3 cityBase;
	Vector3 cityAxis;
	Plane bot, top;
	double in, out;
	int dummy;

	cityBase.x = cos(city.getPosition().getX() * PI / 180.0) * cos(city.getPosition().getY() * PI / 180.0);
	cityBase.y = cos(city.getPosition().getY() * PI / 180.0) * sin(city.getPosition().getX() * PI / 180.0);
	cityBase.z = sin(city.getPosition().getY() * PI / 180.0);

	cityAxis = cityBase;
	V3Normalize(&cityAxis);

	V3Normalize(&rayDir);

	if (!intcyl(&rayStart, &rayDir, &cityBase, &cityAxis, 0.01, &in, &out))
		return 0;

	bot.a = -cityAxis.x;
	bot.b = -cityAxis.y;
	bot.c = -cityAxis.z;
	bot.d = 1.0;
	top.a = cityAxis.x;
	top.b = cityAxis.y;
	top.c = cityAxis.z;
	top.d = -1.0 - 0.5;

	return clipobj(&rayStart, &rayDir, &bot, &top, &in, &out, &dummy, &dummy);
}

void Client3d::setup()
{
    MapPosition p1(100, 50);
    MapPosition p2(150,300);

    ReferenceCountPtr<Pais> pais1 = new Pais("ARGENTINA", p1);
    ReferenceCountPtr<Pais> pais2 = new Pais("BOlIVIA", p2);
    map.agregarPais(pais1);
    map.agregarPais(pais2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.33, 0.1, 100.0);

	planetQuad = gluNewQuadric();
	cityQuad = gluNewQuadric();

	gluQuadricDrawStyle(planetQuad, GLU_LINE);
	gluQuadricDrawStyle(cityQuad, GLU_LINE);
}

void Client3d::unsetup()
{
	gluDeleteQuadric(planetQuad);
	gluDeleteQuadric(cityQuad);
}

void Client3d::updateViewPos(double deltaT)
{
	double alphaPrime = 0.0, betaPrime = 0.0, distPrime = 0.0;

	if (keyMap[SDLK_LEFT])
		alphaPrime -= 0.5;
	if (keyMap[SDLK_RIGHT])
		alphaPrime += 0.5;
	if (keyMap[SDLK_DOWN])
		betaPrime -= 0.5;
	if (keyMap[SDLK_UP])
		betaPrime += 0.5;
	if (keyMap[SDLK_PAGEDOWN])
		distPrime += 2.5;
	if (keyMap[SDLK_PAGEUP])
		distPrime -= 2.5;

	alpha += deltaT * alphaPrime;
	beta += deltaT * betaPrime;
	dist += deltaT * distPrime;

	alpha = (alpha > 2 * PI) ? alpha - 2 * PI : alpha;
	alpha = (alpha < -2 * PI) ? alpha +  2 * PI : alpha;
	beta = (beta > 1.0) ? 1.0 : beta;
	beta = (beta < -1.0) ? -1.0 : beta;

	viewpoint.x = dist * cos(alpha) * cos(beta);
	viewpoint.y = dist * sin(alpha) * cos(beta);
	viewpoint.z = dist * sin(beta);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		viewpoint.x,
		viewpoint.y,
		viewpoint.z,
		0.0, 0.0, 0.0,
		0.0, 0.0, 1.0);
}

void Client3d::updatePickedObjects()
{
	double mm[16], pm[16];
	int v[4];
	Point3 fp, np;
	Vector3 rayDir;

	glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glGetDoublev(GL_PROJECTION_MATRIX, pm);
	glGetIntegerv(GL_VIEWPORT, v);

	gluUnProject(mouseX, mouseY, 1.0, mm, pm, v, &fp.x, &fp.y, &fp.z);
	gluUnProject(mouseX, mouseY, 0.0, mm, pm, v, &np.x, &np.y, &np.z);
	rayDir.x = fp.x - np.x;
	rayDir.y = fp.y - np.y;
	rayDir.z = fp.z - np.z;

	selectedCity = -1;

    int num = 0;
    Mapa::IteradorPais iter;	
	for (iter = map.primerPais(); iter != map.ultimoPais(); ++iter)
	{
        ReferenceCountPtr<Pais> pais = *iter;
		if (cityRayIntersection(*pais, viewpoint, rayDir))
		{
			selectedCity = num;
			break;
		}
        ++num;
	}
}

void Client3d::update()
{
	static int lastTime = SDL_GetTicks();
	int newTime = SDL_GetTicks();
	double deltaT = (newTime - lastTime) / 1000.0;
	lastTime = newTime;
	
	updateViewPos(deltaT);
	updatePickedObjects();
}

bool Client3d::handleEvent(const SDL_Event& e)
{	
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
		return false;
	
	if (e.type == SDL_KEYDOWN)
		keyMap[e.key.keysym.sym] = true;
	else if (e.type == SDL_KEYUP)
		keyMap[e.key.keysym.sym] = false;
	else if (e.type == SDL_MOUSEMOTION)
	{
		mouseX = e.motion.x;
		mouseY = VRES - e.motion.y;
	}

	return true;
}

void Client3d::drawPlanet()
{
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(planetQuad, 1.0, 64, 64);
}

void Client3d::drawCities()
{
    Mapa::IteradorPais iter;
    int num = 0;
	for (iter = map.primerPais(); iter != map.ultimoPais(); iter++)
	{
		if (num != selectedCity)
			glColor3f(1.0, 0.0, 0.0);
		else
			glColor3f(0.0, 1.0, 0.0);
		ReferenceCountPtr<Pais> pais = *iter;
		glPushMatrix();
		glRotated(0.5, 0.0, 0.0, 1.0);
		glRotated(90.0 - pais->getPosition().getY(), 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 1.0);
		gluCylinder(cityQuad, 0.01, 0.01, 0.5, 16, 1);
		glPopMatrix();
        ++num;
	}
}

void Client3d::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	drawPlanet();
	drawCities();

	SDL_GL_SwapBuffers();
}

void Client3d::run()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetVideoMode(HRES, VRES, 32, SDL_OPENGL);

	setup();

	SDL_Event e;
	while (true)
	{
		if (SDL_PollEvent(&e))
			if (!handleEvent(e))
				break;

		update();
		draw();
	}

	unsetup();
	
	SDL_Quit();
}
