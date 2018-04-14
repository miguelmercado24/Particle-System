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

	/*void ParticleSystem::setAnims(Animation &a, int X, int Y, float Angle, int radius)
	{
		for (size_t i = 0; i < m_particles.size(); ++i)
		{
			Particle& p = m_particles[i];
			p.settings(a, X, Y, Angle, radius);
		}
	}*/

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
				//resetParticle(i);

			// update the particles
				p.update(elapsed);
		}
	}

	void ParticleSystem::resetParticle(std::size_t index)
	{
		// give a random velocity and lifetime to the particle
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = (std::rand() % 50) + 50.f;
		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

		// reset the position of the corresponding vertex
		m_vertices[index].position = m_emitter;
	}


