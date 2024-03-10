#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar la señal clicked de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->frame_lateral->findChildren<QPushButton *>();
    for (QPushButton *btn : botones)
    {
        connect(btn, &QPushButton::clicked, this, [=]()
                { actualizarEstiloBoton(btn); });

        // Establecer la política de tamaño mínimo
        btn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        btn->setMinimumHeight(40);
    }

    // boton por defecto
    ui->bt_0->animateClick();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEstiloBoton(QPushButton *botonPresionado)
{
    // Limpiar el estilo de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->frame_lateral->findChildren<QPushButton *>();

    QString estilo = "QPushButton { }";
    for (QPushButton *btn : botones)
    {
        btn->setStyleSheet(estilo);
    }

    // Aplicar el estilo al botón presionado
    estilo = "QPushButton { "
             "border-left: 3px solid #026ec1;"
             "background-color: #0e0d14"
             " }"
             "QPushButton:hover {"
             "background-color: #0e0d14;"
             "}";
    botonPresionado->setStyleSheet(estilo);
}

void MainWindow::on_btn_menu_clicked()
{
    if (FrameLateralCollapsed)
    {
        // Expandir el frame lateral
        ui->frame_lateral->setMaximumWidth(expandedWidth);
        ui->btn_menu->setIcon(QIcon(":/img/icon_light/menu.svg"));

        FrameLateralCollapsed = false;
    }
    else
    {
        // Colapsar el frame lateral
        ui->frame_lateral->setMaximumWidth(collapsedWidth);
        ui->btn_menu->setIcon(QIcon(":/img/icon_light/chevron-left.svg"));

        FrameLateralCollapsed = true;
    }
}

void MainWindow::on_bt_0_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_0);
}

void MainWindow::on_bt_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}

void MainWindow::on_bt_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::on_bt_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

void MainWindow::on_bt_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

void MainWindow::on_bt_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_5);
}
