#include <iostream>

using namespace std;

char arr[10][110];

void monkey(int partition, int index, int count);

int main()
{
    int n;
    cin >> n;
    monkey(n, 0, 0);

    for (int i = 0; i < 7; i++)
    {
        bool isAllA = true;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 'A')
                isAllA = false;
            if (j == n - 1 && isAllA == true)
            {
                printf("B");
            }
            else
            {
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void monkey(int partition, int index, int count)
{
    if (count == 7)
        return;

    int aNum = partition % 2 == 0 ? partition / 2 : (partition + 1) / 2;
    int bNum = partition % 2 == 0 ? partition / 2 : (partition - 1) / 2;

    for (int i = index; i < index + aNum; i++)
    {
        arr[count][i] = 'A';
        monkey(aNum, index, count + 1);
    }
    for (int i = index + aNum; i < index + partition; i++)
    {
        arr[count][i] = 'B';

        monkey(bNum, index + aNum, count + 1);
    }
}