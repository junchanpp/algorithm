#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int notColorWeak(int N, vector<vector<char> > arr);
int colorWeak(int N, vector<vector<char> > arr);


int main(){
    int N;
    cin >> N;
    vector<vector<char> > arr(N,vector<char>(N));
    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            arr[i][j] = s[j];
        }
    }

    cout << notColorWeak(N, arr) << " " << colorWeak(N, arr) << endl;
}

vector<vector<bool> > visited;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};




int notColorWeak(int N, vector<vector<char> > arr){
    visited.assign(N,vector<bool>(N,false));
    int count = 0;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(visited[i][j]){
                continue;
            }
            count++;

            queue<pair<int, int> > q;
            q.push(make_pair(i,j));

            char color = arr[i][j];
            visited[i][j] = true;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int a = 0 ; a < 4; a++){
                    if(x+dx[a] < 0 || y+dy[a] < 0 || x+dx[a] >= N || y+dy[a] >= N){
                        continue;
                    }
                    if(visited[x+ dx[a]][y+dy[a]]){
                        continue;
                    }
                    if((color == 'G') && (arr[x+ dx[a]][y+dy[a]] == 'G')){
                        q.push(make_pair(x+dx[a],y+dy[a]));
                        visited[x+ dx[a]][y+dy[a]] = true;
                    } else if (color == 'R' &&  arr[x+ dx[a]][y+dy[a]] == 'R') {
                        q.push(make_pair(x+dx[a],y+dy[a]));
                        visited[x+ dx[a]][y+dy[a]] = true;
                    } else if(color == 'B' && arr[x+ dx[a]][y+dy[a]] == 'B'){
                        q.push(make_pair(x+dx[a],y+dy[a]));
                        visited[x+ dx[a]][y+dy[a]] = true;
                    }
                }
            }
        }
    }
    return count;
}

int colorWeak(int N, vector<vector<char> > arr){
    visited.assign(N,vector<bool>(N,false));
    int count = 0;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(visited[i][j]){
                continue;
            }
            count++;

            queue<pair<int, int> > q;
            q.push(make_pair(i,j));

            char color = arr[i][j];
            visited[i][j] = true;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int a = 0 ; a < 4; a++){
                    if(x+dx[a] < 0 || y+dy[a] < 0 || x+dx[a] >= N || y+dy[a] >= N){
                        continue;
                    }
                    if(visited[x+ dx[a]][y+dy[a]]){
                        continue;
                    }
                    if((color == 'G' || color == 'R') && (arr[x+ dx[a]][y+dy[a]] == 'G' || arr[x+ dx[a]][y+dy[a]] == 'R')){
                        q.push(make_pair(x+dx[a],y+dy[a]));
                        visited[x+ dx[a]][y+dy[a]] = true;
                    } else if(color == 'B' && arr[x+ dx[a]][y+dy[a]] == 'B'){
                        q.push(make_pair(x+dx[a],y+dy[a]));
                        visited[x+ dx[a]][y+dy[a]] = true;
                    }
                }
            }
        }
    }
    return count;
}