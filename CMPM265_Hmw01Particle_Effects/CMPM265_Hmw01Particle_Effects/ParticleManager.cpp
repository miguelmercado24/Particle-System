//Miguel Ocana Mercado
//mocaname@ucsc->edu
//CMPM 265
//HMK01 Particle Systems

#include"ParticleManager.h"

ParticleManager::ParticleManager(unsigned int count)
{
	system1 = new ParticleSystem(count);
	system1->setEmitter(Vector2f(200,400));
	system1->velStrategy = new LinearStrategy();
	system1->rotStrategy = new LinearStrategy();
	system1->angleStrategy = new LinearStrategy();

	system2 = new ParticleSystem(count);
	system2->setEmitter(Vector2f(700, 400));
	system2->velStrategy = new ExponentialStrategy();
	system2->rotStrategy = new ExponentialStrategy();
	system2->angleStrategy = new ExponentialStrategy();

	system3 = new ParticleSystem(count);
	system3->setEmitter(Vector2f(1200, 400));
	system3->velStrategy = new SinStrategy();
	system3->rotStrategy = new SinStrategy();
	system3->angleStrategy = new SinStrategy();
}

void ParticleManager::setEmitterPos(Vector2f position) 
{
	//system1->setEmitter(position);
	//system2->setEmitter(position->x - 200);
	//system2->setEmitter(position->x + 200);

}

void ParticleManager::setSystemsText()
{
	p_texture1.loadFromFile("images/rock_v02.png");
	p_texture2.loadFromFile("images/Ship.png");
	p_texture3.loadFromFile("images/blue_bulet.png");
	system1->setTexture(&p_texture1);
	system2->setTexture(&p_texture2);
	system3->setTexture(&p_texture3);
}

void ParticleManager::Update(Time elapsed)
{
	system1->update(elapsed);
	system2->update(elapsed);
	system3->update(elapsed);

	//increasing particles
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		system1->incPart();
		system2->incPart();
		system3->incPart();
	}

	//decreasingparticles
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		system1->decPart();
		system2->decPart();
		system3->decPart();
	}
}
