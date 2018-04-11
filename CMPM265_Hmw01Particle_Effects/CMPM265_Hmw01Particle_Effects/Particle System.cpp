//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"
#include"Particle System.h"


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
			p.update(elapsed);

		}
	}

	void ParticleSystem::draw(RenderTarget& target, RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		target.draw(m_vertices, states);
	}


