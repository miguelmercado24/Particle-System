#pragma once
//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"
#include"Globals.h"

using namespace sf;
using namespace std;

class ParticleSystem
{
public:
	
	ParticleSystem(unsigned int count);
	unsigned int currentparticles;
	void setEmitter(Vector2f position);
	void setTexture(Texture* texture);
	void incPart();
	void decPart();
	void update(Time elapsed);
	vector<Particle> m_particles;
	Strategy *velStrategy = nullptr;
	Strategy *rotStrategy = nullptr;

private:

	//void ParticleSystem::resetParticle(std::size_t index);
	VertexArray m_vertices;
	Time m_lifetime;
	Vector2f m_emitter;
	Texture p_texture;

};