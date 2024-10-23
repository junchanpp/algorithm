#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Team{
    int needed;
    int Da;
    int Db;
    int Ddiff;

    Team(int needed, int Da, int Db, int Ddiff) : needed(needed), Da(Da), Db(Db), Ddiff(Ddiff){}
}Team;

bool compare(const Team& ta, const Team& tb){
    return (abs(ta.Ddiff) == abs(tb.Ddiff)) ? ta.needed > tb.needed : abs(ta.Ddiff) > abs(tb.Ddiff);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while(1){
        int N, A, B;
        vector<Team> teams;
        
        cin >> N >> A >> B;


        if(N == 0 && A == 0 && B == 0){
            break;
        }


        int totalSum = 0;

        for(int i = 0; i < N; i++){
            int K, Da, Db, D;
            cin >> K >> Da >> Db;
            D = Da - Db;

            teams.push_back(Team(K, Da, Db, D));
        }

        sort(teams.begin(), teams.end(), compare);

        for(int i = 0; i < N; i++){
            Team nowTeam = teams[i];
            int remained = nowTeam.needed;
            if(nowTeam.Ddiff < 0){
                if(remained > A){
                    totalSum += A * nowTeam.Da;
                    totalSum += (remained - A) * nowTeam.Db;
                    B -= remained - A;
                    A = 0;
                }else {
                    totalSum += remained * nowTeam.Da;
                    A -= remained;
                }
            }else if(nowTeam.Ddiff > 0){
                if(remained > B){
                    totalSum += B * nowTeam.Db;
                    totalSum += (remained - B) * nowTeam.Da;
                    A -= remained - B;
                    B = 0;
                }else {
                    totalSum += remained * nowTeam.Db;
                    B -= remained;
                }
            }else{
                totalSum += remained * nowTeam.Da;
            }
        }

        cout << totalSum << '\n';
    }
}