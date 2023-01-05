#include "perpustakaan.h"
#include <iomanip>

//buku
void CreateListBuku(listBuku &LB){
    firstBuku(LB) = nil;
}

//mahasiswa
void CreateListMahasiswa(listMahasiswa &LM){
    firstMahasiswa(LM) = nil;
}

// relasi
void CreateListRelasi(listRelasi &LR){
    firstRelasi(LR) = nil;
}

adrBuku newElementBuku(buku B){
    adrBuku p;
    p = new elementBuku;
    infoBuku(p) = B;
    nextBuku(p) = nil;
    return p;
}

void insertLastBuku(listBuku &LB, adrBuku pB){
    if(firstBuku(LB) == nil) {
        firstBuku(LB) = pB;
        nextBuku(firstBuku(LB)) = nil;
    } else if(nextBuku(firstBuku(LB)) == nil) {
        nextBuku(pB) = nil;
        nextBuku(firstBuku(LB)) = pB;
    } else {
        adrBuku p = firstBuku(LB);
        while(nextBuku(p) != nil){
            p = nextBuku(p);
        }
        nextBuku(pB) = nil;
        nextBuku(p) = pB;
    }
}

adrBuku searchBuku(listBuku LB, int noIndukBuku){
    adrBuku p;
    p = firstBuku(LB);
    while(p != nil) {
        if(infoBuku(p).noIndukBuku == noIndukBuku){
            return p;
            break;
        }
        p = nextBuku(p);
    }
    return nil;
}

adrMahasiswa newElementMahasiswa(mahasiswa M){
    adrMahasiswa p;

    p = new elementMahasiswa;
    infoMahasiswa(p) = M;
    nextMahasiswa(p) = nil;
    return p;
}

void insertLastMahasiswa(listMahasiswa &LM, adrMahasiswa pM, listRelasi &LR){
    if(firstMahasiswa(LM) == nil) {
        buku(pM) = firstRelasi(LR);
        firstMahasiswa(LM) = pM;
        nextMahasiswa(firstMahasiswa(LM)) = nil;
    } else if(nextMahasiswa(firstMahasiswa(LM)) == nil) {
        buku(pM) = firstRelasi(LR);
        nextMahasiswa(pM) = nil;
        nextMahasiswa(firstMahasiswa(LM)) = pM;
    } else {
        adrMahasiswa p = firstMahasiswa(LM);
        while(nextMahasiswa(p) != nil){
            p = nextMahasiswa(p);
        }
        buku(pM) = firstRelasi(LR);
        nextMahasiswa(pM) = nil;
        nextMahasiswa(p) = pM;
    }
    firstRelasi(LR) = nil;
}

int hitungBuku(listBuku LB){
    adrBuku B = firstBuku(LB);
    if(B == nil) {
        return 0;
    } else {
        int j = 0;
        while(B != nil) {
            j+=1;
            B = nextBuku(B);
        }
        return j;
    }
}

int hitungMahasiswa(listMahasiswa LM){
    adrMahasiswa M = firstMahasiswa(LM);
    if(M == nil) {
        return 0;
    } else {
        int j = 0;
        while(M != nil) {
            j+=1;
            M = nextMahasiswa(M);
        }
        return j;
    }
}

int findMaxDipinjam(listMahasiswa LM) {
    adrMahasiswa M = firstMahasiswa(LM);
    int MAX = 0;
    while(M != nil){
        if(MAX < infoMahasiswa(M).jumlahDipinjam) {
           MAX = infoMahasiswa(M).jumlahDipinjam;
        }
        M = nextMahasiswa(M);
    }
    return MAX;
}

int findMinDipinjam(listMahasiswa LM) {
    adrMahasiswa M = firstMahasiswa(LM);
    int MIN = infoMahasiswa(M).jumlahDipinjam;
    while(M != nil){
        if(MIN > infoMahasiswa(M).jumlahDipinjam) {
           MIN = infoMahasiswa(M).jumlahDipinjam;
        }
        M = nextMahasiswa(M);
    }
    return MIN;
}

void deleteLastMahasiswa(listMahasiswa &LM, adrMahasiswa &pM){
    if(firstMahasiswa(LM) == nil){
        cout << "List Kosong" << endl;
    }else {
        adrMahasiswa p = firstMahasiswa(LM);
        while (nextMahasiswa(nextMahasiswa(p)) != nil) {
            p = nextMahasiswa(p);
        }
        pM = nextMahasiswa(p);
        nextMahasiswa(pM) = nil;
        nextMahasiswa(p) = nil;
    }
}

void deleteFirstMahasiswa(listMahasiswa &LM, adrMahasiswa &pM){
    if(firstMahasiswa(LM) == nil){
        cout<<"List Kosong"<<endl;
    }else if(nextMahasiswa(firstMahasiswa(LM)) == nil){
        firstMahasiswa(LM) = nil;
    }else{
        pM = firstMahasiswa(LM);
        firstMahasiswa(LM) = nextMahasiswa(pM);
    }
}

adrMahasiswa searchMahasiswa(listMahasiswa LM, int id){
    adrMahasiswa p;
    p = firstMahasiswa(LM);
    while(p != nil && infoMahasiswa (p).id != id) {
        p = nextMahasiswa(p);
    }
    return p;
}


