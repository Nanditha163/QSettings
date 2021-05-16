#include "widget.h"
#include "ui_widget.h"
#include<QColorDialog>
#include<QSettings>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //To set default color as black

   for(int i=0;i<9;i++)
    {
       ColorList.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_1_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[0],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[0]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->pushButton_1->setStyleSheet(css);

        }
}

void Widget::on_pushButton_2_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[1]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_2->setStyleSheet(css);

       }

}

void Widget::on_pushButton_3_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[2],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[2]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_3->setStyleSheet(css);

       }

}

void Widget::on_pushButton_4_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[3],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[3]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_4->setStyleSheet(css);

       }
}

void Widget::on_pushButton_5_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[4],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[4]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_5->setStyleSheet(css);

       }
}

void Widget::on_pushButton_6_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[5],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[5]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_6->setStyleSheet(css);

       }

}

void Widget::on_pushButton_7_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[6],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[6]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_7->setStyleSheet(css);

       }

}

void Widget::on_pushButton_8_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[7],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[7]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_8->setStyleSheet(css);

       }

}

void Widget::on_pushButton_9_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[8],this,"Choose Background color");

       if(color.isValid())

       {

           ColorList[8]=color;

           QString css=QString ("Background-color:%1").arg(color.name());

           ui->pushButton_9->setStyleSheet(css);

       }

}

void Widget::on_SaveColor_clicked()
{
    SaveColor("pushButton_1",ColorList[0]);

    SaveColor("pushButton_2",ColorList[1]);

    SaveColor("pushButton_3",ColorList[2]);

    SaveColor("pushButton_4",ColorList[3]);

    SaveColor("pushButton_5",ColorList[4]);

    SaveColor("pushButton_6",ColorList[5]);

    SaveColor("pushButton_7",ColorList[6]);

    SaveColor("pushButton_8",ColorList[7]);

    SaveColor("pushButton_9",ColorList[8]);

}

void Widget::on_LoadColor_clicked()
{
    setLoadedColor("pushButton_1",0,ui->pushButton_1);

    setLoadedColor("pushButton_2",0,ui->pushButton_2);

    setLoadedColor("pushButton_3",0,ui->pushButton_3);

    setLoadedColor("pushButton_4",0,ui->pushButton_4);

    setLoadedColor("pushButton_5",0,ui->pushButton_5);

    setLoadedColor("pushButton_6",0,ui->pushButton_6);

    setLoadedColor("pushButton_7",0,ui->pushButton_7);

    setLoadedColor("pushButton_8",0,ui->pushButton_8);

    setLoadedColor("pushButton_9",0,ui->pushButton_9);

}

void Widget::SaveColor(QString key, QColor color)
{
    int red=color.red();

        int green=color.green();

        int blue=color.blue();

        QSettings settings("Blikoon","SettingsDemo");

        settings.beginGroup("ButtonColor");

        settings.setValue(key +"r",red);

        settings.setValue(key +"g",green);

        settings.setValue(key +"b",blue);

        settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;

      int green;

      int blue;

      QSettings settings("Blikoon","SettingsDemo");

      settings.beginGroup("ButtonColor");

      red=settings.value(key+"r",QVariant(0)).toInt();

      green=settings.value(key+"g",QVariant(0)).toInt();

      blue=settings.value(key+"b",QVariant(0)).toInt();

      settings.endGroup();

      return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color=loadColor(key);

        ColorList[index]=color;

        QString css=QString ("Background-color:%1").arg(color.name());

        button->setStyleSheet(css);
}
