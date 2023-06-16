#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_radioButton_Lisans_clicked();

    void on_radioButton_Lisansustu_clicked();

    void on_pushButton_Bilgileri_Yazdir_clicked();

    bool Mezuniyet_Sorgula();

    void on_pushButton_Mezuniyet_Durumu_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
