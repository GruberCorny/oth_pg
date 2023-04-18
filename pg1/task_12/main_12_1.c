#include <stdio.h>


void ausgabe(char zustand)
{
    printf("\nbits are:");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", ((zustand >> i) & 1));
    }
}

int main()
{
    char zustand = 0xC5;

    ausgabe(zustand);

    if (0 == (zustand & 10000000))
    {
        printf("\nno power");
    }
    else if (1 == ((zustand >> 7) & 00000001))
    {
        printf("\ngot power");
    }
    else
    {
        printf("\nsomting went ronge");
    }
    printf("\nR hat den zustand %d", ((zustand >> 6) & 1));
    printf("\nB hat den zustand %d", ((zustand >> 4) & 1));

    zustand = zustand & 0xf3;
    ausgabe(zustand);

    zustand = zustand | 0x03;
    ausgabe(zustand);

    zustand = (zustand ^ 0x20);
    ausgabe(zustand);

    printf("\nzustand: 0x%x ", zustand & 0xffU);

    return 0;
}