#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
    return (First(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address P = malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
    free(*P);
}

address Search (List L, infotype X){
    address P = First(L);
    while (P != Nil){
        if (Info(P) == X){
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            InsVFirst(L,X);
        } else {
            address Last = First(*L);
            while (Next(Last) != Nil){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirst (List *L, infotype *X){
    address P = First(*L);  
    *X = Info(P);
    First(*L) = Next(P);
    Next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
    address P = First(*L);
    address Prec = Nil;
    while (Next(P) != Nil){
        Prec = P;
        P = Next(P);
    }
    *X = Info(P);
    if (Prec == Nil){
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
    Dealokasi(&P);
}

void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        InsertFirst(L,P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L,P,Last);
    }
}

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP (List *L, infotype X){
    address P = First(*L);
    address Prec = Nil;
    while (P != Nil && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != Nil){
        if (Prec == Nil){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = Nil;
        Dealokasi(&P);
    }
}

void DelLast (List *L, address *P){
    address Last = First(*L);
    address Prec = Nil;
    while (Next(Last) != Nil){
        Prec = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prec == Nil){
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;     
}

void PrintInfo (List L){
    address P = First(L);
    printf("[");
    while (P != Nil){
        printf("%d",Info(P));
        if (Next(P) != Nil){
            printf(",");
        }
        P = Next(P);
    }
    printf("]\n");
}

int NbElmt (List L){
    int count = 0;
    address P = First(L);
    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}

infotype Max (List L){
    address P = First(L);
    infotype max = Info(P); //integer
    while (P != Nil){
        if (Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}
address AdrMax (List L){
    address P = First(L);
    address max = P; //pointer to elmtlist
    while (P != Nil){
        if (Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}

infotype Min (List L){
    address P = First(L);
    infotype min = Info(P); //integer
    while (P != Nil){
        if (Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin (List L){
    address P = First(L);
    address min = P; //pointer to elmtlist
    while (P != Nil){
        if (Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}

float Average (List L){
    address P = First(L);
    float sum = 0;
    int count = 0;
    while (P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return sum/count;
}

void InversList (List *L){
    address P = First(*L);
    address Prec = Nil;
    address NextP = Nil;
    while (P != Nil){
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}  

void Konkat1 (List *L1, List *L2, List *L3){
    address P = First(*L1);
    address P2 = First(*L2);
    while (P != Nil){
        InsVLast(L3,Info(P));
        P = Next(P);
    }
    while (P2 != Nil){
        InsVLast(L3,Info(P2));
        P2 = Next(P2);
    }
}