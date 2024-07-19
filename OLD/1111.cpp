#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, arr[55];
    vector<int> ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (n == 1)
    {
        cout << "A";
        return 0;
    }
    if (n == 2)
    {
        if (arr[0] == arr[1])
            cout << arr[0];
        else
            cout << "A";
        return 0;
    }
    int a, b;
    if (arr[1] == arr[0])
        a = 0;
    else
        a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

    b = arr[1] - a * arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (!(arr[i] * a + b == arr[i + 1]))
        {
            cout << "B";
            return 0;
        }
    }
    cout << a * arr[n - 1] + b;
}