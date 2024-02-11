<?php
    include "Tabeldpr.php";
    // membuat 5 anggota
    $a1 = new Dpr("023","Kevin_Sanjaya", "HAM", "PPID","img.jpg");
    $a2 = new Dpr("264","Ratna_Sanjaya", "Sosial", "NAP","img.jpg");
    $a3 = new Dpr("022","Udin_Sanjaya", "Ekonomi", "SKP","img.jpg");
    $a4 = new Dpr("153","Retno_Sanjaya", "Olahraga", "IPS","img.jpg");
    $a5 = new Dpr("738","Karbu_Supra", "HAM", "P4","img.jpg");

    // mebuat list untuk menampung data dpr
    $tabel =  new Tabeldpr();
    
    // add anggota ke dalam list
    $tabel->add_anggota($a1);
    $tabel->add_anggota($a2);
    $tabel->add_anggota($a3);
    $tabel->add_anggota($a4);
    $tabel->add_anggota($a5);

    // print tabel
    $tabel->tampil_tabel();
    
    // update data
    $tabel->update_anggota("732","Karbu_Supra", "MAh", "P4","img1.jpg");
    $tabel->update_anggota("738","Karbu_Supra", "MAh", "P4","img1.jpg");
    

    // print tabel
    echo "</br>";
    $tabel->tampil_tabel();
    
    // delete data dari list
    $tabel->delete_anggota("214");
    $tabel->delete_anggota("022");

    // print tabel
    echo "</br>";
    $tabel->tampil_tabel();

    
?>