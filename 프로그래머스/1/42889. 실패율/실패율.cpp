#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 각 스테이지에 따른 실패율 -> pair(stage number, 실패율)
bool cmp (pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> progress(N+2);
    vector<pair<int, double>> fail;
    for (int i=0; i<stages.size(); i++) {
        progress[stages[i]] += 1;
    }
    //progress(4) [0,4,0,0]
    //progress [0,<1,3,2,1,0>,1]
    //실패율 (5,0), (4, 0.5), (3, 0.5),(2,3/7), (1,1/8)
    int players_num = progress[N+1];
    for (int i=N; i>0; i--) {
        players_num += progress[i];
        if (players_num == 0) fail.push_back(make_pair(i, double(0)));
        else fail.push_back(make_pair(i, double(progress[i]) /double(players_num)));
    }
    
    sort(fail.begin(), fail.end(), cmp);
    
    for (int i=0; i<N; i++) {
        answer.push_back(fail[i].first);
    }
    
    return answer;
}