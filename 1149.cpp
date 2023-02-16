#include <iostream>
#include <algorithm>

using namespace std;

typedef struct House
{
    int costRed;
    int costGreen;
    int costBlue;
} House;

int houseNum;
House houseArr[1010];

// i번째가 빨강일 때 i~n까지 최소비용
int costMemoizationRed[1010] = {
    0,
};

// i번째가 초록일 때 i~n까지 최소비용
int costMemoizationGreen[1010] = {
    0,
};

// i번째가 파랑일 때 i~n까지 최소비용
int costMemoizationBlue[1010] = {
    0,
};

int calculateMinimumCost(int, char);

int main()
{
    scanf("%d", &houseNum);
    for (int i = 0; i < houseNum; i++)
    {
        scanf("%d %d %d", &houseArr[i].costRed, &houseArr[i].costGreen, &houseArr[i].costBlue);
    }

    int cost = calculateMinimumCost(0, 'R');
    cost = min(calculateMinimumCost(0, 'G'), cost);
    cost = min(calculateMinimumCost(0, 'B'), cost);

    cout << cost;
}

int calculateMinimumCost(int i, char selectedColor)
{
    //만약 끝에 도달했을 때,
    if (i == houseNum - 1)
    {
        if (selectedColor == 'R')
        {
            return houseArr[i].costRed;
        }
        else if (selectedColor == 'G')
        {
            return houseArr[i].costGreen;
        }
        else
        {
            return houseArr[i].costBlue;
        }
    }

    if (selectedColor == 'R' && costMemoizationRed[i] != 0)
    {
        return costMemoizationRed[i];
    }
    if (selectedColor == 'G' && costMemoizationGreen[i] != 0)
    {
        return costMemoizationGreen[i];
    }
    if (selectedColor == 'B' && costMemoizationBlue[i] != 0)
    {
        return costMemoizationBlue[i];
    }

    int costMin;

    if (selectedColor == 'R')
    {
        costMin = min((calculateMinimumCost(i + 1, 'G') + houseArr[i].costRed), (calculateMinimumCost(i + 1, 'B') + houseArr[i].costRed));
        costMemoizationRed[i] = costMin;
    }
    else if (selectedColor == 'G')
    {
        costMin = min((calculateMinimumCost(i + 1, 'R') + houseArr[i].costGreen), (calculateMinimumCost(i + 1, 'B') + houseArr[i].costGreen));
        costMemoizationGreen[i] = costMin;
    }
    else if (selectedColor == 'B')
    {
        costMin = min(calculateMinimumCost(i + 1, 'G') + houseArr[i].costBlue, calculateMinimumCost(i + 1, 'R') + houseArr[i].costBlue);
        costMemoizationBlue[i] = costMin;
    }

    return costMin;
}