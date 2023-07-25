#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> nextNode[257];

int memo[257][257];

int solve(int a, int b){
    if(a==b && a== N){
        return 1;
    }
    if(memo[a][b] != -1){
        return memo[a][b];
    }
    if(memo[b][a] != -1){
        return 0;
    }

    if(a > b){
        int size = nextNode[b].size();
        int maxLength = 0;
        for(int i = 0; i < size; i++){
            if(a==nextNode[b][i] && a!=N)continue;
            int nextLength = solve(a,nextNode[b][i]);
            if(nextLength > maxLength)maxLength = nextLength;
        }

        return memo[a][b] =  maxLength == 0 ? 0 : 1 + maxLength;
    }else {
        int size = nextNode[a].size();
        int maxLength = 0;
        for(int i = 0; i < size; i++){
            if(b==nextNode[a][i] && b != N)continue;
            int nextLength = solve(nextNode[a][i],b);
            if(nextLength > maxLength)maxLength = nextLength;
        }

        return memo[a][b] =  maxLength == 0 ? 0 : 1 + maxLength;

    }
}

int main(){
    for(int i = 0; i < 257; i++){
        for(int j = 0 ; j < 257; j++){
            memo[i][j]= -1;
        }
    }
    scanf("%d", &N);

    while(1){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        if(temp1==temp2 && temp1 == 0)break;
        else if(temp1==temp2)continue;

        if(temp1 < temp2){
            int temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }
        nextNode[temp2].push_back(temp1);
    }

    int ans = solve(1,1);

    if(ans==0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> root1;
    vector<int> root2;

    root1.push_back(1);
    root2.push_back(1);

    memo[N][N] = 1;

    int nowAns = ans;

    while(root1[root1.size()-1] != N || root2[root2.size()-1] != N){
        int lastElementFromRoot2 = root2[root2.size()-1];
        for(int i = root1[root1.size()-1]; i <= N; i++){
            if(memo[i][lastElementFromRoot2]+1 == nowAns){
                nowAns--;
                root1.push_back(i);
                break;
            }
        }
        int lastElementFromRoot1 = root1[root1.size()-1];
        for(int i = root2[root2.size()-1]; i <= N; i++){
            if(memo[lastElementFromRoot1][i]+1 == nowAns){
                nowAns--;
                root2.push_back(i);
                break;
            }
        }
    }
    cout << ans-1 << endl;

    for(int i = 0; i < root2.size(); i++){
        cout << root2[i] << " ";
    }
    for(int i = root1.size()-2; i >=0; i--){
        cout << root1[i] << " ";
    }
}

