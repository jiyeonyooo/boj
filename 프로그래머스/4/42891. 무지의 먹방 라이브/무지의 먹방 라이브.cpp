#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; //pair의 second를 기준으로 오름차순 
}
 
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int food_nums = food_times.size(); //음식의 개수
    int pre_min = 0; //이전단계의 min_times 값
    vector<pair<int, int>> foods;
    for (int i=0; i<food_nums; i++) {
        foods.push_back(make_pair(food_times[i],i+1)); //first: 먹는데 소요되는 시간, second: 음식의 번호
    }
    sort(foods.begin(), foods.end()); //먹는 시간을 기준으로 오름차순 정리
    
    for (vector<pair<int, int>>::iterator it=foods.begin(); it != foods.end(); ++it,--food_nums) {
        long long spend_times = (long long)(it->first - pre_min) * food_nums;
        if (spend_times == 0) continue;
        if (spend_times <= k) {
            k -= spend_times;
            pre_min = it->first;
        } else {
            k = k % food_nums;
            sort(it, foods.end(), cmp);
            return (it+k)->second;
        }
    }
    return -1;
}