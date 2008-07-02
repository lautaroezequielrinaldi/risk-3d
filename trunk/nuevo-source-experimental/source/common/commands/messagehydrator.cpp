#include "messagehydrator.h"

ReferenceCountPtr<Command> MessageHydrator::createMessage(const std::string& commandName, const std::string xml) {
    ReferenceCountPtr<Attack> cmd
    if (commandName == "attack") {
        cmd = new Attack();
    }
    if (commandName == "defend") {
        cmd = new Defend();
    }
    if (commandName == "battle") {
        cmd = new BattleResult();
    }
    if (commandName == "chat") {
        cmd = new Chat();
    }
    if (commandName == "didIWin") {
        cmd = new DidIWin();
    }
    if (commandName == "joinGame") {
        cmd = new JoinGame();
    }
    if (commandName == "lose") {
        cmd = new Lose();
    }
    if (commandName == "map") {
        cmd = new Map();
    }
    if (commandName == "mapList") {
        cmd = new MapList();
    }
    if (commandName == "move") {
        cmd = new Move();
    }
    if (commandName == "noMore") {
        cmd = new NoMore();
    }
    if (commandName == "noRoom") {
        cmd = new NoRoom();
    }
    if (commandName == "populate") {
        cmd = new Populate();
    }
    if (commandName == "quit") {
        cmd = new Quit();
    }
    if (commandName == "readyToPlay") {
        cmd = new ReadyToPlay();
    }
    if (commandName == "selectMap") {
        cmd = new SelectMap();
    }
    if (commandName == "surrender") {
        cmd = new Surrender();
    }
    if (commandName == "turnToAttack") {
        cmd = new TurnToAttack();
    }
    if (commandName == "turnToDefend") {
        md = new TurnToDefend();
    }
    if (commandName == "turnToOccupy") {
        cmd = new TurnToOccupy();
    }
    if (commandName == "turnToMove") {
        cmd = new TurnToMove();
    }
    if (commandName == "win") {
        cmd = new Win();
    }
    if (commandName == "youAre") {
        cmd = new YouAre();
    }
    if (cmd != NULL) {
        cmd->hydrate(xml);
    }
    return cmd;
}

MessageHydrator::~MessageHydrator() {
    // No realiza ninguna acion.
}
