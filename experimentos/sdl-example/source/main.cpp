#include<iostream>
#include<SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

SDL_Surface* screen;
GLUquadricObj* sphere;

bool running = true;
float deltaStep = 0.01f;
float minimumScaleFactor = 0.1f;
float maximumScaleFactor = 1.0f;
float scaleFactor = minimumScaleFactor;
float radius = 0.5f;

void process_quit_event(const SDL_QuitEvent& event) {
    running = false;
}

void process_keydown_event( const SDL_KeyboardEvent& event ) {
    switch ( event.keysym.sym ) {
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_f:
            SDL_WM_ToggleFullScreen( screen );
            break;
        case SDLK_UP:
            scaleFactor += deltaStep;
            if ( scaleFactor > maximumScaleFactor ) {
                scaleFactor = maximumScaleFactor;
            }
            break;
        case SDLK_DOWN:
            scaleFactor -= deltaStep;
            if ( scaleFactor < minimumScaleFactor ) {
                scaleFactor = minimumScaleFactor;
            }
            break;
        default:
            break;
    }
    std::cout << "Se presionò una tecla" << std::cout;
}

void process_keyup_event( const SDL_KeyboardEvent& event ) {
    std::cout << "Se soltò una tecla" << std::cout;
}

void process_mousemotion_event( const SDL_MouseMotionEvent& event ) {
    std::cout << "Se movio el mouse a X: " << event.x << std::endl;
    std::cout << "Se movio el mouse a Y: " << event.y << std::endl;
}

void process_mousebuttondown_event( const SDL_MouseButtonEvent& event ) {
    std::cout << "Se presinò el mouse en X: " << event.x << std::endl;
    std::cout << "Se presionò el mouse en Y: " << event.y << std::endl;
}

void process_mousebuttonup_event( const SDL_MouseButtonEvent& event ) {
    std::cout << "Se soltò el mouse en X: " << event.x << std::endl;
    std::cout << "Se soltò el mous een Y: " << event.y << std::endl;
}

void process_event( const SDL_Event& event ) {
    switch (  event.type  ) {
        case SDL_QUIT:
            process_quit_event( event.quit );
            break;
        case SDL_KEYDOWN:
            process_keydown_event(  event.key  );
            break;
        case SDL_KEYUP:
            process_keydown_event(  event.key  );
            break;
        case SDL_MOUSEMOTION:
            process_mousemotion_event(  event.motion  );
            break;
        case SDL_MOUSEBUTTONDOWN:
            process_mousebuttondown_event(  event.button  );
            break;
        case SDL_MOUSEBUTTONUP:
            process_mousebuttonup_event(  event.button  );
            break;
    }
}

void initOpenGL(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(60.0, 1.33, 0.1, 100.0);
}

void initQuadric() {
    sphere = gluNewQuadric();
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
}

void deleteQuadric() {
    gluDeleteQuadric(sphere);
}

void drawSphere() {
	SDL_Rect rectangle;
	rectangle.x = 5;
	rectangle.y = 5;
	rectangle.w = 100;
	rectangle.h	 = 100;
	SDL_Delay(10);
	SDL_FillRect(screen, &rectangle, 0xee);
	SDL_Flip(screen);
	SDL_GL_SwapBuffers();
}

void main_loop() {
    SDL_Event event;

    while (  running  ) {
        if (  SDL_PollEvent(  &event  )  ) {
            process_event(  event  );
        }
        drawSphere();
    }
}
        
int main( int argc, char** argv ) {
    if (  SDL_Init(  SDL_INIT_EVERYTHING  ) < 0 ) {
        std::cout << "Error al iniciar SDL: " << SDL_GetError() << std::endl;
        return 0;
    }

    initOpenGL(1024, 768);

    screen = SDL_SetVideoMode(  1024, 768, 32, SDL_OPENGL | SDL_OPENGLBLIT | SDL_RESIZABLE |
        SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (  screen == NULL  ) {
        std::cout << "Error al crear ventana: " << SDL_GetError() << std::endl;
    }

    SDL_WM_SetCaption(  "Hola Mundo!!!", "Hola Mundo!!!"  );

    //initQuadric();
    main_loop();
    //deleteQuadric();
    return 0;
}

