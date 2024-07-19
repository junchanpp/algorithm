#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    vector<int> S(4), R(4);
    for(int i = 0 ; i < 4; i++){
        cin >> S[i] >> R[i];
    }

    vector<pair<int, int> > original;
    for(int i = 0 ; i < 4; i++){
        original.push_back(make_pair(S[i],R[i]));
    }

    sort(R.begin(), R.end());

    bool canAllEqualSuit = true;

    int suit = S[0];
    for(int i = 0 ; i < 4; i++){
        if(S[i] != suit){
            canAllEqualSuit = false;
        }
    }


    bool canStraightRank = true;
    bool isJumped = false;
    for(int i = 0 ; i < 3; i++){
        if(R[i] != R[i+1]-1){
            if(R[i] == R[i+1]-2 && !isJumped){
                isJumped = true;
            } else {
                canStraightRank = false;
            }
        }
    }


    bool isQuadruple = false;
    bool isTriple = false;
    int pairCount = 0;
    for(int i = 0; i < 4; i++){
        int count = 1;
        for(int j = i+1; j < 4; j++){
            if(R[i] == R[j]){
                count++;
            }
        }
        if(count == 4){
            isQuadruple = true;
        }
        if(count == 3){
            isTriple = true;
        }
        if(count == 2){
            pairCount++;
        }
    }

    if(canStraightRank && canAllEqualSuit){
        cout << suit << " ";

        if(R[0]+3 != R[3]){
            for(int i = 0 ; i < 3; i++){
                if(R[i] +2 == R[i+1]){
                    cout << R[i]+1;
                    break;
                }
            }
            return 0;
        } else {
            cout << (R[3]+1 == 14 ? R[0] - 1 : R[3]+1);
            return 0;
        }

    }else if(isQuadruple){
        cout << 3 << " ";
        bool isExistSpade[14] ={0,};
        for(int i = 0; i < 4; i++){
            if(original[i].first == 3){
                isExistSpade[original[i].second] = true;
            }
        }
        if(!isExistSpade[13]){
            cout << 13;
        }else if(!isExistSpade[12]){
            cout << 12;
        }else if(!isExistSpade[11]){
            cout << 11;
        }else if(!isExistSpade[10]){
            cout << 10;
        }else {
            cout << 9;
        }
        return 0;

    }else if(isTriple){
        for(int i = 0 ; i < 4; i++){
            int count = 1;
            bool isExist[4] = {0,};
            isExist[original[i].first] = true;
            for(int j = i+1 ; j < 4; j++){
                if(original[i].second ==original[j].second){
                    count++;
                    isExist[original[j].first] = true;
                }
            }
            if(count == 3){
                for(int j = 0 ; j < 4; j++){
                    if(!isExist[j]){
                        cout << j << " ";
                        break;
                    }
                }
                cout << original[i].second;
                return 0;
            }
        }

    }else if(pairCount >= 2){
        int num = R[0] > R[1] ? R[0] :
            R[1] > R[2] ? R[1] :
            R[2] > R[3] ? R[2] : 
            R[3] > R[0] ? R[3] : 
            R[0];
        for(int i = 0 ; i < 4; i++){
            int count = 1;
            bool isExist[4] = {0,};
            isExist[original[i].first] = true;
            for(int j = i+1 ; j < 4; j++){
                if(original[i].second ==original[j].second && original[i].second == num){
                    count++;
                    isExist[original[j].first] = true;
                }
            }
            if(count == 2){
                for(int j = 0 ; j < 4; j++){
                    if(!isExist[j]){
                        cout << j << " ";
                        break;
                    }
                }
                cout << original[i].second;
                return 0;
            }
        }

    }else if(canAllEqualSuit){
        cout << original[0].first << " ";
        cout << (R[3] != 13 ? 13 :
                R[2] != 12 ? 12 :
                R[1] != 11 ? 11 :
                R[0] != 10 ? 10 :
                9);

    }else if(canStraightRank){
        cout << 3 << " ";

        if(R[0]+3 != R[3]){
            for(int i = 0 ; i < 3; i++){
                if(R[i] +2 == R[i+1]){
                    cout << (R[i]+1);
                    break;
                }
            }
            return 0;
        } else {
            cout << (R[3]+1 == 14 ? R[0]-1 : R[3]+1);
            return 0;
        }

    }else if(pairCount == 1){
       for(int i = 0 ; i < 4; i++){
            int count = 1;
            bool isExist[4] = {0,};
            isExist[original[i].first] = true;
            for(int j = i+1 ; j < 4; j++){
                if(original[i].second ==original[j].second){
                    count++;
                    isExist[original[j].first] = true;
                }
            }
            if(count == 2){
                for(int j = 0 ; j < 4; j++){
                    if(!isExist[j]){
                        cout << j << " ";
                        break;
                    }
                }
                cout << original[i].second;
                return 0;
            }
        }
    }else {
        int max = 0;
        int nowSuit = 0;
        for(int i = 0; i < 4; i++){
            if(max < original[i].second){
                max = original[i].second;
                nowSuit = original[i].first;
            }
        }

        cout << (nowSuit == 0 ? 1 : 0) << " " << max;
        
    }





}