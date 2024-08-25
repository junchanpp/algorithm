#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;
vector<vector<char> > board;
vector<vector<bool> > visited;
int y,x;

int answer = 0;

int dy[] = {0,0,0,-1,-1,-1,1,1,1};
int dx[] = {-1,1,0,-1,1,0,-1,1,0};

int main(){
    cin >> N;
    board.assign(N, vector<char>(N, 0));
    visited.assign(N, vector<bool>(N, 0));
    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j <N; j++){
            board[i][j] = s[j];
            if(board[i][j] == 'F'){
                y = i;
                x = j;
            }
        }
    }



    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visited[y][x] = 1;
    answer = 0;


    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;

        q.pop();
        for(int i = 0 ; i < 8; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || visited[nextY][nextX] || board[nextY][nextX] != '.'){
                continue;
            }
            visited[nextY][nextX] = 1;
            answer++;
            q.push(make_pair(nextY,nextX));
        }
    }

    cout << answer;
}