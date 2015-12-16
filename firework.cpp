#include <stdlib.h>
#include <chrono>
#include <thread>
#include "firework.h"

const GLfloat Firework::Gravity = 0.05f;
Firework firework;

// Generates appropriate fields for each firework
// Random X location is set, speeds, angles
// Random colors are assigned to make things interesting
// All particles in firework are fired in same direction & color
// Fireworks have a randomly determined time until they burst
void Firework::initParticles() {
    float xInitLoc = rand() % 500; //Initial location on the x axis (y stays the same)
    //Random speeds, not sure of values
    float initParticleSpeed = rand() % 100;
    initParticleSpeed += 200; //Allows room for gravity to properly affect particles
    float initParticleAngle = rand() % 45; //Angle from 0 to 45 degrees

    // Assign rbg colors, 0-255 randomly.
    QColor initColor;
    initColor.setRed(rand() % 255);
    initColor.setGreen(rand() % 255);
    initColor.setBlue(rand() % 255);
    initColor.setAlpha(255);

    // Initialize all particles to have the same xLoc, speed, angle, and color
    for (std::vector<Particle>::iterator it = firework.particles.begin() ; it != firework.particles.end(); ++it) {
        Particle particle = *it;
        particle.xLoc = xInitLoc;
        particle.yLoc = 0;
        particle.velocity.speed = initParticleSpeed;
        particle.velocity.angle = initParticleAngle;
        particle.color = initColor;
    }

    timeUntilLaunch = rand() % 200; //To spread out explosions

    hasExploded = false; // Hasn't exploded yet
}

void Firework::burst() {
    while ( alpha > 0 ) {
        //Code for firework exploding
        for (std::vector<Particle>::iterator it = firework.particles.begin() ; it != firework.particles.end(); ++it) {
            float particleAngle = rand() % 100 + 45; // Randomizing angle
            Particle particle = *it;
            particle.velocity.speed = 0.99 * particle.velocity.speed; //Lowering speed
            particle.velocity.angle = particleAngle;
            particle.xLoc += ((particle.velocity.angle / 100)*particle.xLoc);
            particle.yLoc -= particle.velocity.speed;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // To give appearance of "falling"
        alpha -= 0.01f; //Make firework particle invisible
    }

    std::vector<Particle>().swap(firework.particles); // Deleting all particles once they're invisible
}

void Firework::launch() {
    //Shoots the firework
    while ( !hasExploded) {
        if ( timeUntilLaunch != 0 ) {
            timeUntilLaunch --;
        } else {
            //Iterate over all particles, update position
            for (std::vector<Particle>::iterator it = firework.particles.begin() ; it != firework.particles.end(); ++it) {
                Particle particle = *it;
                particle.xLoc += ((particle.velocity.angle / 100)*particle.xLoc); //Hacky movement on the x axis
                particle.yLoc += particle.velocity.speed;
                particle.velocity.speed -= 9.8; //Decrease at gravity speed
                if ( particle.velocity.speed <= 0 ) {
                    hasExploded=true;
                    burst(); //Explode at apex of arc
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(20)); // To give appearance of "rising"
            }
        }
    }
}

void mainLaunch() {
    //Adding 20 fireworks
    for (int i = 0; i < 20; i++ ) {
        Firework fw;
        fw.initParticles();
        fw.launch();
        std::this_thread::sleep_for(std::chrono::milliseconds(fw.timeUntilLaunch)); // Wait to launch next one until this one is launched
    }

}
