#include <iostream>
#include <algorithm>
#define MAXN 505

using namespace std;

struct Station {
    double price, distance;
} st[MAXN];

bool cmp(Station a, Station b)
{
    if (a.distance != b.distance) return a.distance < b.distance;
    else return a.price < b.price;
}

int main()
{
    // init
    double cmax, d, davg;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &st[i].price, &st[i].distance);
    st[n] = {0, d};

    // sort by distance
    sort(st, st + n, cmp);

    // special judge
    if (st[0].distance != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    // simulate
    int curr_st = 0;
    double accessible_range = cmax * davg,
    traveled = 0, cost = 0, tank = 0;
    while (curr_st < n)
    {
        // find the next station to go
        int target = curr_st + 1;
        bool isAccessible = false;
        for (int i = curr_st + 1; i <= n; i++)
        {
            if (st[i].distance <= st[curr_st].distance + accessible_range)
            {
                isAccessible = true;
                if (st[i].price <= st[curr_st].price)
                {
                    target = i;
                    break;
                }
                else if (st[i].price <= st[target].price)
                    target = i;
            }
        }
        
        // special judge: unaccessible to any other stations
        if (! isAccessible)
        {
            printf("The maximum travel distance = %.2lf", traveled + cmax * davg);
            return 0;
        }

        // have accessible stations
        double require = (st[target].distance - st[curr_st].distance) / davg;
        if (st[target].price <= st[curr_st].price)
        {
            if (require <= tank)
                tank -= require;
            else
            {
                cost += (require - tank) * st[curr_st].price;
                tank = 0;
            }
        }
        else
        {
            cost += (cmax - tank) * st[curr_st].price;
            tank = cmax - require;
        }
        traveled = st[target].distance;
        curr_st = target;
    }
    printf("%.2lf", cost);
    return 0;
}