//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"
#include"ParticleSystem.h"
#include"Globals.h"


ParticleSystem::ParticleSystem(unsigned int count) :

	m_particles(count),
	m_vertices(Points, count),
	m_lifetime(seconds(3)),
	m_emitter(0, 0),
	currentparticles(count)
	{
	}

	void ParticleSystem:: setEmitter(Vector2f position)
	{
		m_emitter = position;
	}

	void ParticleSystem::setTexture(Texture* texture)
	{
		//p_texture.loadFromFile("images/rock_v02.png");
		p_texture = *texture;

		for (size_t i = 0; i < m_particles.size(); ++i)
		{
			// apply the text to each particle
			Particle& p = m_particles[i];
			//p.vertex.setTexture(&p_texture);
			 p.vertex.setTexture(texture);
		}
	}


	void ParticleSystem:: incPart()
	{
		m_particles.resize(prt += 100);
		//m_vertices.resize(prt += 100);
		setTexture(&p_texture);
		
	}

	void ParticleSystem::decPart()
	{
		if (prt <= 0)
		{
			pText.setString("Min Particles Reached!");
			window.draw(pText);
		}

		else
		{
			m_particles.resize(prt -= 100);
			//m_vertices.resize(prt -= 100);
			setTexture(&p_texture);
		}
	}

	void ParticleSystem::update(Time elapsed)
	{
		for (size_t i = 0; i < m_particles.size(); ++i)
		{
			// update the particle lifetime
			Particle& p = m_particles[i];

			// if the particle is dead, respawn it
			if (p.alive == false)
				p.resetParticle(m_emitter);

			// update the particles
				p.update(elapsed);
		}
	}



