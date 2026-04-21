#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argn, char **args)
{
    float A;
    unsigned int R;
    unsigned int MASK;
    unsigned int bits;

    for (int k = -100; k<=100; k++)
    {   
        A = (float)k;
        memcpy(&bits,&A,sizeof(float));
        printf("%f \t ",A);
        for (int index = 31; index >= 0; index--)
        {
            MASK = 0x00000001 << index;
            R = (bits & MASK) >> index;
            printf("%u",R);
        }

        printf("\n");
    }
    
    return 0;
}