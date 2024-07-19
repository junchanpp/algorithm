#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <set>

using namespace std;
bool edge[300][300];
unsigned char inDegree[300];
int n;
priority_queue<int,vector<int> ,greater<int> > pq;
deque<int> answer;


void dfs(int startNode, int endNode){
    inDegree[startNode] = 0;//시작지점은 모두 단방향으로 판단

    pq.push(startNode);
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        answer.push_back(node);

        for(int i = node+1; i<= endNode; i++){
            if(edge[node][i] == true){
                inDegree[i]--;
                if(inDegree[i]==0){
                    pq.push(i);
                }
            }
        }

    }

}

int countIntersection(deque<unsigned char>& A, deque<unsigned char>& B) {
    int count = 0;
    unsigned char i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            count++;
            i++;
            j++;
        }
    }
    return count;
}

deque<unsigned char> mergeUnique(deque<unsigned char>& vec1, deque<unsigned char>& vec2) {
    set<unsigned char> s;
    for (unsigned char n : vec1) {
        s.insert(n);
    }
    for (unsigned char n : vec2) {
        s.insert(n);
    }
    deque<unsigned char> result(s.begin(), s.end());
    return result;
}
deque<unsigned char> reverseConcat(deque<unsigned char>& a, deque<unsigned char>& b) {
    deque<unsigned char> result;
    for (int i = 0; i < a.size(); i++) {
        result.push_back(a[i]);
    }

    for (int i = b.size() - 2; i >= 0; i--) {
        result.push_back(b[i]);
    }

    return result;
}

int main (){
    cin >>n;

    while(1){
        int p,q;
        cin >> p >> q;
        if(p==0 && q== 0)break;
        edge[p][q] = true;
        inDegree[q]++;
    }

    dfs(1,n);

    register deque<deque<unsigned char> > path;//1부터 n까지 가는 모든 경로 저장
    deque<deque<unsigned char> > mainPath;

    deque<unsigned char> a;
    a.push_back(0);

    path.push_back(a);

    for(int i =1 ; i<answer.size();i++){
        int end = path.size();
        for(int j =0;j <end;j++){
            if(edge[(path[j]).back()+1][answer[i]]==1){
                deque<unsigned char> temp(path[j]);
                temp.push_back(answer[i]-1);

                if(temp.back()==n-1){
                    mainPath.push_back(temp);
                    continue;
                }
                path.push_back(temp);
            }
        }
    }
    path.clear();

    if(mainPath.empty()){
        cout << 0 ;
        return 0;
    }

    deque<unsigned char> longestPath;

    for(int i =0; i< mainPath.size();i++){
        for(int j =i+1; j< mainPath.size();j++){
            if(countIntersection(mainPath[i], mainPath[j]) == 2){
                deque<unsigned char> temp = reverseConcat(mainPath[i],mainPath[j]);
                if(temp.size() > longestPath.size()){
                    longestPath = temp;
                }
            }
        }
    }

    cout << longestPath.size()-1 << endl;
    for(int i =0; i< longestPath.size();i++){
        cout << longestPath[i]+1 << " ";
    }
}