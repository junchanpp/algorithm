#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
vector< vector<int> > S;

int countMember(int bit){
    int sum = 0;
    while(bit != 0){
        if(bit % 2 == 1){
            sum++;
        }
        bit = bit>>1;
    }
    return sum;
}

vector<int> getMember(int bit, int teamFlag){
    vector<int> members;
    int index = 0;
    while(bit != 0){
        if(bit % 2 == teamFlag){
            members.push_back(index);
        }
        index++;
        bit = bit>>1;
    }
    while(index != N&& teamFlag == 0){
        members.push_back(index++);
    }

    return members;
}

int getTeamStartScore(int bit){
    vector<int> members = getMember(bit, 1);

    int score = 0;

    for(int i = 0 ; i < members.size(); i++){
        for(int j = 0; j < members.size(); j++){
            score += S[members[i]][members[j]];
        }
    }

    return score;
}

int getTeamLinkScore(int bit){
    vector<int> members =  getMember(bit, 0);

    int score = 0;

    for(int i = 0 ; i < members.size(); i++){
        for(int j = 0; j < members.size(); j++){
            score += S[members[i]][members[j]];
        }
    }

    return score;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;

    S.assign(N,vector<int>(N,0));
    
    for(int i =0; i<N;i++){
        for(int j=0;j<N;j++){
            cin >> S[i][j];
        }
    }

    int maxBit = pow(2,N);

    int bit = 1;

    int minAnswer = INT_MAX;

    while(bit != maxBit){
        int count = countMember(bit);
        if(count < 2 || count > N -2){
            bit++;
            continue;
        }

        int teamStartScore = getTeamStartScore(bit);
        int teamLinkScore = getTeamLinkScore(bit);

        int score = abs(teamStartScore - teamLinkScore);

        if (score < minAnswer){
            minAnswer = score;
        }

        bit++;
    }

    cout << minAnswer;



}