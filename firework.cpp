#include <stdlib.h>
#include "firework.h"

const GLfloat Firework::Gravity = 0.05f;
Firework firework;

void Firework::initParticles() {
    float xInitLoc = rand() % 500;
    //Random speeds, not sure of values
    float initParticleSpeed = rand() % 100;
    float initParticleAngle = rand() % 100 + 45;

    // Assign rbg colors, 0-255 randomly. Alpha set to max for now
    QColor initColor;
    initColor.setRed(rand() % 255);
    initColor.setGreen(rand() % 255);
    initColor.setBlue(rand() % 255);
    initColor.setAlpha(255);

    // Initialize all particles to have the same xLoc, speed, angle, and color
    for (std::vector<Particle>::iterator it = firework.particles.begin() ; it != firework.particles.end(); ++it) {
        Particle particle = *it;
        particle.xLoc = xInitLoc;
        particle.velocity.speed = initParticleSpeed;
        particle.velocity.angle = initParticleAngle;
        particle.color = initColor;
    }
}

void Firework::burst() {
    //Code for firework exploding
    for (std::vector<Particle>::iterator it = firework.particles.begin() ; it != firework.particles.end(); ++it) {
        float particleSpeed = rand() % 25;
        float particleAngle = rand() % 100 + 45;
        Particle particle = *it;
        particle.velocity.speed = particleSpeed;
        particle.velocity.angle = particleAngle;
    }
    if ( alpha > 0.0f ) {
        alpha -= 0.01f; //Make firework particle invisible
    }
    miniLaunch();
}

void Firework::launch() {
    //Shoots the firework


    //At apex of arc, burst
    burst();
}

void Firework::miniLaunch() {

}
