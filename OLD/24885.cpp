#include<iostream>
#include<vector>

using namespace std;

int N,M,K;
vector<int> inputs;

int main(){
    cin >> N >> M >> K;
    inputs.assign(N,0);
    for(int i = 0; i<N;i++){
        cin >>inputs[i];
    }

    vector<int> stocks;
    if(inputs[0] < inputs[1]){
        stocks.push_back(inputs[0]);
    }
    for(int i = 1 ; i < N - 1; i++){
        bool isIncreased = inputs[i-1] < inputs[i] && inputs[i] < inputs[i+1];
        bool isDecreased = inputs[i-1] > inputs[i] && inputs[i] > inputs[i+1];
        bool isPoint = !isIncreased && !isDecreased; 
        if(isPoint){
            sotcks.push_back(inputs[i]);
        }
    }
    if(inputs[N-2] < inputs[N-1]){
        stocks.push_back(inputs[N-1]);
    }


    int maxMoney = M;

    int nowMoney = M;
    int amount = 0;
    int debt = 0;

    for(int i = 0; i < stocks.size(); i++){
        if(maxMoney < nowMoney + amount * stocks[i]){
            maxMoney = nowMoney + amount * stocks[i];
        }

        if(i == N-1){
            break;
        }

        if(stocks[i] < stocks[i+1] && debt == 0){

        } else if(stocks[i] > stocks[i+1]){
            if(debt == 0){

            } else {
                

            }
        }


    }

    cout << maxMoney;

}