#include <iostream>
#include <string>
using namespace std;
int abc[30]= {};

bool is_prime(int a)
{
    if (a == 1 || a == 0) return false;
    for (int i = 2; i * i <= a + 1; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        abc[s[i]-'a']++;
    int max=-1, min=1000;
    for (int i = 0; i < 30; i++)
    {
        if (abc[i] > max) max = abc[i];
        if (abc[i] != 0 && abc[i] < min) min = abc[i];
    }
    int diff = max - min;
    if (is_prime(diff)) printf("Lucky Word\n%d", diff);
    else printf("No Answer\n0");
    return 0;
}