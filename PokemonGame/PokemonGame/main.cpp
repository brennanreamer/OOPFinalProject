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
			//Create array of wild pokemon for battling
			Pokemon wild[6] = { Charmander(1), Bulbasaur(1),Squirtle(1),Caterpie(1), Spearow(1), Pidgey(1) };
			int random = rand() % 6;
			user.wild_battle(user, wild[random]);
		}
		else if (choice == 2)
		{
			int num_poss_trainers = 4; //number of names in below array of trainers
			Trainer poss_names[4] = { Trainer("Annie", Pidgey(2), Caterpie(3), Spearow(2)),
				Trainer("Kent", Pidgey(2), Caterpie(3), Spearow(2)),
				Trainer("Joey", Pidgey(2), Caterpie(3), Spearow(2)),
				Trainer("Haley", Charmander(1), Squirtle(3), Pidgey(2))};
			int num = rand() % num_poss_trainers; // random choice between 0 and length of array
			Trainer opponent = poss_names[num];
			user.fight(user, opponent);
		}
		else if (choice == 3)
		{
			int shop_choice = 0;
			while (shop_choice != 3) {
				cout << "Welcome to the shop! How can I help you today?" << endl << endl;
				cout << "You have " << user.show_money() << " coins." << endl;
				cout << "1) Buy Pokeballs" << endl;
				cout << "2) Sell Pokemon" << endl;
				cout << "3) Exit" << endl;
				cin >> shop_choice;
				if (shop_choice == 1) {
					cout << "How many would you like? (Price: 10 coins each)" << endl;
					int amt = 0;
					cin >> amt;
					int price = amt * 10;
					if (amt > 0) {
						if (price <= user.show_money()) {
							user.set_pokeball(amt); //give user amount of pokeballs requested
							user.set_money(-price); //charge 10 coins per pokeball purchased
							cout << "You have received " << amt << " pokeballs for a total of " << price << " coins." << endl;
						}
						else {
							cout << "You don't have enough coins." << endl;
						}
					}
				}
				if (shop_choice == 2) {
					cout << "Which pokemon would you like to sell? (10 coins per the pokemon's level)" << endl;
					int poke;
					user.show_pokemon();
					cin >> poke;
					poke -= 1;
					cout << "You have received " << 10 * user.pokemon[poke].show_level() << " coins for selling " << user.pokemon[poke].show_name() << "." << endl;
					user.set_money(10 * user.pokemon[poke].show_level());
					user.pokemon[poke] = Pokemon(); //sets sold pokemon to an empty slot
					//PROBLEM: Need to move other pokemon in party to replace empty slot
					for (int i = 1; i < 6; i++) {
						if (user.pokemon[i].show_name() != "Empty") {
							if ((user.pokemon[i - 1].show_name() == "Empty")) {
								user.pokemon[i - 1] = user.pokemon[i];
								user.pokemon[i] = Pokemon();
							}
						}
					}
				}
				if (shop_choice == 3) {
					cout << "Thanks for coming!" << endl;
				}
			}
		}
		else if (choice == 4)
		{
			user.show_pokemon();
		}
		else if (choice == 0)
		{
			cout << "Thanks for playing!" << endl;
		}
	}
	//

	return 0;
}