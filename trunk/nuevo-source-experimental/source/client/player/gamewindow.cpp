#include "gamewindow.h"
#include<GL/glut.h>
#include<sstream>
#include<iostream>
#include "../../common/parser/mapaparser.h"
#include "../../common/model/randomdice.h"

#include <iostream>
using namespace std;

GameWindow::GameWindow(const ReferenceCountPtr<ServerProxy>& serverProxy):
    serverProxy(serverProxy),
    mainLoopRunning(true),
    uiState(),
    didIWinButton(uiState),
    noMoreButton(uiState),
    surrenderButton(uiState),
    quitButton(uiState),
    hooverCountryLabel(uiState),
    hooverUnitLabel(uiState),
    messageLabel(uiState),
    sphere(uiState) {
    if (this->serverProxy != NULL) {
        this->serverProxy->registerCommandObserver(this);
    }
    // Creo a duras penas un GameManager y un Mapa
    MapaParser parser;

    // Estado inicial ClientWaiting
    ReferenceCountPtr<ClientState> initialState = new ClientWaiting(*this);
    setState(initialState);

    ReferenceCountPtr<Mapa> map = parser.loadMap("mapa.xml");
    RandomDice* dice = new RandomDice();
    ReferenceCountPtr<Game> game = new Game(map, *dice);
    sphere.setGame(game);
}

GameWindow::~GameWindow() {
    // No realiza ninguna accion.
}

bool GameWindow::initializeSDL(int argc, char** argv) {
    // Inicializo SDL
   if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
        return false;
    }
    // Creo una ventana
    SDL_Surface* screen = SDL_SetVideoMode( SDL_GetVideoInfo()->current_w,
        SDL_GetVideoInfo()->current_h, SDL_GetVideoInfo()->vfmt->BitsPerPixel,
            SDL_OPENGL  ); //| SDL_FULLSCREEN
    if ( screen == NULL ) {
        return false;
    }
    glutInit(&argc, argv);
    return true;
}

void GameWindow::initializeOpenGL() {
    // Habilita depth buffer
    glEnable(GL_DEPTH_TEST);
    // Habilita estilo de lineas
    glEnable(GL_LINE_SMOOTH);
    // Habilita shade model smooth
    glShadeModel(GL_SMOOTH);

    // Carga la matriz de proyeccion
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

    // Da perspectiva
    gluPerspective(60.0, 1.33, 0.1, 100.0);

    // Establezco tamaño de boton did i win y posicion.
    didIWinButton.setX(0);
    didIWinButton.setY(330);
    didIWinButton.setWidth(200);
    didIWinButton.setHeight(100);
    didIWinButton.setVisible(true);
    didIWinButton.setEnabled(true);
    didIWinButton.setText("DID I WIN");

    // Establezco tamaño de boton no more y posicion.
    noMoreButton.setX(0);
    noMoreButton.setY(220);
    noMoreButton.setWidth(200);
    noMoreButton.setHeight(100);
    noMoreButton.setVisible(true);
    noMoreButton.setEnabled(true);
    noMoreButton.setText("END ACTION");

    // Establezco tamaño de boton surrender y posicion.
    surrenderButton.setX(0);
    surrenderButton.setY(110);
    surrenderButton.setWidth(200);
    surrenderButton.setHeight(100);
    surrenderButton.setVisible(true);
    surrenderButton.setEnabled(true);
    surrenderButton.setText("SURRENDER");

    // Establezco tamaño de boton quit y posicion.
    quitButton.setX(0);
    quitButton.setY(0);
    quitButton.setWidth(200);
    quitButton.setHeight(100);
    quitButton.setVisible(true);
    quitButton.setEnabled(true);
    quitButton.setText("QUIT");

    // Establece tamaño de label y posicion
    hooverCountryLabel.setX(0);
    hooverCountryLabel.setY(550);
    hooverCountryLabel.setWidth(200);
    hooverCountryLabel.setHeight(100);
    hooverCountryLabel.setVisible(false);
    hooverCountryLabel.setEnabled(false);

   // Establece tamaño de label y posicion
    hooverUnitLabel.setX(0);
    hooverUnitLabel.setY(440);
    hooverUnitLabel.setWidth(200);
    hooverUnitLabel.setHeight(100);
    hooverUnitLabel.setVisible(false);
    hooverUnitLabel.setEnabled(false);
    
    // Establezco tamaño de label y posicion.
    messageLabel.setX(210);
    messageLabel.setY(0);
    messageLabel.setWidth(SDL_GetVideoInfo()->current_w - 210);
    messageLabel.setHeight(100);
    messageLabel.setEnabled(false);
    messageLabel.setVisible(true);
    messageLabel.setText("Mensaje de prueba");

    // Cargo las texturas de la esfera.
    sphere.getTexture().load("./image");
}

