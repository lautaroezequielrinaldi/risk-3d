/**
 * Project Includes.
 */
#include "referencecount.h"

ReferenceCount::ReferenceCount():
    referenceCount( 0 ) {
    // No realiza ninguna acciòn.
}

void ReferenceCount::increment() {
    this->referenceCount++;
}

void ReferenceCount::decrement() {
    this->referenceCount--;
}

int ReferenceCount::getReferenceCount() {
    return this->referenceCount;
}

ReferenceCount::~ReferenceCount() {
    // No realiza ninguna acciòn.
}

