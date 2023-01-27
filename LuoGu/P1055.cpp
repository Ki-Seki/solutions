#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int checksum = 0, oringinal_checksum;
    cin >> str;
    for(int i=0, j=1;i<11;i++)
    {
        if(str[i] != '-')
        {
            checksum += int(str[i]-'0') * (j++);
        }
    }
    checksum %= 11;

    if(str[12]=='X')
        oringinal_checksum = 10;
    else
        oringinal_checksum = int(str[12]-'0');
    
    if(checksum == oringinal_checksum)
        cout << "Right";
    else
    {
        if(checksum == 10)
            cout << str.substr(0,12) << 'X';
        else
            cout << str.substr(0,12) << char('0'+checksum);
    }
    
    system("pause");
    return 0;
}