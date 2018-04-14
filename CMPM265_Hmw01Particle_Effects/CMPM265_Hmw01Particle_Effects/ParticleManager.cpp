//Miguel Ocana Mercado
//mocaname@ucsc->edu
//CMPM 265
//HMK01 Particle Systems

#include"ParticleManager.h"

ParticleManager::ParticleManager(unsigned int count)
{
	system1 = new ParticleSystem(count);
	system1->setEmitter(Vector2f(200,400));
	system2 = new ParticleSystem(count);
	system2->setEmitter(Vector2f(700, 400));
	system3 = new ParticleSystem(count);
	system3->setEmitter(Vector2f(1200, 400));
}

void ParticleManager::setEmitterPos(Vector2f position) 
{
	system1->setEmitter(position);
	//system2->setEmitter(position->x - 200);
	//system2->setEmitter(position->x + 200);

}

void ParticleManager::setSystemsText()
{
	system1->setText();
	system2->setText();
	system3->setText();
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
