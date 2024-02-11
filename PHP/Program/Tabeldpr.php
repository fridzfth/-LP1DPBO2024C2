<?php
include "Dpr.php";
// Definisi table class 
class Tabeldpr{
    // atribut
    private $list = []; // list for store dpr's datas
    // construct
    function __construct(){
    }
    // add to list
    function add_anggota(Dpr $anggota){
        $this->list[] = $anggota;
    }

    function cari_anggota($id){
        $result = NULL;
        foreach ($this->list as $anggota) { // loop to search data with id = $id
            if($anggota->get_id() ==  $id){
                $result = $anggota; 
            }
        }
        return $result;
    }

    function update_anggota($id, $nama, $bidang, $partai, $foto){
        $anggota = $this->cari_anggota($id);
        if($anggota != NULL){
            $anggota->set_nama($nama);
            $anggota->set_bidang($bidang);
            $anggota->set_partai($partai);
            $anggota->set_foto($foto);
            echo "</br>"."Anggota dengan ID {$id} berhasil diupdate." . "</br>";
        }else{
            echo "</br>"."Anggota dengan ID {$id} tidak ditemukan." .  "</br>";
        }
    }

    function delete_anggota($id){
        /* alternative index($key) search
        $key = array_search($id, array_column($this->list, 'id')); */
        foreach ($this->list as $key => $anggota) { // loop to search index($key) data with id = $id
            if($anggota->get_id() ==  $id){
                unset($this->list[$key]); 
                echo "</br>"."Anggota dengan ID {$id} berhasil dihapus."."</br>";
                return;
            }
        }
        echo "</br>"."Anggota dengan ID {$id} tidak ditemukan."."</br>";
    }

    // Metode untuk menampilkan semua data dalam tabel
    function tampil_tabel() {
        echo "<table border='1' cellpadding='5'>";
        echo "<tr><th colspan='5'>DATA ANGGOTA DPR</th></tr>";
        echo "<tr>";
        echo "<th>Id</th>";
        echo "<th>Nama</th>";
        echo "<th>Bidang</th>";
        echo "<th>Partai</th>";
        echo "<th>Foto</th>";
        echo "</tr>";
        foreach ($this->list as $anggota)  {
            $anggota->tampilkanInfo();
        }
        echo "</table>";
    }

    // destruct
    function __destruct(){
    }

}

?>