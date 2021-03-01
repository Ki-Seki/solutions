#include <iostream>

using namespace std;

int main()
{
    int reachable_count = 0, height, apple_h[10];
    for(int i=0; i<10; i++)
    {
        cin >> apple_h[i];
    }
    cin >> height;
    height += 30;
    for(int i=0; i<10; i++)
    {
        if (height >= apple_h[i])
        {
            reachable_count++;
        }
    }
    cout << reachable_count;
    return 0;
}