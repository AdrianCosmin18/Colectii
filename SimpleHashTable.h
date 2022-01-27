#include"Stored.h"

template<typename K, typename V>
class SimpleHashTable
{

private:
	Stored<K, V>** hashTable;


public:

	SimpleHashTable() {
		hashTable = new Stored<K, V>*[10];
	}


	int hashKey(K key) {

		return 	key.length() % 10;
	}
			
	void put(K key, V value) {

		 int index = hashKey(key);


		 if (occupied(index)) {

			 int stopIndex = index;

			 if (index == 9) {
				 index = 0;
			 }
			 else {
				 index++;
			 }

			 while (occupied(index) == true && index != stopIndex) {

				 index = (+index + 1) % 10;
			 }
		 }
		

		 if (occupied(index)) {

			 cout << "Nu avem locuri" << endl;
		 }
		 else {
			 hashTable[index] = new Stored<K, V>();
			 hashTable[index]->key = key;
			 hashTable[index]->value = value;
		 }
	 }

	int findPosition(K key) {

		
		int index = hashKey(key) + 1;
		

		if (hashTable[index] != NULL && hashTable[index]->key == key) {

			cout << "\nNu intra aici";

			return index;
		}



		int stopIndex = index;

		if (index == 9) {
			index = 0;
		}
		else {
			index++;
		}


		while (index != stopIndex && hashTable[index] != NULL && !(hashTable[index]->key == key)) {

			cout << "\nintra in while";
			index = (index + 1) % 10;;//alta regula
		}

		//if (hashTable[index] != NULL && hashTable[index]->key == key) {

		//	return index;
		//}
		return -1;
	}

	bool occupied(int position) {

		 return hashTable[position] == NULL;
	 }








};

