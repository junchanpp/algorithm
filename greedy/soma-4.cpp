#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> chap;

int findIndex(int startIndex, char c){
    for(int i = startIndex; i<N;i++){
        if(chap[i][0]==c || chap[i][1]==c){
            return i;
        }
    }
}
int findIndexMax(char c){
    for(int i = N-1; i>=0;i--){
        if(chap[i][0]==chap[i][1])continue;
        if(chap[i][0]==c || chap[i][1]==c){
            return i;
        }
    }
}
int swapToMove(int s, int e, char c){
    int count = 0;
    for(int i = e-1;i>=s;i--){
        int nowIndex = chap[i+1][0] == c ? 0 : 1;
        if(i==s){
            swap(chap[i][(chap[i][0]== c ? 1 : 0)], chap[i+1][nowIndex]);
            count++;
            continue;
        }
        int index0 = findIndexMax(chap[i][0]);
        int index1 = findIndexMax(chap[i][1]);
        
        if(index0 >index1){
            swap(chap[i][0],chap[i+1][nowIndex]);
            count++;
        }else {
            swap(chap[i][1],chap[i+1][nowIndex]);
            count++;
        }
    }
    return count;
}

/*

N명의 사람들이 있고(2<=N<=6),
각각 젓가락을 가지고 있는다 젓가락 종류는 'A','B','C','D'와 같이 존재한다.
인접한 사람끼리만 젓가락 하나씩 교환할 수 있다.
모두 짝이 맞게 하기 위해 최소한으로 교환해야하는 횟수는?
ex) AC DB DB CA가 짝이 맞게 교환하는 방법
AC DB DC BA 
AC DC DB BA 
CC DA DB BA 
CC DD AB BA
CC DD AA BB

1. 1~N번째를 for문 돌려 앞에서부터 하나씩 비교
2. 짝이 안 맞으면 두 개 중 가장 가까이 있는 거부터 가져오게 하기(AB CD BC AD와 같이 있을 때, 'A','B'중 'B'먼저 가져오기)
3. 가져올 때, 왼쪽 젓가락과 교환하게 될텐데 왼쪽 젓가락 종류들 중 가장 멀리 있는 거부터 교환(AB CD BC AD가 있고 'B'를 가져오기 위해서 'CD'와 교환할 때, D(4번쨰, C는 2번쨰)가 가장 멀리 있으므로 D와 교환)
*/
int main(){
    cin >> N;

    for(int i =0; i<N;i++){
        string s;
        cin >> s;
        chap.push_back(s);
    }

    int count = 0;

    for(int i =0;i < N;i++){
        if(chap[i][0]==chap[i][1])continue;
        int index0 = findIndex(i+1,chap[i][0]);
        int index1 = findIndex(i+1,chap[i][1]);
        char findChar = chap[i][(index0 < index1 ? 0 : 1)];
        int minIndex = min(index0,index1);

        int swapCount = swapToMove(i,minIndex,findChar);
        count+=swapCount;

    }

    cout << count << endl;
}