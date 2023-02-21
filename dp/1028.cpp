//2022-02-21 22:15 start
//2022-02-21 23:19 end
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int R,C;
int diamond[751][751];
int rd[751][751];
int ru[751][751];
int ld[751][751];
int lu[751][751];

int main(){
    cin >> R >> C;
    for(int i =0; i< R;i++){
        string s;
        cin >> s;
        for(int j =0;j<C;j++){
            diamond[i][j]= s[j]-'0';
            if(diamond[i][j] == 0){
                rd[i][j]=0;
                ru[i][j]=0;
                ld[i][j]=0;
                lu[i][j]=0;
            }else {
                rd[i][j]=-1;
                ru[i][j]=-1;
                ld[i][j]=-1;
                lu[i][j]=-1;
            }
        }
    }

    for(int i =0; i <R;i++){
        for(int j =0;j<C;j++){
            int count = 0;
            int maxCount = 0;
            if(rd[i][j]==-1){
                count = 0;
                while(i+count <R && j+count < C && diamond[i+count][j+count]){//[i][j]입장에서 rd구하기
                    count++;
                }
                maxCount = count;
                while(count !=0){
                    lu[i+count-1][j+count-1] = count;
                    rd[i+count-1][j+count-1] = maxCount-count+1;
                    count--;
                }
            }
            if(ld[i][j]==-1){
                count = 0;
                while(i+count < R && j-count >= 0 && diamond[i+count][j-count]){//[i][j]입장에서 ld구하기
                    count++;
                }
                maxCount = count;
                while(count != 0){
                    ru[i+count-1][j-count+1] = count;
                    ld[i+count-1][j-count+1] = maxCount-count+1;
                    count--;
                }
            }
            
        }
    }//모든 ld,lu,rd,ru가 정리되었음.
    int max = 0;

    for(int i = 0; i < R; i++){
        for(int j =0; j<C;j++){
            int count=0;
            while(i+count < R && i-count >=0){
                if(rd[i-count][j] >= count+1 && ld[i-count][j] >= count+1 && ru[i+count][j] >= count+1 && lu[i+count][j] >= count+1){
                    int nowMax = count+1;
                    if(max < nowMax)max = nowMax;
                }
                count++;
            }
        }
    }

    cout << max;


}