void GameWindow::terminateSDL() {
    SDL_FreeSurface( SDL_GetVideoSurface() );
    SDL_Quit();
}

void GameWindow::terminateOpenGL() {

}

void GameWindow::runMainLoop() {
    while ( mainLoopRunning ) {
        processEvents();
        updateScene();
        drawScene();
    }
}

void GameWindow::stopMainLoop() {
    mainLoopRunning = false;
}

void GameWindow::enable2D() {
    int vPort[4];
    glGetIntegerv(GL_VIEWPORT, vPort);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
}

void GameWindow::disable2D() {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}

void GameWindow::updateScene() {
    sphere.update();
}

void GameWindow::drawScene() {
    // Limpia el fondo
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Dibuja la esfera
    sphere.draw();

    // Habilita modo 2D
    enable2D();
    // Prepara IMGUI
    uiState.prepare();

    // Dibuja y procesa el label para pais bajo el mouse.
    if (sphere.getHooverCountry() != NULL) {
        hooverCountryLabel.setText( sphere.getHooverCountry()->getNombre());
        hooverCountryLabel.setVisible(true);
        hooverCountryLabel.setEnabled(true);
        hooverCountryLabel.doProcess();

        std::ostringstream unitStr;
        unitStr << "Unidades: ";
        unitStr << sphere.getHooverCountry()->getArmyCount();

        hooverUnitLabel.setVisible(true);
        hooverUnitLabel.setEnabled(true);
        hooverUnitLabel.setText(unitStr.str());
        hooverUnitLabel.doProcess();
    }

    // Dibuja y procesa boton de did i win.
    if ( didIWinButton.doProcess() ) {
        state->executeDidIWin();
    }

    // Dibuja y procesa boton de no more.
    if ( noMoreButton.doProcess() ) {
        state->executeNoMore();
    }

    // Dibuja y procesa el boton de surrender.
    if ( surrenderButton.doProcess() ) {
        state->executeSurrender();
    }

    // Dibuja y procesa el boton de quit,
    if ( quitButton.doProcess() ) {
        state->executeQuit();
    }

    // Dibuja el label
    messageLabel.doProcess();

    // Termina IMGUI
    uiState.unprepare();

    // Deshabilita 2D
    disable2D();

    // Hace swap del buffer
    SDL_GL_SwapBuffers();
}

void GameWindow::processMouseDown(const SDL_MouseButtonEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(SDL_GetVideoInfo()->current_h - event.y);
    uiState.setMousePressed(true);
    processSphereClick();
}

void GameWindow::processMouseUp(const SDL_MouseButtonEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(SDL_GetVideoInfo()->current_h - event.y);
    uiState.setMousePressed(false);
}

void GameWindow::processMouseMotion(const SDL_MouseMotionEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(SDL_GetVideoInfo()->current_h - event.y);
}

void GameWindow::processKeyDown(const SDL_KeyboardEvent& event)  {
    uiState.setKeyPressed(event.keysym.sym, true);
    if ( uiState.getKeyPressed(SDLK_ESCAPE) ) {
       state->executeQuit(); 
    }
}

void GameWindow::processKeyUp(const SDL_KeyboardEvent& event) {
    uiState.setKeyPressed(event.keysym.sym, false);
}

void GameWindow::processQuit(const SDL_QuitEvent& event) {
    disconnectAndQuit();
}

void GameWindow::processSphereClick() {
    if (sphere.getHooverCountry() != NULL) {
        state->selectCountry(sphere.getHooverCountry());
    }
}

