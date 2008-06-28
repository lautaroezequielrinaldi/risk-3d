#include "glspherewidget.h"
// Almacena el valor de la constante PI
const double PI = 3.1415926535897932384626433832795;

void GLSphereWidget::loadTexture(const std::string& imageFileName) {
    glEnable(GL_TEXTURE_2D);
    SDL_Surface * mapaSurface = IMG_Load(imageFileName.c_str());
    if (mapaSurface) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        SDL_LockSurface(mapaSurface);

        gluBuild2DMipmaps(GL_TEXTURE_2D,3,mapaSurface->w,
           mapaSurface->h,GL_BGR_EXT, GL_UNSIGNED_BYTE, mapaSurface->pixels);

        SDL_UnlockSurface(mapaSurface);
        SDL_FreeSurface(mapaSurface);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    }
}

void GLSphereWidget::update() {
	lastTime = SDL_GetTicks();
    int newTime = SDL_GetTicks();
    double deltaTime = (newTime - lastTime) / 1000.0;
    lastTime = newTime;
}

void GLSphereWidget::drawWidget() {
    // Cargo la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// Cargo la identidad
	glLoadIdentity();
	// Guardo la matriz en el stack.
	glPushMatrix();
	// Translado coordenadas del origen
	glTranslatef(-0.0f, 0.0f, 0.0f);
	glRotatef(0.5f, 0.5f, 0.5f, 0.5f);
	// Cargo la matriz model view.
	glMatrixMode(GL_MODELVIEW);
	// Cargo la identidad.
	glLoadIdentity();
	// Guardo en el stack la matriz.
	glPushMatrix();
	// Habilito la textura
    glBindTexture( GL_TEXTURE_2D, texture );
    glEnable(GL_TEXTURE_2D);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
	// Dibujo esfera
    gluSphere(sphere, radius, 20, 20);
	// Deshabilito la textura
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);

	// Cargo matriz.
	glPopMatrix();
	// Cargo matriz.
	glPopMatrix();
}

void GLSphereWidget::handleKeyDownEvent(const SDL_KeyboardEvent& event) {
    double distancePrime = 0.0, alphaPrime = 0.0, betaPrime = 0.0;

    if (event.keysym.sym == SDLK_LEFT)
        alphaPrime -= 0.5;
    if (event.keysym.sym == SDLK_RIGHT)
        alphaPrime += 0.5;
    if (event.keysym.sym == SDLK_DOWN)
        betaPrime -= 0.5;
    if (event.keysym.sym == SDLK_UP)
        betaPrime += 0.5;
    if (event.keysym.sym == SDLK_PAGEDOWN)
        distancePrime += 5.0;
    if (event.keysym.sym == SDLK_PAGEUP)
        distancePrime -= 5.0;

    alpha += deltaTime * alphaPrime;
    beta += deltaTime * betaPrime;
    distance += deltaTime * distancePrime;

    alpha = (alpha > 2 * PI) ? alpha - 2 * PI : alpha;
    alpha = (alpha < -2 * PI) ? alpha +  2 * PI : alpha;
    beta = (beta > 1.0) ? 1.0 : beta;
    beta = (beta < -1.0) ? -1.0 : beta;
}

GLSphereWidget::GLSphereWidget(const std::string& imageFileName, const float& radius): GL3DWidget(), texture(0), sphere(NULL), radius(radius) {
    sphere = gluNewQuadric();
    gluQuadricDrawStyle (sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
	this->setTexture(imageFileName);
	this->setBackgroundColor(GLWIDGET_ACTIVE, Color::RED);
	this->setBackgroundColor(GLWIDGET_INACTIVE, Color::BLUE);
	this->lastTime = 0.0;
	this->deltaTime = 0.0;
	this->alpha = 0.0;
	this->beta = 0.0;
	this->distance = 2.0;
}

void GLSphereWidget::setTexture(const std::string& imageFileName) {
	this->loadTexture(imageFileName);
}

GLSphereWidget::~GLSphereWidget() {
	gluDeleteQuadric(sphere);
}

