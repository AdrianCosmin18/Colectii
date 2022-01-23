#include<iostream>
#include<string>
using namespace std;


class Car
{
private:
	int id;
	string marca;
	string model;
	int an;

public:

	int get_id() { return id; }
	string get_marca() { return marca; }
	string get_model() { return model; }
	int get_an() { return an; }

	void set_id(int i) { id = i; }
	void set_marca(string m) { marca = m; }
	void set_model(string m) { model = m; }
	void set_an(int a) { an = a; }

	Car() :id{ -1 }, marca { "anonima" }, model{ "anonim" }, an{ 0 }{}

	Car(int i, string marc, string mod, int a) :id{ i }, marca { marc }, model{ mod }, an{ a }{}

	Car(string prp) {

		string v[4];
		int poz = prp.find(',');
		int k = -1;
		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}
		v[3] = prp;

		id = stoi(v[0]);
		marca = v[1];
		model = v[2];
		an = stoi(v[3]);
	}


	virtual string describe() {

		string text = "";
		text += "\nID : " + to_string(id);
		text += "\nMarca : " + marca;
		text += "\nModel : " + model;
		text += "\nAn : " + to_string(an);
		text += "\n";

		return text;
	}

	//suprascriem operatorii de comparare
	bool operator< (Car c1) {

		return (this->an < c1.an);
	}

	bool operator== (Car c1) {

		return (this->id == c1.id && this->marca == c1.marca && this->model == c1.model);
	}//equals

	friend ostream& operator<<(ostream& os, const Car& c) {


		string text = "";
		text += "\nID : " + to_string(c.id);
		text += "\nMarca : " + c.marca;
		text += "\nModel : " + c.model;
		text += "\nAn : " + to_string(c.an);
		text += "\n";

		os << text;

		return os;
	}

	string describe_to_file() {

		string text = to_string(id) + "," + marca + "," + model + "," + to_string(an);
		return text;
	}
};

