#include <iostream>
#include <iomanip>
using namespace std;

struct Hero{
    string nama;
    string role;
    string kesulitan;
};

Hero hero[100] = {
    {"Ling","Assassin","Hard"},
    {"Tigreal","Tank","Easy"},
    {"Kagura","Mage","Hard"},
    {"Beatrix","Marksman","Medium"},
    {"Fredrinn","Fighter","Medium"}
};

int jumlahHero = 5;

bool login(){
    string username, password;
    int percobaan = 0;

    while(percobaan < 3){
        cout<<"=== LOGIN ==="<<endl;
        cout<<"Masukkan Nama : "; cin>>username;
        cout<<"Masukkan NIM  : "; cin>>password;

        if(username == "050" && password == "050"){
            cout<<"Login berhasil!"<<endl;
            return true;
        }

        percobaan++;
        cout<<"Login gagal! Sisa percobaan "<<3-percobaan<<endl;
    }
    return false;
}

int tambahHero(){
    cout<<endl<<"=== TAMBAH HERO ==="<<endl;

    cout<<"Nama Hero : "; cin>>hero[jumlahHero].nama;
    cout<<"Role Hero : "; cin>>hero[jumlahHero].role;
    cout<<"Tingkat Kesulitan (Easy/Medium/Hard): "; cin>>hero[jumlahHero].kesulitan;

    jumlahHero++;
    return 0;
}

int lihatHero(){
    cout<<endl<<"=== DATA HERO ==="<<endl;

    cout<<"+----+---------------+---------------+-----------+"<<endl;
    cout<<"| No | Nama Hero     | Role          | Kesulitan |"<<endl;
    cout<<"+----+---------------+---------------+-----------+"<<endl;

    for(int i=0;i<jumlahHero;i++){
        cout<<"| "<<setw(2)<<i+1<<" "
            <<"| "<<setw(13)<<left<<hero[i].nama
            <<"| "<<setw(13)<<left<<hero[i].role
            <<"| "<<setw(9)<<left<<hero[i].kesulitan
            <<"|"<<endl;
    }

    cout<<"+----+---------------+---------------+-----------+"<<endl;
    return 0;
}

int ubahHero(){
    int no;
    lihatHero();

    cout<<"Pilih nomor hero yang diubah : ";
    cin>>no;
    no--;

    cout<<"Nama baru : "; cin>>hero[no].nama;
    cout<<"Role baru : "; cin>>hero[no].role;
    cout<<"Kesulitan baru : "; cin>>hero[no].kesulitan;

    return 0;
}

int hapusHero(){
    int no;
    lihatHero();

    cout<<"Pilih nomor hero yang dihapus : ";
    cin>>no;
    no--;

    for(int i=no;i<jumlahHero;i++){
        hero[i] = hero[i+1];
    }

    jumlahHero--;
    return 0;
}

int main(){

    if(login()==false){
        cout<<"Program berhenti karena gagal login 3 kali"<<endl;
        return 0;
    }

    int pilih;

    do{
        cout<<endl<<"=== MENU HERO MOBILE LEGENDS ==="<<endl;
        cout<<"1. Tambah Hero"<<endl;
        cout<<"2. Lihat Hero"<<endl;
        cout<<"3. Ubah Hero"<<endl;
        cout<<"4. Hapus Hero"<<endl;
        cout<<"5. Keluar"<<endl;

        cout<<"Pilih : ";
        cin>>pilih;

        switch(pilih){
            case 1: tambahHero(); break;
            case 2: lihatHero(); break;
            case 3: ubahHero(); break;
            case 4: hapusHero(); break;
            case 5: cout<<"Program selesai"<<endl; break;
        }

    }while(pilih != 5);

    return 0;
}