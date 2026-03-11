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

void garis(){
    cout<<"+----+---------------+---------------+-----------+"<<endl;
}

void garis(int panjang){
    for(int i=0;i<panjang;i++){
        cout<<"-";
    }
    cout<<endl;
}

void tambahHero(Hero hero[], int &jumlahHero){
    cout<<endl<<"=== TAMBAH HERO ==="<<endl;

    cout<<"Nama Hero : "; cin>>hero[jumlahHero].nama;
    cout<<"Role Hero : "; cin>>hero[jumlahHero].role;
    cout<<"Tingkat Kesulitan (Easy/Medium/Hard): "; cin>>hero[jumlahHero].kesulitan;

    jumlahHero++;
}

void lihatHero(Hero hero[], int jumlahHero){
    cout<<endl<<"=== DATA HERO ==="<<endl;

    garis();
    cout<<"| No | Nama Hero     | Role          | Kesulitan |"<<endl;
    garis();

    for(int i=0;i<jumlahHero;i++){
        cout<<"| "<<setw(2)<<i+1<<" "
            <<"| "<<setw(13)<<left<<hero[i].nama
            <<"| "<<setw(13)<<left<<hero[i].role
            <<"| "<<setw(9)<<left<<hero[i].kesulitan
            <<"|"<<endl;
    }

    garis();
}

void ubahHero(Hero hero[], int jumlahHero){
    int nomorhero;

    lihatHero(hero, jumlahHero);

    cout<<"Pilih nomor hero yang diubah : ";
    cin>>nomorhero;
    nomorhero--;

    cout<<"Nama baru : "; cin>>hero[nomorhero].nama;
    cout<<"Role baru : "; cin>>hero[nomorhero].role;
    cout<<"Kesulitan baru : "; cin>>hero[nomorhero].kesulitan;
}

void hapusHero(Hero hero[], int &jumlahHero){
    int no;

    lihatHero(hero, jumlahHero);

    cout<<"Pilih nomor hero yang dihapus : ";
    cin>>no;
    no--;

    for(int i=no;i<jumlahHero;i++){
        hero[i] = hero[i+1];
    }

    jumlahHero--;
}

int main(){

    if(login()==false){
        cout<<"Kesempatan login habis"<<endl;
        return 0;
    }

    int pilihanmenu;

    do{
        cout<<endl<<"=== MENU HERO MOBILE LEGENDS ==="<<endl;
        cout<<"1. Tambah Hero"<<endl;
        cout<<"2. Lihat Hero"<<endl;
        cout<<"3. Ubah Hero"<<endl;
        cout<<"4. Hapus Hero"<<endl;
        cout<<"5. Keluar"<<endl;

        cout<<"Pilih : ";
        cin>>pilihanmenu;

        switch(pilihanmenu){
            case 1: tambahHero(hero, jumlahHero); break;
            case 2: lihatHero(hero, jumlahHero); break;
            case 3: ubahHero(hero, jumlahHero); break;
            case 4: hapusHero(hero, jumlahHero); break;
            case 5: cout<<"Program selesai"<<endl; break;
        }

    }while(pilihanmenu != 5);

    return 0;
}