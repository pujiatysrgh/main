#ifndef PERPUSTAKAAN_H_INCLUDED
#define PERPUSTAKAAN_H_INCLUDED

#include <iostream>

using namespace std;
#define firstBuku(L) ((L).firstBuku)
#define firstRelasi(L) ((L).firstRelasi)
#define firstMahasiswa(L) ((L).firstMahasiswa)
#define infoMahasiswa(P) (P)->infoMahasiswa
#define infoBuku(P) (P)->infoBuku
#define nextMahasiswa(P) (P)->nextMahasiswa
#define nextBuku(P) (P)->nextBuku
#define nextRelasi(P) (P)->nextRelasi
#define relasiBuku(P) (P)->relasiBuku
#define buku(P) (P)->buku
#define nil NULL

struct mahasiswa{
    string namaMahasiswa, tanggalPinjam, tanggalKembali;
    int id, jumlahDipinjam;
};

struct buku{
    string judulBuku, namaPenulis, tahunTerbit;
    int noIndukBuku, jumlahDipinjam;
};

typedef struct elementMahasiswa *adrMahasiswa;
typedef struct elementBuku *adrBuku;
typedef struct elementRelasi *adrRelasi;

struct elementBuku {
    buku infoBuku;
    adrBuku nextBuku;
};

struct elementMahasiswa {
    mahasiswa infoMahasiswa;
    adrRelasi buku;
    adrMahasiswa nextMahasiswa;
};

struct elementRelasi{
    adrBuku relasiBuku;
    adrRelasi nextRelasi;
};

struct listMahasiswa{
    adrMahasiswa firstMahasiswa;
};

struct listBuku{
    adrBuku firstBuku;
};

struct listRelasi{
    adrRelasi firstRelasi;
};

//buku
void CreateListBuku(listBuku &LB);
void showAll(listMahasiswa LM);
adrBuku newElementBuku(buku B);
void insertLastBuku(listBuku &LB, adrBuku pB);
adrBuku searchBuku(listBuku LB, int noIndukBuku);
int hitungBuku(listBuku LB);

//mahasiswa
void CreateListMahasiswa(listMahasiswa &LM);
adrMahasiswa newElementMahasiswa(mahasiswa M);
void insertLastMahasiswa(listMahasiswa &LM, adrMahasiswa pM, listRelasi &LS);
void deleteLastMahasiswa(listMahasiswa &LM, adrMahasiswa &pM);
void deleteFirstMahasiswa(listMahasiswa &LM, adrMahasiswa &pM);
adrMahasiswa searchMahasiswa(listMahasiswa LM, int id);
int hitungMahasiswa(listMahasiswa LM);
int findMaxDipinjam(listMahasiswa LM);
int findMinDipinjam(listMahasiswa LM);

//relasi
void CreateListRelasi(listRelasi &LR);
adrRelasi newElementRelasi(adrBuku B);
void insertLastRelasi(listRelasi &LR, adrRelasi pR);
void showBuku(listBuku &LB);
void showMahasiswa(listMahasiswa &LM);


//menu
int menu();
#endif // PERPUSTAKAAN_H_INCLUDED
