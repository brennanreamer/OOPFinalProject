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
Trainer::Trainer(string in_name, Pokemon in_pokemon1, Pokemon in_pokemon2, Pokemon in_pokemon3) { //FIND WAY TO SHORTEN THIS
	name = in_name;
	money = 100;
	pokeballs = 3;
	potions = 1;
	pokemon[0] = in_pokemon1;
	pokemon[1] = in_pokemon2;
	pokemon[2] = in_pokemon3;
}
Trainer::~Trainer() {

}
string Trainer::show_name() {
	return "Trainer " + name;
}
void Trainer::throw_pokeball() {
	if (pokeballs > 0)
	{
		pokeballs -= 1; //lose a pokeball who it is thrown
	}
	if (pokeballs<=0){
		cout << "No pokeballs left";
	}
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
		cout << "(Note: Pokemon currently in chosen position will be removed)" << endl;
		user.show_pokemon(); //show user their pokemon
		int pos;
		cout << "Please enter position (1-6): ";
		cin >> pos;
		pokemon[pos] = poke; //Place new pokemon in chosen position
		//Maybe add a place to store pokemon?
	}
}
void Trainer::fight(Trainer user, Trainer& opp) {
	srand(time(0));
	int num_user_poke = user.num_pokemon(user);
	cout << "You are fighting " << opp.show_name() << "'s " << opp.pokemon->show_name() << endl;
	/*for (int tot = 0; tot <= num_user_poke; tot++)
	{*/
		while ((user.pokemon->show_health() > 0) && (opp.pokemon->show_health() > 0)) {
			//Display info on pokemon
			cout << "-------------------" << endl;
			cout << user.pokemon[0].show_name() << endl;
			cout << "Level: " << user.pokemon[0].show_level() << endl;
			cout << "Health: " << user.pokemon[0].show_health() << endl;
			cout << "PP: " << user.pokemon[0].show_PP() << endl << endl;
			cout << opp.pokemon[0].show_name() << endl;
			cout << "Level: " << opp.pokemon[0].show_level() << endl;
			cout << "Health: " << opp.pokemon[0].show_health() << endl;
			cout << "PP: " << opp.pokemon[0].show_PP() << endl << endl;
			//Users turn
			cout << "Choose a move\n";
			for (int i = 0; i <= 3; i++) {
				cout << i << " - " << user.pokemon[0].moves[i].get_attack() << endl;
			}
			int move_choice;
			cin >> move_choice;
			if (user.pokemon[0].moves[move_choice].pp > user.pokemon[0].show_PP()) { //if chosen move requires more PP than pokemon has
				cout << "Not enough PP, please choose a different move" << endl;
				for (int i = 1; i <= 4; i++) {
					cout << i << " - " << user.pokemon[0].moves[i].get_attack() << endl;
				}
				int move_choice;
				cin >> move_choice;
			}
			int opponent_choices = opp.pokemon[0].num_moves();
			int opp_choice = rand() % opponent_choices;
			//User Attack
			cout << "Opp damaged by " << user.pokemon[0].moves[move_choice].get_damage() << endl;
			opp.pokemon[0].set_health(user.pokemon[0].moves[move_choice].get_damage());
			user.pokemon[0].set_PP(user.pokemon[0].moves[move_choice].pp);
			//Opp Attack
			cout << "User damaged by " << opp.pokemon[0].moves[opp_choice].get_damage() << endl;
			user.pokemon[0].set_health(opp.pokemon[0].moves[opp_choice].get_damage());
			opp.pokemon[0].set_PP(opp.pokemon[0].moves[opp_choice].pp);
			//Print Moves used and pokemon health and PP
			cout << user.pokemon[0].show_name() << " used " << user.pokemon[0].moves[move_choice].get_attack() << endl;
			cout << opp.pokemon[0].show_name() << " used " << opp.pokemon[0].moves[opp_choice].get_attack() << endl << endl;
		}
//	}
	if (user.pokemon->show_health() <= 0) { //If user's pokemon has fainted
		cout << user.pokemon->show_name() << " has feinted." << endl;
		int feint_count = 0;
		for (int i = 1; i <= 6; i++) {
			if (user.pokemon[i].show_health() <= 0) {
				feint_count++;
			}
		}
		if (feint_count == 6) {
			cout << "You have lost the battle." << endl;
		}
		else {
			cout << "Which pokemon would you like to use?" << endl; //User chooses another pokemon
			user.show_pokemon();
			int poke_choice;
			cin >> poke_choice;
			if (user.pokemon[poke_choice].show_health() <= 0) { //If chosen pokemon has already feinted, user chooses again
				cout << user.pokemon[poke_choice].show_name() << " has feinted. Please choose a different pokemon.";
				user.show_pokemon();
				int poke_choice;
				cin >> poke_choice;
			}
			//Set fighting pokemon as pokemon[poke_choice]
		}
	}
	if (opp.pokemon->show_health() <= 0) {
		int feint_count = 0;
		cout << "The opponent's " << opp.pokemon->show_name() << " has fainted." << endl;
		for (int i = 1; i <= 6; i++) {
			if (opp.pokemon[i].show_health() <= 0) {
				feint_count++;
			}
		}
		if (feint_count == 6) {
			cout << "You won the battle!" << endl;
		}
		else {
			//Set fighting pokemon as next pokemon opp has
		}
	}
	//Add code to fight again with new sets of pokemon
}

