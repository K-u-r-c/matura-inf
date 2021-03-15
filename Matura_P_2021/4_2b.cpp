#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	string nazwa;
	int powierzchnia;
} galeria;

int powierzchnia(string s, int l) {
	int suma = 0, lewa = 0, prawa = 0;

	for (int i = 0; i < l; i++) {
		lewa = stoi(s.substr(0, s.find(" ", 0)));
		s = s.substr(s.find(" ") + 1);
		prawa = stoi(s.substr(0, s.find(" ", 0)));
		s = s.substr(s.find(" ") + 1);

		suma += lewa * prawa;
	}

	return suma;
}

int main(int argc, char** argv) {
	fstream fp("galerie.txt");
	ofstream out("wynik4_2b.txt");
	string linia, pom;
	vector<string> cities;
	vector<galeria> gal_v;

	if (fp.is_open()) {
		while (getline(fp, linia)) {
			pom = linia.substr(linia.find(" ") + 1);

			cities.push_back(pom.substr(0, pom.find(" 0 0", 0)));
		}
	}

	for (auto x : cities) {
		string city_name = x.substr(0, x.find(" ", 0));
		string lokale = x.substr(x.find(" ") + 1);
		int liczba_lokali = count(lokale.begin(), lokale.end(), ' ') / 2 + 1;
		
		galeria g;
		g.nazwa = city_name;
		g.powierzchnia = powierzchnia(lokale, liczba_lokali);

		gal_v.push_back(g);
	}

	string max_n = "", min_n = "";
	int max_p = 0, min_p = 999999;

	for (auto x : gal_v) {
		if (x.powierzchnia > max_p) {
			max_n = x.nazwa;
			max_p = x.powierzchnia;
		}
		else if (x.powierzchnia < min_p) {
			min_n = x.nazwa;
			min_p = x.powierzchnia;
		}
	}

	out << max_n << " " << max_p << endl;
	out << min_n << " " << min_p << endl;

	fp.close();
	out.close();

	return 0;
}