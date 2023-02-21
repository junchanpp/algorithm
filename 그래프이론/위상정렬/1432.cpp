//2023-02-19 23:28:00 start

#include<iostream>
#include<string>
#include<vector>
#include<queue>


using namespace std;

int n;
vector<int> v[51];
vector<int> vReverse[51];
bool arr[51][51];// cycle 확인용
int indegree[51]={0,};
int outdegree[51]={0,};
int value[51];




priority_queue<int,vector<int>,greater<int> > pq;
priority_queue<int,vector<int>,less<int> > pqLess;

int main(){
    cin >> n;

    for(int i = 0; i <n;i++){
        value[i]=i+1;
    }

    string s;

    for(int i =0; i< n; i++){
        cin >> s;
        for(int j =0 ; j < n;j++){
            if(s[j]=='1'){v[i].push_back(j);vReverse[j].push_back(i);indegree[j]++;outdegree[i]++;}
            arr[i][j] = s[j]-'0';
        }
    }

    for(int i =0; i< n;i++){
        for(int j=0;j<n;j++){
            for(int k= 0; k <n;k++){
                if(arr[i][j] == true && arr[j][k] == true){
                    if(i==k){
                        cout << -1 << endl;
                        return 0;
                    }
                    arr[i][k] = true;
                }
            }
        }
        if(indegree[i]==0)pq.push(i);
    }//사이클 검사 끝

    while(!pq.empty()){
        int index = pq.top();
        pq.pop();

        for(vector<int>::iterator iter = v[index].begin(); iter != v[index].end();iter++){
            int nextIndex = *iter;
            indegree[nextIndex]--;

            if(indegree[nextIndex] == 0){
                pq.push(nextIndex);
            }
        }
    }
    for(int i =0 ; i< n;i++){
        if(outdegree[i]==0)pqLess.push(i);
    }


    int number = n;
    while(!pqLess.empty()){
        int index = pqLess.top();
        pqLess.pop();
        value[index] = number--;
        for(vector<int>::iterator iter = vReverse[index].begin(); iter != vReverse[index].end();iter++){
            int nextIndex = *iter;
            outdegree[nextIndex]--;

            if(outdegree[nextIndex] == 0){
                pqLess.push(nextIndex);
            }
        }
    }

    for(int i =0; i< n;i++){
        cout << value[i] << " " ;
    }
    return 0;
}