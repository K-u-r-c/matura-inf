#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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
	ofstream out("wynik4_2a.txt");
	string linia, pom;
	vector<string> cities;

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

		out << city_name << " ";
		out << powierzchnia(lokale, liczba_lokali) << " ";
		out << liczba_lokali << endl;
	}

	fp.close();
	out.close();

	return 0;
}