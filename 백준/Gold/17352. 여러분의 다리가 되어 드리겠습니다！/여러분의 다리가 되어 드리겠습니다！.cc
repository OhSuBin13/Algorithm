#include <iostream>
#define MAX 300001
using namespace std;

int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionParent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	parent[y] = x;
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N-2; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	int first = find(1);
	int second= 0;
	for (int i = 2; i <= N; i++) {
		if (find(i) != first) {
			second = i;
			break;
		}
	}
	cout << first << " " << second;
	return 0;
}
