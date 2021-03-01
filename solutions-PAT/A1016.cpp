#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 1005

struct Record{
    char name[25];
    int month, day, hour, minute;
    bool status;  // true denotes on-line
} records[MAXN];

int toll[24], acc_toll[24],  // denote the payment rate
cnt[MAXN] = {};  // denote the number of pairs of each user's correct records

bool cmp(Record a, Record b)
{
    if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.day != b.day) return a.day < b.day;
    else if (a.hour != b.hour) return a.hour < b.hour;
    else return a.minute < b.minute;
}

int filter(int n)
{
    int lasted = 0;
    
    for (int i = 0; i < n; i++)  // filter out wrong data
    {
        // judge if it should be filtered out
        bool flag = false;
        if (records[i].status == true)
            if (i + 1 < n)
                if (records[i+1].status == false)
                    flag = true;
        else
            if (i - 1 >= 0)
                if (records[i-1].status == true)
                    flag = true;
        
        if (flag)
            lasted++;
        else
            records[i].name[0] = 'z' + 1;  // filter it out
    }
    return lasted;
}

double get_payment(int sd, int sh, int sm, int ed, int eh, int em)
{
    double payment = 0;
    if (ed - sd >= 2) payment += acc_toll[23] * (ed - sd - 1);
    if (ed - sd == 0) payment -= acc_toll[23];
    payment += (acc_toll[23] - acc_toll[sh]) + toll[sh] * (60 - sm);
    payment += acc_toll[eh] - toll[eh] * (60 - em);
    return payment / 100.0;
}

void output_user_bill(Record *rcd, int cnt)
{
    if (cnt != 0)
    {
        double total = 0;
        printf("%s %02d\n", rcd[0].name, rcd[0].month);
        for (int i = 0; i < cnt; i++)
        {
            int minutes, start = i * 2, end = i * 2 + 1;
            minutes = rcd[end].day * 24 * 60 + rcd[end].hour * 60 + rcd[end].minute -
                (rcd[start].day * 24 * 60 + rcd[start].hour * 60 + rcd[start].minute);
            double payment = get_payment(rcd[start].day, rcd[start].hour, rcd[start].minute, rcd[end].day, rcd[end].hour, rcd[end].minute);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
                rcd[start].day, rcd[start].hour, rcd[start].minute, rcd[end].day, rcd[end].hour, rcd[end].minute, minutes, payment);
            total += payment;
        }
        printf("Total amount: $%.2f\n", total);
    }
}

int main()
{
    // input data
    for (int i = 0; i < 24; i++) scanf("%d", &toll[i]);
    for (int i = 0; i < 24; i++)  // calculate the accumulated toll
        if (i == 0) acc_toll[i] = toll[i] * 60;
        else acc_toll[i] = acc_toll[i-1] + toll[i] * 60;
    int n;
    scanf("%d", &n);
    char tmp[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d:%d %s", records[i].name, &records[i].month, &records[i].day, &records[i].hour, &records[i].minute, tmp);
        records[i].status = (tmp[1] == 'n');  // if it is on-line
    }

    // sort
    std::sort(records, records + n, cmp);

    // test
    printf("\nTHIS IS A TEST\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %02d:%02d:%02d:%02d %d\n", records[i].name, records[i].month, records[i].day, records[i].hour, records[i].minute, records[i].status);
    }
    printf("\nTEST END\n");

    // standardize and calculate the number of each user's records
    /*
    int current_cnt = 0, index = 0;
    for (int i = 0; i < n; i++)  // filter out wrong data
    {
        if (i == n - 1)  // special judge for records[i]
            if (!(strcmp(records[i-1].name, records[i].name) == 0 && records[i-1].status == true && records[i].status == false))
                records[i].name[0] = 'z' + 1;
        
        if (strcmp(records[i].name, records[i+1].name) == 0)  //consistent names
        {
            
            

            int flag = int(records[i].status) * 10 + int(records[i+1].status);
            switch (flag)
            {
            case 10:  // on-line off-line
                current_cnt++;
                break;
            case 11:  // on-line on-line
                records[i].name[0] = 'z' + 1;  // get rid of the records[i] when resorts later
                break;
            case 00:  // off-line off-line
                records[i+1].name[0] = 'z' + 1;  // get rid of the records[i+1] when resorts later
                break;
            case 01: // off-line on-line
                break;
            }
        }
        else  // inconsistent names
        {
            // save data and reset some variables
            cnt[index++] = current_cnt;
            current_cnt = 0;

            // special judge for records[i]
            if (!(strcmp(records[i-1].name, records[i].name) == 0 && records[i-1].status == true && records[i].status == false))
                records[i].name[0] = 'z' + 1;
        }
    }*/
    int lasted = filter(n);

    // resort
    std::sort(records, records + n, cmp);

    int index = 0;
    for (int i = 0; i < lasted - 1; i++)
        if (strcmp(records[i].name, records[i+1].name) == 0)
            cnt[index]++;
        else
        {
            cnt[index] = (cnt[index] + 1) / 2;
            index++;
        }
        


    

    // test
    printf("\nTHIS IS A TEST\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %02d:%02d:%02d:%02d %d\n", records[i].name, records[i].month, records[i].day, records[i].hour, records[i].minute, records[i].status);
    }
    printf("\nTEST END\n");

    // output
    int acc = 0;  // accumulated cnt
    for (int i = 0; i < lasted / 2; i++)
    {
        output_user_bill(records + acc, cnt[i]);
        acc += cnt[i] * 2;
    }
    return 0;
}