#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>


using namespace std;

int N, M, X, Y;
vector<int> A,B;
vector<vector<int> > edges;

//1. 보안 시스템이 설치되는 타이밍 배열 생성 -> 생략 후, 2번의 배열 바로 생성
//2. 그 후, 타이밍 * A[i]를 저장하는 배열 생성
//3. 그중 높은 값 X개 뽑아서 더하기
//4. 그 중 높은 값이 INT_MAX가 있다면 -1 출력

vector<long long> earned;

void insert(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> X >> Y;
    A.assign(N, 0);
    edges.assign(N, vector<int>(0));
    B.assign(Y, 0);
    earned.assign(N,-1);

    for(int i = 0 ; i <  N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        s--;e--;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    for(int i = 0 ; i <  Y; i++){
        cin >> B[i];
        B[i]--;
    }

}

void solve(){
    int count = 0;
    queue<int> q;
    for(int i = 0; i < Y; i++){
        q.push(B[i]);
        earned[B[i]] = 0;
    }
    count++;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0 ; i < size; i++){
            int s = q.front();
            q.pop();
            for(int j = 0; j < edges[s].size(); j++){
                int e = edges[s][j];
                if(earned[e] == -1){
                    earned[e] = (long long)count * A[e];
                    q.push(e);
                }
            }
        }
        count++;
    }
}

void print(){
    vector<long long> result;
    for(int i = 0 ; i < earned.size(); i++){
        if(earned[i] == -1 && A[i] != 0){
            cout << -1;
            return;
        }
        result.push_back(A[i] == 0 ? 0 : earned[i]);
    }
    sort(result.rbegin(), result.rend());

    long long sum = 0;

    for(int i = 0; i< X; i++){
        sum += result[i];
    }

    cout << sum;
}

int main(){
    insert();
    solve();
    print();
}