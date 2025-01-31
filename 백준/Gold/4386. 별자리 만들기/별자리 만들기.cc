#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321
using namespace std;

int n;
vector<pair<double, double>> v;
vector<bool> visited;
double res = 0;

void Input() {
	cin >> n;
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
}

void Solution() {
	visited[0] = true;
	int cnt = 1;

	while (cnt != n) {
		double minDistance = MAX;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) continue;
			double x2 = v[i].first;
			double y2 = v[i].second;
			for (int j = 0; j < n; j++) {
				if (visited[j] == true) continue;

				double x1 = v[j].first;
				double y1 = v[j].second;
				double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

				if (minDistance > dist) {
					pos = j;
					minDistance = dist;
				} 
			}
		}
		res += minDistance;
		visited[pos] = true;
		cnt++;
	}
	cout << res;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	cout << fixed;
	cout.precision(2);
	Solve();
	return 0;
}