void Trainer::wild_battle(Trainer user, Pokemon& opp) {
	srand(time(0));
	cout << "You are fighting wild " << opp.show_name() << endl;
	int num_user_poke = user.num_pokemon(user);
	/*for (int tot = 0; tot<=num_user_poke; tot++)
	{*/
		while ((user.pokemon->show_health() > 0) && (opp.show_health() > 0)) {
			//Display info on pokemon
			cout << "-------------------" << endl;
			cout << user.pokemon[0].show_name() << endl;
			cout << "Level: " << user.pokemon[0].show_level() << endl;
			cout << "Health: " << user.pokemon[0].show_health() << endl;
			cout << "PP: " << user.pokemon[0].show_PP() << endl << endl;
			cout << opp.show_name() << endl;
			cout << "Level: " << opp.show_level() << endl;
			cout << "Health: " << opp.show_health() << endl;
			cout << "PP: " << opp.show_PP() << endl << endl;
			//Users turn
			cout << "Choose a move\n";
			for (int i = 0; i <= 3; i++) {
				cout << i << " - " << user.pokemon[0].moves[i].get_attack() << endl;
			}
			cout << "5 - Catch pokemon\n";
			int move_choice;
			cin >> move_choice;
			if (move_choice != 5 && (user.pokemon[0].moves[move_choice].pp > user.pokemon[0].show_PP())) { //if chosen move requires more PP than pokemon has
				cout << "Not enough PP, please choose a different move" << endl;
				for (int i = 1; i <= 4; i++) {
					cout << i << " - " << user.pokemon[0].moves[i].get_attack() << endl;
				}
				int move_choice;
				cin >> move_choice;
			}
			int opponent_choices = opp.num_moves();
			int opp_choice = rand() % opponent_choices;
			//Catch pokemon
			if (move_choice == 5)
			{
				if (pokeballs > 0) {
					cout << user.show_name() << " threw a pokeball\n" << "...\n" << "...\n" << "...\n";
					int catch_chance = rand() % 2;
					if (catch_chance == 0)
					{
						cout << user.show_name() << " caught the wild " << opp.show_name() << endl;
						catch_pokemon(opp, user);
						throw_pokeball();
						break;
					}
					else if (catch_chance == 1)
					{
						cout << opp.show_name() << " was not caught" << endl;
						throw_pokeball();
					}
				}
				else if (pokeballs <= 0)
				{
					throw_pokeball();
				}
			}
			//Fight wild pokemon
			if (move_choice < 5) {
				cout << "Opp took " << user.pokemon[0].moves[move_choice].get_damage() << " damage" << endl;
				opp.set_health(user.pokemon[0].moves[move_choice].get_damage());
				user.pokemon[0].set_PP(user.pokemon[0].moves[move_choice].pp);
				//Opp Attack
				cout << "User took " << opp.moves[opp_choice].get_damage() << " damage" << endl;
				user.pokemon[0].set_health(opp.moves[opp_choice].get_damage());
				opp.set_PP(opp.moves[opp_choice].pp);
				//Print Moves used and pokemon health and PP
				cout << user.pokemon[0].show_name() << " used " << user.pokemon[0].moves[move_choice].get_attack() << endl;
				cout << opp.show_name() << " used " << opp.moves[opp_choice].get_attack() << endl << endl;
			}
		}
	//}
	if (user.pokemon->show_health() <= 0) { //If user's pokemon has fainted
		cout << user.pokemon->show_name() << " has feinted." << endl;
		int feint_count = 0;
		for (int i = 1; i <= 6; i++) {
			if (user.pokemon[i].show_health() <= 0) {
				feint_count++;
			}
		}
		if (feint_count == 6) {
			cout << "You have lost the battle." << endl;
		}
		else {
			cout << "Which pokemon would you like to use?" << endl; //User chooses another pokemon
			user.show_pokemon();
			int poke_choice;
			cin >> poke_choice;
			if (user.pokemon[poke_choice].show_health() <= 0) { //If chosen pokemon has already feinted, user chooses again
				cout << user.pokemon[poke_choice].show_name() << " has feinted. Please choose a different pokemon.";
				user.show_pokemon();
				int poke_choice;
				cin >> poke_choice;
			}
			//Set fighting pokemon as pokemon[poke_choice]
		}
	}
	if (opp.show_health() <= 0) {
		int feint_count = 0;
		cout << "Wild " << opp.show_name() << " has feinted." << endl;

	}
}

int Trainer::num_pokemon(Trainer user)
{
	int user_poke = 0;
	for (int i = 0; i < 6; i++)
	{
		if (user.pokemon[i].show_name() != "Empty")
		{
			user_poke = user_poke + 1;
		}
	}
	return user_poke;
}