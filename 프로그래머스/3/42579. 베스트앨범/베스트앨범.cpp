#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}
bool comp2(pair<int,int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m; // genre, play
    map<string, vector<pair<int, int>>> list; // genre, play, id
    vector<pair<int, string>> v; // play, genre
    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        int play = plays[i];
        m[genre] += play;
        list[genre].push_back(make_pair(play, i));
    }
    
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(make_pair(iter->second, iter->first));
        sort(list[iter->first].begin(), list[iter->first].end(), comp2);
    }
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        string genre = v[i].second;
        int k = 0;
        for (auto iter = list[genre].begin(); iter != list[genre].end(); iter++) {
            if (k == 2) break;
            answer.push_back(iter->second);
            k++;
        }
    }

    return answer;
}