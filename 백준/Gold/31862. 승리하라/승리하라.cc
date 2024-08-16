#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int N, M, K;

vector<int> winCount;
vector<pair<int, int> > plays;

int solve(int index, int maxIndex){
    if(index >= plays.size()){
        return winCount[K] > winCount[maxIndex] ? 1 : 0;
    }
    int count = 0;

    int team1 = plays[index].first;
    int team2 = plays[index].second;
    int playCount = 1;
    for(int i = 0; i <= playCount; i++){
        winCount[team1] += playCount - i;
        winCount[team2] += i;
        int newMaxIndex = maxIndex;
        if(winCount[team1] > winCount[newMaxIndex] && team1 != K){
            newMaxIndex = team1;
        }else if(winCount[team2] > winCount[newMaxIndex] && team2 != K){
            newMaxIndex = team2;
        }
        
        count += solve(index+1, newMaxIndex);
        winCount[team1] -= playCount - i;
        winCount[team2] -= i;
    }

    return count;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    winCount.assign(N+1,0);

    int maxIndex = 0;
    for(int i = 0; i < M; i++){
        int team1, team2, playResult;

        cin >> team1 >> team2 >> playResult;

        if(playResult == 1){
            winCount[team1]++;
            if(winCount[team1] > winCount[maxIndex] && team1 != K){
                maxIndex = team1;
            }
        } else if(playResult == 2){
            winCount[team2]++;
            if(winCount[team2] > winCount[maxIndex] && team2 != K){
                maxIndex = team2;
            }
        } else {
            if(team1 > team2){
                int temp = team1;
                team1 = team2;
                team2 = temp;
            }
            plays.push_back(make_pair(team1, team2));
        }
    }

    cout << solve(0, maxIndex);


}