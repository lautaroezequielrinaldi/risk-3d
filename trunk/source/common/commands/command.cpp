#include "command.h"

Command::Command(Player& player, Mapa &mapa): jugador(player), mapa ( mapa )
{
}

Command::~Command()
{
}
