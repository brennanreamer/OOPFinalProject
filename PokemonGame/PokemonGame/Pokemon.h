#pragma once
#include <string>
#include "Attack.h"
using std::string;
class Pokemon
{
	//attributes
	string name;
	string type;
	int level;
	int health;
	int PP;
public:
	Attack moves[4]; //each pokemon has 4 moves

	//constructor
	Pokemon(); // Default Constructor
	Pokemon(string in_name, string in_type, int level);
	//destructor
	~Pokemon();
	//methods
	string show_name();
	string show_type();
	int show_level();
	int show_health();
};

