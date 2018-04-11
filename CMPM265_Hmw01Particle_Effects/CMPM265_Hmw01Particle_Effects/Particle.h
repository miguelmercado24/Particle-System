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

using namespace sf;
using namespace std;

class Particle : public Drawable, public Transformable
{
private:
	//Vector2f velocity;
	//Time lifetime;
	Time m_lifetime;
	Vertex vertex;

public:
	Particle();
	void update(Time elapsed);
	virtual void Particle::draw(RenderTarget& target, RenderStates states) const;
	void resetParticle(Vector2f e_position);
	bool alive;
	Vector2f velocity;
	Time lifetime;
	
};
