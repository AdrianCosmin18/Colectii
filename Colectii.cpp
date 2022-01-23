#include"Exercitii.h"

int main() {

	
	Set<Person*>* set = new Set<Person*>();

	set->add(new Person(0,"Cosmin", "M", 14));
	set->add(new Person(1,"Mihai", "M", 21));
	set->add(new Person(2,"George", "M", 19));
	set->add(new Person(4,"Laura", "F", 17));

	set->remove(new Person("0,Cosmin,M,14"));
	set->traverse();
}


