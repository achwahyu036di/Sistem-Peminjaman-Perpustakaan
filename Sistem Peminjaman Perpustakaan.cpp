#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
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

class Perpustakaan {
public:
    vector<Buku> bukuList;
    const string fileName = "file.txt";

    void bacaData() {
        ifstream file(fileName);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            string judul, pengarang, tahunStr, dipinjamStr;
            size_t pos = 0;
            pos = line.find(";"); judul = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(";"); pengarang = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(";"); tahunStr = line.substr(0, pos); line.erase(0, pos + 1);
            dipinjamStr = line;

            bukuList.emplace_back(judul, pengarang, std::stoi(tahunStr), dipinjamStr == "1");
        }
        file.close();
    }

    void simpanData() {
        ofstream file(fileName);
        for (auto &buku : bukuList) {
            file << buku.toString();
        }
        file.close();
    }

    void tambahBuku(vector<Buku>& dataBuku, int banyakData) {
        for (int a = 0; a < banyakData; ++a) {
            cout << "Data Buku Ke-" << a + 1 << ":\n";
            Buku buku;
            buku.no = a + 1;

            cout << "Masukkan ID Buku\t: ";
            cin.ignore();
            getline(cin, buku.idbuku);

            cout << "Masukkan Judul Buku Baru\t: ";
            getline(cin, buku.judul);

            cout << "Masukkan Nama Pengarang Buku\t: ";
            getline(cin, buku.pengarang);

            cout << "Masukkan Tahun Buku\t: ";
            cin >> buku.tahunterbit;

            cout << "Masukkan Stok Buku\t: ";
            cin >> buku.stokbuku;

            dataBuku.push_back(buku);
        }
    }


    void cariBuku() {
            string judul;
            cout << "Masukkan Judul Buku yang Dicari: ";
            cin >> ws; getline(cin, judul);

            for (auto &buku : bukuList) {
                if (buku.judul == judul) {
                    cout << "Buku Ditemukan: " << buku.judul << ", " << buku.pengarang << ", " << buku.tahun << ", " << (buku.statusbuku ? "Dipinjam" : "Tersedia") << "\n";
                    return;
                }
            }
            cout << "Buku Tidak Ditemukan\n";
        }

    void editBuku() {
            string judul;
            cout << "Masukkan Judul Buku yang Ingin Diedit: ";
            cin >> ws; getline(cin, judul);

            for (auto &buku : bukuList) {
                if (buku.judul == judul) {
                    cout << "Masukkan Pengarang Baru: ";
                    getline(cin, buku.pengarang);
                    cout << "Masukkan Tahun Terbit Baru: ";
                    cin >> buku.tahun;
                    simpanData();
                    return;
                }
            }
            cout << "Buku Tidak Ditemukan\n";
        }

    void pinjamBuku() {
            string judul;
            cout << "Masukkan Judul Buku yang Ingin Dipinjam: ";
            cin >> ws; getline(cin, judul);

            for (auto &buku : bukuList) {
                if (buku.judul == judul && !buku.statusbuku) {
                    buku.statusbuku = true;
                    simpanData();
                    cout << "Buku Berhasil Dipinjam\n";
                    return;
                }
            }
            cout << "Buku Tidak Ditemukan atau Sudah Dipinjam\n";
        }

    void kembalikanBuku() {
            string judul;
            cout << "Masukkan Judul Buku yang Ingin Dikembalikan: ";
            cin >> ws; getline(cin, judul);

            for (auto &buku : bukuList) {
                if (buku.judul == judul && buku.statusbuku) {
                    buku.statusbuku = false;
                    simpanData();
                    cout << "Buku Berhasil Dikembalikan\n";
                    return;
                }
            }
            cout << "Buku Tidak Ditemukan atau Belum Dipinjam\n";
        }

    void tampilkanBuku() {
            cout << "Daftar Buku di Perpustakaan:\n";
            for (auto &buku : bukuList) {
                cout << buku.judul << ", " << buku.pengarang << ", " << buku.tahun << ", " << (buku.dipinjam ? "Dipinjam" : "Tersedia") << "\n";
            }
        }

    void keluar() {
            cout << "Terima kasih telah menggunakan layanan perpustakaan.\n";
        }
};

int n;
int banyakdata;

int main () {
    while(true) {

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
                Perpustakaan.tambahBuku;
            } else if (n == 2) {
                Perpustakaan.cariBuku;

            } else if (n == 3) {
                Perpustakaan.editBuku;

            } else if (n == 4) {
                Perpustakaan.pinjamBuku;

            } else if (n == 5) {
                Perpustakaan.kembalikanBuku;

            } else if (n == 6) {
                Perpustakaan.tampilkanBuku;
                break;

            } 
            else {
                cout << "Pilihan Anda tidak valid, Silakan coba lagi/\n";
            } 
    }

    return 0;
}