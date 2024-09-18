#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T, N;
int nodeA, nodeB;
int commonParent;
map<int, int> mappingParent;
vector<int> nodeA_parent;
vector<int> nodeB_parent;

void Input() {
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;

		mappingParent[b] = a;
	}

	cin >> nodeA >> nodeB;
}

void TwoPointer() {
	int aPoint = nodeA_parent.size() - 1;
	int bPoint = nodeB_parent.size() - 1;

	while (aPoint >= 0 && bPoint >= 0) {
		if (nodeA_parent[aPoint] == nodeB_parent[bPoint]) {
			commonParent = nodeA_parent[aPoint];
			aPoint--;
			bPoint--;
		}
		else {
			break;
		}
	}

	cout << commonParent << "\n";
}

void Solve() {
	int node = nodeA;

	nodeA_parent.push_back(node);
	while (mappingParent[node] != 0) {
		int parent = mappingParent[node];
		nodeA_parent.push_back(parent);
		node = parent;
	}

	node = nodeB;

	nodeB_parent.push_back(node);
	while (mappingParent[node] != 0) {
		int parent = mappingParent[node];
		nodeB_parent.push_back(parent);
		node = parent;
	}

	TwoPointer();
}

void Clear() {
	for (int i = 0; i < mappingParent.size(); i++) {
		mappingParent[i] = 0;
	}

	nodeA_parent.erase(nodeA_parent.begin(), nodeA_parent.end());
	nodeB_parent.erase(nodeB_parent.begin(), nodeB_parent.end());

	commonParent = 0;
}

void Solution() {
	cin >> T;
	
	while (T--) {
		Input();
		Solve();
		Clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}