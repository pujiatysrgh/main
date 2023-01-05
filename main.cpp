#include <iostream>
#include "perpustakaan.h"

using namespace std;

int main()
{
    // Define List Variable
    listBuku LB;
    listMahasiswa LM;
    listRelasi LR;

    // Define Variable
    mahasiswa MHS;
    buku BUKU;


    // Define adr of List
    adrRelasi R;
    adrBuku B;
    adrMahasiswa M;

    // Create List For All Defined List
    CreateListBuku(LB);
    CreateListMahasiswa(LM);
    CreateListRelasi(LR);


    // Akses menu
 int masukan;
    char kembali;
    masukan = menu();
    while(masukan != 0){
        if(masukan == 1){
            // Defined i
            int N;
            int i = 0;
            cout << "Banyaknya Input:";
            cin >> N;
            while(i < N){
                cout << "Nomor Induk Buku: ";
                cin >> BUKU.noIndukBuku;
                cout << "Judul Buku: ";
                cin >> BUKU.judulBuku;
                cout << "Nama Penulis: ";
                cin >> BUKU.namaPenulis;
                cout << "Tahun Terbit: ";
                cin >> BUKU.tahunTerbit;
                cout << endl;
                B = newElementBuku(BUKU);
                insertLastBuku(LB, B);
                i++;

            //i = 0;
            }
        }else if(masukan == 2){
            cout << "========== SHOW BUKU ==========" << endl;
            showBuku(LB);
            cout << endl;
        }else if(masukan == 3){
            cout<<"============== Masukan Data Mahasiswa ============"<<endl;
            cout << "Banyaknya Mahasiswa:";
            int N,i;
            i = 0;
            cin >> N;
            while(i < N) {
            int h = 0;
                cout << "Nama Mahasiswa: ";
                cin >> MHS.namaMahasiswa;
                cout << "ID Mahasiswa: ";
                cin >> MHS.id;
                cout << "Tanggal Pinjam: ";
                cin >> MHS.tanggalPinjam;
                cout << "Tanggal Kembali: ";
                cin >> MHS.tanggalKembali;
                cout << endl;
                cout << "Jumlah Buku Yang Dipinjam:";
                cin >> MHS.jumlahDipinjam;
                while (h < MHS.jumlahDipinjam) {
                    cout << "Nomor Induk Buku: ";
                    cin >> BUKU.noIndukBuku;
                    B = searchBuku(LB, BUKU.noIndukBuku);
                    R = newElementRelasi(B);
                    insertLastRelasi(LR, R);
                    h++;
                }
                M = newElementMahasiswa(MHS);
                insertLastMahasiswa(LM, M, LR);
                i++;
                cout << endl;
        }
        }else if(masukan == 4){
            cout << "=================== SHOW MAHASISWA ===================" << endl;
            showMahasiswa(LM);
            cout << endl;
        }else if(masukan == 5){
            cout << "=================== SHOW ALL ===================" << endl;
            showAll(LM);
            cout << endl;
        }else if(masukan == 6){
            cout << "========== Menghitung Jumlah Data ==========" << endl;
            cout << "Jumlah Buku :" << hitungBuku(LB) << endl;
            cout << "Jumlah Mahasiswa :" << hitungMahasiswa(LM) << endl;
        }else if(masukan == 7){
            cout << "======== Cari Jumlah Peminjaman Paling Banyak ========" << endl;
            int jmlMax = findMaxDipinjam(LM);
            cout<<jmlMax<<endl;
            cout<<endl;
        }else if(masukan == 8) {
            cout << "======== CARI JUMLAH BUKU YG PALING SEDIKIT ========" << endl;
            int jmlMin = findMinDipinjam(LM);
            cout<<jmlMin<<endl;
            cout<<endl;
        }else if(masukan == 9){
            cout << "Menghapus Data Pertama"<< endl;
            deleteFirstMahasiswa(LM,M);
            cout << endl;
            showAll(LM);
            cout<<endl;
        }else if(masukan == 10){
            cout<<"Menghapus Data Terakhir"<<endl;
            deleteLastMahasiswa(LM, M);
            cout << endl;
            showAll(LM);
            cout<<endl;
        }else if(masukan == 11) {
            cout << "Masukkan nomor induk buku:" << endl;
            cin >> BUKU.noIndukBuku;
            adrBuku B = searchBuku(LB, BUKU.noIndukBuku);
            if(B == nil) {
                cout << "Buku tidak ditemukan.." << endl;
            } else {
                cout << "Nomor Induk Buku: ";
                cout << infoBuku(B).noIndukBuku << endl;
                cout << "Judul Buku: ";
                cout << infoBuku(B).judulBuku << endl;
                cout << "Nama Penulis: ";
                cout << infoBuku(B).namaPenulis<< endl;
                cout << "Tahun Terbit: ";
                cout << infoBuku(B).tahunTerbit << endl;
            }
        }else{
            cout<<"Menu tidak ditemukan"<<endl;
        }
        cout<<endl;
        cout<<"Kembali ke menu ? (Y/N) : ";
        cin>>kembali;

        if(kembali == 'Y'){
            cout<<endl;
            masukan = menu();
        }else if(kembali=='N'){
            masukan = 0;
        }
    }
    cout << "EXIT" << endl;
    return 0;
}
