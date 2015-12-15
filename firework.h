#ifndef FIREWORK_H
#define FIREWORK_H
#include <iostream>

using namespace std;

struct Velocity {
    float angle;
    float speed;
};

struct Particle {
    float mass;
    Velocity velocity;
    QColor color;
    float xLoc; //Initial X Location;
};

const int Max_Particles = 100;
//Firework FireworkContainer[Max_Particles];

struct Firework {
    GLfloat gravity;
    float radius;
    vector<Particle> particles;

    void initParticles();
    void burst();
    void launch();
    void miniLaunch();
};

#endif // FIREWORK_H


