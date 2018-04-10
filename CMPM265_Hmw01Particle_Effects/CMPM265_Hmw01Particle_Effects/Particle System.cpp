//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"
#include"Particle System.h"

class ParticleSystem : public Drawable, public Transformable
{
public:

	ParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(Points, count),
		m_lifetime(seconds(3)),
		m_emitter(0, 0)
	{
	}

	void setEmitter(Vector2f position)
	{
		m_emitter = position;
	}

	/*void update(Time elapsed)
	{
		for (size_t i = 0; i < m_particles.size(); ++i)
		{
			// update the particle lifetime
			Particle& p = m_particles[i];
			p.lifetime -= elapsed;

			// if the particle is dead, respawn it
			if (p.lifetime <= sf::Time::Zero)
				resetParticle(i);

			// update the position of the corresponding vertex
			m_vertices[i].position += p.velocity * elapsed.asSeconds();

			// update the alpha (transparency) of the particle according to its lifetime
			float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
			m_vertices[i].color.a = static_cast<Uint8>(ratio * 255);
		}
	}*/

private:

	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	/*void resetParticle(size_t index)
	{
		// give a random velocity and lifetime to the particle
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = (std::rand() % 50) + 50.f;
		m_particles[index].velocity = Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = milliseconds((std::rand() % 2000) + 1000);

		// reset the position of the corresponding vertex
		m_vertices[index].position = m_emitter;
	}*/

	vector<Particle> m_particles;
	VertexArray m_vertices;
	Time m_lifetime;
	Vector2f m_emitter;

};
