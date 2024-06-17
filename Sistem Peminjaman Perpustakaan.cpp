#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct buku {
    string judul_buku;
    string nama_pengarang;
    int kode_buku;
}

struct peminjam {
    string nama_peminjam;
    int id_peminjam;
}

void buku() {
    

}

int a;

int main() {
    cout << "::: SISTEM PEMINJAMAN PERPUSTAKAAN :::\n";
    cout << "--------------------------------------\n";
    
    cout << "Masukkan Pilihan Anda : " << endl;
    cin >> a;

    cout << "[1] Input Data Buku \n";
    cout << "[2] Daftar Buku\n";
    cout << "[3] Input Data Peminjam\n";
    cout << "[4] Daftar Peminjam\n";
    
}