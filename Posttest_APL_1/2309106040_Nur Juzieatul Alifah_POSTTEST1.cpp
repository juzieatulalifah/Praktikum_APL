#include <iostream>
#include <limits> 

using namespace std;

int main() {
    int pilih;
    int salah = 0;
    bool berhasil = false;
    double rupiah = 0, dollar = 0, yen = 0, euro = 0;
    int pilihan;

    while (true) {
        cout << "Menu" << endl;
        cout << "1. Log in " << endl;
        cout << "2. Exit" << endl;
        cout << "Masukkan Pilihan (1/2) : ";
        
        // Memastikan input adalah angka
        if (!(cin >> pilih)) {
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        string username, password;

        switch (pilih) {
            case 1:
                cout << "Masukkan Username anda : ";
                cin.ignore();
                getline(cin, username);
                cout << "Masukkan password anda : ";
                getline(cin, password);
                if (username == "Nur Juzieatul Alifah" && password == "2309106040") {
                    cout << "Login Berhasil" << endl;
                    berhasil = true;
                    break;
                } else {
                    salah++;
                    if (salah < 3) {
                        cout << "Username atau Password salah! Silakan coba lagi." << endl;
                    } else {
                        cout << "Anda telah mencoba login sebanyak 3 kali. Program akan berhenti." << endl;
                        cin.ignore();
                        return 0;
                    }
                }
                break;
            case 2:
                cout << "Bye bye." << endl;
                return 0; // Keluar dari program (Exit)
            default:
                cout << "Pilihan tidak valid. Silakan pilih (1/2)." << endl;
        }
        
        if (berhasil) {
            do {
                cout << "Menu Konversi uang" << endl;
                cout << "1. Rupiah Ke Dollar, Yen, Euro" << endl;
                cout << "2. Dollar Ke Rupiah, Yen, Euro" << endl;
                cout << "3. Yen ke Rupiah, Dollar, Euro" << endl;
                cout << "4. Euro ke Rupiah, Dollar, Yen" << endl;
                cout << "5. Exit" << endl;
                cout << "Masukkan Pilihan (1/2/3/4/5): ";
                
                // Memastikan input adalah angka
                if (!(cin >> pilihan)) {
                    cout << "Input tidak valid. Silakan masukkan angka." << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue;
                }
                 switch (pilihan) {
                    case 1:
                        cout << "Masukkan Nilai Rupiah anda: ";
                        cin >> rupiah;

                        dollar = rupiah * 0.000070;
                        yen = rupiah * 0.0077;
                        euro = rupiah * 0.000061;

                        cout << rupiah << " Rupiah adalah " << dollar << " Dollar, " << yen << " Yen, " << euro << " Euro." << endl;
                        cout << endl;
                        break;

                    case 2:
                        cout << "Masukkan nilai Dollar Anda: ";
                        cin >> dollar;

                        rupiah = dollar * 14300;
                        yen = dollar * 110.64;
                        euro = dollar * 0.88;

                        cout << dollar << " Dollar adalah " << rupiah << " Rupiah, " << yen << " Yen, " << euro << " Euro." << endl;
                        cout << endl;
                        break;

                    case 3:
                        cout << "Masukkan nilai Yen Anda: ";
                        cin >> yen;

                        rupiah = yen * 182.31;
                        dollar = yen * 0.0090;
                        euro = yen * 0.0078;

                        cout << yen << " Yen adalah " << rupiah << " Rupiah, " << dollar << " Dollar, " << euro << " Euro." << endl;
                        cout << endl;
                        break;

                    case 4:
                        cout << "Masukkan nilai euro Anda: ";
                        cin >> euro;

                        rupiah = euro * 16238.50;
                        dollar = euro * 1.14;
                        yen = euro * 129.53;

                        cout << euro << " Euro adalah " << rupiah << " Rupiah, " << dollar << " Dollar, " << yen << " Yen." << endl;
                        cout << endl;
                        break;

                    case 5 :
                        cout << "baibaii" << endl;
                        return 0;
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan pilih (1/2/3/4/5)." << endl;

                }
            } while (pilihan != 5); 
            }
        }
    }

