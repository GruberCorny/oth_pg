#include <stdio.h>






void Zahl_ausgeben2(int **zahl)
{
printf("Zahl: %d\n", **zahl );
}
void Zahl_ausgeben1(int *zahl)
{
Zahl_ausgeben2(&zahl);
}
int main()
{
int zahl = 5;
Zahl_ausgeben1(&zahl);
return 0;
}
