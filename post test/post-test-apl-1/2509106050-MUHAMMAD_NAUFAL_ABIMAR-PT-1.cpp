#include <iostream>
using namespace std;

int main() {

    string username, password;
    int kesempatan = 0;

    while (kesempatan < 3) {
        cout << "===== LOGIN =====" << endl;
        cout << "Masukkan Username : ";
        cin >> username;
        cout << "Masukkan Password : ";
        cin >> password;

        if (username == "050" && password == "050") {
            cout << "Login berhasil" << endl;
            break;
        } else {
            cout << "Login gagal" << endl;
            kesempatan++;
        }
    }

    if (kesempatan == 3) {
        cout << "password atau ussername anda salah." << endl;
        return 0;
    }

    int pilihan;

    do {
        cout << endl;
        cout << "===== MENU KONVERSI =====" << endl;
        cout << "1. Jam ke Menit dan Detik" << endl;
        cout << "2. Menit ke Jam dan Detik" << endl;
        cout << "3. Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jam;
            cout << "Masukkan jam: ";
            cin >> jam;
            cout << "Menit : " << jam * 60 << endl;
            cout << "Detik : " << jam * 3600 << endl;
        }
        else if (pilihan == 2) {
            int menit;
            cout << "Masukkan menit: ";
            cin >> menit;
            cout << "Jam   : " << menit / 60 << endl;
            cout << "Detik : " << menit * 60 << endl;
        }
        else if (pilihan == 3) {
            int detik;
            cout << "Masukkan detik: ";
            cin >> detik;
            cout << "Jam   : " << detik / 3600 << endl;
            cout << "Menit : " << detik / 60 << endl;
        }
        else if (pilihan == 4) {
            cout << "Terima kasih" << endl;
        }
        else {
            cout << "Pilihan tidak tersedia" << endl;
        }

    } while (pilihan != 4);

    return 0;
}