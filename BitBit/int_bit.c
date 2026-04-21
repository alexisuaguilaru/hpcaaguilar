#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **args)
{
    int A;
    unsigned int R;
    unsigned int MASK;

    for (A = -100; A<=100; A++)
    {   
        printf("%i \t ",A);
        for (int index = 15; index >= 0; index--)
        {
            MASK = 0x00000001 << index;
            R = (A & MASK) >> index;
            printf("%u",R);
        }

        printf("\n");
    }
    
    return 0;
}