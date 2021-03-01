#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int elec;
    cin >> elec;
    if (elec >= 401)
        printf("%.1f", 150*0.4463+250*0.4663+(elec-400)*0.5663);
    else if(elec >= 151)
        printf("%.1f", 150*0.4463+(elec-150)*0.4663);
    else
        printf("%.1f", elec*0.4463);
    system("pause");
    return 0;
}