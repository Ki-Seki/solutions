#include <iostream>
#include <cmath>
#define MAXN 10
using namespace std;
int n, ingred[MAXN][2], ans = 1e9;

// to decide whether to choose ingred[index] or not
void dfs(int index, int sour, int bitter, int choosed)
{
    if (index == n)
    {
        if (choosed > 0 && abs(sour - bitter) < ans)
            ans = abs(sour - bitter);
        return;
    }

    // not choose ingred[index]
    dfs(index+1, sour, bitter, choosed);

    // choose ingred[index]
    dfs(index+1, sour*ingred[index][0], bitter+ingred[index][1], choosed+1);
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ingred[i][0] >> ingred[i][1];
    dfs(0, 1, 0, 0);
    cout << ans << endl;
    return 0;
}