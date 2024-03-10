#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_menu_clicked();
    void actualizarEstiloBoton(QPushButton *botonPresionado);
    void on_bt_0_clicked();
    void on_bt_1_clicked();
    void on_bt_4_clicked();
    void on_bt_5_clicked();
    void on_bt_2_clicked();
    void on_bt_3_clicked();
private:
    Ui::MainWindow *ui;
    QString originalButton;
    QString borderLeftButton;
    QString removeBorderLeft;
    bool FrameLateralCollapsed = false;
    const int collapsedWidth = 43;
    const int expandedWidth = 16777215;

};
#endif // MAINWINDOW_H
