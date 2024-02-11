/* Saya Mohammad Faridz Fathin [2202680] mengerjakan LP1 dalam mata kuliah DPBO untuk keberkahanNya maka saya 
tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Definisi kelas DPR
class Dpr {
    // properti dpr
    private String id;
    private String nama;
    private String bidang;
    private String partai;

    // Konstruktor
    public Dpr() {
    }
    // VOID SET ATRIBUT
    public void setNama(String nama) {
        this.nama = nama;
    }
    public void setBidang(String bidang) {
        this.bidang = bidang;
    }
    public void setPartai(String partai) {
        this.partai = partai;
    }
    public void setId(String id) {
        this.id = id;
    }
    // VOID GET ATRIBUT
    public String getId() {
        return this.id;
    }
    public String getBidang() {
        return this.bidang;
    }
    public String getPartai() {
        return this.partai;
    }
    public String getNama() {
        return this.nama;
    }
}   

// Definisi kelas Tabeldpr
class Tabeldpr {
    // atribut
    private List<Dpr> list = new ArrayList<>(); // list to store dpr's datas
    // construct
    public Tabeldpr(){
    }    
    // add to list
    public void addAnggota(Dpr anggota) {
        this.list.add(anggota); // memasukkan data ke dalam list
    }
    // method untuk mencari data anggota dengan id sesuai input
    public Dpr cariAnggota(String id) {
        Dpr result = null; // result di set null terlebih dahulu 
        for (Dpr anggota : this.list) { // loop to search data with id = $id
            if (anggota.getId().equals(id)) { // jika ditemukan id yang sama
                result = anggota; // data anggota tsb disimpan di result 
            }
        }
        return result; 
    }
    // void untuk update anggooa
    public void updateAnggota(String id, String nama, String bidang, String partai, String foto) {
        Dpr anggota = this.cariAnggota(id); // memanggil method yang telah dibuat sebelumnnya untuk menampung data sesuai id
        if (anggota != null) { // kalau data yang dicari ada (not null)
            anggota.setNama(nama); // set/ perbarui data anggota
            anggota.setBidang(bidang);
            anggota.setPartai(partai);
        }
    }
    // void untuk hapus anggota sesuai id masukan
    public void deleteAnggota(String id) {
        for (Dpr anggota : this.list) { // loop to search index($key) data with id = $id
            if (anggota.getId().equals(id)) { // sama seperti sebelumnya jika ketemu id yang sama 
                this.list.remove(anggota); // hapus data dari list
                System.out.println("Anggota dengan ID " + id + " berhasil dihapus.\n" );
                return; // berhenti
            }
        }// jika tidak ada maka akan ditmapilkan pesan demikian
        System.out.println("Maaf anggota dengan ID " + id + " tidak ditemukan.\n" );
    }

    // Metode untuk menampilkan semua data dalam tabel
    public void tampilTabel() {
        if (this.list.isEmpty() != true){    // jika listnya tidak kosong 
            int max=0, max2=0, max3=0, max4 = 0, all=0; // untuk menampung strlen terpanjang diset 0 terlebih dahlu
            //max(id), max2(nama), max3(bidang), max4(partai), all(semua max)
            for(Dpr anggota : this.list){ // untuk setiap anggota dalam list 
                if (max< anggota.getId().length()) {    // jika max kurang dari pjg str id
                    max = anggota.getId().length(); // maka max akan disi nilai tsb
                }
            }// kursng lebih sama seperti diatas
            for(Dpr anggota : this.list){
                if (max2< anggota.getNama().length()) {
                    max2 = anggota.getNama().length();
                }
            }
            for(Dpr anggota : this.list){
                if (max3 < anggota.getBidang().length()) {
                    max3 = anggota.getBidang().length();
                }
            }
            for(Dpr anggota : this.list){
                if (max4< anggota.getPartai().length()) {
                    max4 = anggota.getPartai().length();
                }
            }// untuk menjumlahkan max dan ditampoung di all 
            if (max>2) { // jika id lebih dari 2
                all+=max-2;
            }if(max2>4){ // jika nama > 4
                all+=max2-4;
            }if (max3>6) {// jika bidang > 6
                all+=max3-6;
            }if (max4>6) {// jika partai > 6 
                all+=max4-6;
            }
            // Mulai print garis paling atas
            System.out.print("+-------------------------------------");
            for (int i = 0; i < all; i++) { // - sebanyak all
                System.out.print("-");
            }
            System.out.println("+");
            System.out.print("|  DATA ANGGOTA DPR RI                ");
            for (int i = 0; i <all; i++) { // spasi sebanyak all
                System.out.print(" ");
            }
            System.out.println("|");
            System.out.print("+------");
            // Awal kerangka Tabel
            if(max > 2){ // id > 2
                for (int i = 0; i < max - 2; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+--------");

            
            if(max2 > 4){ //nama > 6
                for (int i = 0; i < max2 - 4; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            
            if(max3 > 6){ // bidang > 6
                for (int i = 0; i < max3 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            
            if(max4 > 6){ // partai > 6
                for (int i = 0; i < max4 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.println("+");
            // Akhir kerangka tabel

            //  Awal Heading
            System.out.print("|  ID  ");
            if(max > 2){
                for (int i = 0; i < max - 2; i++) {
                    System.out.print(" ");
                }
            }
            System.out.print("|  NAMA  ");

            if(max2 > 4){
                for (int i = 0; i < max2 - 4; i++) {
                    System.out.print(" ");
                }
            }
            System.out.print("|  BIDANG  ");

            if(max3 > 6){
                for (int i = 0; i < max3 - 6; i++) {
                    System.out.print(" ");
                }
            }
            System.out.print("|  PARTAI  ");

            if(max4 > 6){
                for (int i = 0; i < max4 - 6; i++) {
                    System.out.print(" ");
                }
            }
            System.out.println("|"); // Akhir Heading

            // Awal Kerangka(Garis) round 2
            System.out.print("+------");
            if(max > 2){
                for (int i = 0; i < max - 2; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+--------");

            if(max2 > 4){
                for (int i = 0; i < max2 - 4; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            if(max3 > 6){
                for (int i = 0; i < max3 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            if(max4 > 6){
                for (int i = 0; i < max4 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.println("+");
            // Akhir Kerangka(Garis) round 2

            // Mulai baca data di list
            for(Dpr anggota : this.list){ // loop untuk setiap data anggota dalam list
                System.out.print("|  " + anggota.getId());
                if(max < 2){
                    for (int i = 0; i < 2- anggota.getId().length(); i++) {
                        System.out.print(" ");
                    }
                }else{
                    for (int i = 0; i < max - anggota.getId().length() ; i++) {
                        System.out.print(" ");
                    }
                }
                System.out.print("  |  " + anggota.getNama());

                if(max2 < 4){
                    for (int i = 0; i < 4- anggota.getNama().length(); i++) {
                        System.out.print(" ");
                    }
                }else{
                    for (int i = 0; i < max2 - anggota.getNama().length(); i++) {
                        System.out.print(" ");
                    }
                }
                System.out.print("  |  "+anggota.getBidang());

                if(max3 < 6){
                    for (int i = 0; i < 6 - anggota.getBidang().length(); i++) {
                        System.out.print(" ");
                    }
                }else{
                    for (int i = 0; i < max3 - anggota.getBidang().length(); i++) {
                        System.out.print(" ");
                    }
                }
                System.out.print("  |  "+anggota.getPartai());

                if(max4 < 6){
                    for (int i = 0; i < 6 - anggota.getPartai().length(); i++) {
                        System.out.print(" ");
                    }
                }else{
                    for (int i = 0; i < max4 - anggota.getPartai().length(); i++) {
                        System.out.print(" ");
                    }
                }
                System.out.println("  |");
            } // Akhir loop baca data
            // Awal Kerangka Penutup
            System.out.print("+------");
            if(max > 2){
                for (int i = 0; i < max - 2; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+--------");

            if(max2 > 4){
                for (int i = 0; i < max2 - 4; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            if(max3 > 6){
                for (int i = 0; i < max3 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.print("+----------");

            if(max4 > 6){
                for (int i = 0; i < max4 - 6; i++) {
                    System.out.print("-");
                }
            }
            System.out.println("+\n");
            // Akhir kerangka penutup
        }else{ // Kalau list masih kosong
            System.out.println("Data Masih Kosong, Silakan Tambah Data Terlebih Dahulu!"+'\n');
        }
    }
}
    // program utama
    class Main {
    public static void main(String[] args) {
        int menu = 0;
        // membuat list untuk menampung data dpr
        Tabeldpr tabel = new Tabeldpr(); // declare tabel kosong
        String id, nama, bidang,partai; //variabel untuk update dan add data
        while (menu != 5) { // berhenti kalau exit
            System.out.println("Selamat Datang di DATA PUSAT DPR RI");
            System.out.println("1. Tambah Data");
            System.out.println("2. Update Data");
            System.out.println("3. Hapus Data");
            System.out.println("4. Tampil");
            System.out.println("5. Exit");
            System.out.print("Silahkan Pilih menu berikut : ");
            Scanner scanner = new Scanner(System.in); // malloc scanf
            try{
                menu = scanner.nextInt();
            }catch(Exception e){
            }
            switch (menu) { // switch menu
                case 4: /// untuk show data
                    tabel.tampilTabel(); // panggil method yang sudah dibuat sebelumnya
                    break;
                case 1:// add data
                    System.out.print("Berapa banyak data yang ingin ditambah ? ");
                    
                    Dpr temp; // data temporary sebelum di masukkan kedalam list
                    int n; // jumlah data yang mau ditambah
                    n = scanner.nextInt(); // scan jumlah data yang mau ditambah
                    for (int i = 0; i < n; i++) {
                        temp = new Dpr(); // set Dpr baru (masih kosong)
                        System.out.println("Silahkan input data (id, nama, bidang, partai)");
                        id = scanner.next(); // scan data yang mmasu di input
                        nama = scanner.next();
                        bidang=scanner.next();
                        partai = scanner.next();

                        temp.setId(id); // set id menggunakan method set
                        temp.setNama(nama);
                        temp.setBidang(bidang);
                        temp.setPartai(partai);

                        tabel.addAnggota(temp); // add to list
                    }
                    System.out.println( n+" Data berhasil ditambahkan\n");
                    break;
                case 2: // update list
                    System.out.print("Silakan ketik id data yang ingin anda update : ");
                    id = scanner.next(); /// scan id ynag ,au diupdate
                    if(tabel.cariAnggota(id)!=null){ // kalau datanya ada
                        System.out.println("Data ditemukan, silakan input data (nama, bidang, partai)");
                        nama = scanner.next(); // kalau data ada lanjut scan
                        bidang=scanner.next();
                        partai = scanner.next();
                        tabel.updateAnggota(id, nama, bidang, partai, partai); // updatdata
                        System.out.println("Anggota dengan ID " + id + " berhasil diupdate.\n");
                    } else { // kalau tidak ada
                        System.out.println(" Maaf anggota dengan ID " + id + " tidak ditemukan.\n" );
                    }
                    break;
                case 3: // hapus data dari list
                    System.out.print("Silakan ketik id data yang ingin anda hapus : ");
                    id = scanner.next(); // scan id data ynag mau diremove
                    tabel.deleteAnggota(id); // remove data
                    break;
                case 5: // exit prog
                    System.out.println("Bye 2x");
                    break;
                default: // INput selain 5 diatas
                    System.out.println("Mohon maaf pilihan tidak ada dalam menu.\n");
                    break;
            }

        }
    }
}
      
