#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Program {
    int s;
    int d;
    int p;
    Program(int s, int d, int p):s(s),d(d),p(p){}
} Program;

Program make_program(int s, int d, int p){
    return Program(s,d,p);
}

bool compare(const Program& a, const Program& b){
    return a.s+a.d < b.s+b.d;
}

int solve(int n, vector<Program> programs, int maxTime);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        vector<Program> programs;
        int n;
        cin >> n;
        int temp_n = n;
        int maxTime = -1;
        while(temp_n--){
            int s, d, p;
            cin >> s >> d >> p;
            programs.push_back(make_program(s,d,p));
            if(s+d > maxTime){
                maxTime = s+d;
            }
        }

        int answer = solve(n,programs, maxTime);
        cout << answer << endl;
    }
}

int findLessThan(vector<int> arr, int v){
    if(arr.size() == 0)return -1;
    int left = -1;
    int right = arr.size();
    
    while (left+1 < right) {
        int mid = (left+right) / 2;

        if (arr[mid] <= v) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int solve(int n, vector<Program> programs, int maxTime){
    vector<int> dp(maxTime+1,0);
    vector<int> nonZeroIndexList;
    nonZeroIndexList.reserve(maxTime+1);

    sort(programs.begin(), programs.end(), compare);

    dp[programs[0].s+programs[0].d] = programs[0].p;
    nonZeroIndexList.push_back(programs[0].s+programs[0].d);

    for(int i = 1 ; i < n; i++){
        int nowTime = programs[i].s+programs[i].d;
        int indexBeforeStart = findLessThan(nonZeroIndexList, programs[i].s);
        dp[nowTime] = max(dp[programs[i-1].s+programs[i-1].d], (indexBeforeStart == -1 ? 0 : dp[nonZeroIndexList[indexBeforeStart]])+programs[i].p);
        if(nonZeroIndexList.back() != nowTime)nonZeroIndexList.push_back(nowTime);
    }

    return dp[nonZeroIndexList[findLessThan(nonZeroIndexList, maxTime)]];
}