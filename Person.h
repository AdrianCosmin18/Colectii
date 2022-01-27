#include"Car.h"

class Person
{
private:
	int id;
	string nume;
	string gen;
	double h;

public:

	int get_id() { return id; }
	string get_nume() { return nume; }
	string get_gen() { return gen; }
	double get_h() { return h; }

	void set_id(int i) { id = i; }
	void set_nume(string n) { nume = n; }
	void set_gen(string g) { gen = g; }
	void set_h(double h) { this->h = h; }


	Person() :id{-1}, nume { "anonim" }, gen{ "M" }, h{ 1.8 }{}

	Person(int i, string n, string g, double inaltime) : id{ i }, nume { n }, gen{ g }, h{ inaltime }{}

	Person(string prp) {

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
		nume = v[1];
		gen = v[2];
		h = stod(v[3]);
	}

	bool operator< (Person p) {

		return (this->h < p.h);
	}

	bool operator== (Person p) {

		return (this->id == p.id && this->nume == p.nume);
	}

	friend ostream& operator<<(ostream& os, const Person& p) {

		string text = "";
		text = "\nID : " + to_string(p.id);
		text += "\nNume : " + p.nume;
		text += "\nGen : " + p.gen;
		text += "\nInaltime : " + to_string(p.h);
		text += "\n";

		os << text;

		return os;
	}

	string describe_to_file() {

		string text = to_string(id) + "," + nume + "," + gen + "," + to_string(h);
		return text;
	}
};

