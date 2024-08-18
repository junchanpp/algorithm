#include <iostream>
#include <vector>

using namespace std;

int map[9][9] = {0,};

bool isIncludeRowNumbers[9][10];
bool isIncludeColumnNumbers[9][10];
bool isInclude3by3Numbers[9][10];



void fill(int r, int c, int num){
    map[r][c] = num;
    isIncludeRowNumbers[r][num] = 1;
    isIncludeColumnNumbers[c][num] = 1;
    isInclude3by3Numbers[(r/3) * 3 + (c / 3)][num] = 1;
}

bool canInsert(int i, int j, int num){
    int newJ = j >= 6 ? 6 : j >= 3 ? 3 : 0;
    int newI = i >= 6 ? 6 : i >= 3 ? 3 : 0;

    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3; b++){
            if(i == newI + a && j == newJ + b){
                continue;
            }
            if(map[newI+a][newJ+b] == 0  && !isIncludeRowNumbers[newI+a][num] && !isIncludeColumnNumbers[newJ + b][num]){
                return false;
            }
        }
    }
    
    return !isIncludeColumnNumbers[j][num] && !isIncludeRowNumbers[i][num];
}


bool isRowCorrect(){
    for(int a = 0; a < 9; a++){
        bool isInclude[10] = {0,};
        for(int i = 0 ; i < 9; i++){
            if(map[a][i] == 0){
                continue;
            }
            if(isInclude[map[a][i]]){
                return false;
            }
            isInclude[map[a][i]] = 1;
        }
    }
    return true;
}

bool isColumnCorrect(){
    for(int a = 0; a < 9; a++){
        bool isInclude[10] = {0,};
        for(int i = 0 ; i < 9; i++){
            if(map[i][a] == 0){
                continue;
            }
            if(isInclude[map[i][a]]){
                return false;
            }
            isInclude[map[i][a]] = 1;
        }
    }
    return true;
}

bool is3by3Correct(){
    for(int a = 0; a < 9; a++){
        bool isInclude[10] = {0,};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int r = i + (a % 3) * 3;
                int c = j + (a / 3) * 3;
                if(map[r][c] == 0){
                    continue;
                }
                if(isInclude[map[r][c]]){
                    return false;
                }
                isInclude[map[r][c]] = 1;
            }
        }
    }

    return true;
}

//각 사분면에서 채워지지 않은 칸에 1~9까지 다 넣어보고 안 넣어지는 수가 있으면 false
bool isAllInsertable(){
    for(int a = 0; a < 9; a++){
        for(int num = 1; num <= 9; num++){
            if(isInclude3by3Numbers[a][num]){
                continue;
            }
            
            bool canBeInserted = false;
            for(int i = (a / 3) * 3; i < (a / 3)*3+3; i++){
                for(int j = (a % 3) * 3; j < (a % 3)*3+3; j++){
                    if(map[i][j] == 0 && !isIncludeRowNumbers[i][num] && !isIncludeColumnNumbers[j][num]){
                        canBeInserted = true;
                        break;
                    }
                }
                if(canBeInserted) break;
            }
            
            if(!canBeInserted){
                return false;
            }
        }
    }
    
    return true;
}

bool isAllCorrect(){
    return isRowCorrect() && isColumnCorrect() && is3by3Correct() && isAllInsertable();
}
int main(){
    int emptyCount = 0;
    for(int i = 0; i < 9; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++){
            if(s[j] =='.' ){
                emptyCount++;
            } else {
                int num = s[j] - '0';
                fill(i,j,num);
            }
        }
    }

    while(emptyCount != 0){
        bool isFilled = false;

        for(int num = 1; num <= 9; num++){
            for(int a = 0; a < 9; a++){//사분면
                if(isInclude3by3Numbers[a][num]){
                    continue;
                }
                
                vector<pair<int,int> > points;
                bool isAlreadyInclude = false;
                for(int i = (a / 3) * 3; i < (a / 3)*3+3; i++){
                    for(int j = (a % 3) * 3; j < (a % 3)*3+3; j++){
                        if(map[i][j] != 0){
                            continue;
                        }
                        if(canInsert(i,j,num)){
                            points.push_back(make_pair(i,j));
                        }
                    }
                }
                if(points.size() == 1){
                    isFilled = true;
                    fill(points[0].first, points[0].second, num);
                    emptyCount--;
                }

            }
        }

        if(!isFilled){
            break;
        }
    }

    if(isAllCorrect()){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9; j++){
                cout << (char)(map[i][j] == 0 ? '.' : (map[i][j] + '0'));
            }
            cout << '\n';
        }
    }else {
        cout << "ERROR\n";
    }
}