#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Trainer.h"
//Pokemon:
#include "Pokemon.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Squirtle.h"
#include "Pidgey.h"
#include "Caterpie.h"
#include "Spearow.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	srand(time(0));
	//Create array of wild pokemon for battling

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
	
	while (choice != 0)
	{
		cout << endl << "What would you like to do, trainer?" << endl;
		cout << "1 - Battle Wild Pokemon" << endl;
		cout << "2 - Battle a trainer" << endl;
		cout << "3 - Go to the shop" << endl; // I think we should get rid of the shop unless we somehow have enough time for it
		cout << "4 - Check your Pokemon" << endl;
		cout << "0 - Exit" << endl;
		cin >> choice;
		if (choice == 1)
		{

		}
		else if (choice == 2)
		{
			int num_poss_trainers = 3; //number of names in below array of trainers
			Trainer poss_names[3] = { Trainer("Annie", Pidgey(2), Caterpie(3), Spearow(2)),
				Trainer("Kent", Pidgey(2), Caterpie(3), Spearow(2)),
				Trainer("Joey", Pidgey(2), Caterpie(3), Spearow(2))};
			int num = rand() % num_poss_trainers; // random choice between 0 and length of array
			Trainer opponent = poss_names[num];
			user.fight(user, opponent);
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