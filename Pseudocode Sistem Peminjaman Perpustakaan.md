# PSEUDOCODE SISTEM PEMINJAMAN PERPUSTAKAAN

### 1.1 Versi Sederhananya

Memulai Program;

Deklarasi;
```cpp
Struct Buku // Menyimpan informasi buku seperti Judul, Pengarang dan Status Peminjaman.
Array daftarBuku // Menyimpan daftar buku yang ada di perpustakaan.
```
Menambahkan Fungsi;
```cpp
Fungsi tambahBuku // Menambahkan buku baru ke daftar buku.
```
```cpp
Fungsi cariBukuJudul // Mencari buku berdasarkan judul bukunya.
```
```cpp
Fungsi cariBukuPengarang // Mencari buku berdasarkan nama pengarangnya.
```
```cpp
Fungsi pinjamBuku // Mengelola peminjaman buku.
```
```cpp
Fungsi kembalikanBuku // Mengelola pengembalian buku.
```
```cpp
Fungsi editBuku // Mengedit informasi buku yang sudah ada di daftar buku.
```
```cpp
Fungsi tampilkanDaftarBuku // Menampilkan seluruh daftar buku bersama dengan statusPeminjamannya.
```
```cpp
Fungsi simpanKeFile // Menyimpan data buku ke dalam bentuk file.
```
```cpp
Fungsi muatDariFile // Memuat data buku yang sudah dalam bentuk file.
```
```cpp
Fungsi main // Menu utama program yang mengatur alur program berdasarkan input yang dipilih oleh pengguna.
```

Mengakhiri Program;


# 



### 1.2 Versi Lebih Kompleks

Memulai Program;

