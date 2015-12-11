#include <stdlib.h>
#include "firework.h"

const GLfloat Firework::Gravity = 0.05f;

void Firework::burst() {
    //Code for firework exploding
    for ( int i = 0; i < 123; i++ ) {
        //TODO: Slowdown particle (to stop), use gravity, replace 123 w/ num particles

    }
    if ( alpha > 0.0f ) {
        alpha -= 0.01f; //Make firework particle invisible
    }
}

void Firework::launch() {
    //Shoots the firework
}
