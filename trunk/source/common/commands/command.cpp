#include "command.h"

Command::Command(Player& player, Mapa &map): jugador(player), mapa ( map )
{
}

Command::~Command()
{
}
