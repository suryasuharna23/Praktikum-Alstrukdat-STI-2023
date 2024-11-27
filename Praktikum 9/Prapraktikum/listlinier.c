#include "listlinier.h"
#include <stdio.h>

boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

address Alokasi (infotype X){
    address P;
    P = (address)malloc(1*sizeof(ElmtList));

    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P; 
    } else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

address Search (List L, infotype X){
    address P;
    boolean found = false;

    while (!IsEmpty(L)){
        if (Info(P) == X){
            found = true;
        } else {
            P = Next(P);
        }
    }

    if (found){
        return P;
    } else {
        return Nil;
    }
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertLast(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X){
    address P = First(*L);
    address prev = Nil;

    while (Next(P) != Nil){
        prev = P;
        P = Next(P);
    }

    *X = Info(P);
    if (prev == Nil){
        First(*L) = Nil;
    } else {
        Next(prev) = Nil;
    }

    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P){
    address Last;
    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, infotype X){
    address Prec;
    address P;
    boolean found = false;

    if (!IsEmpty(*L))
    {
        if (X == Info(First(*L)))
        {
            DelFirst(L, &P);
            Dealokasi(&P);
        }
        else
        {
            P = First(*L);
            while (!found && P != Nil)
            {
                if (Info(P) == X)
                {
                    found = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (found)
            {
                DelAfter(L, &P, Prec);
                Dealokasi(&P);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, address *P){
    address Last = First(*L);
    address PrecLast = Nil;

    while (Next(Last) != Nil)
    {
        PrecLast = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (PrecLast == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(PrecLast) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void PrintInfo (List L){
    address P;
    boolean isFirst = true;

    printf("[");
    if (!IsEmpty(L))
    {
        P = First(L);
        while (P != Nil)
        {
            if (!isFirst)
            {
                printf(",");
            }
            printf("%d", Info(P));
            isFirst = false;

            P = Next(P);
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L){
    int count = 0;
    address P;

    if (!IsEmpty(L))
    {
        P = First(L);
        while (P != Nil)
        {
            count++;
            P = Next(P);
        }
    }

    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

infotype Max (List L){
    infotype max = Info(First(L));
    address P = Next(First(L));
    while (P != Nil)
    {
        if (Info(P) > max)
        {
            max = Info(P);
        }
        P = Next(P);
    }

    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
    address PMax = First(L);
    address P = Next(First(L));
    while (P != Nil)
    {
        if (Info(P) > Info(PMax))
        {
            PMax = P;
        }
        P = Next(P);
    }

    return PMax;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
    infotype min = Info(First(L));
    address P = Next(First(L));
    while (P != Nil)
    {
        if (Info(P) < min)
        {
            min = Info(P);
        }
        P = Next(P);
    }

    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
    address PMin = First(L);
    address P = Next(First(L));
    while (P != Nil)
    {
        if (Info(P) < Info(PMin))
        {
            PMin = P;
        }
        P = Next(P);
    }

    return PMin;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
    infotype sum = 0;
    int count = 0;
    address P = First(L);

    while (P != Nil)
    {
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return sum * 1.0 / count;
}
/* Mengirimkan nilai rata-rata info(P) */

void InversList(List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P;
    address Prec = Nil;
    address Succ;

    if (!IsEmpty(*L))
    {
        P = First(*L);
        while (P != Nil)
        {
            Succ = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = Succ;
        }
        First(*L) = Prec;
    }
}

void Konkat1(List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last1;

    CreateEmpty(L3);
    if (IsEmpty(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != Nil)
        {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}