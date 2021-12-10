#include "Pokemon.h"
#include <iostream>
using std::cout;
using std::endl;
Pokemon::Pokemon() { //Default Constructor (if not a pokemon)
	name = "Empty";
	type = "Normal";
	level = 0;
	health = 0;
	PP = 0;
	exp = 0;
}
Pokemon::Pokemon(string in_name, string in_type, int in_level) {
	name = in_name;
	type = in_type;
	level = in_level;
	health = 100;
	PP = 200;
	exp = 0;
}
Pokemon::~Pokemon() {

}
string Pokemon::show_name() {
	return name;
}
string Pokemon::show_type() {
	return type;
}
int Pokemon::show_level() {
	return level;
}
int Pokemon::show_exp() {
	return exp;
}
int Pokemon::show_health() {
	return health;
}
int Pokemon::show_PP() {
	return PP;
}
void Pokemon::set_health(int num) {
	health = health - num;
}
void Pokemon::set_PP(int num) {
	PP = PP - num;
}
int Pokemon::num_moves()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (moves[i].get_attack() != "Empty Slot")
		{
			count = count + 1;
		}
	}
	return count;
}
void Pokemon::exp_earn(int amt) {
	exp += amt;
	if (exp >= 100) {
		level++;
		exp -= 100;
		cout << name << " has leveled up to level " << level << "!" << endl;
	}
}