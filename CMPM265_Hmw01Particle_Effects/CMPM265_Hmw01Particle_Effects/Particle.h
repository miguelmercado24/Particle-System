#pragma once
//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include"Globals.h"

using namespace sf;
using namespace std;

class Particle
{
private:
	//Vector2f velocity;
	//Time lifetime;
	Time m_lifetime;

public:
	RectangleShape vertex;
	Particle();
	float x, y, dx, dy, R, angle;
	Animation anim;
	//void settings(Animation &a, int X, int Y, float Angle, int radius);
	void update(Time elapsed);
	void resetParticle(Vector2f e_position);
	bool alive;
	Vector2f velocity;
	Time lifetime;
	
};
