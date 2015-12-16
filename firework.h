#ifndef FIREWORK_H
#define FIREWORK_H
#include <iostream>

using namespace std;

struct Velocity {
    float angle;
    float speed;
};

void mainLaunch();

struct Particle {
    float mass;
    Velocity velocity;
    QColor color;
    float xLoc; //Initial X Location;
    float yLoc; //Always starts at 0
};

const int Max_Particles = 100;
//Firework FireworkContainer[Max_Particles];

struct Firework {
    GLfloat gravity;
    float radius;
    bool hasExploded;
    float timeUntilLaunch;
    vector<Particle> particles;

    void initParticles();
    void burst();
    void launch();
    void miniLaunch();
};

#endif // FIREWORK_H


