#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> input1;
    vector<int> input2;
    priority_queue<pair<int, int> > pq1;//남은개수, 인덱스(열 기준)
    priority_queue<pair<int, int> > pq2;//남은개수, 인덱스(열 기준)
    vector<vector<int> > answers;

    cin >> n;

    input1.assign(n,0);
    input2.assign(n,0);
    answers.assign(n, vector<int>(n,0));

    for(int i = 0 ; i < n; i++){
        cin >> input1[i];
    }

    for(int i = 0 ; i < n; i++){
        cin >> input2[i];
    }


    for(int i = 0 ; i < n ; i++){
        if(input1[i] > 0){
            pq1.push(make_pair(input1[i],i));
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(input2[i] > 0){
            pq2.push(make_pair(input2[i],i));
        }
    }

    while(!pq1.empty()){
        int size = pq1.top().first;
        int baseIndex = pq1.top().second;
        pq1.pop();
        vector<pair<int, int> > usedList;
        for(int j = 0; j < size; j++){
            if(pq2.empty()){
                cout << -1;
                return 0;
            }
            int index = pq2.top().second;
            int count = pq2.top().first-1;
            pq2.pop();

            usedList.push_back(make_pair(count, index));
            answers[baseIndex][index] = 1;
        }
        for(int j = 0; j < usedList.size(); j++){
            if(usedList[j].first > 0){
                pq2.push(usedList[j]);
            }
        }
    }

    if(!pq2.empty()){
        cout << -1;
        return 0;
    }

    cout << "1\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << answers[i][j];
        }
        cout << '\n';
    }

    return 0;
}