//Miguel Ocana Mercado
//mocaname@ucsc.edu
//CMPM 265
//HMK01 Particle Systems
#pragma once
#include"Globals.h"

class Strategy
{
public:
	virtual float update(float ratio) = 0;
};

class LinearStrategy : public Strategy
{
public:
	virtual float update(float ratio)
	{
		return 1;
	}
};

class ExponentialStrategy : public Strategy
{
public:
	virtual float update(float ratio)
	{
		return ratio;
	}
};
class SinStrategy : public Strategy
{
public:
	virtual float update(float ratio)
	{
		return sinf(ratio * 2 * 3.14);
	}
};
