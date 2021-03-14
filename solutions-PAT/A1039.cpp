#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 175760  // 26 * 26 * 26 * 10

using namespace std;

vector<int> stu_cou[MAXN + 5];  // student - course table; using linear probing

int get_id(char name[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
        id = id * 26 + name[i] - 'A';
    id = id * 10 + name[3] - '0';
    return id;
}

int main()
{
    //input

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int course_i, stu_cnt;
        char tmp[5];
        scanf("%d %d", &course_i, &stu_cnt);
        for (int j = 0; j < stu_cnt; j++)
        {
            scanf("%s", tmp);
            stu_cou[get_id(tmp)].push_back(course_i);
        }
    }

    // output

    for (int i = 0; i < n; i++)
    {
        char tmp[5];
        scanf("%s", tmp);
        int id = get_id(tmp);
        sort(stu_cou[id].begin(), stu_cou[id].end());
        printf("%s %d", tmp, stu_cou[id].size());
        for (int j = 0; j < stu_cou[id].size(); j++)
            printf(" %d", stu_cou[id][j]);
        printf("\n");
    }
    return 0;
}