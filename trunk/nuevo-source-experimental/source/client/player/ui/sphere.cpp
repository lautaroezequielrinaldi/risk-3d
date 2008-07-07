#include "sphere.h"
#include<iostream>
Sphere::Sphere(UIState& uiState, const ReferenceCountPtr<Game>& game):
    Textured(),
    game(game),
    uiState(uiState),
    sphereState(),
    crossHairState() {
    initializeQuad();
}

Sphere::Sphere(UIState& uiState, const Texture& theTexture,
    const ReferenceCountPtr<Game>& game):
    Textured(theTexture),
    game(game),
    uiState(uiState),
    sphereState() {
    initializeQuad();
}

Sphere::~Sphere() {
    terminateQuad();
}

void Sphere::initializeQuad() {
    sphereQuad = gluNewQuadric();
    countryQuad = gluNewQuadric();
    gluQuadricDrawStyle (sphereQuad, GLU_FILL);
    gluQuadricNormals(sphereQuad, GLU_SMOOTH);
    gluQuadricTexture(sphereQuad, GL_TRUE);
    gluQuadricOrientation(sphereQuad, GLU_OUTSIDE);
}

void Sphere::terminateQuad() {
    gluDeleteQuadric(sphereQuad);
    gluDeleteQuadric(countryQuad);
}

bool Sphere::countryRayIntersection(MapPosition& position,
    Point3 rayStart, Vector3 rayDir) {
    Point3 countryBase;
    Vector3 countryAxis;
    Plane bot, top;
    double in, out;
    int dummy;
    countryBase.x = cos(position.getY() * PI / 180.0) * cos(position.getX() * PI / 180.0);
    countryBase.y = cos(position.getY() * PI / 180.0) * sin(position.getX() * PI / 180.0);
    countryBase.z = sin(position.getY() * PI / 180.0);
    countryAxis = countryBase;
    V3Normalize(&countryAxis);
    V3Normalize(&rayDir);

    if (!intcyl(&rayStart, &rayDir, &countryBase, &countryAxis, 0.01, &in, &out))
        return 0;

    bot.a = -countryAxis.x;
    bot.b = -countryAxis.y;
    bot.c = -countryAxis.z;
    bot.d = 1.0;
    top.a = countryAxis.x;
    top.b = countryAxis.y;
    top.c = countryAxis.z;
    top.d = -1.0 - 0.1;

    return clipobj(&rayStart, &rayDir, &bot, &top, &in, &out, &dummy, &dummy);
}

void Sphere::setGame(const ReferenceCountPtr<Game>& game) {
    this->game = game;
}

ReferenceCountPtr<Pais> Sphere::getHooverCountry() {
    return hooverCountry;
}

void Sphere::update() {
    double newTime = SDL_GetTicks();
    double deltaTime = (newTime - sphereState.getLastTime()) / 1000.0;
    sphereState.setLastTime(newTime);

    updateSphere(deltaTime);
    updateCrossHairAndCountries();
}

void Sphere::updateSphere(const double& deltaTime) {
    if ( uiState.getKeyPressed(SDLK_LEFT) ) {
        sphereState.incrementAlphaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_RIGHT) ) {
        sphereState.decrementAlphaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_UP) ) {
        sphereState.incrementBetaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_DOWN) ) {
        sphereState.decrementBetaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_PAGEUP) ) {
        sphereState.incrementDistanceInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_PAGEDOWN) ) {
        sphereState.decrementDistanceInTime(deltaTime);
    }

    viewpoint.x = sphereState.getDistance() * cos(sphereState.getAlpha())
        * cos(sphereState.getBeta());
    viewpoint.y = sphereState.getDistance() * sin(sphereState.getAlpha())
        * cos(sphereState.getBeta());
    viewpoint.z = sphereState.getDistance() * sin(sphereState.getBeta());

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        viewpoint.x,
        viewpoint.y,
        viewpoint.z,
        0.0, 0.0, 0.0,
        0.0, 0.0, 1.0);
}

