#include <iostream>
#include "Animal.h"`
#include <string>

using namespace std;
using namespace ZooSpace;

int main() {
	string name;

	Bird parrot("Carol");
	printinfo(parrot);
	
	Fish goldfish("Govard", "Pacific Ocean", "Food for Fish");
	printinfo(goldfish);

	Mammal dog("River");
	printinfo(dog);
	
	Reptile lizard("Sheldon", "Pasadena");
	printinfo(lizard);

	Centaur centaur("Araghorn, son Arathorna", "New York", "Pizza with pineapples");
	printinfo(centaur);


	Aqua aqua("Ocean");
	aqua.water();
	aqua.living(goldfish);
	Air air("Freedom");
	air.place();
	air.living(parrot);
	Field field("Pole");
	field.grow();
	field.living(centaur);
	return 0;
}