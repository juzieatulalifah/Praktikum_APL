#include <iostream>
#include <string>
using namespace std;

const int banyaklist = 10000;
int maxpercobaan = 3;

struct bahasapemrograman {
    string nama;
    string deskripsi;
};

void menu(){
    cout <<"================================================="<<endl;
    cout << "Menu" << endl;
    cout <<"================================================="<<endl;
    cout <<"1.Liat list bahasa pemrograman favorit tahun 2024"<<endl;
    cout <<"2.Tambahkan bahasa pemrograman favorit tahun 2024" <<endl;
    cout <<"3.Ubah data bahasa pemrograman favorit tahun 2024"<<endl;
    cout <<"4.Hapus bahasa pemrograman favorit tahun 2024"<<endl;
    cout <<"5.Keluar dari program"<<endl;
    cout <<"================================================="<<endl;
    cout <<"Masukkan pilihan (1/2/3/4/5) : ";
}

bool login() {
    string username;
    string nim;
    int percobaan = 0;

    do {
        cout << "Masukkan username: ";
        getline(cin, username);

        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (username == "Nur Juzieatul Alifah" && nim == "2309106040") {
            return true;
        } else {
            cout << "Username atau nim salah." << endl;
            percobaan++;
        }
    } while (percobaan < maxpercobaan);

    cout << "Anda telah salah memasukkan username atau NIM sebanyak 3 kali. Program akan berhenti" << endl;
    return false;
}

void tambahbahasa(bahasapemrograman bahasa[], int &hitung){
    if (hitung < banyaklist) {
        cout << "Masukkan nama bahasa pemrograman: ";
        cin.ignore();
        getline(cin, bahasa[hitung].nama);
        cout << "Masukkan deskripsi bahasa pemrograman: ";
        getline(cin, bahasa[hitung].deskripsi);
        hitung++;
        cout << "Bahasa pemrograman berhasil ditambahkan." << endl;
    } else {
        cout << "Daftar bahasa pemrograman sudah penuh." << endl;
    }
}

void liatlist(const bahasapemrograman bahasa[], int hitung){
    if (hitung == 0) {
        cout << "\n \nBelum ada list bahasa pemrograman yang disimpan." << endl;
    } else {
        cout << "Daftar Bahasa Pemrograman Terfavorit:" << endl;
        for (int i = 0; i < hitung; ++i) {
            cout << i + 1 << ". " << bahasa[i].nama << " - " << bahasa[i].deskripsi << endl;
        }
    }
}

void ubahbahasa(bahasapemrograman bahasa[], int hitung){
    if (hitung == 0) {
        cout << "\nGak bisa dong, listnya masih kosong" << endl;
        return;
    }

    cout << "Masukkan nomor bahasa pemrograman yang ingin diperbarui: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index >= 1 && index <= hitung) {
        cout << "Masukkan nama bahasa pemrograman baru: ";
        getline(cin, bahasa[index - 1].nama);
        cout << "Masukkan deskripsi bahasa pemrograman baru: ";
        getline(cin, bahasa[index - 1].deskripsi);
        cout << "Bahasa pemrograman berhasil diperbarui." << endl;
    } else {
        cout << "Nomor bahasa pemrograman tidak valid." << endl;
    }
}

void hapusbahasa(bahasapemrograman bahasa[], int &hitung){
    if (hitung == 0) {
        cout << "\nTidak ada data untuk dihapus." << endl;
        return;
    }
    cout << "Masukkan nomor bahasa pemrograman yang ingin dihapus: ";
    int index;
    cin >> index;
    if (index >= 1 && index <= hitung) {
        for (int i = index - 1; i < hitung - 1; ++i) {
            bahasa[i] = bahasa[i + 1];
        }
        hitung--;
        cout << "Bahasa pemrograman berhasil dihapus." << endl;
    } else {
        cout << "Nomor bahasa pemrograman tidak valid." << endl;
    }
}

int main() {
    bahasapemrograman bahasa[banyaklist];
    int hitung = 0;
    int choice;

    if (!login()) {
    return 1;
    }

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                liatlist(bahasa, hitung);
                break;
            case 2:
                tambahbahasa(bahasa, hitung);
                break;
            case 3:
                ubahbahasa(bahasa, hitung);
                break;
            case 4:
                hapusbahasa(bahasa, hitung);
                break;
            case 5:
                cout << "Baibaiii" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
                cin.clear();
                cin.ignore();
        }
    } while (choice != 5);

    return 0;
}
