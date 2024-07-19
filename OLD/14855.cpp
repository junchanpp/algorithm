#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Dumpling{
    int a; 
    int b;
    int c;
    int d;
    // Dumpling(int a, int b, int c, int d):a(a),b(b),c(c),d(d){}
} Dumpling;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m , c0, d0;
    cin >> n >> m >> c0 >> d0;
    vector<Dumpling> reciptList(m);
    for(int i = 0 ; i < m;i++){
        cin >> reciptList[i].a >> reciptList[i].b >> reciptList[i].c >> reciptList[i].d;
    }
    // d/c가 가장 큰 것부터 넣기
    vector<int> memo(n+1,0);
    for(int i = 0; i < reciptList.size(); i++){
        Dumpling dumpling = reciptList[i];
        int a = dumpling.a;
        int b = dumpling.b;
        int c = dumpling.c;
        int d = dumpling.d;
        int maxNumOfDumpling = n/c;
        while(a >= b && maxNumOfDumpling--){
            a-=b;
            for(int j = 0 ; j <= n; j++){
                int remainGram = n - j;
                if(c <= remainGram){
                    memo[j] = max(memo[j], memo[j+c]+d);
                }
            }
        }
    }

    int maxNum = 0;

    for(int i = 0 ; i <= n; i++){
        int remainGram = i;
        maxNum = max(maxNum, memo[i] + (remainGram/c0) * d0);
    }

    cout << maxNum;


    return 0;
}