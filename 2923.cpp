#include <iostream>
#include <vector>

using namespace std;



int N;
int a[101] = {0,};
int b[101] = {0,};
int aCopy[101];
int bCopy[101];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    vector<int> answers;

    for(int i = 1 ; i <= N;i++){
        int ai, bi;
        cin >> ai >> bi;
        a[ai]++;
        b[bi]++;

        int answer = 0;
        int start = 1;
        int end = 100;
        for(int j = 1;j<=100;j++){aCopy[j] = a[j];bCopy[j] = b[j];}
        int count = 0;
        while(count != i){
            while(start <= 100 && aCopy[start] == 0){start++;}
            while(end >= 1 && bCopy[end] == 0){end--;}
            if(start > 100 || end < 1){
                break;
            }
            answer = max(answer, start+end);
            count++;
            if(aCopy[start] > bCopy[end]){
                aCopy[start]-=bCopy[end];
                bCopy[end] = 0;
            } else {
                bCopy[end]-=aCopy[start];
                aCopy[start] = 0;
            }
        }
        answers.push_back(answer);
    }
    for(int i  = 0 ; i < answers.size();i++){
        cout << answers[i] << '\n';
    }
}