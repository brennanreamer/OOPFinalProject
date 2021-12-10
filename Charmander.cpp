#include "Charmander.h"
#include <string>
using std::string;
Charmander::Charmander(int level) : Pokemon("Charmander", "Fire", level) {
	moves[0] = Attack("Scratch", 40, 35, 100);
	moves[1] = Attack("Flamethrower", 60, 30, 45);
}
Charmander::Charmander(string in_name, int level) : Pokemon(in_name, "Fire", level)  {
	moves[0] = Attack("Scratch", 40, 35, 100);
	moves[1] = Attack("Flamethrower", 60, 30, 45);
}
