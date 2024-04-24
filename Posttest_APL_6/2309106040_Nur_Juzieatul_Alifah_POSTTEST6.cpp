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
        string tanggal;
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
    cout <<"5. Sorting data" << endl;
    cout <<"6. Searching Nama dan deskripsi bahasa pemrograman" << endl;
    cout <<"7. Searching Tanggal rilis bahasa pemrograman" << endl;
    cout <<"8. Keluar" << endl;
    cout <<"================================================="<<endl;
    cout <<"Masukkan pilihan (1/2/3/4/5/6/7/8) : ";
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
        cout << "Masukkan tanggal dikeluarkannya bahasa pemrograman: ";
        getline(cin, data.bahasa[data.hitung].tanggal);
        data.hitung++;
        cout << "\nBahasa pemrograman berhasil ditambahkan." << endl;
    } else {
        cout << "\nDaftar bahasa pemrograman sudah penuh." << endl;
    }
}

void lihatList(const DataBahasa *data){
    if (data->hitung == 0) {
        cout << "\nBelum ada list bahasa pemrograman yang disimpan." << endl;
    } else {
        cout << "\nDaftar Bahasa Pemrograman Terfavorit:" << endl;
        for (int i = 0; i < data->hitung; ++i) {
            cout << i + 1 << ". " << data->bahasa[i].nama << " - " << data->bahasa[i].deskripsi << " - " << data->bahasa[i].tanggal<< endl;
        }
        cout << "\nJumlah list bahasa pemrograman: " << data->hitung << endl;
    }
}

//sorting
void quickSortNamaDescending(DataBahasa &data, int low, int high) {
    if (low < high) {
        int pivot = high;
        int j = low - 1;
        for (int i = low; i <= high; i++) {
            if (data.bahasa[i].nama > data.bahasa[pivot].nama) {
                j++;
                swap(data.bahasa[i], data.bahasa[j]);
            }
        }
        swap(data.bahasa[pivot], data.bahasa[j + 1]);
        pivot = j + 1;
        quickSortNamaDescending(data, low, pivot - 1);
        quickSortNamaDescending(data, pivot + 1, high);
    }
}

void sortingNamaDescending(DataBahasa &data) {
    quickSortNamaDescending(data, 0, data.hitung - 1);
}

void selectionSortTanggalAscending(DataBahasa &data) {
    for (int i = 0; i < data.hitung - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < data.hitung; j++) {
            if (data.bahasa[j].tanggal < data.bahasa[minIndex].tanggal) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data.bahasa[i], data.bahasa[minIndex]);
        }
    }
}

void sortingTanggalAscending(DataBahasa &data) {
    selectionSortTanggalAscending(data);
}

void bubbleSortDeskripsiAscending(DataBahasa &data) {
    for (int i = 0; i < data.hitung - 1; i++) {
        for (int j = 0; j < data.hitung - i - 1; j++) {
            if (data.bahasa[j].deskripsi > data.bahasa[j + 1].deskripsi) {
                swap(data.bahasa[j], data.bahasa[j + 1]);
            }
        }
    }
}

void sortingDeskripsiAscending(DataBahasa &data) {
    bubbleSortDeskripsiAscending(data);
}


// int pilihmenusort;
// void sortingdata(DataBahasa &data) {
//     cout << "\nMenu Sorting : "<<endl;
//     cout << "1. Sorting Nama "<<endl;
//     cout << "2. Sorting Deskripsi "<<endl;
//     cout << "3. Sorting Tanggal"<<endl;
//     cout << "Masukkan pilihan (1/2/3): ";
//     cin >> pilihmenusort;
    
//     if{(pilihmenusort == 1)
//     sortingNamaDescending(data);}
//     else if (pilihmenusort == 2){
//         sortingDeskripsiAscending(data);
//     }else if (pilihmenusort == 3) {
//     sortingTanggalAscending(data);}
//     // sortingDeskripsiAscending(data);
//     else{
//         cout << "Inputan tidak valid";
//     }

// }


//searching
int linearSearchDescending(const DataBahasa &data, const string &nama) {
    for (int i = data.hitung - 1; i >= 0; --i) {
        if (data.bahasa[i].nama == nama) {
            return i; 
        }
    }
    return -1;
}

int binarySearchAscending(const DataBahasa &data, const string &tanggal) {
    int low = 0, high = data.hitung - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data.bahasa[mid].tanggal == tanggal) {
            return mid;
        } else if (data.bahasa[mid].tanggal < tanggal) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}



bool pilihanBenar(int pilihan) {
    return (pilihan >= 1 && pilihan <= 8);
}

int main() {
    DataBahasa data;
    int pilihan;
    int pilihmenusort;

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
                lihatList(&data);
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
            void sortingdata(DataBahasa &data); 
            cout << "\nMenu Sorting : "<<endl;
            cout << "1. Sorting Nama "<<endl;
            cout << "2. Sorting Deskripsi "<<endl;
            cout << "3. Sorting Tanggal"<<endl;
            cout << "Masukkan pilihan (1/2/3): ";
            cin >> pilihmenusort;

            if(pilihmenusort == 1)
            sortingNamaDescending(data);
            else if (pilihmenusort == 2)
            sortingDeskripsiAscending(data);
            else if (pilihmenusort == 3) 
            sortingTanggalAscending(data);
            else{
            cout << "Inputan tidak valid";
            }
            break;
            //karena nama dan deskripsi menggunakan metode yang sama, digabungkan
            case 6:{
                cout << "Masukkan nama bahasa pemrograman yang ingin dicari: ";
                string nama;
                cin.ignore();
                getline(cin, nama);
                int indexNama = linearSearchDescending(data, nama);
                if (indexNama != -1) {
                    cout << "\nNama bahasa pemrograman ditemukan pada indeks: " << indexNama + 1 << endl;
                    cout << "Nama: " << data.bahasa[indexNama].nama << endl;
                    cout << "Deskripsi: " << data.bahasa[indexNama].deskripsi << endl;
                    cout << "Tanggal: " << data.bahasa[indexNama].tanggal << endl;
                } else {
                    cout << "Nama bahasa pemrograman tidak ditemukan." << endl;
                }
                break;
                }

            case 7:{
                    cout << "Masukkan tanggal bahasa pemrograman yang ingin dicari: ";
                    string tanggal;
                    cin.ignore();
                    getline(cin, tanggal);
                    int indexTanggal = binarySearchAscending(data, tanggal);
                    if (indexTanggal != -1) {
                        cout << "\nTanggal ditemukan pada indeks: " << indexTanggal + 1 << endl;
                        cout << "Nama: " << data.bahasa[indexTanggal].nama << endl;
                        cout << "Deskripsi: " << data.bahasa[indexTanggal].deskripsi << endl;
                        cout << "Tanggal: " << data.bahasa[indexTanggal].tanggal << endl;
                    } else {
                        cout << "Tanggal tidak ditemukan." << endl;
                    }
                    break;
                }
                break;
            case 8:
                cout << "Baibaiii" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan pilih kembali." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    } while (pilihan != 8);

    return 0;
}