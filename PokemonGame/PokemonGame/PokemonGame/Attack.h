#pragma once

#include <string>
using std::string;
class Attack
{
public:
	string name;
	int damage;
	int pp;
	int accuracy;

	Attack();
	Attack(string name, int damage, int pp, int accuracy);
	~Attack();
	string get_attack();
	int get_damage();
};

