#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_radioButton_Lisans_clicked()
{
    ui->groupBox_Sinif->setEnabled(true);
    ui->groupBox_Alinan_Zorunlu_Dersler_1->setEnabled(true);
    ui->groupBox_Alinan_Zorunlu_Dersler_2->setEnabled(false);
    ui->groupBox_Durum->setEnabled(false);
}


void Dialog::on_radioButton_Lisansustu_clicked()
{
    ui->groupBox_Sinif->setEnabled(false);
    ui->groupBox_Alinan_Zorunlu_Dersler_1->setEnabled(false);
    ui->groupBox_Alinan_Zorunlu_Dersler_2->setEnabled(true);
    ui->groupBox_Durum->setEnabled(true);
}


void Dialog::on_pushButton_Bilgileri_Yazdir_clicked()
{
    QString ad, soyad, bolum, seviye;
        ad=ui->lineEdit_Ad->text();
        soyad=ui->lineEdit_Soyad->text();
        bolum=ui->lineEdit_Bolum->text();

        if(ui->radioButton_Lisans->isChecked()){
            seviye=ui->radioButton_Lisans->text();
        }
        if(ui->radioButton_Lisansustu->isChecked()){
            seviye=ui->radioButton_Lisansustu->text();
        }
        QMessageBox::information(this,"Ogrenci Bilgileri","Ad: "+ad+"\n"+"Soyad: " + soyad + "\n" + "Bolum: " + bolum + "\n" + "Seviye " + seviye + "\n", "Ok" );
}

bool Dialog::Mezuniyet_Sorgula(){
    if(ui->radioButton_Lisans->isChecked() ){
        if(ui->radioButton_4_Sinif->isChecked() && ui->checkBox_AIIT->isChecked() && ui->checkBox_ISG->isChecked() && ui->checkBox_Turk_Dili->isChecked()){
            return true;
        }
        else{
            return false;
        }
    }
    if(ui->radioButton_Lisansustu->isChecked() && ui->checkBox_Secmeli_Dersler->isChecked() && ui->checkBox_Seminer->isChecked() && ui->checkBox_Tez->isChecked()){
        return true;
    }
    else{
        return false;
    }
}

void Dialog::on_pushButton_Mezuniyet_Durumu_clicked()
{
    bool durum;
    durum=Mezuniyet_Sorgula();
    if(ui->radioButton_Lisans->isChecked()){
        if(durum){
            QMessageBox::information(this,"Mezuniyet Durumu","Ogrenci lisans mezunu durumundadir.","Tamam");

        }
        else{
             QMessageBox::information(this,"Mezuniyet Durumu","Ogrenci lisans ogrencisi durumundadir.","Tamam");
        }
    }

    if(ui->radioButton_Lisansustu->isChecked()){
        if(durum){
            QMessageBox::information(this,"Mezuniyet Durumu","Ogrenci lisansustu mezun durumundadir.","Tamam");

        }
        else{
             QMessageBox::information(this,"Mezuniyet Durumu","Ogrenci lisansustu ogrencisi durumundadir.","Tamam");
        }
    }
}

