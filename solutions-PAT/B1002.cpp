#include <iostream>
#include <cstring>
#define MAXN 105
using namespace std;

int main()
{
    char number[MAXN], trans[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    scanf("%s", number);
    int len = strlen(number), sum = 0;
    for (int i = 0; i < len; i++)
        sum += number[i] - '0';
    
    // due to the sum < 1000, there is no need to calculate the digit of var. sum
    if (0 <= sum && sum <= 9) printf("%s", trans[sum]);
    if (10 <= sum && sum <= 99) printf("%s %s", trans[sum/10], trans[sum%10]);
    if (100 <= sum && sum <= 999) printf("%s %s %s", trans[sum/100], trans[sum/10%10], trans[sum%10]);
    return 0;
}