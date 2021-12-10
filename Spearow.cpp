#include "Spearow.h"
#include <string>
using std::string;
Spearow::Spearow(int level) : Pokemon("Spearow", "Flying", level) {
	moves[0] = Attack("Gust", 20, 15, 90);
	moves[1] = Attack("Fly", 60, 40, 85);
}
Spearow::Spearow(string in_name, int level) : Pokemon(in_name, "Flying", level) {
	moves[0] = Attack("Gust", 20, 15, 90);
	moves[1] = Attack("Fly", 60, 40, 85);
}