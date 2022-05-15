#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
connect(ui->pushButton_plmn,SIGNAL(clicked()),this,SLOT(operations()));
connect(ui->pushButton_procemt,SIGNAL(clicked()),this,SLOT(operations()));
connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(math_operations()));
connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
connect(ui->pushButton_dil,SIGNAL(clicked()),this,SLOT(math_operations()));

ui->pushButton_min->setCheckable(true);
ui->pushButton_plus->setCheckable(true);
ui->pushButton_x->setCheckable(true);
ui->pushButton_dil->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){

     QPushButton *button = static_cast<QPushButton*>(sender());

      double numbers;

      QString new_label;
      if( ui->label->text().contains(".") && button->text()=="0"){
new_label = ui->label->text()+ button->text();
      }else{



      numbers = (ui->label->text()+ button->text()).toDouble();

      new_label = QString::number(numbers,'g',11);
}
      ui->label->setText(new_label);
}


void MainWindow::on_pushButton_crapka_clicked()
{
if(!(ui->label->text().contains(".")))
ui->label->setText(ui->label->text()+".");
}
void MainWindow::operations(){

     QPushButton *button = static_cast<QPushButton*>(sender());

      double numbers;

      QString new_label;
if(button->text()=="+/-"){


      numbers = (ui->label->text()).toDouble();
numbers=numbers*(-1);
      new_label = QString::number(numbers,'g',11);

      ui->label->setText(new_label);
}else if(button->text()=="%"){
    numbers = (ui->label->text()).toDouble();
numbers=numbers*(0.01);
    new_label = QString::number(numbers,'g',11);

    ui->label->setText(new_label);
}
}
void MainWindow::math_operations(){
QPushButton *button = static_cast<QPushButton*>(sender());
num_first = ui->label->text().toDouble();
button->setChecked(true);
 ui->label->setText("");

}
void MainWindow::on_pushButton_ac_clicked()
{
  ui->pushButton_min->setChecked(false);
    ui->pushButton_plus->setChecked(false);
      ui->pushButton_dil->setChecked(false);
        ui->pushButton_x->setChecked(false);

         ui->label->setText("0");
}


void MainWindow::on_pushButton_dorivn_clicked()
{
    double labelNumber,numSecond;
    QString new_label;
    numSecond = ui->label->text().toDouble();
if(ui->pushButton_plus->isChecked()){
labelNumber = num_first + numSecond;
new_label = QString::number(labelNumber,'g',11);

ui->label->setText(new_label);
ui->pushButton_plus->setChecked(false);
}else if(ui->pushButton_min->isChecked()){
    labelNumber = num_first - numSecond;
    new_label = QString::number(labelNumber,'g',11);

    ui->label->setText(new_label);
    ui->pushButton_min->setChecked(false);
}else if(ui->pushButton_dil->isChecked()){
    if(numSecond == 0){
 ui->label->setText("0");
    }else{

    labelNumber = num_first / numSecond;
    new_label = QString::number(labelNumber,'g',11);

    ui->label->setText(new_label);

    }
     ui->pushButton_dil->setChecked(false);
}else if(ui->pushButton_x->isChecked()){
    labelNumber = num_first * numSecond;
    new_label = QString::number(labelNumber,'g',11);

    ui->label->setText(new_label);
    ui->pushButton_x->setChecked(false);
}

}

