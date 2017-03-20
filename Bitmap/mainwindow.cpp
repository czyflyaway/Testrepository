#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printBarcode(const QString &barcode)
{
    struct zint_symbol * my_symbol = ZBarcode_Create();

    my_symbol->symbology=BARCODE_CODE128;
    my_symbol->show_hrt = 0;

    ZBarcode_Encode(my_symbol, (unsigned char*)(barcode.toStdString().c_str()),0);

    ZBarcode_Print(my_symbol,0);
    ZBarcode_Delete(my_symbol);


    m_barcodeBmp.load(my_symbol->outfile);

//    painter.save();
//    painter.drawPixmap(barcodeRect,
//                       QPixmap::fromImage(m_Img),
//                       m_Img.rect());
//    painter.restore();
}

void MainWindow::on_pushButton_clicked()
{
    QBitmap pix(500,500);
    pix.fill(QColor(255,255,255));
    QString barcode = QString("SH000000110101");
    printBarcode(barcode);
    QPainter painter(&pix);
    painter.drawPixmap(10, 10, 200, 100, m_barcodeBmp);
    painter.drawText(QRect(10, 200, 200, 20), Qt::AlignHCenter|Qt::AlignTop, barcode);
    painter.end();
    pix.save("test.png");
    //This is to test Github
}
