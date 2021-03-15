#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	string linia;
	fstream fp("galerie.txt");
	ofstream out("wynik4_1.txt");
	vector<string> kraje_v, wyswietlone;

	if (fp.is_open()) {
		while(getline(fp, linia)) {
			kraje_v.push_back(linia.substr(0, linia.find(" ", 0)));
		}
	} else cout << "Nie ma pliku";

	for (auto x : kraje_v) {
		if (find(wyswietlone.begin(), wyswietlone.end(), x) != wyswietlone.end()) {
			continue;
		}
		else {
			cout << x << " " << count(kraje_v.begin(), kraje_v.end(), x) << endl;
			
			out << x << " " << count(kraje_v.begin(), kraje_v.end(), x) << endl;
			
			wyswietlone.push_back(x);
		}
	}

	fp.close();
	out.close();

	return 0;
}