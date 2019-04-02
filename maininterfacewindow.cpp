#include "maininterfacewindow.h"
#include "ui_maininterfacewindow.h"

MainInterfaceWindow::MainInterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterfaceWindow)
{
    ui->setupUi(this);
    QStringList list;
    list << "Point" << "Line" << "Circle" << "Triangle" << "Square";
    ui->cmbMove->addItems(list);
    ui->cmbStatic->addItems(list);
    ui->cmbStatic->setCurrentIndex(4);
}

MainInterfaceWindow::~MainInterfaceWindow()
{
    delete ui;
}

void MainInterfaceWindow::on_cmbStatic_currentIndexChanged()
{
    ui->openGLWidget->setStaticState(ui->cmbStatic->currentIndex());
    ui->openGLWidget->update();
}

void MainInterfaceWindow::on_cmbMove_currentIndexChanged()
{
    ui->openGLWidget->setMovingState(ui->cmbMove->currentIndex());
    ui->openGLWidget->update();
}
