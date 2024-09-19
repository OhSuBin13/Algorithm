#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
vector<int> node;
map<int, int> parent;
map<int, int> son;
int ans = 0;

void Input() {
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		node.push_back(a);
	}
}

void Clear() {
	ans = 0;
	parent.erase(parent.begin(), parent.end());
	node.erase(node.begin(), node.end());
	son.erase(son.begin(), son.end());
}

void MakeTree() {
	parent[node[0]] = 0;
	int par = node[0];
	int index = 0;

	for (int i = 1; i < n; i++) {
		if (node[i] - 1 == node[i - 1]) {
			parent[node[i]] = par;
			son[par]++;
		}
		else {
			for (int j = index; j < node.size(); j++) {
				if (son[node[j]] == 0) {
					par = node[j];
					son[node[j]]++;
					index = j;
					break;
				}
			}
			parent[node[i]] = par;
		}
	}
}

void FindCousion() {
	int findPar = parent[k];
	if (findPar == 0) return;
	if (parent[findPar] == 0) return;

	for (int i = 0; i < node.size(); i++) {
		if (node[i] == k) continue;

		int par = parent[node[i]];

		if (par != 0 && par != findPar && parent[par] == parent[findPar]) ans++;
	}
}

void Solve() {
	MakeTree();
	FindCousion();
	cout << ans << "\n";

}

void Solution() {
	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;

		Clear();
		Input();
		Solve();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}