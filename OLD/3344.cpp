#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
 
vector<int> answer;
void solve(int depth);
int main(){
    scanf("%d", &n);

    if(n%6 == 3){
        for(int i = 4; i <=n;i+=2){
            printf("%d\n", i);
        }
        printf("2\n");
        for(int i = 5; i <=n;i+=2){
            printf("%d\n", i);
        }
        printf("1\n3\n");
    } else if(n%6 == 2){
        for(int i = 2; i <=n;i+=2){
            printf("%d\n", i);
        }
        printf("3\n1\n");
        for(int i = 7; i <=n;i+=2){
            printf("%d\n", i);
        }
        printf("5\n");
    } else {
        for(int i = 1; i <=n;i+=2){
            printf("%d\n", i);
        }
        for(int i = 2; i <=n;i+=2){
            printf("%d\n", i);
        }
    }

    return 0;
}