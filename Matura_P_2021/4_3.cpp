#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	string nazwa;
	int wartosc;
} unikalne;

vector<int> lokale_f(string s, int l) {
	int lewa = 0, prawa = 0;
	vector<int> tab;

	for (int i = 0; i < l; i++) {
		lewa = stoi(s.substr(0, s.find(" ", 0)));
		s = s.substr(s.find(" ") + 1);
		prawa = stoi(s.substr(0, s.find(" ", 0)));
		s = s.substr(s.find(" ") + 1);

		tab.push_back(lewa * prawa);
	}

	return tab;
}

int main(int argc, char** argv) {
	fstream fp("galerie.txt");
	ofstream out("wynik4_3.txt");
	string linia, pom;
	vector<string> cities;
	vector<unikalne> unik_v;

	if (fp.is_open()) {
		while (getline(fp, linia)) {
			pom = linia.substr(linia.find(" ") + 1);

			cities.push_back(pom.substr(0, pom.find(" 0 0", 0)));
		}
	}

	for (auto x : cities) {
		vector<int> tab;
		string city_name = x.substr(0, x.find(" ", 0));
		string lokale = x.substr(x.find(" ") + 1);
		int liczba_lokali = count(lokale.begin(), lokale.end(), ' ') / 2 + 1;

		unikalne u;

		tab = lokale_f(lokale, liczba_lokali);

		u.nazwa = city_name;

		sort(tab.begin(), tab.end());

		u.wartosc = unique(tab.begin(), tab.end()) - tab.begin();

		unik_v.push_back(u);
	}

	string max_n, min_n;
	int max_w = 0, min_w = 99999;

	for (auto x : unik_v) {
		if (x.wartosc > max_w) {
			max_w = x.wartosc;
			max_n = x.nazwa;
		}
		else if (x.wartosc < min_w) { 
			min_w = x.wartosc; 
			min_n = x.nazwa;
		}
	}

	out << max_n << " " << max_w << endl;
	out << min_n << " " << min_w << endl;

	fp.close();
	out.close();

	return 0;
}