#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long int ll;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while(pq.size() >= 2 && pq.top() < K) {
        ll lowScov = pq.top();
        pq.pop();
        ll secondScov = pq.top();
        pq.pop();
        ll newScov = lowScov + 2 * secondScov;
        pq.push(newScov);
        answer++;
    }
    if (pq.top() < K) return -1;
    return answer;
}