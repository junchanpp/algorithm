#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;

int N, M, R;
vector<vector<int> > board;
vector<vector<int> > game;

map<char, int> dys;
map<char, int> dxs;

int attack(int startY, int startX, char direction){
    if(!game[startY][startX]){
        return 0;
    }
    int dy = dys[direction];
    int dx = dxs[direction];
    queue<pair<int, int> > q;
    q.push(make_pair(startY,startX));
    int count = 1;
    game[startY][startX] = 0;
    

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int size = board[y][x];

        while(--size){
            y += dy;
            x += dx;
            if(y < 0 || x < 0 || y >= N || x >= M){
                break;
            }
            if(!game[y][x]){
                continue;
            }
            game[y][x] = 0;
            count++;
            q.push(make_pair(y,x));
        }
    }
    return count;
}

void defence(int y, int x){
    game[y][x] = 1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> R;
    board.assign(N, vector<int>(M,0));
    game.assign(N, vector<int>(M,1));

    dys['S'] = 1;
    dxs['S'] = 0;
    dys['N'] = -1;
    dxs['N'] = 0;
    dys['E'] = 0;
    dxs['E'] = 1;
    dys['W'] = 0;
    dxs['W'] = -1;


    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> board[i][j];
        }
    }

    int score = 0;

    for(int i = 0 ; i < R; i++){
        int y, x;
        char direction;
        cin >> y >> x >> direction;
        score += attack(--y, --x, direction);
        cin >> y >> x;
        defence(--y,--x);
    }

    cout << score << '\n';

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cout << (game[i][j] == 1 ? 'S' : 'F') << " ";
        }
        cout << '\n';
    }

}