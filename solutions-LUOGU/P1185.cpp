/*
 * hint:
 * 对于含有 m（m>1） 层二叉树的图来说：
 * * 图形宽度为 3*2^(m-1)-1
 * * 图形高度为 3*2^(m-2)
 * * 根节点横坐标（同图形高度）为 3*2^(m-2)
 * * 总共节点数最大为 2^m-1
 * * 第 m 行结点个数最大为 2^(m-1)
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#define MAXW 1600
#define MAXH 800
#define MAXCNT 1050

using namespace std;

int m, n, len, width, height;
bool bt[MAXCNT] = {};
char graph[MAXH][MAXW];

void create_bt(int level)
{
    len = pow(2, level) - 1;
    memset(bt+1, true, len);
}

void delete_node(int no)
{
    if (bt[no] == true)
    {
        bt[no] = false;
        if (no * 2 <= len)
            delete_node(no * 2);
        if (no * 2 + 1 <= len)
            delete_node(no * 2 + 1);
    }
}

/*
now：当前节点在静态表示的二叉树中的位置
x：当前结点在绘制图形当中的横坐标
y：当前结点在绘制图形当中的纵坐标
edgelen：当前结点与子节点间的边的长度
*/
void create_graph(int now, int x, int y, int edgelen)
{
    // root
    if (bt[now])
        graph[x][y] = 'o';

    // left
    if (bt[now*2])
    {
        for (int i = 1; i <= edgelen; i++)
            graph[x+i][y-i] = '/';
        if (edgelen == 2)
            create_graph(now*2, x+edgelen+1, y-edgelen-1, 1);
        else if (edgelen == 1)
            graph[x+edgelen+1][y-edgelen-1] = 'o';
        else
            create_graph(now*2, x+edgelen+1, y-edgelen-1, (edgelen+1)/2-1);
    }

    // right
    if (bt[now*2+1])
    {
        for (int i = 1; i <= edgelen; i++)
            graph[x+i][y+i] = '\\';
        if (edgelen == 2)
            create_graph(now*2+1, x+edgelen+1, y+edgelen+1, 1);
        else if (edgelen == 1)
            graph[x+edgelen+1][y+edgelen+1] = 'o';
        else
            create_graph(now*2+1, x+edgelen+1, y+edgelen+1, (edgelen+1)/2-1);
    }
}

int main()
{
    // init
    fill(graph[0], graph[0]+ MAXW * MAXH, ' ');

    // input & create the binary tree
    scanf("%d %d",&m,&n);
    create_bt(m);
    while(n--)
    {
        int i, j, no;
        scanf("%d %d",&i,&j);
        no = pow(2, i-1) - 1 + j;
        delete_node(no);
    }

    // calculate some important variables
    width = 3 * pow(2, m-1) - 1;
    height = 3 * pow(2, m-2);
    int root_edge = height / 2 - 1;
    if (m == 2) root_edge = 1;

    // draw tree graph
    create_graph(1, 1, height, root_edge);

    // output
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
	return 0;
}