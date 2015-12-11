#ifndef FIREWORK_H
#define FIREWORK_H

#endif // FIREWORK_H

using namespace std;

struct Velocity {
    float angle;
    float speed;
};

struct Particle {
    float mass;
};

struct Firework {
    Firework() { // default values?

    }
    float radius;
    vector<Particle> particles;
    Velocity x, y;
    pair<float> position;
    QRgb color;

    void burst();
    void launch();
};


