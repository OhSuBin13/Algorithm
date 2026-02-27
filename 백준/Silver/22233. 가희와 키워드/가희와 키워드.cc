#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string post) {
	string word;
	vector<string> words;
	for (auto& i : post) {
		if (i == ',') {
			words.push_back(word);
			word = "";
		}
		else word.push_back(i);
	}
	if (!word.empty()) words.push_back(word);
	return words;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_set<string> keywords;
	for (int i = 0; i < N; i++) {
		string keyword; 
		cin >> keyword;
		keywords.insert(keyword);
	}

	for (int i = 0; i < M; i++) {
		string post; cin >> post;
		vector<string> words = split(post);
		for (auto& i : words) {
			keywords.erase(i);
		}
		cout << keywords.size() << "\n";
	}
	return 0;
}