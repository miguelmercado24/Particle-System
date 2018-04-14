//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems
#pragma once
#include"Globals.h"
#include"ParticleSystem.h"

class ParticleManager

{
private:
	

	Vector2f left;
	Vector2f right;

public:

	ParticleSystem *system1 = nullptr;
	ParticleSystem *system2 = nullptr;
	ParticleSystem *system3 = nullptr;
	ParticleManager(unsigned int count);
	void setEmitterPos(Vector2f position);
	void setSystemsText();
	void Update(Time elapsed);

	void incParts();
	void decParts();

};


