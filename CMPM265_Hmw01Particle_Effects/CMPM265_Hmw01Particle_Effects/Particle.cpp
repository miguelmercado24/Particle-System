//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems

#include"Particle.h"

Particle::Particle()
{
	vertex.setSize(Vector2f(10,10));
	m_lifetime = seconds(3);
	initSize= Vector2f(10, 10);
	maxSize= Vector2f(70,70);
	rotateMaxSpeed = 100;
	maxVelocity = Vector2f(20, 20);

}

void Particle::update(Time elapsed)
	{

	// update the particle lifetime
	lifetime -= elapsed;

	// Check to see if particle is dead
	if (lifetime <= Time::Zero)
		alive = false;
	

	// update the position of the vertex
	//vertex.move(velocity * elapsed.asSeconds());
	vertex.move(Vector2f(cos(angle) * (velocity* elapsed.asSeconds(), sin(angle) * velocity* elapsed.asSeconds())));

	// update the alpha (transparency) of the particle according to its lifetime
	float ratio = lifetime.asSeconds() / m_lifetime.asSeconds();
	Color c = vertex.getFillColor();
	c.a = static_cast<Uint8>(ratio * 255);
	vertex.setFillColor(c);

	//Updating the size  (i.e., size = start_size + ((lifetime-current_time)/lifetime)*final_size).

	//float sizeRatio = (lifetime.asSeconds() - m_lifetime.asSeconds()) / lifetime.asSeconds();
	float sizeRatioAnti = m_lifetime.asSeconds() / lifetime.asSeconds();
	
	//increasing size
	vertex.setSize((sizeRatioAnti)*maxSize);

	/*if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		vertex.setSize((sizeRatioAnti)*maxSize);
	}*/

	//shrinking size
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		vertex.setSize((ratio)*maxSize);
		//vertex.setSize((ratio)* initSize);
	}

	//update rotation
	rotateSpeed = ratio *rotateMaxSpeed;
	vertex.rotate(rotateSpeed*elapsed.asSeconds());

	}



void Particle:: resetParticle(Vector2f e_position)
{
	// give a random velocity and lifetime to the particle
	angle = (rand() % 360) * 3.14f / 180.f;
	speed = (rand() % 50) + 50.f;
	velocity = Vector2f(cos(angle) * speed, sin(angle) * speed);
	lifetime = milliseconds((rand() % 2000) + 1000);
	//vertex.setSize(Vector2f(10, 10));
	alive = true;

	// reset the position of the corresponding vertex
	vertex.setPosition(e_position);
}

