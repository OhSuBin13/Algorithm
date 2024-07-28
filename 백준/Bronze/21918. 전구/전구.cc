#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 31
using namespace std;

int N, M;
vector<int> light;

void Input() {
	cin >> N >> M;
	light.resize(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> light[i];
	}

}

void Order(int a, int b, int c) {
	switch (a)
	{
	case 1:
		light[b] = c;
		break;
	case 2:
		for (int i = b; i <= c; i++) {
			light[i] = (light[i] + 1) % 2;
		}
		break;
	case 3:
		for (int i = b; i <= c; i++) {
			light[i] = 0;
		}
		break;
	case 4:
		for (int i = b; i <= c; i++) {
			light[i] = 1;
		}
		break;
	default:
		break;
	}
}

void Solve() {
	int a, b, c;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		Order(a, b, c);
	}

	for (int i = 1; i <= N; i++) {
		cout << light[i] << " ";
	}
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}