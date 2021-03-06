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
	Texture p_texture1;
	Texture p_texture2;
	Texture p_texture3;
	ParticleManager(unsigned int count);
	void setEmitterPos(Vector2f position);
	void setSystemsText();
	//void SetBehaviours();
	void Update(Time elapsed);

};


