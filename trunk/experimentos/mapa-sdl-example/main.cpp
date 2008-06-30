#include<cmath> // Para funciones de math.h
#include<iostream>
#include<GL/gl.h> // Para funciones de OpenGL
#include<GL/glu.h>// Para funciones de OpenGLU
#include<SDL/SDL.h> // Para funciones de SDL
#include<SDL/SDL_image.h> // Para definiciones de SDL_image

// Almacena el valor de la constante PI
const double PI = 3.1415926535897932384626433832795;
// Almacena el angulo beta
double beta = 0.0;
// Almacena el angulo alfa
double alpha = 0.0;
// Almacena la distancia al modelo a mostrar
double distance = 2.0;
// Almacena el estado de las teclas del teclado
bool keyboard[SDLK_LAST];
// Almacena el estado de la rueda del mouse
bool mouseWheel[2];
// Almacena la pantalla donde se va a dibujar
SDL_Surface* screen;
// Almacena la textura del mapa
GLuint textura_mapa;
// Almacena el objeto quadrico esfera que vamos a dibujar
GLUquadricObj* sphere;
// Flag booleana indicando si la apliaciòn esta corriendo
bool running;

void loadTexture() {
    glEnable(GL_TEXTURE_2D);
    SDL_Surface * mapaSurface = IMG_Load("mapa.jpg");
    if (mapaSurface) {
        glGenTextures(1, &textura_mapa);
        glBindTexture(GL_TEXTURE_2D, textura_mapa);

        SDL_LockSurface(mapaSurface);

        gluBuild2DMipmaps(GL_TEXTURE_2D,3,mapaSurface->w,
           mapaSurface->h,GL_BGR_EXT, GL_UNSIGNED_BYTE, mapaSurface->pixels);

        SDL_UnlockSurface(mapaSurface);
        SDL_FreeSurface(mapaSurface);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR); 
        std::cout << "Se cargo textura" << std::endl;
    } else {
        std::cout << "No se pudo abrir imagen: " << IMG_GetError() << std::endl;
        exit(0);
    }
}

void initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(1024, 768, 32, SDL_OPENGL | SDL_DOUBLEBUF |
        SDL_FULLSCREEN);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
}

void initOpenGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.33, 0.1, 100.0);
    loadTexture();
}

void initQuadric() {
    sphere = gluNewQuadric();
    gluQuadricDrawStyle (sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
}

void destroyQuadric() {
    gluDeleteQuadric(sphere);
}

void destroyOpenGL() {
    // No reliza ninguna acciòn
}

void destroySDL() {
    SDL_FreeSurface(screen);
    SDL_Quit();
}

void processKeyDownEvent(SDL_KeyboardEvent& event) {
    keyboard[event.keysym.sym] = true;
    if (event.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
}

void processKeyUpEvent(SDL_KeyboardEvent& event)  {
    keyboard[event.keysym.sym] = false;
}   

void processMouseButtonDownEvent(SDL_MouseButtonEvent& event) {
    if (event.button == SDL_BUTTON_WHEELUP) {
        mouseWheel[0] = true;
    }
    if (event.button == SDL_BUTTON_WHEELDOWN) {
        mouseWheel[1] = true;
    }
}

void processMouseButtonUpEvent(SDL_MouseButtonEvent& event) {
    if (event.button == SDL_BUTTON_WHEELUP) {
        mouseWheel[0] = false;
    }
    if (event.button == SDL_BUTTON_WHEELDOWN) {
        mouseWheel[1] = false;
    }
}

void processMouseMotionEvent(SDL_MouseMotionEvent& event) {

}

void processQuitEvent(SDL_QuitEvent& event) {
    running = false;
}

void processEvents() {
    SDL_Event event;
    if ( SDL_PollEvent(&event) ) {
        switch (event.type) {
            case SDL_KEYDOWN:
                processKeyDownEvent(event.key);
                break;
            case SDL_KEYUP:
                processKeyUpEvent(event.key);
                break;
            case SDL_MOUSEBUTTONDOWN:
                processMouseButtonDownEvent(event.button);
                break;
            case SDL_MOUSEBUTTONUP:
                processMouseButtonUpEvent(event.button);
                break;
            case SDL_MOUSEMOTION:
                processMouseMotionEvent(event.motion);
                break;
            case SDL_QUIT:
                processQuitEvent(event.quit);
                break;
        }
    }
}

void updateModel() {
    static int lastTime = SDL_GetTicks();
    int newTime = SDL_GetTicks();
    double deltaTime = (newTime - lastTime) / 1000.0;
    lastTime = newTime;

    double distancePrime = 0.0, alphaPrime = 0.0, betaPrime = 0.0;

    if (keyboard[SDLK_LEFT])
        alphaPrime -= 0.5;
    if (keyboard[SDLK_RIGHT])
        alphaPrime += 0.5;
    if (keyboard[SDLK_DOWN])
        betaPrime -= 0.5;
    if (keyboard[SDLK_UP])
        betaPrime += 0.5;
    if (keyboard[SDLK_PAGEDOWN] || mouseWheel[1])
        distancePrime += 5.0;
    if (keyboard[SDLK_PAGEUP] || mouseWheel[0])
        distancePrime -= 5.0;

    alpha += deltaTime * alphaPrime;
    beta += deltaTime * betaPrime;
    distance += deltaTime * distancePrime;

    alpha = (alpha > 2 * PI) ? alpha - 2 * PI : alpha;
    alpha = (alpha < -2 * PI) ? alpha +  2 * PI : alpha;
    beta = (beta > 1.0) ? 1.0 : beta;
    beta = (beta < -1.0) ? -1.0 : beta;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.5f, .5f, 0.0f);
    std::cout << alpha << " " << beta << " " << distance << std::endl;
	gluLookAt(
        distance * cos(alpha) * cos(beta) + 0.5,
        distance * sin(alpha) * cos(beta) + 0.5,
        distance * sin(beta) + 0.5,
        0.5, 0.5, 0.0,
        0.0, 0.0, 1.0);
    //glScalef(1.0f, 1.0f, 1.0f);
}

void drawModel() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture( GL_TEXTURE_2D, textura_mapa ); 
    glEnable(GL_TEXTURE_2D);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    gluSphere(sphere, 0.3, 20, 20);

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);    
    
    SDL_GL_SwapBuffers();
}

void mainLoop() {
    // The application is running
    running = true;

    // While the application is running
    while (running) {
        // Process Events
        processEvents();

        // Updates the Model
        updateModel();

        // Draws the Model
        drawModel();
    }
}

int main(int argc, char** argv) {
    // Initialize SDL
    initSDL();

    // Initialize OpenGL
    initOpenGL();

    // Initialize Quadric Objects
    initQuadric();

    // Execute the Main Loop
    mainLoop();

    // Destroys Quadric Objects
    destroyQuadric();

    // Destroys OpenGL
    destroyOpenGL();

    // Destroys SDL
    destroySDL();

    // Exits the application
    return 0;
}

