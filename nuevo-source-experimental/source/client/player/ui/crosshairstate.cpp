#include "crosshairstate.h"

CrossHairState::CrossHairState(const double& latitude, const double& longitude,
    const bool& inPlanet):
    latitude(latitude),
    longitude(longitude),
    inSphere(inPlanet) {
    // No realiza ninguna accion.
}

CrossHairState::~CrossHairState() {
    // No realiza ninguna accion.
}

void CrossHairState::setLatitude(const double& latitude) {
    this->latitude = latitude;
}

double CrossHairState::getLatitude() const {
    return latitude;
}

void CrossHairState::setLongitude(const double& longitude) {
    this->longitude = longitude;
}

double CrossHairState::getLongitude() const {
    return longitude;
}

void CrossHairState::setInSphere(const bool& inSphere) {
    this->inSphere = inSphere;
}

bool CrossHairState::getInSphere() const {
    return inSphere;
}

