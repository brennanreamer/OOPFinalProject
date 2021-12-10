#include "Bulbasaur.h"
#include <string>
using std::string;
Bulbasaur::Bulbasaur(int level) : Pokemon("Bulbasaur", "Grass", level) {
	moves[0] = Attack("Tackle", 30, 25, 100);
	moves[1] = Attack("Vine Whip", 55, 45, 55);
}
Bulbasaur::Bulbasaur(string in_name, int level) : Pokemon(in_name, "Grass", level) {
	moves[0] = Attack("Tackle", 30, 25, 100);
	moves[1] = Attack("Vine Whip", 55, 45, 55);
}
