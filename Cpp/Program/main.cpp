#include <bits/stdc++.h>
#include "Dpr.cpp"

using namespace std;

int main(){
    // deklarasi menu dari class menu
    Menu menU;
    int menu = 0;
    // print menu awal
    cout << '\n' << " Selamat datang di DBMS 최주우" << '\n';
    while (menu != 5){ // keluar program saat exit
        cout << '\n' << " Silahkan Pilih Menu Di bawah ini" << '\n';
        cout << '\n' << " 1. Tambah Data" << '\n';
        cout << '\n' << " 2. Update Data" << '\n';
        cout << '\n' << " 3. Hapus Data" << '\n';
        cout << '\n' << " 4. Tampil Data" << '\n';
        cout << '\n' << " 5. Exit" << '\n';
        cout << '\n' << " Ketikkan angka menu :  " << ends;
        
        cin >> menu;
        if (menu == 1){ // kalau tambah data
            cout << '\n' << " Masukkan Jumlah data yang akan ditambahkan " << '\n'<< ' ';
            int i, n = 0;

            string name, id, bidang, partai;

            // input amount of people
            cin >> n;
            // scanf data sesuai masukan n
            for (i = 1; i < n+1; i++){
                if (i == 1 ){
                    cout << '\n' << " Input Data Id DPR Pertama " << '\n' << ' ';
                }else{
                    cout << '\n' << " Input Data Id DPR ke -" << i <<'\n' << ' ';
                }

                // Atribu input
                cin >> id;

                if (i == 1 ){
                    cout << '\n' << " Input Data Nama DPR Pertama " << '\n' << ' ';
                }else{
                    cout << '\n' << " Input Data Nama DPR ke -" << i <<'\n' << ' ';
                }
                // Atribu input
                cin >> name;
                if (i == 1 ){
                    cout << '\n' << " Input Data Bidang DPR Pertama " << '\n' << ' ';
                }else{
                    cout << '\n' << " Input Data Bidang DPR ke -" << i <<'\n' << ' ';
                }
                // Atribu input
                cin >> bidang;
                if (i == 1 ){
                    cout << '\n' << " Input Data Partai DPR Pertama " << '\n' << ' ';

                }else{
                    cout << '\n' << " Input Data Partai DPR ke -" << i <<'\n'<<' ';
                }
                // Atribu input
                cin >> partai;
                // panggil method untuk tmabah data
                menU.add_anggota(Dpr(id,name,bidang,partai));
                
            }
            cout << '\n' << " Data added succesfully " << '\n';

        }else if( menu == 4){ // print data
            menU.show_anggota();
        }else if (menu == 5){ // exit
            cout << '\n' << " Bye See You Next Time" << '\n';                
        }else if (menu == 2){ // update data
            menU.update_anggota();
        }else if (menu == 3){ // hapus data
            menU.delete_anggota();
        }else{ // kalau tidak sesuai menu
            cout << " Inputan Tidak sesuai, please try again!!" << '\n';
        }
    }
    
    return 0;   
}
