//2023-02-18 00:09:20 start


#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include <math.h>

using namespace std;

bool isNotAsign(int value[10]){
    for(int i =0; i<10;i++){
        if(value[i] == -1) return true;
    }
    return false;
}
int countZeroNumber(int zeroWhiteList[10]){
    int count=0;
    for(int i = 0; i < 10;i++){
        if(zeroWhiteList[i]==0)count++;
    }
    return count;
}
int findZeroCanNumber(int zeroWhiteList[10]){
    for(int i = 0; i < 10;i++){
        if(zeroWhiteList[i]==0)return i;
    }
    return -1;
}

int findBestNumber(int score[10][13]){
    vector<int> allList;
    for(int i = 0; i< 10;i++){
        allList.push_back(i);
    }
    for(int i =12; i>=0; i--){
        int maxCount = 0;
        vector<int> maxCountList;

        for(int j = 0;j<allList.size();j++){
            if(maxCount < score[allList[j]][i]){
                maxCount = score[allList[j]][i];
                maxCountList.clear();
                maxCountList.push_back(allList[j]);
            }else if(maxCount == score[allList[j]][i]){
                maxCountList.push_back(allList[j]);
            }
        }
        allList = maxCountList;
    }
    return allList[0];
}

int main(){
    int n;

    cin >>n;
    string s[n];

    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    int score[10][13]={0,};
    int zeroWhiteList[10]={0,};
    bool isUseAlpha[10] = {false};

    for(int i = 0;i < n;i++){
        zeroWhiteList[s[i][0]-'A']=1;
        for(int j = 0; j< s[i].length();j++){
            score[s[i][j]-'A'][s[i].length()-j]++;
            isUseAlpha[s[i][j]-'A'] = true;
        }
    }

    for(int i = 0; i < 10;i++){
        for(int j = 0 ; j < 12;j++){
            while(score[i][j] >= 10){
                score[i][j+1]++;
                score[i][j]-=10;
            }
        }
    }

    int isAllUseAlpha = true;
    for(int i = 0; i< 10; i++){
        if(isUseAlpha[i] == false){
            isAllUseAlpha = false;
        }
    }
    int value[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int nowValue = 9;
    memset(value,-1,sizeof(value)/sizeof(int));
    while(isNotAsign(value)){
        int alphaNum = findBestNumber(score);
        if(isAllUseAlpha && countZeroNumber(zeroWhiteList) == 1){//10개의 알파벳이 모두 사용중일 때 검사하도록 로직 수정
            alphaNum = findZeroCanNumber(zeroWhiteList);
            for(int i = 0; i < 13; i++){
                score[alphaNum][i]= -1;
            }
            value[alphaNum] = 0;
            zeroWhiteList[alphaNum]=1;
            continue;
        }
        for(int i = 0; i < 13; i++){
            score[alphaNum][i]= -1;
        }
        zeroWhiteList[alphaNum] = 1;
        value[alphaNum] = nowValue--;
    }

    long long sum = 0;

    for(int i = 0; i < n; i++){
        int maxIndex = s[i].length()-1;
        for(int j = 0; j < s[i].length();j++){
            sum +=pow(10,j)*value[s[i][maxIndex-j]-'A'];
        }
    }

    cout << sum;
}