//2023-02-17 18:23:40 start
//2023-02-17 19:08:00 end
#include <iostream>

using namespace std;

//조커 박스는 아무거나 담을 수 있음
//나머지 박스는 같은 색상의 카드만 담을 수 있음
/*

다른 색상이 포함되어 있으면 무조건 한 번은 이동해야 함(조커가 아닌 경우)
이미 정리된 박스는 냅두어도 된다.

*/
int main(){
    int boxN, cardM;

    cin >> boxN >> cardM;

    int box[51][51]; // y는 박스 하나, x는 카드 색상별 그 박스 안의 개수, 같은 카드 장수 최대 9개
    int singleBoxCardNumber[51]={0,};

    for(int i = 0; i< boxN; i++){
        for(int j = 0; j< cardM; j++){
            cin >> box[i][j];
        }
    }
    int count = 0;
    for(int j = 0; j < boxN;j++){
        int index = -1;
        bool isUpdateCount = false;
        for(int k = 0; k < cardM; k++){
            if(box[j][k]!=0) {
                if(index !=-1 || singleBoxCardNumber[k] !=0){
                    count++;
                    isUpdateCount= true;
                    break;
                } else {
                    index = k;
                }
            }
        }
        if(!isUpdateCount && index != -1){
            singleBoxCardNumber[index]++;
        }
    }
    if(count >0)count--;

    cout << count << endl;

}