#include <iostream>

using namespace std;

void sort(int a[]);

int to_output_index(char alp);

int main()
{
    int num[3];
    char alp[3];
    cin >> num[0] >> num[1] >> num[2] >> alp[0] >> alp[1] >> alp[2];
    sort(num);
    cout << num[to_output_index(alp[0])] << ' ' << num[to_output_index(alp[1])] << ' '  << num[to_output_index(alp[2])];
    return 0;
}

void sort(int a[])
{
    int tmp;
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            if(a[j] < a[i])
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] =tmp;
            }
        }
    }
    return;
}

int to_output_index(char alp)
{
    switch (alp)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    }
    return -1;
}