#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct compare {
    bool operator()(const pair<int, pii>& a,
        const pair<int, pii>& b) const {
        if (a.first != b.first)
            return a.first > b.first;
        if (a.second.first != b.second.first)
            return a.second.first > b.second.first;
        return a.second.second > b.second.second;
    }
};

int solution(vector<vector<int>> jobs) {
    /*
    * parameter: jobId, requestTime, elapsedTime
    * priority: 1. low elapsedTime 2. fast requestTime 3. low jobId
    * retrun: mean turnaround times (endTime - requestTime)
    */
    int answer = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, compare> waitingQueue; // {elapsedTime, {requestTime, jobId}}
    int jobSize = jobs.size();
    vector<pair<int, pii>> jobList; // {requestTime, {jobId, elapsedTime}}
    for (int i = 0; i < jobSize; i++) {
        int jobId = i;
        int requestTime = jobs[i][0];
        int elapsedTime = jobs[i][1];
        jobList.push_back({ requestTime, {jobId, elapsedTime} });
    }
    sort(jobList.begin(), jobList.end());
    
    int time = 0;
    int completed_jobs = 0;
    int jobIdx = 0;
    while (completed_jobs < jobSize) {
        while (jobIdx < jobSize && jobList[jobIdx].first <= time) {
            int jobId = jobList[0].second.first;
            int requestTime = jobList[jobIdx].first;
            int elapsedTime = jobList[jobIdx].second.second;
            waitingQueue.push({ elapsedTime,{requestTime, jobId} });
            jobIdx++;
            //cout << "request: " << requestTime << " elapsed: " << elapsedTime << " jobId: " << jobId << "\n";
        }
        if (!waitingQueue.empty()) {
            pair<int, pii> job = waitingQueue.top();
            waitingQueue.pop();
            int jobId = job.second.second;
            int requestTime = job.second.first;
            int elapsedTime = job.first;
            time += elapsedTime;
            answer += time - requestTime;
            completed_jobs++;
            //cout << "waiting " << "request: " << requestTime << " elapsed: " << elapsedTime << " jobId: " << jobId << "\n";
            //cout << "answer: " << answer << "\n";
        }
        else {
            if (jobIdx < jobSize) {
                time = jobList[jobIdx].first;
            }
        }
    }
    return answer / jobSize;
}