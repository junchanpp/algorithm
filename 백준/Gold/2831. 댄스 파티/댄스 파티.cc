#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> menTaller;
vector<int> menSmaller;
vector<int> womenTaller;
vector<int> womenSmaller;
int N;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int man;
        cin >> man;
        if(man > 0){
            menTaller.push_back(man);
        } else {
            menSmaller.push_back(man * -1);
        }
    }
    for(int i = 0 ; i < N; i++){
        int woman;
        cin >> woman;
        if(woman > 0){
            womenTaller.push_back(woman);
        } else {
            womenSmaller.push_back(woman * -1);
        }
    }

    sort(menTaller.begin(), menTaller.end());
    sort(menSmaller.begin(), menSmaller.end());
    sort(womenTaller.begin(), womenTaller.end());
    sort(womenSmaller.begin(), womenSmaller.end());

    int count = 0;

    int i = 0, j = 0;
    while(i < womenTaller.size() && j < menSmaller.size()){
        if(womenTaller[i] < menSmaller[j]){
            count++;
            i++;
            j++;
            continue;
        }
        j++;
    }

    i = 0, j = 0;
    while(i < menTaller.size() && j < womenSmaller.size()){
        if(menTaller[i] < womenSmaller[j]){
            count++;
            i++;
            j++;
            continue;
        }
        j++;
    }

    cout << count;

}