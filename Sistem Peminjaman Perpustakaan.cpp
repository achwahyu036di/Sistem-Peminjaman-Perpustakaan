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
        int idbuku;
        int tahunterbit;
        int stokbuku;
        bool statusbuku;
};

class Peminjam {
    public:
        string namapeminjam;
        string asaldaerahpeminjam;
        int idpeminjam;
};

int n;

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
        Buku buku;
        cout << "Masukkan Judul Buku\t :";
        cin >> buku.judul;

        cout << "Masukkan Nama Pengarang\t :";
        cin >> buku.pengarang;

        cout << "Masukkan Tahun Terbit\t :";
        cin >> buku.tahunterbit;

        cout << "Masukkan Stok Buku\t :";
        cin >> buku.stokbuku;
    }
}
//     switch(n) {
//         case 1 : {
//             Buku buku;
//             cout << "Masukkan Judul Buku\t :\n";
//             cin >> buku.judul;

//             cout << "Masukkan Nama Pengarang\t :\n";
//             cin >> buku.pengarang;

//             cout << "Masukkan Tahun Terbit\t :\n";
//             cin >> buku.tahunterbit;

//             cout << "Masukkan Stok Buku\t :\n";
//             cin >> buku.stokbuku;

//             break;
            
//         case 2 : {

//         }
//         case 3 : {

//         }
//         case 4 : {

//         }
//         case 5 : {

//         }
//         case 6 : {

//         }
//         case 7 : {

//         }
//     }

    
//     return 0;

// }
