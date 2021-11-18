#pragma once
#include "Pokemon.h"
#include <string>
using std::string;
class Trainer
{
	string name;
	int money;
	int pokeballs;
	int potions;
public:
	Pokemon pokemon[6]; //each trainer can have max 6 pokemon

	Trainer();
	Trainer(string in_name); //user may set name
	~Trainer();

	//methods
	string show_name();
	void throw_pokeball();
	void show_pokemon();
	void catch_pokemon(Pokemon name, Trainer user);
};

