#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBitmap>
#include <QPixmap>
#include "zint.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /*打印条形码*/
    void printBarcode(const QString &barcode);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QBitmap m_bmp;
    QImage  m_Img;
    QBitmap m_barcodeBmp;
    //QPixmap m_bmp;
};

#endif // MAINWINDOW_H