Deklarasi struct Buku; // menyimpan informasi buku.
```cpp
    struct Buku {
        string judul;
        string pengarang;
        bool dipinjam;
    };
```
Deklarasi array dinamis;  // menyimpan daftar buku.
```cpp
    Buku daftarBuku[100];
    int jumlahBuku = 0;
```
Fungsi menambahkan buku baru;
```cpp
    function tambahBuku(string judul, string pengarang) {
        Buku bukuBaru;
        bukuBaru.judul = judul;
        bukuBaru.pengarang = pengarang;
        bukuBaru.dipinjam = false;
    
        daftarBuku[jumlahBuku] = bukuBaru;
        jumlahBuku++;
        cout << "Buku berhasil ditambahkan.";
    }
```
Fungsi mencari buku berdasarkan judul;
```cpp
    function cariBukuJudul(string judul) {
        for (int i = 0; i < jumlahBuku; i++) {
            if (daftarBuku[i].judul == judul) {
                return i;
            }
        }
        return -1; // Buku tidak ditemukan.
    }
```
Fungsi mencari buku berdasarkan pengarang;
```cpp
    function cariBukuPengarang(string pengarang) {
        for (int i = 0; i < jumlahBuku; i++) {
            if (daftarBuku[i].pengarang == pengarang) {
                return i;
            }
        }
        return -1; // Buku tidak ditemukan.
    }
```
Fungsi meminjam buku;
```cpp
    function pinjamBuku(string judul) {
        int indeks = cariBukuJudul(judul);
        if (indeks != -1 && !daftarBuku[indeks].dipinjam) {
            daftarBuku[indeks].dipinjam = true;
            cout << "Buku berhasil dipinjam.";
        } else {
            cout << "Buku tidak ditemukan atau sudah dipinjam.";
        }
    }
```
Fungsi mengembalikan buku;
```cpp
    function kembalikanBuku(string judul) {
        int indeks = cariBukuJudul(judul);
        if (indeks != -1 && daftarBuku[indeks].dipinjam) {
            daftarBuku[indeks].dipinjam = false;
            cout << "Buku berhasil dikembalikan.";
        } else {
            cout << "Buku tidak ditemukan atau belum dipinjam.";
        }
    }
```
Fungsi mengedit buku;
```cpp
    function editBuku(string judul, string judulBaru, string pengarangBaru) {
        int indeks = cariBukuJudul(judul);
        if (indeks != -1) {
            daftarBuku[indeks].judul = judulBaru;
            daftarBuku[indeks].pengarang = pengarangBaru;
            cout << "Buku berhasil diedit.";
        } else {
            cout << "Buku tidak ditemukan.";
        }
    }
```
Fungsi menampilkan daftar buku;
```cpp
    function tampilkanDaftarBuku() {
        for (int i = 0; i < jumlahBuku; i++) {
            cout << "Judul: " << daftarBuku[i].judul << ", Pengarang: " << daftarBuku[i].pengarang;
            if (daftarBuku[i].dipinjam) {
                cout << " (Dipinjam)";
            }
            cout << endl;
        }
    }
```
Fungsi menyimpan data buku ke dalam file;
```cpp
    function simpanKeFile(string namaFile) {
        ofstream file(namaFile);
        for (int i = 0; i < jumlahBuku; i++) {
            file << daftarBuku[i].judul << ";" << daftarBuku[i].pengarang << ";" << daftarBuku[i].dipinjam << endl;
        }
        file.close();
    }
```
Fungsi memuat data buku yang sudah dalam bentuk file;
```cpp
    function muatDariFile(string namaFile) {
        ifstream file(namaFile);
        string line;
        jumlahBuku = 0;
        while (getline(file, line)) {
            Buku buku;
            string[] data = split(line, ';');
            buku.judul = data[0];
            buku.pengarang = data[1];
            buku.dipinjam = data[2] == "1";
            daftarBuku[jumlahBuku] = buku;
            jumlahBuku++;
        }
        file.close();
    }
```
Fungsi utama untuk mengelola menu dan alur program;
```cpp
    function main() {
        muatDariFile("data_buku.txt");
        
        while (true) {
            cout << "1. Tambah Buku" << endl;
            cout << "2. Cari Buku (Judul)" << endl;
            cout << "3. Cari Buku (Pengarang)" << endl;
            cout << "4. Pinjam Buku" << endl;
            cout << "5. Kembalikan Buku" << endl;
            cout << "6. Edit Buku" << endl;
            cout << "7. Tampilkan Daftar Buku" << endl;
            cout << "8. Keluar" << endl;
            cout << "Pilih menu: ";
            int pilihan;
            cin >> pilihan;
            
            if (pilihan == 1) {
                string judul, pengarang;
                cout << "Masukkan judul buku: ";
                cin >> judul;
                cout << "Masukkan nama pengarang: ";
                cin >> pengarang;
                tambahBuku(judul, pengarang);

            } else if (pilihan == 2) {
                string judul;
                cout << "Masukkan judul buku: ";
                cin >> judul;
                int indeks = cariBukuJudul(judul);
                if (indeks != -1) {
                    cout << "Buku ditemukan: " << daftarBuku[indeks].judul << " oleh " << daftarBuku[indeks].pengarang;
                } else {
                    cout << "Buku tidak ditemukan.";
                }

            } else if (pilihan == 3) {
                string pengarang;
                cout << "Masukkan nama pengarang: ";
                cin >> pengarang;
                int indeks = cariBukuPengarang(pengarang);
                if (indeks != -1) {
                    cout << "Buku ditemukan: " << daftarBuku[indeks].judul << " oleh " << daftarBuku[indeks].pengarang;
                } else {
                    cout << "Buku tidak ditemukan.";
                }

            } else if (pilihan == 4) {
                string judul;
                cout << "Masukkan judul buku yang ingin dipinjam: ";
                cin >> judul;
                pinjamBuku(judul);

            } else if (pilihan == 5) {
                string judul;
                cout << "Masukkan judul buku yang ingin dikembalikan: ";
                cin >> judul;
                kembalikanBuku(judul);
                
            } else if (pilihan == 6) {
                string judul, judulBaru, pengarangBaru;
                cout << "Masukkan judul buku yang ingin diedit: ";
                cin >> judul;
                cout << "Masukkan judul baru: ";
                cin >> judulBaru;
                cout << "Masukkan nama pengarang baru: ";
                cin >> pengarangBaru;
                editBuku(judul, judulBaru, pengarangBaru);

            } else if (pilihan == 7) {
                tampilkanDaftarBuku();

            } else if (pilihan == 8) {
                simpanKeFile("data_buku.txt");
                break;

            } else {
                cout << "Pilihan tidak valid.";
                
            }
        }
    }
```
Mengakhiri Program;
