#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    float index = 1;
    cin >> n;
    for(int line=1; line<n+1; line++)
    {
        for (int row = 0; row < n-line+1; row++)
        {
            printf("%02.0f", index++);
        }
        cout << endl;
    }
    return 0;
}
