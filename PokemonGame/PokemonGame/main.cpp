#include <iostream>
#include <string>
#include "Trainer.h"
#include "Pokemon.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Squirtle.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string name;
	cout << "Welcome to the world of Pokemon!" << endl;
	cout << "Please enter your name: ";
	cin >> name;
	Trainer user = Trainer(name);
	int choice;
	cout << "Nice to meet you, " << user.show_name() << "!" << endl;
	cout << "Please choose your starter pokemon!" << endl;
	//Place starter pokemon options here
	cout << "1) Charmander" << endl;
	cout << "2) Bulbasaur" << endl;
	cout << "3) Squirtle" << endl;
	cin >> choice;
	if (choice == 1) {
		char choice_name;
		cout << "Would you like to name your pokemon? (Y/N) ";
		cin >> choice_name;
		if (choice_name == 'Y' || choice_name == 'y') { //if user wants to nickname pokemon
			string nickname;
			cout << "Name: ";
			cin >> nickname;
			cout << nickname << endl;
			Charmander poke1 = Charmander(nickname, 1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
		else if (choice_name == 'N' || choice_name == 'n') { //if no nickname
			Charmander poke1 = Charmander(1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
	}
	else if (choice == 2) {
		char choice_name;
		cout << "Would you like to name your pokemon? (Y/N) ";
		cin >> choice_name;
		if (choice_name == 'Y' || choice_name == 'y') { //if user wants to nickname pokemon
			string nickname;
			cout << "Name: ";
			cin >> nickname;
			Bulbasaur poke1 = Bulbasaur(nickname, 1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
		else if (choice_name == 'N' || choice_name == 'n') { //if no nickname
			Bulbasaur poke1 = Bulbasaur(1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
	}
	else if (choice == 3) {
		char choice_name;
		cout << "Would you like to name your pokemon? (Y/N) ";
		cin >> choice_name;
		if (choice_name == 'Y' || choice_name == 'y') { //if user wants to nickname pokemon
			string nickname;
			cout << "Name: ";
			cin >> nickname;
			Squirtle poke1 = Squirtle(nickname, 1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
		else if (choice_name == 'N' || choice_name == 'n') { //if no nickname
			Squirtle poke1 = Squirtle(1);
			user.pokemon[0] = poke1; //assign starter pokemon to Trainer
			cout << poke1.show_name() << " has been added to your team!" << endl;
		}
	}
	else {
		cout << "That's not an option" << endl; //Error
	}
	//
	while (choice != 0)
	{
		cout << "What would you like to do, trainer?" << endl;
		cout << "1 - Catch a pokemon" << endl;
		cout << "2 - Battle a trainer" << endl;
		cout << "3 - Go to the shop" << endl;
		cout << "4 - Check your Pokemon" << endl;
		cout << "0 - Exit" << endl;
		cin >> choice;
		if (choice == 1)
		{

		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

		}
		else if (choice == 4)
		{
			user.show_pokemon();
		}
		else if (choice == 0)
		{

		}
	}
	//

	return 0;
}