void Sphere::updateCrossHairAndCountries() {
    double mm[16], pm[16];
    int v[4];
    Point3 fp, np;
    Vector3 rayDir;

    glGetDoublev(GL_MODELVIEW_MATRIX, mm);
    glGetDoublev(GL_PROJECTION_MATRIX, pm);
    glGetIntegerv(GL_VIEWPORT, v);

    gluUnProject(uiState.getMouseX(), uiState.getMouseY(), 1.0, mm, pm, v, &fp.x, &fp.y, &fp.z);
    gluUnProject(uiState.getMouseX(), uiState.getMouseY(), 0.0, mm, pm, v, &np.x, &np.y, &np.z);
    rayDir.x = fp.x - np.x;
    rayDir.y = fp.y - np.y;

    rayDir.z = fp.z - np.z;
    V3Normalize(&rayDir);
    
    Point3 planetCenter = {0.0, 0.0, 0.0};
    double rayLen = intersectRaySphere(viewpoint, rayDir, planetCenter, 1.0);
    if (rayLen != std::numeric_limits<double>::infinity()) {
        Point3 intPoint;
        V3ScalarMult(&rayDir, rayLen);
        V3Add(&viewpoint, &rayDir, &intPoint);
        crossHairState.setLatitude(90.0 - acos(intPoint.z) * 180.0 / PI);
        crossHairState.setLongitude(atan2(intPoint.y, intPoint.x) * 180.0 / PI);
        crossHairState.setInSphere(true);
        if (game != NULL && game->getMapa() != NULL) {
            Mapa::IteradorPais countryIter;
            bool found = false;
            for (countryIter = game->getMapa()->primerPais();
                countryIter != game->getMapa()->ultimoPais(); ++countryIter) {
                MapPosition position = (*countryIter)->getPosition();
                if (countryRayIntersection(position, viewpoint, rayDir)) {
                    hooverCountry = (*countryIter);
                    found = true;
                }
                if (!found) {
                    hooverCountry = NULL;
                }
            }
        } else {
            hooverCountry = NULL;
        }
    }
    else
    {
        crossHairState.setInSphere(false);
        hooverCountry = NULL;
    }
}

void Sphere::draw() {
    drawSphere();
    drawCrossHair();
    drawCountries();
}

void Sphere::drawSphere() {
    // Habilito textura
    enableTexture();
    // Dibujo la esfera
    gluSphere(sphereQuad, 1.0, 64, 64);
    // Deshabilito textura
    disableTexture();
}

void Sphere::drawCrossHair() {
    if (!crossHairState.getInSphere())
        return;
        
    double clatRad = (90.0 - crossHairState.getLatitude()) * PI / 180.0;
    double lonRad = crossHairState.getLongitude() * PI / 180.0;
    double da = PI / 32.0;
    
    glColor3f(0.0, 0.0, 0.5);
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 64; i++)
        glVertex3d( 1.1 * sin(clatRad) * cos(da * i),
                    1.1 * sin(clatRad) * sin(da * i),
                    1.1 * cos(clatRad));
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 64; i++)
        glVertex3d( 1.1 * sin(da * i) * cos(lonRad),
                    1.1 * sin(da * i) * sin(lonRad),
                    1.1 * cos(da * i));
    glEnd();
    
    glBegin(GL_LINES);
        glVertex3d( 1.1 * sin(clatRad) * cos(lonRad),
                    1.1 * sin(clatRad) * sin(lonRad),
                    1.1 * cos(clatRad));
        glVertex3d( 1.0 * sin(clatRad) * cos(lonRad),
                    1.0 * sin(clatRad) * sin(lonRad),
                    1.0 * cos(clatRad));
    glEnd();
}

void Sphere::drawCountries() {
    // Si hay un juego y mapa disponible
    if (game != NULL && game->getMapa() != NULL) {
        // Obtengo mapa
        ReferenceCountPtr<Mapa> map = game->getMapa();
        // Obtengo iterador de paises.
        Mapa::IteradorPais countryIter;

        // Itero por cada pais.
        for (countryIter = map->primerPais(); countryIter != map->ultimoPais();
            ++countryIter) {
            // Obtiene la pisicion del pais.
            MapPosition position = (*countryIter)->getPosition();
            // Hago push de matriz actual
            glPushMatrix();
            // Rota la matriz
            glRotated(position.getX(), 0.0, 0.0, 1.0);
            // Rota la matriz
            glRotated(90.0 - position.getY(), 0.0, 1.0, 0.0);
            // Translada origen de coordenadas
            glTranslatef(0.0, 0.0, 1.0);
            int color = game->getCountryOwner((*countryIter)->getNombre());
            switch (color) {
                case 1:
                    glColor3f(1.0f, 0.0f, 0.0f);
                    break;
                case 2:
                    glColor3f(0.0f, 0.0f, 0.0f);
                    break;
                case 3:
                    glColor3f(0.0f, 1.0f, 0.0f);
                    break;
                case 4:
                    glColor3f(1.0f, 1.0f, 0.0f);
                    break;
                case 5:
                    glColor3f(0.0f, 0.0f, 1.0f);
                    break;
                 case 6:
                    glColor3f(1.0f, 1.0f, 1.0f);
                    break;
                default:
                    glColor3f(0.5f, 0.5f, 0.5f);
                    break;
            }
            // Dibuja cilindro
            gluCylinder(countryQuad, 0.01, 0.01, 0.1, 16, 1);
            // Hago pop de matriz actual
            glPopMatrix();
        }
    } 
}

