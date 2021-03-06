#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <list>
#include<string>
#include<sstream>

using namespace std;
using namespace sf;

//Setting the Window Dimensions
extern RenderWindow window;

class Animation
{
public:
	float Frame, speed;
	Sprite sprite;
	std::vector<IntRect> frames;
	Texture text;

	Animation();

	Animation(Texture &t, int x, int y, int w, int h, int count, float Speed);

	void update();

	bool isEnd();

};

extern Texture t1, t2, t3, t4, t5, t6, asteroid;

//Animations

extern Animation sExplosion;
extern Animation sRock;
extern Animation sRock_small;
extern Animation sBullet;
extern Animation sExplosion_ship;

//begining number of particles
extern int prt;

extern const int W;
extern const int H;

extern unsigned int currentparticles;

//Text for Number of Particles
extern Text pText;
extern Text lText;
extern Text eText;
extern Text sText;