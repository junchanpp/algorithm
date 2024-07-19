#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <cmath>


using namespace std;

bool solve(int N, int M, int D, vector<vector<char> > initGreens,vector<vector<char> > finalGreens);

int main(){
    int N, M, D;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<vector<char> > initGreens(N, vector<char>(M));
    vector<vector<char> > finalGreens(N, vector<char>(M));

    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            initGreens[i][j] = s[j];
        }
    }

    cin >> D;

    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            finalGreens[i][j] = s[j];
        }
    }

    cout << (solve(N,M,D,initGreens,finalGreens) ? "YES" : "NO") << endl;
    return 0;
}

bool solve(int N, int M, int D, vector<vector<char> > initGreens,vector<vector<char> > finalGreens){
    //그래프 문제
    //initGreens를 기준으로 D만큼 범위 bfs,dfs로 탐색해서 finalGreens에 잔디가 있으면 잔디 심기
    //마지막에 initGreens와 finalGreens가 일치하는지 확인
    //O(N * M * D * D) 시간복잡도 예상

    vector<vector<bool> > visited(N, vector<bool>(M, false));

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j <M; j++){
            if(visited[i][j]){
                continue;
            }
            if(initGreens[i][j] == 'O'){
                visited[i][j] = true;
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int dy = -D ; dy <=D;dy++){
                        int absDy = abs(dy);
                        for(int dx = -(D-absDy); dx<=(D-absDy);dx++){
                            if(y+dy < 0 || x+dx <0 || y+dy >= N || x+dx >= M){
                                continue;
                            }
                            if(finalGreens[y+dy][x+dx] == 'O' && !visited[y+dy][x+dx]){
                                initGreens[y+dy][x+dx] = 'O';
                                visited[y+dy][x+dx] = true;
                                q.push(make_pair(y+dy,x+dx));
                            }

                        }
                    }
                }
                
            }
        }
    }
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j <M; j++){
            if(initGreens[i][j] != finalGreens[i][j]){
                return false;
            }
        }
    }
    return true;
}