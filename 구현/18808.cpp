#include <iostream>
#include <utility>

using namespace std;

bool sticker[101][4][11][11];
pair<int,int> stickerSize[101][4];


int main(){
    int N,M,K;

    cin >> N >> M >> K;

    for(int i =0; i< K;i++){
        cin >> stickerSize[i][0].first >> stickerSize[i][0].second;

        for(int j = 0; j< stickerSize[i][0].first ; j++){
            for(int k = 0; k< stickerSize[i][0].second; k++){
                cin >> sticker[i][0][j][k];
            }
        }
        for(int degree = 1; degree<4;degree++){
            stickerSize[i][degree].first = stickerSize[i][degree-1].second;
            stickerSize[i][degree].second = stickerSize[i][degree-1].first;
            for(int j = 0; j< stickerSize[i][degree-1].first ; j++){
                for(int k = 0; k< stickerSize[i][degree-1].second; k++){
                    sticker[i][degree][k][stickerSize[i][degree-1].first - j -1] = sticker[i][degree-1][j][k];
                }
            }
        }
    }
    bool arr[N][M];
    for(int i =0 ; i < N ;i++){
        for(int j = 0; j<M;j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < K ; i++){
        for(int degree = 0 ; degree < 4; degree++){
            bool isInserted = false;
            for(int a = 0; a < N - stickerSize[i][degree].first+1; a++){
                for(int b = 0; b< M - stickerSize[i][degree].second+1; b++){
                    bool isInsertable = true;
                    for(int a1 = 0; a1 < stickerSize[i][degree].first; a1++){
                        for(int b1 = 0; b1 <stickerSize[i][degree].second; b1++){
                            if(arr[a+a1][b+b1] == 1 && sticker[i][degree][a1][b1] == 1){
                                isInsertable = false;
                            }
                        }
                    }
                    if(isInsertable){
                        isInserted = true;
                        for(int a1 = 0; a1 < stickerSize[i][degree].first; a1++){
                            for(int b1 = 0; b1 <stickerSize[i][degree].second; b1++){
                                if(arr[a+a1][b+b1] == 0 && sticker[i][degree][a1][b1] == 1){
                                    arr[a+a1][b+b1] = 1;
                                }
                            }
                        }
                        break;
                    }
                }
                if(isInserted){
                    break;
                }
            }
            if(isInserted){
                break;
            }
        }
    }
    int count =0;
    for(int i =0 ; i< N; i++){
        for(int j= 0; j <M;j++){
            if(arr[i][j]==1)count++;
        }
    }
    cout << count;
}