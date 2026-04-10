#include <iostream>
#include <iomanip>
using namespace std;

struct Hero{
    string nama;
    string role;
    string kesulitan;
    int level;
};

Hero hero[100] = {
    {"Ling","Assassin","Hard",90},
    {"Tigreal","Tank","Easy",70},
    {"Kagura","Mage","Hard",85},
    {"Beatrix","Marksman","Medium",80},
    {"Fredrinn","Fighter","Medium",75}
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
    cout<<"+----+---------------+---------------+-----------+--------+"<<endl;
}

void tambahHero(Hero *hero, int *jumlahHero){
    cout<<endl<<"=== TAMBAH HERO ==="<<endl;

    cout<<"Nama Hero : "; cin>>hero[*jumlahHero].nama;
    cout<<"Role Hero : "; cin>>hero[*jumlahHero].role;
    cout<<"Kesulitan : "; cin>>hero[*jumlahHero].kesulitan;
    cout<<"Level     : "; cin>>hero[*jumlahHero].level;

    (*jumlahHero)++;
}

void lihatHero(Hero *hero, int jumlahHero){
    cout<<endl<<"=== DATA HERO ==="<<endl;

    garis();
    cout<<"| No | Nama Hero     | Role          | Kesulitan | Level |"<<endl;
    garis();

    for(int i=0;i<jumlahHero;i++){
        cout<<"| "<<setw(2)<<i+1<<" "
            <<"| "<<setw(13)<<left<<hero[i].nama
            <<"| "<<setw(13)<<left<<hero[i].role
            <<"| "<<setw(9)<<left<<hero[i].kesulitan
            <<"| "<<setw(5)<<hero[i].level<<" |"<<endl;
    }

    garis();
}

void ubahHero(Hero *hero, int jumlahHero){
    int nomorhero;

    lihatHero(hero, jumlahHero);

    cout<<"Pilih nomor hero : ";
    cin>>nomorhero;
    nomorhero--;

    cout<<"Nama baru : "; cin>>hero[nomorhero].nama;
    cout<<"Role baru : "; cin>>hero[nomorhero].role;
    cout<<"Kesulitan baru : "; cin>>hero[nomorhero].kesulitan;
    cout<<"Level baru : "; cin>>hero[nomorhero].level;
}

void hapusHero(Hero *hero, int *jumlahHero){
    int no;

    lihatHero(hero, *jumlahHero);

    cout<<"Pilih nomor hero : ";
    cin>>no;
    no--;

    for(int i=no;i<*jumlahHero-1;i++){
        hero[i] = hero[i+1];
    }

    (*jumlahHero)--;
}

void sortingNamaDesc(Hero *hero, int jumlahHero){
    for(int i=0;i<jumlahHero-1;i++){
        for(int j=i+1;j<jumlahHero;j++){
            if(hero[i].nama < hero[j].nama){
                swap(hero[i], hero[j]);
            }
        }
    }
    cout<<"Sorting Nama Descending berhasil!"<<endl;
}

void sortingLevelAsc(Hero *hero, int jumlahHero){
    for(int i=0;i<jumlahHero-1;i++){
        for(int j=i+1;j<jumlahHero;j++){
            if(hero[i].level > hero[j].level){
                swap(hero[i], hero[j]);
            }
        }
    }
    cout<<"Sorting Level Ascending berhasil!"<<endl;
}

void sortingRoleAsc(Hero *hero, int jumlahHero){
    for(int i=0;i<jumlahHero-1;i++){
        for(int j=i+1;j<jumlahHero;j++){
            if(hero[i].role > hero[j].role){
                swap(hero[i], hero[j]);
            }
        }
    }
    cout<<"Sorting Role Ascending berhasil!"<<endl;
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
        cout<<"5. Sorting Nama (Desc)"<<endl;
        cout<<"6. Sorting Level (Asc)"<<endl;
        cout<<"7. Sorting Role (Asc)"<<endl;
        cout<<"8. Keluar"<<endl;

        cout<<"Pilih : ";
        cin>>pilihanmenu;

        switch(pilihanmenu){
            case 1: tambahHero(hero, &jumlahHero); break;
            case 2: lihatHero(hero, jumlahHero); break;
            case 3: ubahHero(hero, jumlahHero); break;
            case 4: hapusHero(hero, &jumlahHero); break;
            case 5: sortingNamaDesc(hero, jumlahHero); break;
            case 6: sortingLevelAsc(hero, jumlahHero); break;
            case 7: sortingRoleAsc(hero, jumlahHero); break;
            case 8: cout<<"Program selesai"<<endl; break;
        }

    }while(pilihanmenu != 8);

    return 0;
}