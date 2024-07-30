#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> S;
vector<pair<long long, pair<int ,int> > > v1;// {a+b, {a,b}}
vector<pair<long long, pair<int ,int> > > v2;// {d-c, {c, d}}

bool isAllDeferent(int a, int b, int c, int d){
    if(a==b || a==c || a==d || b == c || b == d || c== d){
        return false;
    }

    return true;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while(1){
        cin >> N;
        if(N == 0){
            return 0;
        }
        v1.clear();
        v2.clear();
        S.clear();
        S.assign(N, 0);
        for(int i = 0; i < N; i++){
            cin >> S[i];
        }

        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                v1.push_back(make_pair(S[i] + S[j], make_pair(S[i], S[j])));
                v2.push_back(make_pair(S[j] - S[i], make_pair(S[i], S[j])));
                v2.push_back(make_pair(S[i] - S[j], make_pair(S[j], S[i])));
            }
        }

        sort(v1.rbegin(), v1.rend());
        sort(v2.rbegin(), v2.rend());

        int v1Index = 0;
        int v2Index = 0;
        bool isFind = false;
        vector<long long> answers;
        while(v1Index < v1.size() && v2Index < v2.size()){
            if(v1[v1Index].first == v2[v2Index].first && isAllDeferent(v1[v1Index].second.first, v1[v1Index].second.second,v2[v2Index].second.first, v2[v2Index].second.second)){
                answers.push_back(v2[v2Index].second.second);
                isFind = true;
            }

            if(v1[v1Index].first > v2[v2Index].first){
                v1Index++;
            }else {
                v2Index++;
            }
        }

        if(isFind){
            sort(answers.rbegin(), answers.rend());
            cout << answers[0] << '\n';
        }else {
            cout << "no solution\n";
        }
    }


    
}