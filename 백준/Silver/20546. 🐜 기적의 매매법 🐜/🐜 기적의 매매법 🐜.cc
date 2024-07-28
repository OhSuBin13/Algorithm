#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 11
using namespace std;

pair<int, int> junhyun; // SeedMoney, Item
pair<int, int> sungmin; // SeedMoney, Item
int price[14];

void Input() {
	int seedMoney;
	cin >> seedMoney;

	junhyun = make_pair(seedMoney, 0);
	sungmin = make_pair(seedMoney, 0);

	for (int i = 0; i < 14; i++) {
		cin >> price[i];
	}
}

void BNP(int money, int price) {
	int item = money / price;
	int seedMoney = junhyun.first;
	int newItem = junhyun.second;

	seedMoney -= item * price;
	newItem += item;
	junhyun = make_pair(seedMoney, newItem);
}

//보유액, 주식 가격, 연속 일 수
void TIMING(int money, int price, int seriesDay) {
	if (seriesDay >= 3 && sungmin.second != 0) {
		int seedMoney = sungmin.first;
		int newItem = sungmin.second;

		seedMoney += newItem * price;
		newItem = 0;
		sungmin = make_pair(seedMoney, newItem);
	}
	else if (seriesDay <= -3) {
		int item = money / price;
		int seedMoney = sungmin.first;
		int newItem = sungmin.second;

		seedMoney -= item * price;
		newItem += item;
		sungmin = make_pair(seedMoney, newItem);
	}
	
	else return;
}

void Solve() {
	int seriesDay = 0;

	for (int i = 0; i < 14; i++) {
		if (i != 0 && price[i] > price[i - 1]) {
			if (seriesDay >= 0) {
				seriesDay++;
			}
			else {
				seriesDay = 1;
			}
		}
		else if (i != 0 && price[i] < price[i - 1]) {
			if (seriesDay <= 0) {
				seriesDay--;
			}
			else {
				seriesDay = -1;
			}
		}
		else if (i != 0 && price[i] == price[i - 1]) {
			seriesDay = 0;
		}
		BNP(junhyun.first, price[i]);
		TIMING(sungmin.first, price[i], seriesDay);
	}
	if (junhyun.first + junhyun.second * price[13] > sungmin.first + sungmin.second * price[13]) {
		cout << "BNP";
	}
	else if(junhyun.first + junhyun.second * price[13] < sungmin.first + sungmin.second * price[13]){
		cout << "TIMING";
	}
	else {
		cout << "SAMESAME";
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