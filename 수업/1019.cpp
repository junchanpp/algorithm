#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<int> v[N+1];
    set<int> C;
    for(int i = 1 ; i <= N ; i++){//입력받기, 정답 출력을 쉽게 하기 위해 1부터 시작
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        while(ss>>word){
            v[i].push_back(stoi(word));
            C.insert(stoi(word));
        }
    }

    set<int> answer;
    while(!C.empty()){//C가 공백일 때까지 반복문
    
        int maxIndex = 0;
        int count = 0;
        for(int i = 1 ; i<=N; i++){
            if(answer.find(i) != answer.end()){//정답목록에 이미 있는 인덱스면 continue
                continue;
            }

            int nowCount = 0;
            for(vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++){//현재 C에 포함된 원소 개수 계산
                if(C.find(*iter) != C.end()){
                    nowCount++;
                }
            }
            
            if(nowCount > count){//현재 v[i]에 대해서 포함된 원소가 가장 많으면 maxIndex를 i로 초기화
                maxIndex = i;
                count = nowCount;
            }
        }

        answer.insert(maxIndex);//가장 많이 포함된 i를 지정
        for(vector<int>::iterator iter = v[maxIndex].begin(); iter != v[maxIndex].end(); iter++){//v[i]에 있는 원소들 C에서 제거
            set<int>::iterator deleteIter;
            if((deleteIter = C.find(*iter))!=C.end()){//C에 있는 것만 제거
                C.erase(deleteIter);
            }
        }   
    }

    for(set<int>::iterator iter = answer.begin(); iter != answer.end();iter++){// 정답 출력
        cout << *iter << " ";
    }
}