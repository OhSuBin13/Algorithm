#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct compare {
	bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
		if (a.first != b.first) return a.first < b.first;
		else if (a.second.size() != b.second.size()) return a.second.size() < b.second.size();
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
	unordered_map<string, int> m;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		m[word]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		int count = i->second;
		string word = i->first;
		if (word.size() < M) continue;
		pq.push(make_pair(count, word));	
	}
	while (!pq.empty()) {
		cout << pq.top().second << "\n";
		pq.pop();
	}
	return 0;
}