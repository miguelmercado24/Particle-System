//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"


void Particle::update(Time elapsed)
	{

	// update the particle lifetime
	lifetime -= elapsed;

	// Check to see if particle is dead
	if (lifetime <= Time::Zero)
		//resetParticle();
		alive = false;
	
	// update the position of the vertex
	vertex.position += velocity * elapsed.asSeconds();

	//update velocity

	//update color

	//update size

	//update rotation

	// update the alpha (transparency) of the particle according to its lifetime
	float ratio = lifetime.asSeconds() / m_lifetime.asSeconds();
	vertex.color.a = static_cast<Uint8>(ratio * 255);
	}

void Particle:: resetParticle(Vector2f e_position)
{
	// give a random velocity and lifetime to the particle
	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = (std::rand() % 50) + 50.f;
	velocity = Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	lifetime = milliseconds((std::rand() % 2000) + 1000);

	// reset the position of the corresponding vertex
	vertex.position = e_position;
}

