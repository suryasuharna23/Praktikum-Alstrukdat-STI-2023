#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    List L;
    CreateEmpty(&L);
    address P;
    boolean valid = true;
    float count = 0, sum = 0; 
    while (valid) {
        int input;
        scanf("%d", &input); 

        if (input < 0 || input > 100) {
            valid = false;
        } else {
            P = Alokasi(input);
            InsertLast(&L, P);
            
            count++;
            sum += input;
        }
    }

    if (count > 0) {
        printf("%d\n", count);
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", sum / count); 
        PrintInfo(L);
        InversList(&L);
        PrintInfo(L);
    } else {
        printf("Daftar nilai kosong\n");
    }

    return 0;
}