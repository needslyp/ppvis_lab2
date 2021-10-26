#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zoo;


class Animal {
private:
	string name_;
	string area_;
	string food_;
public:

	Animal():name_("no info"), area_("no info"), food_("no info"){}
	Animal(string name):name_(name) {}
	Animal(string name, string area): name_(name), area_(area) {}
	Animal(string name, string area, string food) :name_(name), area_(area), food_(food) {}

	virtual void move() {
		cout << this->name_ << " can move by everything\n";
	}

	void set_name(string name){
		this->name_ = name;
	}
	string get_name() {
		return name_;
	}
	void set_area(string area) {
		this->area_ = area;
	}
	string get_area() {
		return area_;
	}
	void set_food(string food) {
		this->food_ = food;
	}
	string get_food() {
		return food_;
	}

	virtual string get_animal_type() = 0;
	virtual void display() = 0;

	friend class Zoo;
};

class Bird : public Animal {
public:
	Bird():Animal() {}
	Bird(string name) :Animal(name) {}
	Bird(string name, string area) : Animal(name, area) {}
	Bird(string name, string area, string food) : Animal(name, area, food) {}

	void move() override {
		cout << this->get_name() << " can move by land and air\n";
	}
	void fly() {
		cout << this->get_name() << " is flying\n";
	}

	string get_animal_type() override {
		return "Bird";
	}

	void display() override {
		move();
		fly();
	}
};	 

class Mammal : public Animal {
public:
	Mammal():Animal() {	}
	Mammal(string name):Animal(name) {}
	Mammal(string name, string area) : Animal(name, area) {}
	Mammal(string name, string area, string food) : Animal(name, area, food) {}

	void move() override {
		cout << this->get_name() << " can move by land and water\n";
	}

	void swim() {
		cout << this->get_name() << " is swimming\n";
	}
	
	string get_animal_type() override {
		return "Mammal";
	}

	void display() override {
		move();
		swim();
	}

};

class Reptile : public Animal{
public:
	Reptile():Animal() {}
	Reptile(string name):Animal(name) {}
	Reptile(string name, string area) : Animal(name, area) {}
	Reptile(string name, string area, string food) : Animal(name, area, food) {}

	void set_name(string name) {
		Animal::set_name(name);
	}
	string get_name() {
		return Animal::get_name();
	}
	void set_area(string area) {
		Animal::set_area(area);
	}
	string get_area() {
		return Animal::get_area();
	}
	void set_food(string food) {
		Animal::set_food(food);
	}
	string get_food() {
		return Animal::get_food();
	}

	void move() override{
		cout << this->get_name() << " can crawl all the day, all the night\n";
	}

	void small_dinosaur() {
		cout << this->get_animal_type() << " used to be big DINOSAURRRRRRRR\n";
	}
	string get_animal_type() override {
		return "Reptile";
	}
	void display() override {
		move();
		small_dinosaur();
	}

};

class Horse : virtual public Mammal {
public:
	Horse() :Mammal() {	}
	Horse(string name) :Mammal(name) {	}
	Horse(string name, string area) : Mammal(name, area) {}
	Horse(string name, string area, string food) : Mammal(name, area, food) {}

	void long_hair() {
		cout << this->get_name() << " has long hair and tail\n";
	}
	void move() override {
		cout << this->get_name() << " gallops at incredible speed, overcoming obstacles\n";
	}
	string get_animal_type() override {
		return "Horse";
	}

	void display() {
		move();
		long_hair();
	}
};

class Human: virtual public Mammal{
public:
	Human():Mammal() {}
	Human(string name):Mammal(name) {}
	Human(string name, string area) : Mammal(name, area) {}
	Human(string name, string area, string food) : Mammal(name, area, food) {}

	void communicate() {
		cout << this->get_name() << " can communicate with other people and animals\n";
	}
	void move() override {
		cout << this->get_name() << " can move using public transport\n";
	}
	string get_animal_type() override {
		return "Human";
	}
	void display() override {
		move();
		communicate();
	}
};

class Centaur : public Human, public Horse {
public:
	Centaur() {}
	Centaur(string name) :Horse(name), Human(name), Mammal(name) {}
	Centaur(string name, string area) : Mammal(name, area) {}
	Centaur(string name, string area, string food) : Mammal(name, area, food) {}
	void driver() {
		cout << Animal::get_name() << " can work in a taxi company as a driver with a personal transport\n";
	}

	string get_animal_type() override {
		return "Centaur";
	}
	void move() override {
		Horse::move();
	}

	void display() {
		move();
		long_hair();
		communicate();
		driver();
	}
};

class Fish : public Animal {
public:
	Fish() :Animal() {}
	Fish(string name) :Animal(name) {}
	Fish(string name, string area) : Animal(name, area) {}
	Fish(string name, string area, string food) : Animal(name, area, food) {}

	void memory() {
		cout << this->get_name() << " hasn't good memory\n";
	}

	string get_animal_type() override {
		return "Fish";
	}

	void display() {
		move();
		memory();
	}
};

namespace ZooSpace {
	void printinfo(Animal& animal) {
	cout << "\t----- Animal -----" << endl;
	cout << "Animal's name: " << animal.get_name() << endl;
	cout << "Animal's type: " << animal.get_animal_type() << endl;
	cout << "Some facts about animal: \n";
	cout << "Habitat: " << animal.get_area() << "\nFeeding: " << animal.get_food() << endl;
	animal.display();
	cout << endl;
	}
}

class Zoo {
private:
	string name_shelter_;
public:
	Zoo() :name_shelter_("no info") {}
	Zoo(string name) : name_shelter_(name) {}

	void living(Animal &animal) {
		cout << animal.get_name() << " can leave in " << this->get_shelter() << endl;
	}
	void set_shelter(string shelter) {
		name_shelter_ = shelter;
	}
	string get_shelter() {
		return name_shelter_;
	}
	virtual string shelter_type() = 0;
};

class Aqua : private Zoo {
public:
	Aqua() :Zoo() {}
	Aqua(string shelter) :Zoo(shelter) {}
	void water() {
		cout << this->shelter_type() << " \""<< this->get_shelter() << "\" has a lot of water\n";
	}

	void living(Animal& animal) {
		Zoo::living(animal);
	}
	string get_shelter() {
		return Zoo::get_shelter();
	}
	string set_shelter(string shelter) {
		Zoo::set_shelter(shelter);
	}
	string shelter_type() {
		return "Aqua";
	}
};

class Field : protected Zoo {
public:
	Field() :Zoo() {}
	Field(string shelter) :Zoo(shelter) {}
	void grow() {
		cout << this->shelter_type() << " \"" << this->get_shelter() << "\" has a lot of grass and flowers\n";
	}
	void living(Animal& animal) {
		Zoo::living(animal);
	}
	string shelter_type() {
		return "Field";
	}
};

class Air : public Zoo {
public:
	Air() :Zoo() {}
	Air(string shelter) :Zoo(shelter) {}
	void place() {
		cout << this->shelter_type() << " \"" << this->get_shelter() << "\" has a lot of FREEEEEEDOM\n";
	}

	string shelter_type() {
		return "Air";
	}
};