adrRelasi newElementRelasi(adrBuku B){
    adrRelasi p = new elementRelasi;
    relasiBuku(p) = B;
    nextRelasi(p) = nil;
    return p;
}

void insertLastRelasi(listRelasi &LR, adrRelasi pR){
     if(firstRelasi(LR) == nil) {
        firstRelasi(LR) = pR;
    } else if(nextRelasi(firstRelasi(LR)) == nil) {
        nextRelasi(firstRelasi(LR)) = pR;
    } else {
        adrRelasi p = firstRelasi(LR);
        while(nextRelasi(p) != nil){
            p = nextRelasi(p);
        }
        nextRelasi(p) = pR;
    }
}

void showBuku(listBuku &LB){
    adrBuku Q = firstBuku(LB);
    int i = 1;
    if (Q == nil){
        cout << "Tidak terdapat data buku" << endl;
    } else {
        cout << "Daftar buku : " << endl;
        while (Q != nil) {
            cout << i << ". " ;
            cout << "No Induk Buku: " << infoBuku(Q).noIndukBuku << endl;
            cout <<"Judul Buku: " << infoBuku(Q).judulBuku << endl;
            cout << "Nama Penulis: " << infoBuku(Q).namaPenulis << endl;
            cout << "Tahun Terbit: " << infoBuku(Q).tahunTerbit << endl;
            cout << endl;
            i++;
            Q = nextBuku(Q);
        }
    }
}

void showMahasiswa(listMahasiswa &LM){
    adrMahasiswa S = firstMahasiswa(LM);
    int i = 1;
    if (S == nil){
        cout << "Tidak terdapat data mahasiswa" << endl;
    } else {
        cout << "Daftar mahasiswa : " << endl;
        while (S != nil) {
            cout << i << ". ";
            cout << "Nama: " << infoMahasiswa(S).namaMahasiswa << endl;
            cout << "ID Mahasiswa: " << infoMahasiswa(S).id << endl;
            cout << "Tanggal Pinjam: " << infoMahasiswa(S).tanggalPinjam << endl;
            cout << "Tanggal Kembali: " << infoMahasiswa(S).tanggalKembali << endl;
            cout << endl;
            i++;
            S = nextMahasiswa(S);
        }
    }
}

void showAll(listMahasiswa LM){
    adrMahasiswa S = firstMahasiswa(LM);
    int i = 1;
    if (S == nil){
        cout << "Tidak terdapat data mahasiswa" << endl;
    } else {
        while (S != nil) {
            cout << "Data mahasiswa : " << endl;
            cout << setw(5) << "No." << setw(15) << "Nama" << setw(15) << "ID" << setw(20) << "Tanggal Pinjam" << setw(20) << "Tanggal Kembali" << endl;
            cout << setw(5) << i;
            cout << setw(15) << infoMahasiswa(S).namaMahasiswa;
            cout << setw(15) << infoMahasiswa(S).id;
            cout << setw(20) << infoMahasiswa(S).tanggalPinjam;
            cout << setw(20) << infoMahasiswa(S).tanggalKembali;
            cout << endl;
            cout << "Buku Dipinjam:" << endl;
            cout << setw(5) << "No." << setw(15) << "Judul" << setw(15) << "Penulis" << setw(20) << "Tahun Terbit" << endl;
            adrRelasi B = buku(S);
            while(B != nil) {
                cout << setw(5) << infoBuku(relasiBuku(B)).noIndukBuku;
                cout << setw(15) << infoBuku(relasiBuku(B)).judulBuku;
                cout << setw(15) << infoBuku(relasiBuku(B)).namaPenulis;
                cout << setw(20) << infoBuku(relasiBuku(B)).tahunTerbit;
                cout << endl;
                B = nextRelasi(B);
            }
            i++;
            S = nextMahasiswa(S);
            cout << endl;
        }
    }
}

int menu(){
    cout << "\n\t\t Selamat Datang di Perpustakaan Umum Bahagia \n" << endl;
    cout << "===================== MENU =====================" << endl;
    cout << "||1. Menambahkan Data Buku                    ||" << endl;
    cout << "||2. Menampilkan Data Buku                    ||" << endl;
    cout << "||3. Menambahkan Data Mahasiswa               ||" << endl;
    cout << "||4. Menampilkan Semua Data Mahasiswa         ||" << endl;
    cout << "||5. Menampilkan Semua Data Buku dan Mahasiswa||" << endl;
    cout << "||6. Menampilkan Jumlah Data                  ||" << endl;
    cout << "||7. Mencari Buku Paling Banyak               ||" << endl;
    cout << "||8. Mencari Buku Paling Sedikit              ||" << endl;
    cout << "||9. Menghapus Data Pertama                   ||" << endl;
    cout << "||10. Menghapus Data Terakhir                 ||" << endl;
    cout << "||11. Mencari Data Buku                       ||" << endl;
    cout << "================================================" << endl;
    cout << endl;
    cout << "Masukkan menu :";
    int inputan;
    inputan = 0;
    cin >> inputan;
    cout << endl;
    return inputan;
}
