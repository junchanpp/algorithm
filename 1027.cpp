#include <iostream>
#include <algorithm>
using namespace std;

int n;
int building[51];
int x, ans, cnt;
double gradient, temp;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &building[i]);

    for (int i = 1; i <= n; i++)
    {
        cnt = 0;

        temp = 1000000001;
        for (int j = i - 1; j >= 1; j--)
        {
            gradient = (building[i] - building[j]) / ((double)i - (double)j);
            if (gradient < temp)
            {
                cnt++;
                temp = gradient;
            }
        }

        temp = -1000000001;
        for (int j = i + 1; j <= n; j++)
        {
            gradient = (building[j] - building[i]) / ((double)j - (double)i);
            if (gradient > temp)
            {
                cnt++;
                temp = gradient;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}