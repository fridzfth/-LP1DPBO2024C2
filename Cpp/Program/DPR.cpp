// libtrary import
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
// standard namespace
using namespace std;

// class declaration for c++
class Dpr{
    // pruvate methods
    private:
        string id;
        string name;
        string bidang;
        string partai;
        
    // public merthods
    public:
        Dpr(){ // kontruktor
            this->name = "";
            this->bidang ="";
            this->id = "";
            this->partai="";
        }

        Dpr(string id, string name, string bidang, string partai){// kontruktor
            this->name = name;
            this->bidang = bidang;
            this->id = id;
            this->partai=partai;
        }
        void set_name(string xp){ // set name 
            this->name = xp;
        }
        void set_id(string yp){ // set id
            this->id = yp;
        }
        void set_bidang(string zp){ // set bdg
            this->bidang = zp;
        }
        void set_partai(string p){ // set partai
            this->partai = p;
        }

        string get_name(){ // return nama
            return this->name;
        }
        string get_bidang(){ // return nama
            return this->bidang;
        }
        string get_id(){ // return nama
            return this->id;
        }
        string get_partai(){ // return nama
            return this->partai;
        }
        ~Dpr(){
            //destructor
        }
};

// class untuk pilihan menu
class Menu{
    // private methods
    private:
        list<Dpr> llist; // list dari kumpulan Dpr
    // public merthods
    public:
        Menu(){ // kontruktor
        }
        // methods untuk add anggota
        void add_anggota(const Dpr& anggota){
            llist.push_back(anggota); // push data DPR ke dalam list
        }
        // methods untuk update anggota    
        void update_anggota(){
            string targetID = ""; // deklarasi string id target yang mau diupdate
            while (targetID != "exit" &&targetID != "cancel" ){ // akan berhenti jika inputan exit atau cancel
                cout << '\n' << " Masukkan Id Anggota DPR yang datanya ingin di-update: (exit : cancel)" << '\n' << ' '; 
                // input id target yang mau di update
                cin >> targetID;
                if(targetID != "exit" &&targetID != "cancel" ){ // cekk apakah perintah exit atau bukan
                    // mencari data yang idnya sama dengan targetID
                    auto it = find_if(llist.begin(), llist.end(), [targetID](Dpr& anggota) { // find_if (fungsi dr pack algo)
                        return anggota.get_id() == targetID;
                    });
                    // jika ada id yang sam dengan target
                    if (it != llist.end()) {
                        string update, name, bidang, partai;  
                        // anggota with the target ID found
                        cout << '\n' << " DPR with ID " << targetID << " found:" << endl;
                        cout << " Name: " << it->get_name() << ", Bidang: " << it->get_bidang() << ", Partai: " << it->get_partai() << endl;
                        
                        // atribut update input
                        cout << '\n' << " Input DPR Name Update " << '\n' << ' ';
                        cin >> name;
                        cout << '\n' << " Input DPR Bidang Update " << '\n' << ' ';
                        cin >> bidang;
                        cout << '\n' << " Input DPR Partai Update " << '\n' << ' ';
                        cin >> partai;

                        cout << '\n' << " Are you sure want to update DPR with ID " << targetID << " from" << '\n';
                        cout << " this -> Name: " << it->get_name() << ", Bidang: " << it->get_bidang() << ", Partai: " << it->get_partai() << endl;
                        cout << " to -> Name: "<<  name << ", Bidang: " << bidang << ", Partai: " << partai << " ?(yes/ no)" << '\n' << ' ';
                        // input apakah user sure mau di update or no
                        cin >> update;
                        // kalau yes maka update
                        if (update == "yes" || update == "y" ){
                            it->set_name(name);
                            it->set_bidang(bidang);
                            it->set_partai(partai);
                            cout << '\n' << " Update data succesfully " << '\n' << ' ';
                        }
                        // id target doesnot found
                    } else {
                        // anggota with the target ID not found
                        cout << '\n' << " No DPR found with ID " << targetID << ". Please Try Again!" << endl;
                    }
                }
            }
        }
        // methods untuk hapus data dari list
        void delete_anggota(){
            string targetID = "", del;
            while (targetID != "exit" &&targetID != "cancel" ){ // hampir sama dengan update jika belum ccl/ ex maka aka terus meminta input
                cout << '\n' << " Masukkan Id Anggota DPR yang datanya ingin dihapus: (exit : cancel)" << '\n' << ' ';
                cin >> targetID;
                // kalau bukan kata kunci exit atau cancel
                if(targetID != "exit" &&targetID != "cancel" ){
                    // Use find_if to get data with ID yang sama dengan targetID 
                    auto newEnd = find_if(llist.begin(), llist.end(), [targetID](Dpr& anggota) {
                        return anggota.get_id() == targetID;
                    });

                    // Check if target is found
                    if (newEnd != llist.end()) {
                        cout << '\n' << " DPR with ID " << targetID << " found:" << endl;
                        cout << " Name: " << newEnd->get_name() << ", Bidang: " << newEnd->get_bidang() << ", Partai: " << newEnd->get_partai() << endl;

                        cout << '\n' << " Are you sure want to delete this data???? (yes/ no)"<< '\n'<< ' ';
                        // input apaah user yakin or no
                        cin >> del;
                        if (del == "yes" || del == "y" ){
                            // Use erase to remove the elements from the list kalau user yakin
                            llist.erase(newEnd);
                            cout << '\n' << " Data with ID " << targetID << " has been Deleted" << "." << endl;
                        }
                    } else {
                        // anggota with the target ID not found
                        cout << '\n' << " No DPR found with ID " << targetID << "." << endl;
                    }
                }
            }
        }
        // print list angggota
        void show_anggota(){
            // jika list kosong
            if (this->llist.empty()){
                cout << '\n' << "   Sorry There's No Data on the List" << '\n';    
            }else{
                // jika list berisi
                cout << '\n' << " Here's Your Data Sir : " << '\n';
                int i = 0;
                for ( list<Dpr>::iterator it = llist.begin();it != llist.end(); it++){
                    cout << "  "<< (i+1 )<<". "<< it->get_id() << " | "<<it->get_name() << " | " << it->get_bidang() << " | " << it->get_partai() << '\n';
                    i++;
                }
            }
        }

        ~Menu(){
            //destructor
        }
};
