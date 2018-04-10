#pragma once
//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include"Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable, public Transformable
{
public:

	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(Points, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0)
	{
	}
	
	void setEmitter(Vector2f position);

	void update(Time elapsed);

private:

	virtual void draw(RenderTarget& target, RenderStates states) const;

	vector<Particle> m_particles;
	VertexArray m_vertices;
	Time m_lifetime;
	Vector2f m_emitter;

};