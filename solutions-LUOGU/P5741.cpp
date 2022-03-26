#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int a, b, c, d;  // 语，数，英，总
} stu[1010];

vector<string> stu_pair;

bool is_close(const Student& s1, const Student& s2)
{
    return
        (abs(s1.a-s2.a) <= 5 &&
        abs(s1.b-s2.b) <= 5 &&
        abs(s1.c-s2.c) <= 5 &&
        abs(s1.d-s2.d) <= 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name;
        scanf("%d%d%d", &stu[i].a, &stu[i].b, &stu[i].c);
        stu[i].d = stu[i].a + stu[i].b + stu[i].c;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (is_close(stu[i], stu[j]))
                if (stu[i].name < stu[j].name)
                    stu_pair.push_back(stu[i].name + " " + stu[j].name);
                else
                    stu_pair.push_back(stu[j].name + " " + stu[i].name);
    sort(stu_pair.begin(), stu_pair.end());
    for (int i = 0; i < stu_pair.size(); i++)
        cout << stu_pair[i] << endl;
    return 0;
}