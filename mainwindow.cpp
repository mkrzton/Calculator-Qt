#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global_variables.h"

#include <QDebug>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPushButton *Button[10];

    for (int i = 0; i < 10; ++i) {

               QString butname = "Button" + QString::number(i);
               Button[i] = MainWindow::findChild<QPushButton *>(butname);
               connect(Button[i], SIGNAL(released()),this, SLOT(digit_pressed()));
            }

    connect(ui->Inv, SIGNAL(released()),this, SLOT(unary_pressed()));
    connect(ui->Perc, SIGNAL(released()), this, SLOT(unary_pressed()));
    connect(ui->Promile, SIGNAL(released()), this, SLOT(unary_pressed()));

    connect(ui->Cube, SIGNAL(released()), this, SLOT(square_pow_operations()));
    connect(ui->Pow, SIGNAL(released()), this, SLOT(square_pow_operations()));
    connect(ui->Sqrt, SIGNAL(released()), this, SLOT(square_pow_operations()));

    connect(ui->Add, SIGNAL(released()), this, SLOT(binary_pressed()));
    connect(ui->Sub, SIGNAL(released()), this, SLOT(binary_pressed()));
    connect(ui->Mult, SIGNAL(released()), this, SLOT(binary_pressed()));
    connect(ui->Div, SIGNAL(released()), this, SLOT(binary_pressed()));

    ui->Add->setCheckable(true);
    ui->Sub->setCheckable(true);
    ui->Mult->setCheckable(true);
    ui->Div->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{

   QPushButton * button = (QPushButton*)sender();

   double label_number;
   QString new_label;

  if((ui->Add->isChecked() || ui->Sub->isChecked() || ui->Mult->isChecked() || ui->Div->isChecked()) && (number_with_at_least_2_digits==false)){

      label_number = button->text().toDouble();
      number_with_at_least_2_digits=true;
      new_label=QString::number(label_number,'g',16);

  }else {

      if(ui->label->text().contains('.') && button->text()=="0"){

          new_label = ui->label->text() + button->text();

      }else{

          label_number = (ui->label->text() + button->text()).toDouble();
          new_label=QString::number(label_number,'g',16);
      }

  }

   ui->label->setText(new_label);

}

void MainWindow::on_Dot_released()
{
    if(ui->label->text().contains('.')){

        ui->label->setText((ui->label->text()));

    }else{

        ui->label->setText((ui->label->text()+"."));
    }

}

void MainWindow::unary_pressed(){

    QPushButton* button = (QPushButton*)sender();
    double label_number;
    QString new_label;

    if(button->text()=="+/-"){

        label_number=ui->label->text().toDouble();
        label_number =label_number* -1;
        new_label = QString::number(label_number,'g',16);
        ui->label->setText(new_label);
    }

    if(button->text()=="%"){

        label_number=ui->label->text().toDouble();
        label_number = label_number* 0.01;
        new_label = QString::number(label_number,'g',16);
        ui->label->setText(new_label);
    }

    if(button->text()=="‰"){

        label_number=ui->label->text().toDouble();
        label_number = label_number* 0.001;
        new_label = QString::number(label_number,'g',16);
        ui->label->setText(new_label);
    }

}


void MainWindow::on_Clear_released()
{
     ui->Add->setChecked(false);
     ui->Div->setChecked(false);
     ui->Mult->setChecked(false);
     ui->Sub->setChecked(false);


     ui->label->setText("0");
}

void MainWindow::on_Equal_released()
{

    double label_number, second_number;
    QString new_label;

    second_number=ui->label->text().toDouble();

    if(ui->Add->isChecked()){

        label_number = first_number + second_number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Add->setChecked(false);

    }else if(ui->Sub->isChecked()){

        label_number = first_number - second_number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Sub->setChecked(false);

    }else if(ui->Mult->isChecked()){

        label_number = first_number * second_number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Mult->setChecked(false);

    }else if(ui->Div->isChecked()){

        label_number = first_number / second_number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Div->setChecked(false);
    }

    number_with_at_least_2_digits=false;
}

void MainWindow::binary_pressed(){

    QPushButton* button = (QPushButton*)sender();

    first_number = ui->label->text().toDouble();

    button->setChecked(true);
}

void MainWindow::square_pow_operations(){

    QPushButton* button = (QPushButton*)sender();
    double label_number, number;
    QString new_label;

    number=ui->label->text().toDouble();

    if(button->text()=="√"){

        label_number = qSqrt(number);
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Add->setChecked(false);

    }else if (button->text()=="x²") {

        label_number = number*number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Add->setChecked(false);

}else if(button->text()=="x³"){


        label_number = number*number*number;
        new_label = QString::number(label_number,'g', 16);
        ui->label->setText(new_label);
        ui->Add->setChecked(false);

    }
          number_with_at_least_2_digits=false;
    }



