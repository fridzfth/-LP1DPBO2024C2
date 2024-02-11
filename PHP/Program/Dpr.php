<?php
// Definisi kelas DPR
class Dpr{
    // properti dpr
    private $id;
    private $nama;
    private $bidang;
    private $partai;
    private $foto;
    
    // Konstruktor
    function __construct($id, $nama, $bidang, $partai, $foto) {
        $this->id = $id;
        $this->nama = $nama;
        $this->bidang = $bidang;
        $this->foto = $foto;
        $this->partai = $partai;
    }

    function set_nama($nama){
        $this->nama = $nama;
    }
    function set_bidang($bidang){
        $this->bidang = $bidang;
    }
    function set_partai($partai){
        $this->partai = $partai;
    }
    function set_id($id){
        $this->id = $id;
    }
    function set_foto($foto){
        $this->foto = $foto;
    }
    function get_id(){
        return $this->id; 
    }

    // Metode untuk menampilkan informasi dpr beserta foto
    public function tampilkanInfo() {
        echo "<tr>";
        echo "<td>{$this->id}</td>";
        echo "<td>{$this->nama}</td>";
        echo "<td>{$this->bidang}</td>";
        echo "<td>{$this->partai}</td>";
        echo "<td><img src='{$this->foto}' alt='{$this->nama}' height='40' width='40' ></td>";
        echo "</tr>";
    }
    function __destruct(){

    }
}


?>