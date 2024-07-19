#include <iostream>
#include <utility>

using namespace std;

int n;
int arr[51];
int s;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &s);

    for (int i = 0; i < n; i++)
    {
        int maxNumIndex = i;
        int end = i + s + 1 > n ? n : i + s + 1;
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] > arr[maxNumIndex])
            {
                maxNumIndex = j;
            }
        }

        if (maxNumIndex != i)
        {
            for (int j = maxNumIndex - 1; j >= i; j--)
            {
                swap(arr[j], arr[j + 1]);
            }
            s = s - (maxNumIndex - i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
