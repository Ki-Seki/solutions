#include <iostream>
#include <algorithm>
using namespace std;

bool is_greater(int a, int b)
{
    return a > b;
}

void to_array(int num, int arr[])
{
    arr[0] = num / 1000;
    arr[1] = num / 100 % 10;
    arr[2] = num / 10 % 10;
    arr[3] = num % 10;
}

int to_digit(int arr[])
{
    return arr[0] * 1000 +
           arr[1] * 100 +
           arr[2] * 10 +
           arr[3];
}

int main()
{
    int num, min_num, max_num, min_arr[4], max_arr[4];
    scanf("%d", &num);
    do{
        to_array(num, max_arr);
        sort(max_arr, max_arr + 4, is_greater);
        max_num = to_digit(max_arr);
        to_array(num, min_arr);
        sort(min_arr, min_arr + 4);
        min_num = to_digit(min_arr);
        num = max_num - min_num;
        printf("%04d - %04d = %04d\n", max_num, min_num, num);
    } while (num != 0 && num != 6174);
    return 0;
}