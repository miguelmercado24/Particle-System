//Miguel Ocana Mercado
//mocaname@ucsc->edu
//CMPM 265
//HMK01 Particle Systems

#include"ParticleManager.h"

ParticleManager::ParticleManager(unsigned int count)
{
	system1 = new ParticleSystem(count);
	system1->setEmitter(Vector2f(100,100));
	system2 = new ParticleSystem(count);
	system2->setEmitter(Vector2f(400, 100));
	system3 = new ParticleSystem(count);
	system3->setEmitter(Vector2f(800, 100));
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
}
