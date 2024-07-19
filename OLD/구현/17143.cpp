#include <iostream>
using namespace std;

typedef struct Shark{
    int speed = 0, direction = 0, size = 0;
    bool isShark = false;
} Shark;

void initShark(Shark& shark){
    shark = Shark();
}

int R;
int C;
int personPos;
int sum = 0;
Shark sharkArr[100][100] ={};

int capture(){
    for(int i = 0 ; i < R; i++){
        if(sharkArr[i][personPos].isShark){
            int sharkCapturedSize = sharkArr[i][personPos].size;
            initShark(sharkArr[i][personPos]);
            return sharkCapturedSize;
        }
    }
    return 0;
}
void movePerson(){
    personPos++;
}
void moveShark(){
    Shark newSharkArr[100][100] = {};

    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C; j++){
            if(sharkArr[i][j].isShark){
                int direction = sharkArr[i][j].direction;
                int speed = sharkArr[i][j].speed;
                int size = sharkArr[i][j].size;
                int newI = i;
                int newJ = j;

                int distance = speed;
                while(distance != 0){
                    if(direction == 1){
                        newI = newI - distance;
                        if(0 > newI){distance = 0 - newI; newI = 0; direction = 2;}
                        else {distance = 0;}
                    } else if (direction == 2) {
                        newI = newI + distance;
                        if((R-1) < newI){distance =  newI - (R-1); newI = R-1; direction = 1;}
                        else {distance = 0;}
                    }

                    if(direction == 3){
                        newJ = newJ + distance;
                        if((C-1) < newJ){distance = newJ - (C-1) ; newJ = C-1; direction = 4;}
                        else {distance = 0;}

                    } else if(direction == 4){
                        newJ = newJ - distance;
                        if(0 > newJ){distance = 0 - newJ; newJ = 0; direction = 3;}
                        else {distance = 0;}

                    }
                }
                
                if(newSharkArr[newI][newJ].isShark && newSharkArr[newI][newJ].size > size){
                    continue;
                }
                newSharkArr[newI][newJ].direction = direction;
                newSharkArr[newI][newJ].speed = speed;
                newSharkArr[newI][newJ].size = size;
                newSharkArr[newI][newJ].isShark = true;
            }
        }
    }

    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C; j++){
            sharkArr[i][j] = newSharkArr[i][j];
        }
    }
}

int main(){
    int M;
    cin >> R >> C >> M;

    for(int i = 0 ; i < M; i++){
        int tempR, tempC, tempSpeed, tempDirection, tempSize;
        cin >> tempR >> tempC >> tempSpeed >> tempDirection >> tempSize;
        tempR--;
        tempC--;

        sharkArr[tempR][tempC].isShark = true;
        sharkArr[tempR][tempC].speed = tempSpeed;
        sharkArr[tempR][tempC].direction = tempDirection;
        sharkArr[tempR][tempC].size = tempSize;
    }

    personPos = 0;

    while(personPos < C){
        sum += capture();
        moveShark();
        movePerson();
    }

    cout << sum << endl;

    return 0;
}