#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A,B;

int main(){
    cin >> N >> A >> B;
    if(A >N-B+1 || N-A+1 < B){
        cout << -1;
        return 0;
    }
    int heightSize = A+B-1;
    int height[heightSize];
    fill(height,height+heightSize+1,1);
    int size = 1;
    for(int i = 0; i< A-1;i++){
        height[i] = size++;
    }

    size = 1;
    
    for(int i =heightSize-1; i > heightSize-1-(B-1);i--){
        height[i] = size++;
    }

    if(A==1 && B ==1){
        height[0] = 1;
    } else if(A == 1){
        height[A-1] = height[A]+1;
    } else {
        height[A-1] = max(height[A-2],height[A])+1;
    }

    int answer[N];
    fill(answer,answer+N,1);
    for(int i = 0; i<(A+B-1);i++){
        answer[N-(A+B-1)+i] = height[i];
    }
    if(A==1){
        swap(answer[0],answer[N-(A+B-1)]);
    }

    for(int i = 0; i<N;i++){
        cout << answer[i] << " ";
    }
    return 0;
}