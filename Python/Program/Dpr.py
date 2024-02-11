# Definisi class dpr
class Dpr:
    # construct
    def __init__(self): 
        self.id = ""
        self.nama = ""
        self.bidang = ""
        self.partai = ""
    # methods for set the atributs
    def set_nama(self, nama):
        self.nama = nama

    def set_bidang(self, bidang):
        self.bidang = bidang

    def set_partai(self, partai):
        self.partai = partai

    def set_id(self, id):
        self.id = id
    # methods for get the value of each atributs
    def get_id(self):
        return self.id

    def get_bidang(self):
        return self.bidang

    def get_partai(self):
        return self.partai

    def get_nama(self):
        return self.nama

# Definisi class for buat table
class Tabeldpr:
    def __init__(self): # construct
        self.list = []  # list kosong
    # add data anggota to the list 
    def add_anggota(self, anggota):
        self.list.append(anggota)
    # cari anggota berdasarkan id
    def cari_anggota(self, id):
        result = None   # di set null terlebih dahulu
        for anggota in self.list:   # loop for each anggota in list
            if anggota.get_id() == id:  # kalau ketemu id yang sama
                result = anggota    # datanya dimasukkan kedalam result
        return result 
    # update anggota sesuai id
    def update_anggota(self, id, nama, bidang, partai):
        anggota = self.cari_anggota(id) # cari data anggota  dengan id tersebut ada  tau tdk
        if anggota: # kalau ada update datanya dengan method yg sudah dibuat
            anggota.set_nama(nama)
            anggota.set_bidang(bidang)
            anggota.set_partai(partai)
    # delete dta sesuai id
    def delete_anggota(self, id): 
        for anggota in self.list: #loop for each anggota in list to get daat with the same id as yhe inout
            if anggota.get_id() == id: # if ketemu 
                self.list.remove(anggota) # do remove 
                print(f"Anggota dengan ID {id} berhasil dihapus.\n")
                return # stop the for
        print(f"Maaf anggota dengan ID {id} tidak ditemukan.\n") # if theres no data with the same id
    # method for show  data on the table
    def tampil_tabel(self):
        if not self.list: # if list still empty
            print("Data Masih Kosong, Silakan Tambah Data Terlebih Dahulu!\n")
        else: # if theres any data on the list
            # looking for the max len for each atribut
            max_len_id = max(len(anggota.get_id()) for anggota in self.list)
            max_len_nama = max(len(anggota.get_nama()) for anggota in self.list)
            max_len_bidang = max(len(anggota.get_bidang()) for anggota in self.list)
            max_len_partai = max(len(anggota.get_partai()) for anggota in self.list)

            all_max_len = 0
            # hitung all max len
            if max_len_id > 2:
                all_max_len += max_len_id - 2
            if max_len_nama > 4:
                all_max_len += max_len_nama - 4
            if max_len_bidang > 6:
                all_max_len += max_len_bidang - 6
            if max_len_partai > 6:
                all_max_len += max_len_partai - 6

            print("+-------------------------------------" + "-" * all_max_len + "+")
            print("|  DATA ANGGOTA DPR RI                " + " " * all_max_len + "|")
            # kerangka
            print("+------" + ( "-"*(max_len_id - 2) if max_len_id > 2 else "") + "+--------" + ("-" * (max_len_nama - 4) if max_len_nama > 4 else "") +
                  "+----------" + ("-" * (max_len_bidang - 6) if max_len_bidang > 6 else "") + "+----------" + ("-" * (max_len_partai - 6) if max_len_partai > 6 else "") + "+")
            # headings
            print( "|  ID  " + (' ' * (max_len_id - 2) if max_len_id >2 else '') +
                    "|  NAMA  " + (' ' * (max_len_nama - 4)if max_len_nama > 4 else '' )+
                    "|  BIDANG  " + (' ' * (max_len_bidang - 6) if max_len_bidang >6 else '') +
                    "|  PARTAI  " + (' ' * (max_len_partai - 6) if max_len_partai>6 else '') +
                    "|")

            # kerangka
            print("+------" + ( "-"*(max_len_id - 2) if max_len_id > 2 else "") + "+--------" + ("-" * (max_len_nama - 4) if max_len_nama > 4 else "") +
                  "+----------" + ("-" * (max_len_bidang - 6) if max_len_bidang > 6 else "") + "+----------" + ("-" * (max_len_partai - 6) if max_len_partai > 6 else "") + "+")
            # data
            for anggota in self.list:
                print("|  " + anggota.get_id() + (' ' * (max_len_id - len(anggota.get_id())) if max_len_id > 2 else ' ' * (2 - len(anggota.get_id())))+
                    "  |  " + anggota.get_nama() + (' ' * (max_len_nama - len(anggota.get_nama())) if max_len_nama > 4 else ' ' * (4 - len(anggota.get_nama())) )+
                    "  |  " + anggota.get_bidang() + (' ' * (max_len_bidang - len(anggota.get_bidang())) if max_len_bidang > 6 else ' ' * (6 - len(anggota.get_bidang()))) +
                    "  |  " + anggota.get_partai() + (' ' * (max_len_partai - len(anggota.get_partai())) if max_len_partai > 6 else ' ' * (6- len(anggota.get_partai())))+ "  |")

            # kerangka
            print("+------" + ( "-"*(max_len_id - 2) if max_len_id > 2 else "") + "+--------" + ("-" * (max_len_nama - 4) if max_len_nama > 4 else "") +
                  "+----------" + ("-" * (max_len_bidang - 6) if max_len_bidang > 6 else "") + "+----------" + ("-" * (max_len_partai - 6) if max_len_partai > 6 else "") + "+\n")

