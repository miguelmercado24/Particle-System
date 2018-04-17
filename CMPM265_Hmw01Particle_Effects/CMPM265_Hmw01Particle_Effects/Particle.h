#pragma once
//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Globals.h"
#include"Strategy.h"

using namespace sf;
using namespace std;

class Particle
{
private:

public:
	RectangleShape vertex;
	Particle();
	void update(Time elapsed);
	void resetParticle(Vector2f e_position);
	bool alive;
	Vector2f velocity, maxVelocity;
	Vector2f initSize, maxSize;
	float rotateSpeed, rotateMaxSpeed;
	float angle, maxRotAngle;
	float speed;
	Time lifetime;
	Time m_lifetime;
};
