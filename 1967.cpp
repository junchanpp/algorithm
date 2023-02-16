#include <iostream>
#include <vector>

using namespace std;

typedef struct Edge
{
    int parentNode;
    int childNode;
    int distance;
} Edge;

int n;
Edge edge[4];
int maxNum = 0;

int calculateDiameter(int node, int startIndex, int distance);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &edge[i].parentNode, &edge[i].childNode, &edge[i].distance);
    }
    calculateDiameter(1, 0, 0);
    printf("%d", maxNum);
}

int calculateDiameter(int node, int startIndex, int distance)
{
    int nextStartIndex;
    vector<int> distanceList;

    for (nextStartIndex = startIndex; nextStartIndex < n && (node >= edge[nextStartIndex].parentNode); nextStartIndex++)
    {
        if (node == edge[nextStartIndex].parentNode)
        {
            int dis = calculateDiameter(edge[nextStartIndex].childNode, nextStartIndex, edge[nextStartIndex].distance);
            distanceList.push_back(dis);
        }
    }

    if (distanceList.empty())
    {
        return distance;
    }
    int maxDis = 0, max2Dis = 0;
    for (int i = 0; i < distanceList.size(); i++)
    {
        if (maxDis < distanceList[i])
        {
            max2Dis = maxDis;
            maxDis = distanceList[i];
        }
        else if (max2Dis < distanceList[i])
        {
            max2Dis = distanceList[i];
        }
    }
    if (maxNum < maxDis + max2Dis)
    {
        maxNum = maxDis + max2Dis;
    }
    return maxDis + distance;
}