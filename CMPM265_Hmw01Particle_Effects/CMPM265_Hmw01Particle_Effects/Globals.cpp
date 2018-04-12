#include "Globals.h"

Animation::Animation()
{

}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
	Frame = 0;
	speed = Speed;
	text = t;

	for (int i = 0; i<count; i++)
		frames.push_back(IntRect(x + i*w, y, w, h));

	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);
	sprite.setTextureRect(frames[0]);
}

void Animation::update()
{
	Frame += speed;
	int n = frames.size();
	if (Frame >= n) Frame -= n;
	if (n>0) sprite.setTextureRect(frames[int(Frame)]);
}

bool Animation::isEnd()
{
	return Frame + speed >= frames.size();
}

//Loading textures
Texture t1, t2, t3, t4, t5, t6;
const int W =512;
const int H =512;