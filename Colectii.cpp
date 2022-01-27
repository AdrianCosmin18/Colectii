#include"Exercitii.h"

int main() {

	
	SimpleHashTable<string, string>* sht = new SimpleHashTable<string, string>();

	sht->put("Cosmin", "BMW");
	sht->put("Andrei", "Mercedes");
	sht->put("Laur", "Logan");
	sht->put("Marcel", "Seat");
	sht->put("Mihai", "Mazda");
	sht->put("Adriana", "Cazan");

	cout << sht->findPosition("Laur");



}


