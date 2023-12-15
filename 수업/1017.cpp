#include <iostream>

using namespace std;

int map[16][16]= {0,};
int size;//전체 size
int cnt = 1;//타일 번호 매김용 count

void solve(int nowSize, int x, int y, int holeX, int holeY); //실제 풀이 메서드
bool check(); // 모든 타일이 올바르게 채워졌는지 확인하는 메서드

int main(){
    int k;
    cin >> k;
    size = 1 << k;
    int temp1, temp2;
    cin >> temp1 >> temp2;
    map[temp1-1][temp2-1] = -1;//구멍타일 초기화

    solve(size, 0, 0, temp1-1, temp2-1);//풀이

    if(!check()){
        cout << -1;//check() 불통과하면 -1 출력
        return 0;
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << map[j][i] << " "; //입력을 반대로 받아서, 출력을 어쩔수없이 반대로 했습니다.
        }
        cout << endl;
    }

    return 0;
}
bool check(){
    int sum[100]= {0,};//최대 99까지 올 수 있으므로 100까지 선언 및 초기화
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j]!=-1)sum[map[i][j]]++;
        }
    }
    if(sum[0] != 0)return false;//비어있는 타일이 존재할 경우 false
    for(int i = 1; i< cnt; i++){
        if(sum[i]!=3)return false; //3개씩 자리 차지하지 않으면 false
    }
    return true;
}

void solve(int nowSize, int x, int y, int holeX, int holeY){
    if(nowSize==2){//사이즈가 2일 경우, 그대로 넣고 종료
        if(x != holeX || y != holeY)map[x][y] = cnt;
        if(x != holeX || y+1 != holeY)map[x][y+1] = cnt;
        if(x+1 != holeX || y != holeY)map[x+1][y] = cnt;
        if(x+1 != holeX || y+1 != holeY)map[x+1][y+1] = cnt;
        cnt++;//사용된 숫자 버리고 다음 숫자 사용하게 +1
        return;
    }
    int newSize = nowSize/2;
    int holeLocation;
    if(holeX> x+newSize-1 || holeY > y+newSize-1)map[x+newSize-1][y+newSize-1]=cnt;//구멍이 아닐 경우에만 L자 타일 입력
    else holeLocation = 1;
    if(holeX< x+newSize || holeY > y+newSize-1)map[x+newSize][y+newSize-1]=cnt;//구멍이 아닐 경우에만 L자 타일 입력
    else holeLocation = 2;
    if(holeX> x+newSize-1 || holeY < y+newSize)map[x+newSize-1][y+newSize]=cnt;//구멍이 아닐 경우에만 L자 타일 입력
    else holeLocation = 3;
    if(holeX< x+newSize || holeY < y+newSize)map[x+newSize][y+newSize]=cnt;//구멍이 아닐 경우에만 L자 타일 입력
    else holeLocation = 4;
    cnt++;//사용된 숫자 버리고 다음 숫자 사용하게 +1
    solve(newSize, x ,y , holeLocation == 1 ? holeX : x+newSize-1, holeLocation == 1 ? holeY : y+newSize-1);//분할하여 타일 넣기
    solve(newSize, x + newSize ,y , holeLocation == 2 ? holeX : x+newSize, holeLocation == 2 ? holeY : y+newSize-1);//분할하여 타일 넣기
    solve(newSize, x ,y+ newSize , holeLocation == 3 ? holeX : x+newSize-1, holeLocation == 3 ? holeY : y+newSize);//분할하여 타일 넣기
    solve(newSize, x+ newSize ,y+ newSize , holeLocation == 4 ? holeX : x+newSize, holeLocation == 4 ? holeY : y+newSize);//분할하여 타일 넣기
}