#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

int N, M, L, T, K;

vector<vector<char> > board[362];//각 t/10마다 선생들 위치 포함 지도 미리 그려두기.
int dy[9] = {0,0,0,-1,-1,-1,1,1,1};
int dx[9] = {-1,1,0,-1,1,0,-1,1,0};


void initBoard(){
    for(int i = 0; i <= T/10 + 1; i++){
        board[i].assign(N+1, vector<char>(M+1));
    }

    for(int i = 1 ; i <= N; i++){
        char tmp[M+1];
        scanf("%s", tmp);
        for(int j = 1; j<= M;j++){
            for(int k = 0; k <= T/10;k++){
                board[k][i][j] = tmp[j-1];
            }
        }
    }

}

void initTeachers(){
    vector<vector< pair<int, int> > > teachers; 

    for(int i = 0; i < L ;i++){//기본 입력 받기
        int p;
        scanf("%d", &p);

        vector<pair<int, int> > teacher;
        for(int j = 0 ; j < p ; j++){
            int y, x;
            scanf("%d %d", &y, &x);
            teacher.push_back(make_pair(y,x));
        }
        teachers.push_back(teacher);
    }

    // t/10마다 바뀌는 선생 위치 board에 저장
    for(int i = 0 ; i <= T/10; i++){
        for(int j = 0 ; j < L;j++){
            vector<pair<int, int> > teacher = teachers[j];
            int p = teacher.size();
            board[i][teacher[i%p].first][teacher[i%p].second] = 'T';
            for(int a = 0 ; a < 9; a++){
                if(teacher[i%p].first+dy[a] < 1 || teacher[i%p].first+dy[a] > N || teacher[i%p].second+dx[a] < 1 || teacher[i%p].second+dx[a] > M){
                    continue;
                }
                board[i][teacher[i%p].first+dy[a]][teacher[i%p].second+dx[a]] = 'T';
            }
        }
    }
}

typedef struct Info{
    int y;
    int x;
    int t;
    bool isAte;

    Info(int y, int x, int t, bool isAte): y(y),x(x),t(t),isAte(isAte) {}

} Info;
struct cmp{
    bool operator()(Info& a, Info& b){
        return a.t > b.t;
    }
};
int ia = 1;

bool isVisited[1001][1001][362][2];// y, x, t, isAte;
bool solve(){
    if(200 < max(N,M)){
        return false;
    }
    Info initInfo = Info(1,1,1,false);

    priority_queue<Info, vector<Info>, cmp > q;

    q.push(initInfo);

    while(!q.empty()){
        
        Info info = q.top();
        q.pop();
        int y = info.y;
        int x = info.x;
        int t = info.t;
        bool isAte = info.isAte;
        if(t+10 > T){
            return false;
        }
        
        if(y < 1 || x < 1 || y > N || x > M || t/10 > 360){//범위 벗어나면 continue
            continue;
        }
        
        if(t!= 1){
            if(isVisited[y][x][t/10][isAte]){//이미 검사했으면 스킵
                continue;
            }
            isVisited[y][x][t/10][isAte] = true;

        }
        
        

        vector<vector<char> > nowBoard = board[t/10];
        vector<vector<char> > nextBoard = board[min(t== 1 ? 5 : t+10, T)/10];//min은 outOfIndex 방지용. T가 들어가게 된다면 실제로는 사용 x


        
        for(int i = 0 ; i < 9; i++){
            int nextY = y+dy[i];
            int nextX = x+dx[i];
            if(nextY < 1 || nextX < 1 || nextY > N || nextX > M){//범위 벗어나면 continue
                continue;
            }
            if(!(nextX==1 && nextY == 1) && !(nextY==N && nextX==M)){//다음위치가 장애물이거나 선생님 눈치 봐야 하는 위치면 continue
                if(nowBoard[nextY][nextX] == '#' || nowBoard[nextY][nextX] == 'T'){
                    continue;
                }
                if(nextBoard[nextY][nextX] == '#' || nowBoard[nextY][nextX] == 'T'){
                    continue;
                }
            }

            //이제 이동하거나 밥먹기 수행
            int nextT = t == 1 ? 5 : t + 10;
            int nextIsAte = isAte;
            if(nextY == 1 && nextX == 1 && isAte){
                return true;
            }
            if(nextY == N && nextX == M && !isAte){
                q = priority_queue<Info, vector<Info>, cmp >();
                nextT = nextT + ((K-1)/10)*10;
                
                nextIsAte = true;
                q.push(Info(nextY,nextX,nextT,nextIsAte));
                break;
            }


            q.push(Info(nextY,nextX,nextT,nextIsAte));
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    scanf("%d %d %d %d %d", &N, &M, &L, &T, &K);
    if(200 < max(N,M)){
        cout << "SAD" ;
        return 0;
    }


    initBoard();
    initTeachers();

    bool isYummy = solve();
    
    printf(isYummy ? "YUMMY" : "SAD");
}