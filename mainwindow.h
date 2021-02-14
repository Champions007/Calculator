#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSvg/QtSvg>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_Sum_clicked();

    void on_btn_Equal_clicked();

    void on_btn_Sub_clicked();

    void on_btn_Multi_clicked();

    void on_btn_Divide_clicked();

    void on_btn_Dot_clicked();

    void on_btn_Clear_clicked();

private:
    Ui::MainWindow *ui;
    void enter_char_in_text_Box(QString character);
    double enter_cauculate_operator_char();
    double calculate_equation(double first_number, double second_number, double third_number, char equation_operator);
    void check_for_first_zero(QString btn_name);
    void check_for_operator(char math_operator);

    double first_number;
    double second_number;
    double third_number;
    char calculate_operator;
    bool equal_clicked;
};
#endif // MAINWINDOW_H
