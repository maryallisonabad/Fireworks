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
};

const int Max_Particles = 10000;
Firework FireworkContainer[Max_Particles];

struct Firework {
    Firework() {
        //Generating random x (y stays the same)
        xLoc = ((float)rand() / (float)RAND_MAX) * 800.0f; // TODO: Play with float value
        //Random speeds, not sure of values
        x.speed = rand() % 100;
        y.speed = rand() % 100;

        // Assign rng colors, 0-255 randomly. Alpha set to max for now
        color.setRed(rand() % 255);
        color.setGreen(rand() % 255);
        color.setBlue(rand() % 255);
        color.setAlpha(255);

        hasExploded = false; //Since firework just started

        cout << "Firework created" << endl;
    }
    GLfloat Gravity;
    float radius;
    vector<Particle> particles;
    Velocity x, y;
    //pair<float> position;
    QColor color; // Made this a QColor instead of a QRgb

    float xLoc; //Initial X Location;
    float life; //Remaining life of particle (when should it die)?
    bool hasExploded;

    void burst();
    void launch();
};

#endif // FIREWORK_H