void GameWindow::processEvents() {
    // Defino el evento a leer
    SDL_Event event;
    // Si hay evento
    if ( SDL_PollEvent(&event) ) {
        // Trato cada tipo de evento
        switch (event.type) {
            // Proceso bonton presionado
            case SDL_MOUSEBUTTONDOWN:
                processMouseDown(event.button);
                break;
            // Proceso boton soltado
            case SDL_MOUSEBUTTONUP:
                processMouseUp(event.button);
                break;
            // Proceso movimiento de mouse
            case SDL_MOUSEMOTION:
                processMouseMotion(event.motion);
                break;
            // Proceso tecla presionada
            case SDL_KEYDOWN:
                processKeyDown(event.key);
                break;
            // Proceso tecla liberada
            case SDL_KEYUP:
                processKeyUp(event.key);
                break;
            // Proceso quit
            case SDL_QUIT:
                processQuit(event.quit);
                break;
        }
    }
}

void GameWindow::disconnectAndQuit() {
    if (serverProxy != NULL) {
        Quit quitCommand;
        serverProxy->notify(quitCommand);
        serverProxy->cancel();
    }
    stopMainLoop();
}

ReferenceCountPtr<ServerProxy> GameWindow::getServerProxy() const {
    return serverProxy;
}

void GameWindow::setState(ReferenceCountPtr<ClientState>& state) {
    this->state = state;
}

int GameWindow::run(int argc, char** argv) {
    if ( initializeSDL(argc, argv) ) {
        initializeOpenGL();

        runMainLoop();

        terminateOpenGL();
        terminateSDL();
       return 0;
    } else {
        return 1;
    }
}


	
void GameWindow::commandExecuted(Attack& cmd){
	
	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
	
	if ( cmd.isValid() ){
		//cambia de estado a defending
		ReferenceCountPtr<ClientState> defending = new ClientDefending(*this, cmd.getAttackedLand(), cmd.getFrom() );
		this->setState(defending);
	}
	//sino fue valido el ataque queda en mismo estado.
	
	
		
}
void GameWindow::commandExecuted(Defend& cmd){

	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
		
	//si llega un defend es xq el anterior fue invalido. Queda en mismo estado defending
}

void GameWindow::commandExecuted(BattleResult& cmd){

	//se muestra a todos el mismo mensaje
	messageLabel.setText(cmd.getMainMsg());
	
	//cambia a estado attacking
	ReferenceCountPtr<ClientState> attacking = new ClientAttacking(*this);
	this->setState(attacking);
	
}

void GameWindow::commandExecuted(TurnToMove& cmd){
	
	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
		
	//cambiar a estado moving
	ReferenceCountPtr<ClientState> moving = new ClientMoving(*this);
	this->setState(moving);
}


void GameWindow::commandExecuted(Move& cmd){
   
   	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
		
	if ( cmd.isValid() ){	
		//cambia estado a populating 
		ReferenceCountPtr<ClientState> popu = new ClientPopulating(*this);
		this->setState(popu);
	}
	//sino es valido sigo en mismo estado
}

void GameWindow::commandExecuted(Populate& cmd){

	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
		
	//no cambia de estado, sigue en el mismo porque le quedan ejercitos para poblar.
}

void GameWindow::commandExecuted(Surrender& cmd){

	cerr<<"En commandExecute ( Surrender )"<<endl;
	
	//muestra a todos el mismo
	messageLabel.setText(cmd.getMainMsg());
	
	//cambia a estado waiting
	ReferenceCountPtr<ClientState> waiting = new ClientWaiting(*this);
	this->setState(waiting);
	
	cerr<<"deberia mostrarse en los clientes el mensaje de surrender..."<<endl;

} 
  
void GameWindow::commandExecuted(TurnToAttack& cmd){

	
	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());

	
	//cambia a estado attacking
	ReferenceCountPtr<ClientState> attacking = new ClientAttacking(*this);
	this->setState(attacking);
}

void GameWindow::commandExecuted(TurnToOccupy& cmd){
   
	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
	
	//pasar a estado occupying   ??????????????
}

void GameWindow::commandExecuted(TurnToPopulate& cmd){

	if( this->serverProxy->getMe() == cmd.getTo() )
		messageLabel.setText(cmd.getMainMsg());
	else
		messageLabel.setText(cmd.getSecMsg());
		
	//cambia estado a populating 
	ReferenceCountPtr<ClientState> popu = new ClientPopulating(*this);
	this->setState(popu);	
}

