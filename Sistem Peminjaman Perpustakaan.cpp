#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

class Buku {
    public:
        string judulBuku;
        string pengarangBuku;
        int idBuku;
        int tahunTerbit;
        int stokBuku;
        bool statusBuku;
};

class Peminjam {
    public:
        string namaPeminjam;
        string asaldaerahPeminjam;
        int idPeminjam;
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
        cout << "Masukkan ID Buku\t : ";
        cin >> buku.kodeBuku;
        
        cout << "Masukkan Judul Buku\t : ";
        cin >> buku.judulBuku;

        cout << "Masukkan Nama Pengarang\t : ";
        cin >> buku.pengarangBuku;

        cout << "Masukkan Tahun Terbit\t : ";
        cin >> buku.tahunTerbit;

        cout << "Masukkan Stok Buku\t : ";
        cin >> buku.stokBuku;
    }
}
//   
            
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
