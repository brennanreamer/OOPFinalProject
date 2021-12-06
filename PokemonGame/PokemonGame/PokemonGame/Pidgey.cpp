#include "Pidgey.h"
#include <string>
using std::string;
Pidgey::Pidgey(int level) : Pokemon("Pidgey", "Flying", level) {
	moves[0] = Attack("Slash", 30, 20, 80);
	moves[1] = Attack("Fly", 60, 40, 85);
}
Pidgey::Pidgey(string in_name, int level) : Pokemon(in_name, "Flying", level) {
}