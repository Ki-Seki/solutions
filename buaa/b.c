#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXS 22
#define MAXN  500015
#define PRIME 500009
int n, m;
char name[MAXS], number[MAXS], query[MAXS];

struct Contact {
    char name[MAXS];
    char number[MAXS];
} contacts[MAXN];  // a hash table with size being 500009
bool is_taken[MAXN] = {false};

int str2int(const char * s)
{
    int ans = 0, len = strlen(s);
    for (int j = 0; j < len; j++)
        ans = (ans * 26 + (name[j]-'a')) % PRIME;
    return ans;
}


int main()
{
    scanf("%d %d\n",&n,&m);
    for (int i=1; i<=n; i++)
    {
        scanf("%s %s", &name, &number);
        int index = str2int(name);
        while (is_taken[index]) index = (index + n * n) % PRIME;
        is_taken[index] = true;
        strcpy(contacts[index].name, name);
        strcpy(contacts[index].number, number);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%s", query);
        int index = str2int(query), cnt = 0;
        while (strcmp(contacts[index].name, query) != 0 && cnt < n)
        {
            index = (index + n * n) % PRIME;
            cnt++;
        }
        if (strcmp(contacts[index].name, query) == 0)
            printf("%s\n", contacts[index].number);
        else
            printf("Not Found\n");
    }
    return 0;
}