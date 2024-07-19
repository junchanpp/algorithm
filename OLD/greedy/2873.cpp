#include <iostream>
#include <string>

using namespace std;

const int MAX_R = 1000;
const int MAX_C = 1000;

int R, C;
int A[MAX_R][MAX_C];
string answer = "";

void append(int r, int c, char dir) {
    for (int i = 0; i < r; i++) {
        answer += dir;
    }
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    if (R % 2 == 1) {
        for (int i = 0; i < R; i++) {
            if (i % 2 == 0) {
                append(C - 1, 'R');
            } else {
                append(C - 1, 'L');
            }
            if (i != R - 1) {
                append(1, 'D');
            }
        }
    } else if (C % 2 == 1) {
        for (int j = 0; j < C; j++) {
            if (j % 2 == 0) {
                append(R - 1, 'D');
            } else {
                append(R - 1, 'U');
            }
            if (j != C - 1) {
                append(1, 'R');
            }
        }
    } else {
        int min_i = 0, min_j = 1;
        for (int i = 0; i < R; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < C; j++) {
                    if (j % 2 == 1 && A[i][j] < A[min_i][min_j]) {
                        min_i = i;
                        min_j = j;
                    }
                }
            } else {
                for (int j = C - 1; j >= 0; j--) {
                    if (j % 2 == 1 && A[i][j] < A[min_i][min_j]) {
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }

        int cur_i = 0, cur_j = 0;
        while (cur_i < min_i) {
            append(C - 1, 'R');
            append(1, 'D');
            append(C - 1, 'L');
            append(1, 'D');
            cur_i += 2;
        }
        while (cur_j < min_j) {
            append(1, 'D');
            append(1, 'R');
            append(1, 'U');
            append(1, 'R');
            cur_j += 2;
        }
        while (cur_i < R - 2) {
            append(C - 1, 'R');
            append(1, 'U');
            append(C - 1, 'L');
            append(1, 'U');
            cur_i += 2;
        }
        while (cur_j < C - 2) {
            append(1, 'R');
            append(1, 'U');
            append(1, 'L');
            append(1, 'U');
            cur_j += 2;
        }
        if (min_j % 2 == 1) {
            append(1, 'R');
           
