#include <stdio.h>

void rekursivefigunacci(int erste, int zweite, int wiederholen){
    if (wiederholen <= 0) return;
    int drei = erste + zweite;
    printf(",%d", drei);
    if (erste > zweite) zweite = erste;
    rekursivefigunacci(drei, zweite, wiederholen-1);
}
void nichtrekursivefigunacci(int erste, int zweite, int max){
    int array[100+2] = {0};
    if (erste > zweite){
        array[1] = erste;
        array[0] = zweite;
    }
    else{
        array[0] = erste;
        array[1] = zweite;
    }
    for (int i = 0; i < max; i++){
        array[i+2] = array[i+1] + array[i];
        if (array[i+2] < 0) {
            printf("\nhier ist die zahl groeser als ein integer und kann deswegen nicht mehr zurueckgegeben werden");
            return;
        }
        printf(",%d",array[i+2]);
    }
}
int main (){
    int zahleins = 0;
    int zahlzwei = 0;
    int wiederholungen = 0;
    printf("\npleas give me your first number:");
    scanf("%d", &zahleins);
    fflush(stdin);
    printf("\npleas give me your second number:");
    scanf("%d", &zahlzwei);
    fflush(stdin);
    printf("\npleas give me how maney fibunacci numbers u want:");
    scanf("%d", &wiederholungen);
    printf("\nfor the numbers %d and %d you get the fibunacci order of: %d,%d", zahleins, zahlzwei, zahleins, zahlzwei);
    nichtrekursivefigunacci(zahleins, zahlzwei, wiederholungen);
    printf("\nfor the numbers %d and %d you get the fibunacci order of: %d,%d", zahleins, zahlzwei, zahleins, zahlzwei);
    rekursivefigunacci(zahleins, zahlzwei, wiederholungen);
    return 0;
}

// die nichtrekursive ist kuerzer weil der compeiler dort warscheinlich mehr compeilen kann.