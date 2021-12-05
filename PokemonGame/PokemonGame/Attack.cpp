#include "Attack.h"

Attack::Attack() { //Empty slot (no move)
	name = "Empty Slot";
	damage = 0;
	pp = 0;
	accuracy = 100;
}
Attack::Attack(string name, int damage, int pp, int accuracy) {
	this->name = name;
	this->damage = damage;
	this->pp = pp;
	this->accuracy = accuracy;
}
Attack::~Attack() {

}

string Attack::get_attack()
{
	return name;
}
