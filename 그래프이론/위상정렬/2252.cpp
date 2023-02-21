//2023-02-19 18:10:38 start
//2023-02-19 18:45:38 end


#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> edge[32001];//간선
int inDegree[32001];//진입 차수
deque<int> deq;
deque<int> answer;
int n,m;

int main(){
    cin >> n >> m;

    for(int i = 0; i< m ; i++){//입력
        register int temp1, temp2;
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        inDegree[temp2]++;
    }
    for(int i = 1; i <= n;i++){
        if(inDegree[i] == 0){// 진입차수가 0이 아니거나, 방문했던 정점은 패스
            deq.push_back(i);
        }
    }

    while(!deq.empty()){
        int value = deq.front();
        deq.pop_front();

        answer.push_back(value);

        for(vector<int>::iterator iter = edge[value].begin(); iter != edge[value].end(); iter++){
            inDegree[*iter]--;
            if(inDegree[*iter]==0){
                deq.push_back(*iter);
            }
        }
    }

    while(!answer.empty()){
        cout << answer.front() << " ";
        answer.pop_front();
    }
}