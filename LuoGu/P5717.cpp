#include <iostream>

using namespace std;

int main()
{
    int a, b, c, tmp;
    cin >> a >> b >> c;

    //ensure the a is the maximum
    if(b>=a && b>=c)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    else if(c>=a && c>=b)
    {
        tmp = a;
        a = c;
        c = tmp;
    }

    if (b+c > a)
    {
        if (b*b+c*c == a*a)
        {
            cout << "Right triangle" << endl;
        }
        if (b*b+c*c > a*a)
        {
            cout << "Acute triangle" << endl;
        }
        if (b*b+c*c < a*a)
        {
            cout << "Obtuse triangle" << endl;
        }
        if (b==c)
        {
            cout << "Isosceles triangle" << endl;
        }
        if (a==b && b == c)
        {
            cout << "Equilateral triangle" << endl;
        }
    }
    else
    {
        cout << "Not triangle";
    }
    
    return 0;
}