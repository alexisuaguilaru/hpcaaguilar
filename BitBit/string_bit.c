#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argn, char **args)
{
    char A[4] = "Hola";
    unsigned int R;
    unsigned int MASK;
    unsigned int bits;

    printf("%s \t ",A);
    for (int k = 0; k<4; k++)
    {
        memcpy(&bits, &A[k], sizeof(char));
        for (int index = 7; index >= 0; index--)
        {
            MASK = 0x00000001 << index;
            R = (bits & MASK) >> index;
            printf("%u",R);
        }
    }
    printf("\n");
    
    return 0;
}