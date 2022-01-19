#include"Exercitii.h"

int main() {

	
	Queue<int>* coada = new Queue<int>();

	coada->push_back(1);
	coada->push_back(4);
	coada->push_back(5);
	coada->push_back(23);
	coada->push_back(43);

	coada->traverse();
}


