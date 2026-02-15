#include <iostream>
#include <set>
#include <map>
using namespace std;


int main() {
	map<char, int> game; // type, people
	game['Y'] = 2, game['F'] = 3, game['O'] = 4;
	set<string> wait;
	string name;
	int N;
	char type;
	cin >> N >> type;
	for (int i = 0; i < N; i++) {
		cin >> name;
		wait.insert(name);
	}
	cout << wait.size() / (game[type] - 1);
	return 0;
}