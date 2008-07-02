#ifndef __CLIENT3D_H__
#define __CLIENT3D_H__

#include <cmath>
#include <list>
#include <SDL.h>
#include <SDL/SDL_image.h>
#include <vector>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include "math3d.h"
#include "ray_cyl.h"

#include "../../common/model/mapa.h"
#include "../../common/model/pais.h"
#include "../../common/model/mapposition.h"
#include "../../common/smartpointer/referencecountptr.h"


class Client3d {
    private:
    Mapa map;
    GLuint texture;
    double alpha;
    double beta;
    double dist;

    Point3 viewpoint;

    bool keyMap[SDLK_LAST];

    double mouseX;
    double mouseY;

    GLUquadric* planetQuad;
    GLUquadric* cityQuad;
    int selectedCity;
    static const size_t HRES = 800;

    static const size_t VRES = 600;

    protected:
        void loadTexture(const std::string& fileName);
        bool cityRayIntersection(Pais& city, Point3 rayStart, Vector3 rayDir);
        void setup();
        void unsetup();
        void updateViewPos(double deltaT);
        void updatePickedObjects();
        void update();
        bool handleEvent(const SDL_Event& e);
        void drawPlanet();
        void drawCities();
        void draw();
    public:
        void run();

};

#endif /* __CLIENT3D_H__ */

