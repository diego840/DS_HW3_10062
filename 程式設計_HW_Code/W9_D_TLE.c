#include <stdio.h>
long long int a, b, answer;
long long int x = 0, y;
int Weight[300010];
int Weight_two[300020];
int main()
{                               // 6 10 {1,2,5,5,5,9} // 6 8 {9,9,9,9,9,9}
    scanf("%lld %lld", &a, &b); //     {9,8,5,5,5,}         {-1,-1,-1,-1,-1,-1}
    for (int i = 0; i < a; i++)
    { //     {0,0,0,1,2,4}        {0,1,2,3,4,5}
        scanf("%d", &Weight[i]);
        while (x > 0 && Weight[i] >= Weight_two[x - 1])
        {
            answer += a - i;
            x--;
        }
        x++;
        Weight_two[i] = b - Weight[i]; //{9,8,5,5,5}
    }
    printf("%lld\n", answer);
    return 0;
}