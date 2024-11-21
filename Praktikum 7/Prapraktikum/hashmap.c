#include "hashmap.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
    M->Count = Nil; // Inisialisasi jumlah elemen ke Nil
    for (int i = 0; i < MaxEl; i++) { 
        M->Elements[i].Key = Undefined;   // Inisialisasi semua key ke Undefined
        M->Elements[i].Value = Undefined; // Inisialisasi semua value ke Undefined
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : Count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
    return (K % MaxEl + MaxEl) % MaxEl; // Menangani kemungkinan K negatif
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
    int i = 0;
    boolean found = false;

    // Cari elemen dengan key k
    while (!found && i < MaxEl) {
        if (M.Elements[i].Key == k) { 
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return M.Elements[i].Value; // Kembalikan value jika ditemukan
    } else {
        return Undefined; // Kembalikan Undefined jika tidak ditemukan
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v) {
    int idx = Hash(k); // Hitung indeks awal berdasarkan hash
    boolean isMember = false;

    // Periksa apakah key sudah ada di HashMap
    for (int i = 0; i < MaxEl; i++) {
        if (M->Elements[i].Key == k) {
            isMember = true; // Key ditemukan, tidak perlu menambahkan
            break;
        }
    }

    if (!isMember) { // Jika key belum ada, tambahkan elemen baru
        // Linear probing untuk menemukan slot kosong
        while (M->Elements[idx].Key != Undefined) {
            idx = (idx + 1) % MaxEl;
        }
        M->Elements[idx].Key = k;  // Simpan key
        M->Elements[idx].Value = v; // Simpan value
        M->Count++;                // Tambahkan jumlah elemen
    }
}
/* Menambahkan elemen sebagai anggota HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh. M mungkin sudah beranggotakan elemen dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan. 
        Indeks yang digunakan untuk menyimpan v adalah hash dari k.
        Gunakan open addressing linear probing dengan interval 1 jika indeks sudah terisi. */
