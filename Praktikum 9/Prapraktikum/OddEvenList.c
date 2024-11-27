#include "listlinier.h"
#include <stdio.h>

void OddEvenList(List L, List *Odd, List *Even) {
    address P = First(L);
    CreateEmpty(Odd);  
    CreateEmpty(Even); 

    while (P != Nil) {
        if (Info(P) % 2 == 0) {
            InsertLast(Even, Alokasi(Info(P)));
        } else {
            InsertLast(Odd, Alokasi(Info(P)));
        }
        P = Next(P);  
    }

    address P1, P2;
    int temp;
    for (P1 = First(*Odd); P1 != Nil; P1 = Next(P1)) {
        for (P2 = Next(P1); P2 != Nil; P2 = Next(P2)) {
            if (Info(P1) > Info(P2)) {
                temp = Info(P1);
                Info(P1) = Info(P2);
                Info(P2) = temp;
            }
        }
    }

    for (P1 = First(*Even); P1 != Nil; P1 = Next(P1)) {
        for (P2 = Next(P1); P2 != Nil; P2 = Next(P2)) {
            if (Info(P1) > Info(P2)) {
                temp = Info(P1);
                Info(P1) = Info(P2);
                Info(P2) = temp;
            }
        }
    }
}

// #include <stdio.h>
// #include "listlinier.h"

// int main() {
//     List L, Odd, Even;
//     address P;
    
//     // Membuat list kosong L, Odd, dan Even
//     CreateEmpty(&L);
//     CreateEmpty(&Odd);
//     CreateEmpty(&Even);
    
//     // Menambahkan beberapa elemen ke list L
//     InsertLast(&L, Alokasi(0));  // Menambahkan angka 1
//     InsertLast(&L, Alokasi(3));  // Menambahkan angka 2
//     InsertLast(&L, Alokasi(1));  // Menambahkan angka 3
//     InsertLast(&L, Alokasi(4));  // Menambahkan angka 4
//     InsertLast(&L, Alokasi(5));  // Menambahkan angka 5
    
//     // Menampilkan list L sebelum pemisahan
//     printf("List L:\n");
//     PrintInfo(L);

//     // Memanggil fungsi OddEvenList untuk memisahkan list L menjadi list Odd dan Even
//     OddEvenList(L, &Odd, &Even);

//     // Menampilkan hasil pemisahan
//     printf("\nList Odd:\n");
//     PrintInfo(Odd);
    
//     printf("\nList Even:\n");
//     PrintInfo(Even);

//     return 0;
// }
