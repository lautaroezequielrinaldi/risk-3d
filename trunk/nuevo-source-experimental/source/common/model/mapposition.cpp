#include "mapposition.h"

MapPosition::MapPosition(const int& x, const int& y):
    x(x),
    y(y) {
    // No realiza ninguna acciòn.
}

void MapPosition::setX(const int& x) {
    this->x = x;
}

int& MapPosition::getX() {
    return this->x;
}

void MapPosition::setY(const int& y) {
    this->y = y;
}

int& MapPosition::getY() {
    return this->y;
}

bool MapPosition::operator==(const MapPosition& position) {
    return (this->x == position.x) && (this->y == position.y);
}

MapPosition::~MapPosition() {
    // No realiza ninguna acciòn.
}

