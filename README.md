# LP1DPBO2024C2 - Data Pusat DPR RI Program 
# C++ Version
## Overview
This C++ program manages and displays information about members of the Indonesian People's Consultative Assembly (Dewan Perwakilan Rakyat or DPR). It consists of two classes: `Dpr` for individual member details and `Menu` for managing a list of members and performing operations such as adding, updating, deleting, and displaying data.
## Author
Saya Mohammad Faridz Fathin mengerjakan LP1 dalam mata kuliah
DPBO untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
## Classes

### 1. Dpr Class
This class represents an individual member of the DPR and includes the following attributes:

- `id`: Member's unique identifier.
- `name`: Member's name.
- `bidang`: Member's field or area of expertise.
- `partai`: Member's political party affiliation.

#### Methods
- `Dpr()`: Constructor to initialize the attributes.
- `Dpr(string id, string name, string bidang, string partai)`: Overloaded constructor to set attributes with initial values.
- `set_name(string xp)`: Set the name attribute.
- `set_id(string yp)`: Set the unique identifier attribute.
- `set_bidang(string zp)`: Set the field attribute.
- `set_partai(string p)`: Set the political party attribute.
- `get_name()`: Retrieve the name attribute.
- `get_bidang()`: Retrieve the field attribute.
- `get_id()`: Retrieve the unique identifier attribute.
- `get_partai()`: Retrieve the political party attribute.
- `~Dpr()`: Destructor.

### 2. Menu Class
This class manages a list of `Dpr` instances and provides methods for adding, updating, deleting, and displaying member data.

#### Methods
- `Menu()`: Constructor to initialize the list.
- `add_anggota(const Dpr& anggota)`: Add a member to the list.
- `update_anggota()`: Update member data based on the unique identifier.
- `delete_anggota()`: Delete a member from the list based on the unique identifier.
- `show_anggota()`: Display member data.
- `~Menu()`: Destructor.

## Program Execution
The main program starts by creating an instance of the `Menu` class, allowing users to interact with the data. The program menu includes options to add, update, delete, display data, and exit the program.

### Example Usage
1. Choose "1" to add data. Enter the number of data entries to add and provide the required information (id, name, bidang, partai) for each member.
2. Choose "2" to update data. Enter the id of the member to update and input the new information (name, bidang, partai).
3. Choose "3" to delete data. Enter the id of the member to delete.
4. Choose "4" to display the data.
5. Choose "5" to exit the program.

Note: The program includes validation for invalid menu options and provides appropriate messages for user feedback.
# Program Flow - Data Pusat DPR RI Program (C++ Version)

1. **Library Import:**
   - Import necessary C++ libraries, including iostream, string, list, and algorithm.

2. **Namespace:**
   - Use the standard namespace for C++.

3. **Class Declaration - Dpr:**
   - Declare the `Dpr` class with private attributes (id, name, bidang, partai) and public methods for setting and getting attributes.

4. **Class Declaration - Menu:**
   - Declare the `Menu` class with private list (llist) and public methods for adding, updating, deleting, and displaying member data.

5. **Main Function:**
   - Include the necessary headers, including "Dpr.cpp," where the implementation of the `Dpr` class is defined.

6. **Menu Instance Creation:**
   - Create an instance of the `Menu` class called `menU`.

7. **Menu Loop:**
   - Enter a loop that continues until the user chooses to exit (menu = 5).

8. **Print Main Menu:**
   - Display the main menu with options to add data, update data, delete data, display data, and exit.

9. **Menu Input:**
   - Prompt the user to input a menu choice.

10. **Menu Options Handling:**
    - Based on the user's input, execute one of the following:
        - **Option 1 (Add Data):**
            - Prompt the user for the number of data entries to add.
            - For each entry, input id, name, bidang, and partai.
            - Add the data to the list using the `add_anggota` method.
            - Display a success message.

        - **Option 2 (Update Data):**
            - Prompt the user to input the id of the member to update.
            - Search for the member with the specified id.
            - If found, prompt the user to input updated name, bidang, and partai.
            - Confirm the update and execute it.
            - Display a success message.

        - **Option 3 (Delete Data):**
            - Prompt the user to input the id of the member to delete.
            - Search for the member with the specified id.
            - If found, prompt the user to confirm deletion.
            - If confirmed, delete the member from the list.
            - Display a success message.

        - **Option 4 (Display Data):**
            - Call the `show_anggota` method to display the list of members.

        - **Option 5 (Exit):**
            - Display a farewell message and exit the program.

        - **Invalid Option:**
            - Display an error message for invalid menu choices.

11. **Exit Program:**
    - End the loop and exit the program.

# Example Usage:
```
Selamat datang di DBMS 최주우

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  1

Masukkan Jumlah data yang akan ditambahkan 
2

Input Data Id DPR Pertama 
101

Input Data Nama DPR Pertama 
John

Input Data Bidang DPR Pertama 
Economics

Input Data Partai DPR Pertama 
ABC

Input Data Id DPR ke -2
102

Input Data Nama DPR ke -2
Alice

Input Data Bidang DPR ke -2
Engineering

Input Data Partai DPR ke -2
XYZ

Data added succesfully 

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  4

Here's Your Data Sir : 
  1. 101 | John | Economics | ABC
  2. 102 | Alice | Engineering | XYZ

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  2

Masukkan Id Anggota DPR yang datanya ingin di-update: (exit : cancel)
101

DPR with ID 101 found:
 Name: John, Bidang: Economics, Partai: ABC

Input DPR Name Update 
Johnny

Input DPR Bidang Update 
Finance

Input DPR Partai Update 
XYZ

Are you sure want to update DPR with ID 101 from
 this -> Name: John, Bidang: Economics, Partai: ABC
 to -> Name: Johnny, Bidang: Finance, Partai: XYZ ?(yes/ no)
yes

Update data succesfully 

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  4

Here's Your Data Sir : 
  1. 101 | Johnny | Finance | XYZ
  2. 102 | Alice | Engineering | XYZ

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  3

Masukkan Id Anggota DPR yang datanya ingin dihapus: (exit : cancel)
102

DPR with ID 102 found:
 Name: Alice, Bidang: Engineering, Partai: XYZ

Are you sure want to delete this data???? (yes/ no)
yes

Data with ID 102 has been Deleted.

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  4

Here's Your Data Sir : 
  1. 101 | Johnny | Finance | XYZ

Silahkan Pilih Menu Di bawah ini

1. Tambah Data
2. Update Data
3. Hapus Data
4. Tampil Data
5. Exit
Ketikkan angka menu :  5

Bye See You Next Time
```
