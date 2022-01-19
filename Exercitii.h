#include"Queue.h"

//functie ce verifica daca un text este corect balantat din pct de vedere al parantezelor : 
// 
//ex: 
//		"(((Ana))sare" - gresit
//		"()sdvs((()))scv" - corect

bool balance(string text) {

	Stack<char>* st = new Stack<char>();


	for (char c : text) {

		if (c == '(') {

			st->push(c);
		}

		if (c == ')' && !st->empty()) {

			if (st->get_top()->get_data() == '(') {

				st->pop();
			}
		}
		else if (c == ')' && st->empty()) {

			return 0;
		}
	}

	cout << endl;
	if (st->empty() == true) {

		return 1;
	}
	return 0;
}

void solve_balance() {

	if (balance("(((Ana))sare") == 1) {

		cout << "e balansat";
	}
	else {

		cout << "nu e balansat";
	}
}



//sortare sir de caractere
void erase_character(string& cuv, char ch) {

	int poz_ch = cuv.find(ch);
	string copie = cuv;
	cuv = cuv.substr(0, poz_ch);
	copie.erase(0, poz_ch + 1);
	cuv = cuv + copie;
}

char biggest_element(string& cuv) {

	char maxi = 'a' - 1;
	int i_maxi = -1;
	for (size_t i{ 0 }; i < cuv.length(); i++) {

		if (cuv[i] > maxi) {

			maxi = cuv[i];
			i_maxi = i;
		}
	}
	
	erase_character(cuv, maxi);
	return maxi;
}

void solve_sortare_cu_stiva() {

	Stack<char>* st = new Stack<char>();
	string cuv;
	cout << "cuv = ";
	getline(cin, cuv);

	while (cuv != "") {

		st->push(biggest_element(cuv));
	}

	while (!st->empty()) {

		cout << st->get_top()->get_data() << " ";
		st->pop();
	}
	

}
