#include <bits/stdc++.h>
#include "Dpr.cpp"


using namespace std;

int main(){

    Menu menU;
    int menu = 0;
    cout << '\n' << " Selamat datang di DBMS 최주우" << '\n';
    while (menu != 5){
        cout << '\n' << " Silahkan Pilih Menu Di bawah ini" << '\n';
        cout << '\n' << " 1. Tambah Data" << '\n';
        cout << '\n' << " 2. Update Data" << '\n';
        cout << '\n' << " 3. Hapus Data" << '\n';
        cout << '\n' << " 4. Tampil Data" << '\n';
        cout << '\n' << " 5. Exit" << '\n';
        cout << '\n' << " Ketikkan angka menu :  " << ends;
        
        cin >> menu;
        if (menu == 1){
            cout << '\n' << " Masukkan Jumlah data yang akan ditambahkan " << '\n'<< ' ';
            int i, n = 0;

            string name, id, bidang, partai;

            // input amount of people
            cin >> n;
            for (i = 1; i < n+1; i++){
                // temporary object
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
                menU.add_anggota(Dpr(id,name,bidang,partai));
                
            }
            cout << '\n' << " Data added succesfully " << '\n';

        }else if( menu == 4){
            menU.show_anggota();

        }else if (menu == 5){
            cout << '\n' << " Bye See You Next Time" << '\n';                
        }else if (menu == 2){
            menU.update_anggota();
        }else if (menu == 3){
            menU.delete_anggota();
        }else{
            cout << " Inputan Tidak sesuai, please try again!!" << '\n';
        }
    }
    
    return 0;   
}