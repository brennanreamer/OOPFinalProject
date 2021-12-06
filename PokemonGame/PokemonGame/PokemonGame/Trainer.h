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
	Trainer(string in_name, Pokemon in_pokemon1, Pokemon in_pokemon2, Pokemon in_pokemon3); //For CPU Trainers, can identify pokemon they have
	~Trainer();

	//methods
	string show_name();
	void throw_pokeball();
	void show_pokemon();
	void catch_pokemon(Pokemon name, Trainer user);
	void fight(Trainer user, Trainer& opp);
	void wild_battle(Trainer user, Pokemon& opp);
	int num_pokemon(Trainer user);
};

