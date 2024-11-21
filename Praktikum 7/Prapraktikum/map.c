#include <stdio.h>
#include "boolean.h"
#include "map.h"

void CreateEmpty(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

boolean IsEmpty(Map M){
    return (M).Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
    return (M).Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

valuetype Value(Map M, keytype k){
    boolean found = false;
    int i = 0; //indeks

    while (!found && i<M.Count){
        if (M.Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }

}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v){
    if (!IsMember(*M, k))
	{
		if (IsEmpty(*M))
		{
			M->Elements[0].Key = k;
			M->Elements[0].Value= v;
		}
		else
		{
			M->Elements[M->Count].Key = k;
			M->Elements[M->Count].Value= v;
		}
		(*M).Count += 1;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
    boolean found = false;
    int i = 0;
    
    if (!IsMember(*M, k)){
        return;
    } 
    while (!found && i < (*M).Count){
        if (M->Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }
    if (found){
        while (i<(M->Count)){
        M->Elements[i].Key = M->Elements[i+1].Key;
        M->Elements[i].Value = M->Elements[i+1].Value;
        i++;
        }
        M->Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
    boolean found = false;
    address i = 0;
    while (!found && i<(M.Count)){
        if (M.Elements[i].Key==k){
            found = true;
        } else {
            i++;
        }
    }
    return (found);
}
/* Mengembalikan true jika k adalah member dari M */