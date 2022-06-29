#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class AbstractClass //Klasa abstrakcyjna
{
public:
	virtual void BonusTaken()  = 0; // Funkcja wirtualna
	virtual void Movement(float, int, Sprite&) = 0;
	virtual void Intersection(std::vector<Sprite>&, Sprite&, int&, float&, bool&, int&, int& ) = 0;
	virtual void Animation(float, Sprite&) = 0;
};


