//2023-02-17 11:53:10 start
//2023-02-17 12:31:37 휴식
//2023-02-17 16:52:17 다시 시작
//실패

#include <iostream>
#include <deque>
#include <utility>

using namespace std;


int dyList[] = {-1,0,0,1,1,1,-1,-1};
int dxList[] = {0,-1,1,0,1,-1,-1,1};

int n, m; // n == x , m == y
int map[51][51];
int visited[51][51];
int newMap[51][51];
int answer[51];

int main(){
    cin >> m >> n; 

    for(int j = 0; j < m;j++){
        string s;
        cin >> s;
        for(int i = 0; i < n;i++){
            if(s[i] == 'x')map[j][i] = 0; // 섬이면 0으로 시작
            else map[j][i]=-1; // 바다면 -1
        }
    }
    deque< deque <pair<int,int> > > landList;

    for(int j = 0; j <m;j++){
        for(int i = 0;i <n;i++){
            if(visited[j][i] == 0 && map[j][i] ==0){

                register deque<pair<int,int> > land;
                register deque<pair<int,int> > newLand;

                visited[j][i] = 1;
                land.push_back(make_pair(i,j));
                while(!land.empty()){
                    register pair<int,int> point = land.front();
                    land.pop_front();
                    int y = point.second;
                    int x = point.first;
                    for(int i = 0; i< 8;i++){
                        int newY = dyList[i]+y;
                        int newX = dxList[i]+x;
                        if(newY <0 || newY > m-1 || newX < 0 || newX > n-1)continue;
                        if(visited[newY][newX] == 0 && map[newY][newX] == 0){
                            visited[newY][newX] = 1;
                            land.push_back(make_pair(newX,newY));
                        }
                    }
                    newLand.push_back(make_pair(x,y));
                }
                
                landList.push_back(newLand);
            }
        }
    }

    register deque< deque <pair<int,int> > > newLandList(landList);
    //리스트에서 하나하나 꺼내서 나갈수 있는지 판단하고 못 나가면 해당 lande들의 높이를 1 증가시키고 다시 넣는다, 나갈 수 있으면 꺼낸상태에서 끝
    while(!landList.empty()){
        register deque<pair<int, int> > land = landList.front();
        landList.pop_front();

        register int currentSize = map[land.front().second][land.front().first];//현재 섬의 높이
        register bool isExit = false;
        register bool visitedForCheckingLand[51][51] = {0,};
        register deque<pair<int, int> > newLand;

        for(int i =0 ; i< land.size(); i++) {
            newLand.push_back(land[i]);
        }

        while(!land.empty() && !isExit){


            pair<int, int> currentPoint = land.front();
            land.pop_front();

            for(int i = 0; i <4; i++){
                int newY = currentPoint.second+dyList[i];
                int newX = currentPoint.first+dxList[i];
                if(newY <0 || newX <0 || newY >= m || newX >= n){
                    isExit = true;
                    break;
                }
                if((visitedForCheckingLand[newY][newX] == 0) && map[newY][newX] < currentSize){
                    visitedForCheckingLand[newY][newX] = 1;
                    land.push_back(make_pair(newX,newY));
                }
            }
            
        }
        if(isExit){
        }
        else {
            for(int i = 0; i < newLand.size(); i++){
                map[newLand[i].second][newLand[i].first]++;
            }
            landList.push_back(newLand);
        }

    }

    //가장 안쪽 섬이 가지고 있는 것은 현재 n번째 안쪽 섬이라는 뜻
    //새로운 판을 만들고 거기서 진행(모두 -1로 초기화)
    //첫좌표를 가지고 새로운판에서 -1로 지정된 가장 큰 수를 가지고 있는 섬은 0으로 치환 -> 그 섬이 만나는 n-1번째 섬은 1로 치환
    //그 섬이 만나는 n-1번째 섬이 이미 -1이 아닌 다른 값을 가지고 있다면 continue;

    int newMap[51][51];
    for(int i = 0; i < 51; i++){
        for(int j = 0; j< 51; j++){
            newMap[i][j]=-1;
        }
    }


    while(!newLandList.empty()){
        int maxIndex = 0;
        for(int i = 1; i < newLandList.size();i++){
            if(newMap[newLandList.at(i).front().second][newLandList.at(i).front().first] == -1 &&map[newLandList.at(maxIndex).front().second][newLandList.at(maxIndex).front().first] < map[newLandList.at(i).front().second][newLandList.at(i).front().first]){
                maxIndex = i;
            }
        }
        deque< pair<int,int> > newLand = newLandList.at(maxIndex);
        newLandList.erase(newLandList.begin()+maxIndex);


        int maxSize = map[newLand.front().second][newLand.front().first];
        int depth = maxSize;
        for(int i =0; i< newLand.size();i++){
            newMap[newLand.at(i).second][newLand.at(i).first] = maxSize - depth;
        }
        answer[maxSize-depth]++;
        depth--;
        for(;depth>=0;depth--){
            int currentSize = depth;
            bool isFind = false;
            bool isDone = false;
            bool visitedForCheckingLand[51][51] = {0,};
            pair<int, int> newPoint;
            deque<pair<int, int> > currentPointdeq;
            currentPointdeq.push_back(make_pair(newLand.front().first, newLand.front().second));
            while(!currentPointdeq.empty() && !isFind && !isDone){
                pair<int, int> currentPoint = currentPointdeq.front();
                currentPointdeq.pop_front();
                for(int i = 0; i <8; i++){
                    int newY = currentPoint.second+dyList[i];
                    int newX = currentPoint.first+dxList[i];
                    if(newY <0 || newX <0 || newY > m-1 || newX > n-1){
                        continue;
                    }
                    if((visitedForCheckingLand[newY][newX] == 0) && map[newY][newX] < currentSize){
                        if(newMap[newY][newX] != -1){
                            isDone = true;
                            break;
                        }
                        visitedForCheckingLand[newY][newX] = 1;
                        currentPointdeq.push_back(make_pair(newX,newY));
                    }
                    else if (map[newY][newX]==currentSize) {
                        if(newMap[newY][newX] != -1){
                            isDone = true;
                            break;
                        }
                        newPoint = make_pair(newX,newY);
                        isFind= true;
                        break;
                    }
                }
            }
            if(isFind){
                if(newLandList.size() == 0 ){
                    for(int i =0; i< newLand.size();i++){
                        newMap[newLand.at(i).second][newLand.at(i).first] = maxSize - depth;
                    }
                    answer[maxSize-depth]++;
                    break;
                }
                int index = 0;
                for(int i =0 ; i< newLandList.size();i++){
                    for(int j =0;j<newLandList[i].size();j++){
                        if(newLandList[i][j].first == newPoint.first && newLandList[i][j].second == newPoint.second){
                            index = i;
                        }
                    }
                }
                
                newLand = newLandList.at(index);
                newLandList.erase(newLandList.begin()+index);
                for(int i =0; i< newLand.size();i++){
                    newMap[newLand.at(i).second][newLand.at(i).first] = maxSize - depth;
                }
                answer[maxSize-depth]++;
            }else {
                break;
            }
        }
    }


    bool isExistLand = false;

    for(int i = 0; i< 51;i++){
        if(answer[i] > 0) {
            cout << answer[i] << " ";
            isExistLand = true;
        }
    }
    if(!isExistLand)cout << -1;
}