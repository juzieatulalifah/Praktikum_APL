#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int banyaklist = 10000;
int maxpercobaan = 3;

struct DataBahasa {
    struct BahasaPemrograman {
        string nama;
        string deskripsi;
    } bahasa[banyaklist];
    int hitung = 0;
};

void menu() {
    cout <<" "<<endl;
    cout <<"================================================="<<endl;
    cout << "Menu" << endl;
    cout <<"================================================="<<endl;
    cout <<"1. Lihat list bahasa pemrograman favorit tahun 2024" << endl;
    cout <<"2. Tambahkan bahasa pemrograman favorit tahun 2024" << endl;
    cout <<"3. Ubah data bahasa pemrograman favorit tahun 2024" << endl;
    cout <<"4. Hapus bahasa pemrograman favorit tahun 2024" << endl;
    cout <<"5. Keluar dari program" << endl;
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

    cout << "\nAnda telah salah memasukkan username atau NIM sebanyak 3 kali. Program akan berhenti" << endl;
    return false;
}

bool ubahBahasa(DataBahasa &data){
    if (data.hitung == 0) {
        cout << "\nGak bisa dong, listnya masih kosong" << endl;
        return false;
    }

    cout << "Masukkan nomor bahasa pemrograman yang ingin diperbarui: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index >= 1 && index <= data.hitung) {
        cout << "\nMasukkan nama bahasa pemrograman baru: ";
        getline(cin, data.bahasa[index - 1].nama);
        cout << "Masukkan deskripsi bahasa pemrograman baru: ";
        getline(cin, data.bahasa[index - 1].deskripsi);
        cout << "\nBahasa pemrograman berhasil diperbarui." << endl;
        return true; 
    } else {
        cout << "\nNomor bahasa pemrograman tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }
}

bool hapusBahasa(DataBahasa &data){
    if (data.hitung == 0) {
        cout << "\nTidak ada data untuk dihapus." << endl;
        return false;
    }
    cout << "\nMasukkan nomor bahasa pemrograman yang ingin dihapus: ";
    int index;
    cin >> index;
    if (index >= 1 && index <= data.hitung) {
        for (int i = index - 1; i < data.hitung - 1; ++i) {
            data.bahasa[i] = data.bahasa[i + 1];
        }
        data.hitung--;
        cout << "\nBahasa pemrograman berhasil dihapus." << endl;
        return true; 
    } else {
        cout << "\nNomor bahasa pemrograman tidak valid." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}


void tambahBahasa(DataBahasa &data){
    if (data.hitung < banyaklist) {
        cout << "\nMasukkan nama bahasa pemrograman: ";
        cin.ignore();
        getline(cin, data.bahasa[data.hitung].nama);
        cout << "Masukkan deskripsi bahasa pemrograman: ";
        getline(cin, data.bahasa[data.hitung].deskripsi);
        data.hitung++;
        cout << "\nBahasa pemrograman berhasil ditambahkan." << endl;
    } else {
        cout << "\nDaftar bahasa pemrograman sudah penuh." << endl;
    }
}

void lihatList(const DataBahasa &data){
    if (data.hitung == 0) {
        cout << "\nBelum ada list bahasa pemrograman yang disimpan." << endl;
    } else {
        cout << "\nDaftar Bahasa Pemrograman Terfavorit:" << endl;
        for (int i = 0; i < data.hitung; ++i) {
            cout << i + 1 << ". " << data.bahasa[i].nama << " - " << data.bahasa[i].deskripsi << endl;
        }
    }
}

bool pilihanBenar(int pilihan) {
    return (pilihan >= 1 && pilihan <= 5);
}

int main() {
    DataBahasa data;
    int pilihan;

    if (!login()) {
        return 1;
    }

    do {
        menu();
        cin >> pilihan;

        if (!pilihanBenar(pilihan)) {
            cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                lihatList(data);
                break;
            case 2:
                tambahBahasa(data);
                break;
            case 3:
                ubahBahasa(data);
                break;
            case 4:
                hapusBahasa(data);
                break;
            case 5:
                cout << "Baibaiii" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    } while (pilihan != 5);

    return 0;
}
