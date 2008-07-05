#include "spherestate.h"

SphereState::SphereState(const double& lastTime, const float& alpha,
    const float& beta, const float& distance):
    lastTime(lastTime),
    alpha(alpha),
    beta(beta),
    distance(distance) {
    // No realiza ninguna accion.
}

SphereState::~SphereState() {
    // No realiza ninguna accion.
}

double SphereState::getLastTime() const {
    return lastTime;
}

void SphereState::setLastTime(double theLastTime) {
    lastTime = theLastTime;
}

float SphereState::getAlpha() const {
    return alpha;
}

float SphereState::getBeta() const {
    return beta;
}

float SphereState::getDistance() const {
    return distance;
}

void SphereState::incrementAlphaInTime(double deltaTime) {
    alpha += 0.5 * deltaTime;
    adjustAlpha();
}

void SphereState::decrementAlphaInTime(double deltaTime) {
    alpha += -0.5 * deltaTime;
    adjustAlpha();
}

void SphereState::incrementBetaInTime(double deltaTime) {
    beta += 0.5 * deltaTime;
    adjustBeta();
}

void SphereState::decrementBetaInTime(double deltaTime) {
    beta += -0.5 * deltaTime;
    adjustBeta();
}

void SphereState::incrementDistanceInTime(double deltaTime) {
    distance += 0.5 * deltaTime;
    adjustDistance();
}

void SphereState::decrementDistanceInTime(double deltaTime) {
    distance += -0.5 * deltaTime;
    adjustDistance();
}

void SphereState::adjustAlpha() {
    alpha = (alpha > 2 * PI) ? alpha - 2 * PI : alpha;
    alpha = (alpha < -2 * PI) ? alpha +  2 * PI : alpha;
}

void SphereState::adjustBeta() {
    beta = (beta > 1.0) ? 1.0 : beta;
    beta = (beta < -1.0) ? -1.0 : beta;
}

void SphereState::adjustDistance() {
    distance = (distance > 2.0) ? 2.0 : distance;
    distance = (distance < -2.0) ? -2.0: distance;
}

