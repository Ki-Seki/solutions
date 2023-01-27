/*
 * hint:
 * 使用 getline() 时，要用 getchar() 或其他清除 '\n' 影响
*/
#include <iostream>
#include <map>
#define RADIX 13
#define MAXN 190
using namespace std;

string times13[RADIX] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string earth2mars[MAXN] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
map <string, int> mars2earth;

void init()
{
    // init 0 ~ 12
    for (int i = 0; i <= 12; i++)
        mars2earth[earth2mars[i]] = i;

    // init 1*13 ~ 12*13
    for (int i = 1; i <= 12; i++)
    {
        earth2mars[i * 13] = times13[i];
        mars2earth[times13[i]] = i * 13;
    }

    // init others
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 12; j++)
        {
            earth2mars[i * 13 + j] = times13[i] + ' ' + earth2mars[j];
            mars2earth[earth2mars[i * 13 + j]] = i * 13 + j;
        }
}

int str2num(string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); i++)
        num = num * 10 + s[i] - '0';
    return num;
}

int main()
{
    init();
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        string s;
        getline(cin, s);
        // cout <<"##" << s << "##";
        if (s[0] <= '9')  // is Earth number, due to 'a': 97, 'A': 65
        {
            int earth = str2num(s);
            cout << earth2mars[earth] << endl;
        }
        else  // is Mars number
            cout << mars2earth[s] << endl;
    }
    return 0;
}