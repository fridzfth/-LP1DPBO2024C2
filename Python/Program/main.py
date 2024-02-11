# Saya Mohammad Faridz Fathin [2202680] mengerjakan LP1 dalam mata kuliah DPBO untuk keberkahanNya maka saya 
# tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
from Dpr import Dpr
from Dpr import Tabeldpr

menu = 0    #inisialisasi ,enu set 0
tabel = Tabeldpr() # instansiasi new tabeldpr

while menu != 5:    # stop ask for input till user input num 5 aka ex
    print("Selamat Datang di DATA PUSAT DPR RI")
    print("1. Tambah Data")
    print("2. Update Data")
    print("3. Hapus Data")
    print("4. Tampil")
    print("5. Exit")
    menu = int(input("Silahkan Pilih menu berikut : ")) #scan menu

    if menu == 4:   #show data table
        tabel.tampil_tabel() 
    elif menu == 1: # add data to the list
        print("Berapa banyak data yang ingin ditambah ? ")
        n = int(input()) # amount of data that u wanna input to the list
        for _ in range(n): # loop sebanyak n
            temp = Dpr()    # instantiation new Dpr  temporary beofre di append ke dalalm list
            print("Silahkan input data (id, nama, bidang, partai)")
            masukan = input().split()
            temp.set_id(masukan[0]) # set temp sesuai masukan
            temp.set_nama(masukan[1])
            temp.set_bidang(masukan[2])
            temp.set_partai(masukan[3])
            tabel.add_anggota(temp) # apppend data to teh list
            temp = Dpr() 
        print(f"{n} Data berhasil ditambahkan\n")
    elif menu == 2: # update data
        print("Silakan ketik id data yang ingin anda update : ")
        id_data = input() # scan id
        if tabel.cari_anggota(id_data): # kalau ada datanya
            print("Data ditemukan, silakan input data (nama, bidang, partai)")
            masukan = input().split() # input data input 
            tabel.update_anggota(id_data, masukan[0], masukan[1], masukan[2])
            print(f"Anggota dengan ID {id_data} berhasil diupdate.\n")
        else: # if data does not found
            print(f"Maaf anggota dengan ID {id_data} tidak ditemukan.\n")
    elif menu == 3: # delete data
        print("Silakan ketik id data yang ingin anda hapus : ")
        id_data = input() # scan id
        tabel.delete_anggota(id_data) # remove data
    elif menu == 5: # exit
        print("Bye 2x")
    else: # default
        print("Mohon maaf pilihan tidak ada dalam menu.\n")
