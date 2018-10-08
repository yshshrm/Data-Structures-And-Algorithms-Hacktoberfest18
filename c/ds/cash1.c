#include<cs50.h>
#include<stdio.h>
#include<math.h>

int change(int cents);

int main(void)

{
    float input;
//prmompt user for change
    do
    {
        printf("change owed:");
        scanf("%f",&input);
    }
    while (input < 0);

// print min number of coins required
    printf("%d\n", change((int)round(input * 100)));

}
// calculate min number of coins required
int change(int cents)
{
    return cents / 25 + cents % 25 / 10 + cents % 25 % 10 / 5 + cents % 25 % 10 % 5 ;
}
