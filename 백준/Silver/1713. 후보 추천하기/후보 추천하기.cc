#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;

struct Candidate
{
	int candidateNum = 0;
	int time = 0;
	int voteNum = 0;
};

int N;
int vote;
queue<int> totalVote;
vector<Candidate>v;
vector<int> sortV;



void Input() {
	cin >> N;
	cin >> vote;

	for(int i = 0; i < vote; i++){
		int num;
		cin >> num;
		totalVote.push(num);
	}
}

bool isEmpty() {
	return (v.size() != N);
}

void postCandidate() {
	while (!totalVote.empty()) {
		int number = totalVote.front();
		totalVote.pop();

		bool flag = false;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].candidateNum == number) {
				v[i].voteNum++;
				flag = true;
				break;
			}
		}

		if (flag == false) {
			Candidate newCandidate;
			newCandidate.candidateNum = number;
			newCandidate.voteNum = 1;

			if (isEmpty()) {
				v.push_back(newCandidate);
			}
			else {
				int minVote = 10000;
				int num = 0;
				int maxTime = 0;
				int pos = 0;

				for (int i = 0; i < v.size(); i++) {
					if (v[i].voteNum < minVote) {
						minVote = v[i].voteNum;
						pos = i;
					}
				}

				for (int i = 0; i < v.size(); i++) {
					if (v[i].voteNum == minVote) {
						num++;
					}
				}

				if(num == 1) v[pos] = newCandidate;
				else {
					for (int i = 0; i < v.size(); i++) {
						if (v[i].voteNum == minVote && v[i].time > maxTime) {
							maxTime = v[i].time;
							pos = i;
						}
					}
					v[pos] = newCandidate;
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			v[i].time++;
		}
	}
}

void FindCandidate() {
	for (int i = 0; i < v.size(); i++) {
		sortV.push_back(v[i].candidateNum);
	}
	
	sort(sortV.begin(), sortV.end());

	sortV.erase(unique(sortV.begin(), sortV.end()), sortV.end());
}

void Solve() {
	postCandidate();
	FindCandidate();
	for (int i = 0; i < sortV.size(); i++) {
		cout << sortV[i] << " ";
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