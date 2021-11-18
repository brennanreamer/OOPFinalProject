#include <iostream>
#include "Trainer.h"
#include "Pokemon.h"
using std::cin;
using std::cout;
using std::endl;
Trainer::Trainer() {
	name = "Ash";
	money = 100;
	pokeballs = 3;
	potions = 1;
	pokemon;
}
Trainer::Trainer(string in_name) {
	name = in_name;
	money = 100;
	pokeballs = 3;
	potions = 1;
	pokemon;
}
Trainer::~Trainer() {

}
string Trainer::show_name() {
	return name;
}
void Trainer::throw_pokeball() {
	pokeballs -= 1; //lose a pokeball who it is thrown
}
void Trainer::show_pokemon() {
	for (int i = 0; i < (sizeof(pokemon)/sizeof(Pokemon)); i++) {
		//output each pokemon's info
		cout << endl;
		cout << i+1 << ") " << pokemon[i].show_name() << endl;
		cout << pokemon[i].show_type() << "-type" << endl;
		cout << "Level: " << pokemon[i].show_level() << endl;
		cout << "HP: " << pokemon[i].show_health() << endl;
	}
}
void Trainer::catch_pokemon(Pokemon poke, Trainer user) {
	int space = 0;
	for (int i = 0; i < sizeof(pokemon); i++) {
		if (pokemon[i].show_name() == "Empty") {
			pokemon[i] = poke;
			space = 1; //returns that space was found
			break;
		}
	}
	if (space == 0) { //if no space was found for the pokemon
		cout << "Where do you want to store " << poke.show_name() << "?" << endl;
		user.show_pokemon(); //show user their pokemon
		int pos;
		cout << "Please enter position (1-6): ";
		cin >> pos;
		pokemon[pos] = poke; //Place new pokemon in chosen position
		//Maybe add a place to store pokemon?
	}
}