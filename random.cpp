#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    string problemVector[] = {
        "https://www.acmicpc.net/problem/2133",
        "https://www.acmicpc.net/problem/1915",
        "https://www.acmicpc.net/problem/11049",
        "https://www.acmicpc.net/problem/1006",
        "https://www.acmicpc.net/problem/11000",
        "https://www.acmicpc.net/problem/2437",
        "https://www.acmicpc.net/problem/3687",
        "https://www.acmicpc.net/problem/1071",
        "https://www.acmicpc.net/problem/2436",
        "https://www.acmicpc.net/problem/1287",
        "https://www.acmicpc.net/problem/9254",
        "https://www.acmicpc.net/problem/22940",
        "https://www.acmicpc.net/problem/7576",
        "https://www.acmicpc.net/problem/7569",
        "https://www.acmicpc.net/problem/16236",
        "https://www.acmicpc.net/problem/9376",
        "https://www.acmicpc.net/problem/1987",
        "https://www.acmicpc.net/problem/14942",
        "https://www.acmicpc.net/problem/2590",
        "https://www.acmicpc.net/problem/20149",
        "https://www.acmicpc.net/problem/2339",
        "https://www.acmicpc.net/problem/14600",
        "https://www.acmicpc.net/problem/17384",
        "https://www.acmicpc.net/problem/14727",
        "https://www.acmicpc.net/problem/1725",
        "https://www.acmicpc.net/problem/15999",
        "https://www.acmicpc.net/problem/11401",
        "https://www.acmicpc.net/problem/1533",
        "https://www.acmicpc.net/problem/2086",
        "https://www.acmicpc.net/problem/11442",
        "https://www.acmicpc.net/problem/11443",
        "https://www.acmicpc.net/problem/15712",
        "https://www.acmicpc.net/problem/10165",
        "https://www.acmicpc.net/problem/10868",
        "https://www.acmicpc.net/problem/2170",
        "https://www.acmicpc.net/problem/15922",
        "https://www.acmicpc.net/problem/16474",
        "https://www.acmicpc.net/problem/2836",
        "https://www.acmicpc.net/problem/1916",
        "https://www.acmicpc.net/problem/1753",
        "https://www.acmicpc.net/problem/2239"};

    srand(time(NULL));
    int index = rand() % problemVector->length();
    cout << problemVector[index] << "" << endl;
    
}