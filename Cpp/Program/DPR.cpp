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

// class declaration for c++
class Menu{
    // pruvate methods
    private:
        list<Dpr> llist;
    // public merthods
    public:
        Menu(){ // kontruktor
        }

        void add_anggota(const Dpr& anggota){// kontruktor
            llist.push_back(anggota);
        }
        void update_anggota(){
            string targetID = "";
            while (targetID != "exit" &&targetID != "cancel" ){
                cout << '\n' << " Masukkan Id Anggota DPR yang datanya ingin di-update: (exit : cancel)" << '\n' << ' '; 

                cin >> targetID;
                if(targetID != "exit" &&targetID != "cancel" ){
                    auto it = find_if(llist.begin(), llist.end(), [targetID](Dpr& anggota) {
                        return anggota.get_id() == targetID;
                    });

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

                        cin >> update;
                        // transform input to lowercase
                        if (update == "yes" || update == "y" ){
                            it->set_name(name);
                            it->set_bidang(bidang);
                            it->set_partai(partai);
                            cout << '\n' << " Update data succesfully " << '\n' << ' ';
                        }

                    } else {
                        // anggota with the target ID not found
                        cout << '\n' << " No DPR found with ID " << targetID << ". Please Try Again!" << endl;
                    }
                }
            }
        }
        void delete_anggota(){
            string targetID = "", del;
            while (targetID != "exit" &&targetID != "cancel" ){
                cout << '\n' << " Masukkan Id Anggota DPR yang datanya ingin dihapus: (exit : cancel)" << '\n' << ' ';
                cin >> targetID;

                if(targetID != "exit" &&targetID != "cancel" ){
                    // Use find_if to get data with ID yang sama dengan targetID 
                
                    auto newEnd = find_if(llist.begin(), llist.end(), [targetID](Dpr& anggota) {
                        return anggota.get_id() == targetID;
                    });

                    // Check if any elements were removed
                    if (newEnd != llist.end()) {
                        cout << '\n' << " DPR with ID " << targetID << " found:" << endl;
                        cout << " Name: " << newEnd->get_name() << ", Bidang: " << newEnd->get_bidang() << ", Partai: " << newEnd->get_partai() << endl;

                        cout << '\n' << " Are you sure want to delete this data???? (yes/ no)"<< '\n'<< ' ';
                        cin >> del;
                        if (del == "yes" || del == "y" ){
                            llist.erase(newEnd);
                            cout << '\n' << " Data with ID " << targetID << " has been Deleted" << "." << endl;
                        }
                        // Use erase to remove the elements from the list
                    } else {
                        // anggota with the target ID not found
                        cout << '\n' << " No DPR found with ID " << targetID << "." << endl;
                    }
                }
            }
        }
        void show_anggota(){
            if (this->llist.empty()){
                cout << '\n' << "   Sorry There's No Data on the List" << '\n';    
            }else{
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
