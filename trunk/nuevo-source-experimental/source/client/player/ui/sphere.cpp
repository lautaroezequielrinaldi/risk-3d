#include "sphere.h"
#include<iostream>
Sphere::Sphere(UIState& uiState):
    Textured(),
    uiState(uiState),
    sphereState(),
    crossHairState() {
    initializeQuad();
}

Sphere::Sphere(UIState& uiState, const Texture& theTexture):
    Textured(theTexture),
    uiState(uiState),
    sphereState() {
    initializeQuad();
}

Sphere::~Sphere() {
    terminateQuad();
}

void Sphere::initializeQuad() {
    sphereQuad = gluNewQuadric();
    gluQuadricDrawStyle (sphereQuad, GLU_FILL);
    gluQuadricNormals(sphereQuad, GLU_SMOOTH);
    gluQuadricTexture(sphereQuad, GL_TRUE);
    gluQuadricOrientation(sphereQuad, GLU_OUTSIDE);
}

void Sphere::terminateQuad() {
    gluDeleteQuadric(sphereQuad);
}

void Sphere::update() {
    double newTime = SDL_GetTicks();
    double deltaTime = (newTime - sphereState.getLastTime()) / 1000.0;
    sphereState.setLastTime(newTime);

    updateSphere(deltaTime);
    updateCrossHair();
}

void Sphere::updateSphere(const double& deltaTime) {
    if ( uiState.getKeyPressed(SDLK_LEFT) ) {
        sphereState.incrementAlphaInTime(deltaTime);
        std::cout << "ALPHA: " << sphereState.getAlpha() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_RIGHT) ) {
        sphereState.decrementAlphaInTime(deltaTime);
        std::cout << "ALPHA: " << sphereState.getAlpha() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_UP) ) {
        sphereState.incrementBetaInTime(deltaTime);
        std::cout << "BETA: " << sphereState.getBeta() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_DOWN) ) {
        sphereState.decrementBetaInTime(deltaTime);
        std::cout << "BETA: " << sphereState.getBeta() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_PAGEUP) ) {
        sphereState.incrementDistanceInTime(deltaTime);
        std::cout << "DISTANCE: " << sphereState.getDistance() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_PAGEDOWN) ) {
        sphereState.decrementDistanceInTime(deltaTime);
        std::cout << "DISTANCE: " << sphereState.getDistance() << std::endl;
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

void Sphere::updateCrossHair() {
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
    }
    else
    {
        crossHairState.setInSphere(false);
    }
}

void Sphere::draw() {
    drawSphere();
    drawCrossHair();
}

void Sphere::drawSphere() {
    // Habilito textura
    enableTexture();
    // Rotate in te  axis
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
    
    glColor3f(1.0, 0.0, 0.0);
    
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
