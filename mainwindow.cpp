#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(240, 390));
    first_number = 0;
    second_number = 0;
    third_number = 0;
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enter_char_in_text_box(QString character)
{
    ui->input_Box->insert(character);
}

double MainWindow::enter_cauculate_operator_char()
{
    equal_clicked = false;
    first_number = QVariant(ui->input_Box->text()).toDouble();
    ui->input_Box->clear();
    return first_number;
}

double MainWindow::calculate_equation(double first_number, double second_number, double third_number, char calculate_operator)
{
    switch (calculate_operator)
    {
        case '+': third_number = first_number + second_number; break;
        case '-': third_number = first_number - second_number; break;
        case '*': third_number = first_number * second_number; break;
        case '/': third_number = first_number / second_number; break;
    }
    return third_number;
}

void MainWindow::check_for_first_zero(QString btn_name)
{
    if(ui->input_Box->text().startsWith("0."))
    {
       enter_char_in_text_box(btn_name);
       return;
    }

    if(ui->input_Box->text().startsWith(ui->btn_0->text()))
    {
       ui->input_Box->setText(btn_name);
       return;
    }

    enter_char_in_text_box(btn_name);
}

void MainWindow::check_for_operator(char math_operator)
{
    if(ui->input_Box->text().isEmpty())
    {
        ui->input_Box->setText("");
        return;
    }

    first_number = enter_cauculate_operator_char();
    calculate_operator = math_operator;
}

void MainWindow::on_btn_1_clicked()
{
   check_for_first_zero(ui->btn_1->text());
}

void MainWindow::on_btn_2_clicked()
{
    check_for_first_zero(ui->btn_2->text());
}

void MainWindow::on_btn_3_clicked()
{
    check_for_first_zero(ui->btn_3->text());
}

void MainWindow::on_btn_4_clicked()
{
    check_for_first_zero(ui->btn_4->text());
}

void MainWindow::on_btn_5_clicked()
{
    check_for_first_zero(ui->btn_5->text());
}

void MainWindow::on_btn_6_clicked()
{
    check_for_first_zero(ui->btn_6->text());
}

void MainWindow::on_btn_7_clicked()
{
    check_for_first_zero(ui->btn_7->text());
}

void MainWindow::on_btn_8_clicked()
{
    check_for_first_zero(ui->btn_8->text());
}

void MainWindow::on_btn_9_clicked()
{
    check_for_first_zero(ui->btn_9->text());
}

void MainWindow::on_btn_0_clicked()
{
    if(ui->input_Box->text().startsWith("0."))
    {
       enter_char_in_text_box("0");
       return;
    }

    if(!ui->input_Box->text().startsWith("0"))
    {
        enter_char_in_text_box("0");
        return;
    }

    ui->input_Box->setText("0");

}

void MainWindow::on_btn_Dot_clicked()
{
    if(ui->input_Box->text().contains(".") || ui->input_Box->text().isEmpty())
    {
        return enter_char_in_text_box("");
    }
    return enter_char_in_text_box(".");
}

void MainWindow::on_btn_Sum_clicked()
{
    check_for_operator('+');
}

void MainWindow::on_btn_Sub_clicked()
{
    check_for_operator('-');
}

void MainWindow::on_btn_Multi_clicked()
{
    check_for_operator('*');
}

void MainWindow::on_btn_Divide_clicked()
{
    check_for_operator('/');
}

void MainWindow::on_btn_Equal_clicked()
{
    if(ui->input_Box->text().isEmpty())
    {
        ui->input_Box->setText("");
        return;
    }

    if(equal_clicked == true)
    {
        on_btn_Clear_clicked();
        return;
    }

    second_number = QVariant(ui->input_Box->text()).toDouble();
    ui->input_Box->clear();
    ui->input_Box->setText(QVariant(calculate_equation(first_number, second_number, third_number, calculate_operator)).toString());
    equal_clicked = true;
}

void MainWindow::on_btn_Clear_clicked()
{

    ui->input_Box->setText("");
    first_number = 0;
    second_number = 0;
    third_number = 0;
}
