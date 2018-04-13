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
#include"Globals.h"

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable, public Transformable
{
public:
	
	ParticleSystem(unsigned int count);
	unsigned int currentparticles;
	
	void setEmitter(Vector2f position);

	//void setAnims(Animation &a, int X, int Y, float Angle, int radius);
	void setText();
	void incPart();
	void decPart();
	void update(Time elapsed);

private:

	virtual void draw(RenderTarget& target, RenderStates states) const;
	void ParticleSystem::resetParticle(std::size_t index);
	vector<Particle> m_particles;
	VertexArray m_vertices;
	Time m_lifetime;
	Vector2f m_emitter;
	Texture asteroid;

};