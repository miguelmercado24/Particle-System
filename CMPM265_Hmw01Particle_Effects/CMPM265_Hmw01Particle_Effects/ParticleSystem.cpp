//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"
#include"ParticleSystem.h"


ParticleSystem::ParticleSystem(unsigned int count):
		
	m_particles(count),
	m_vertices(Points, count),
	m_lifetime(seconds(3)),
	m_emitter(0, 0)
	{
	}

	void ParticleSystem:: setEmitter(Vector2f position)
	{
		m_emitter = position;
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

			// update the position of the corresponding vertex
			/*m_vertices[i].position += p.velocity * elapsed.asSeconds();

			// update the alpha (transparency) of the particle according to its lifetime
			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);*/

		}
	}

	void ParticleSystem::draw(RenderTarget& target, RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		for (Particle p : m_particles)
		{
			target.draw(p.vertex);
		}
		//target.draw(m_particles[i].vertex, states);
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


