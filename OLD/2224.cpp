#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[200][200] = {0,};


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    
    cin >> N;
    cin.ignore();

    for(int i = 0 ; i < N; i++){
        string s;
        vector<char> temp;
        getline(cin, s);
        
        char from = s[0];
        char to = s[s.length()-1];
        arr[from][to] = 1;
    }

    for(int k = 'A' ; k < 'z'+1; k++){
        for(int i = 'A' ; i < 'z'+1; i++){
            if(i == k)continue;
            for(int j = 'A' ; j < 'z'+1; j++){
                if(i == j)continue;
                if(j == k)continue;

                arr[i][j] = arr[i][j] || (arr[i][k] == 1 && arr[k][j]);
            }
        }
    }
    int count = 0;

    for(int i = 'A' ; i < 'z'+1; i++){
        for(int j = 'A' ; j < 'z'+1; j++){
            if(i == j)continue;
            if(arr[i][j] == 1){
                count++;
            }
        }
    }
    cout << count << endl;

    for(int i = 'A' ; i < 'z'+1; i++){
        for(int j = 'A' ; j < 'z'+1; j++){
            if(i == j)continue;
            if(arr[i][j] == 1){
                cout << (char)i << " => " << (char)j << endl;
            }
        }
    }


}