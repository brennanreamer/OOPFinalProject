#include "Caterpie.h"
#include <string>
using std::string;
Caterpie::Caterpie(int level) : Pokemon("Caterpie", "Bug", level) {
	moves[0] = Attack("Stun Spore", 20, 15, 90);
	moves[1] = Attack("Tail Whip", 10, 5, 95);
}
Caterpie::Caterpie(string in_name, int level) : Pokemon(in_name, "Bug", level) {
}