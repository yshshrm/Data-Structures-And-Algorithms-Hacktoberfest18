#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() 
{
    uint16_t a;
	  scanf("%d", &a);
    uint16_t msb = 32768;
    
    for (int i = 0; i < 16; i++)
    {
        if ( a >= msb)
        {
            printf("1"); 
            a = a - msb;
            msb = msb / 2;
        } else {
            printf("0");
            msb = msb / 2;
        }
    }
    printf("\n");
	  return 0;
}
