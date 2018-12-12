#ifndef MAININTERFACEWINDOW_H
#define MAININTERFACEWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainInterfaceWindow;
}

class MainInterfaceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterfaceWindow(QWidget *parent = 0);
    ~MainInterfaceWindow();

private slots:
    void on_cmbStatic_currentIndexChanged();

private:
    Ui::MainInterfaceWindow *ui;
};

#endif // MAININTERFACEWINDOW_H
