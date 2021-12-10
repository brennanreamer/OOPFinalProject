#include "Squirtle.h"
#include <string>
using std::string;
Squirtle::Squirtle(int level) : Pokemon("Squirtle", "Water", level) {
	moves[0] = Attack("Tackle", 30, 25, 100);
	moves[1] = Attack("Bubble", 50, 50, 60);
}
Squirtle::Squirtle(string in_name, int level) : Pokemon(in_name, "Water", level) {
	moves[0] = Attack("Tackle", 30, 25, 100);
	moves[1] = Attack("Bubble", 50, 50, 60);
}