#include<iostream>
#define max(a,b) a > b ? a : b

using namespace std;
 
int n;
int ans[2];
int chess[11][11];
int l[20];
int r[20];
 
 
void tracking(int row, int col, int count, int color)
{
    if (col >= n) {
        row++;
        if(col%2 == 0) col = 1;
        else col = 0;
    }
    if (row >= n) {
        ans[color] = max(ans[color], count);
        return;
    }
 
    if (chess[row][col] && !l[col - row + n - 1] && !r[row + col])
    {
        l[col - row + n - 1] = r[row + col] = 1;
        tracking(row, col+2, count + 1, color);
        l[col - row + n - 1] = r[row + col] = 0;
    }
    tracking(row, col+2, count, color);
}
 
int main(void)
{
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> chess[i][j];
        }
    }
 
    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);
 
    cout << ans[0] + ans[1];
 
    return 0;
}