#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<string> wait;
	string name;
	int N;
	int divisor;
	char type;
	cin >> N >> type;
	if (type == 'Y') divisor = 1;
	else if (type == 'F') divisor = 2;
	else divisor = 3;
	for (int i = 0; i < N; i++) {
		cin >> name;
		wait.insert(name);
	}
	cout << wait.size() / divisor;
	return 0;
}