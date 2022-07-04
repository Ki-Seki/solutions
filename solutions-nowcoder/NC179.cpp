// 通过 7/8 组用例

#include <bits/stdc++.h>
using namespace std;

int numKLenSubstrRepeats(string s, int k)
{
    // init
    int abc[26], cnt = 0;
    memset(abc, 0, sizeof(abc));
    for (int i = 0; i < k; i++) abc[s[i]-'a']++;
    for (int i = 0; i < 26; i++) if (abc[i] > 1) {cnt++; break;}

    // main loop
    int tail, head;
    bool lst = cnt;  // 上一个序列是否有重复字符
    for (int i = 1; i <= s.length()-k; i++)
    {
        tail = s[i-1] - 'a';
        head = s[i+k-1] - 'a';
        abc[head]++;
        abc[tail]--;
        if (abc[head] == 1 && abc[tail] == 0) cnt += lst;
        else if (abc[head] >= 2 || abc[tail] >= 2) {cnt++; lst = true;}
        else 
        {
            lst = false;
            for (int j = 0; j < 26; j++) if (abc[j] > 1) {cnt++; lst = true;}
        }
    }
    return cnt; 
}

int main()
{
    cout << numKLenSubstrRepeats("topcoder",4) << endl;
    return 0;
}