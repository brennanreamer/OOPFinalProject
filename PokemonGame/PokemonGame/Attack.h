#pragma once
#include <string>
using std::string;
class Attack
{
	string name;
	int damage;
	int pp;
	int accuracy;
public:
	Attack();
	Attack(string name, int damage, int pp, int accuracy);
	~Attack();
	string get_attack();
	int show_pp();
	int get_damage();
};

