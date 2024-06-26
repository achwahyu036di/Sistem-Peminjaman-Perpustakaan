#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

class Buku {
    public:
        string judul;
        string pengarang;
        string idbuku;
        int no;
        int tahunterbit;
        int stokbuku;
        bool statusbuku;
};

class Peminjam {
    public:
        string namapeminjam;
        string asaldaerahpeminjam;
        string nomorteleponpeminjam;
        int idpeminjam;
};

int n;
int banyakdata;

int main () {
    cout << ":::::::::::::::: SELAMAT DATANG DI PERPUSTAKAAN PUTRA BANGSA ::::::::::::::::\n";
    cout << "-----------------------------------------------------------------------------\n";

    cout << "Silahkan Anda bisa memilih layanan berikut ini :\n";
    cout << "[1] Menambahkan Buku Baru \n";
    cout << "[2] Mencari Buku\n";
    cout << "[3] Mengedit Informasi Buku\n";
    cout << "[4] Meminjam Buku\n";
    cout << "[5] Mengembalikan Buku\n";
    cout << "[6] Menampilkan Daftar Buku\n";
    cout << "[7] Keluar\n";
    cout << "\n";
    
    cout << "Silahkan tentukan pilihan Anda [1] - [7]\n";
    cin >> n;

    if (n == 1) {
        int namabuku;
        cout << ":::::::: Menambahkan Buku Baru ::::::::\n";
        cout << "---------------------------------------\n";
        
        cout << "Jumlah Buku Ditambahkan\t : ";
        cin >> banyakdata;
        
        vector <Buku> dataBuku (banyakdata);
        for (int a = 0; a < banyakdata; ++a) {
            cout << "Data Buku Ke-" << a + 1 << ":\n";
            dataBuku[a].no = a + 1; 
        
            Buku buku;
            cout << "Masukkan ID Buku\t : ";
            cin.ignore();
            getline(cin, dataBuku[a].idbuku);

            cout << "Masukkan Judul Buku Baru\t : ";
            cin >> dataBuku[a].judul;
            cin.ignore();
            getline(cin, dataBuku[a].judul);

            cout << "Masukkan Nama Pengarang Buku\t : ";
            cin>> dataBuku[a].pengarang;
            cin.ignore();
            getline(cin, dataBuku[a].pengarang);

            cout << "Masukkan Tahun Buku\t : ";
            cin >> dataBuku[a].tahunterbit;

            cout << "Masukkan Stok Buku\t : ";
            cin >> dataBuku[a].stokbuku; 
        }

    // } else if (n == 2) {
    //     int namabuku;

    // } else if (n == 3) {
    //     int namabuku;

    // } else if (n == ) {
    //     int namabuku;

    // } else if (n == ) {
    //     int namabuku;

    // } else if (n == ) {
    //     int namabuku;

    // } 
    // else {
        
    // } 
}
