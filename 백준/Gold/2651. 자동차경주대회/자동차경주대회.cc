#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int maxDistance;
int N;
vector<int> distances;
vector<int> times;

vector<int> memo;

vector<int> answers;
int answer;

void solve(){
    memo.assign(N+1 ,-1);

    queue<pair<int, int> > q;//현재 위치, 정비소요시간

    q.push(make_pair(-1,0));

    while(!q.empty()){
        int location = q.front().first;
        int usedTime = q.front().second;
        q.pop();
        if(location >= 0 && memo[location] != -1 && usedTime > memo[location]){
            continue;
        }

        int nowDistance = 0;
        for(int i = location +1; i < N+1; i++){
            nowDistance += distances[i];
            if(nowDistance > maxDistance){
                break;
            }
            if(memo[i] != -1 && memo[i] <= usedTime + times[i]){
                continue;
            }
            memo[i] = usedTime + times[i];
            q.push(make_pair(i, memo[i]));
        }
    }

    answer = memo[N];
    answers.push_back(N);
    for(int i = N -1; i >= 0; i--){
        if(memo[i] + times[answers.back()] == memo[answers.back()]){
            answers.push_back(i);
        }
    }

    reverse(answers.begin(), answers.end());
    answers.pop_back();
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> maxDistance >> N;
    distances.assign(N+1, 0);
    times.assign(N+1, 0);
    for(int i = 0; i < N+1; i++){
        cin >> distances[i];
    }
    for(int i = 0; i < N; i++){
        cin >> times[i];
    }
    
    solve();

    cout << answer << '\n';
    cout << answers.size() << '\n';
    for(int i = 0; i < answers.size(); i++){
        cout << (answers[i] + 1) << ' ';
    }
}