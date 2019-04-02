/*!
 *
 *  Intersection Tester - v1.0.0
    Original Author: Liam McNabb
    Proceeding Author(s): N/A
    Copyright (c) 2019
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (IntersectionTester), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
    /**
     * @brief MainInterfaceWindow constructor
     * @param parent widget parent
     */
    explicit MainInterfaceWindow(QWidget *parent = 0);
    ~MainInterfaceWindow();

private slots:
    /**
     * @brief on_cmbStatic_currentIndexChanged action to switch the state for
     * the static primitive
     */
    void on_cmbStatic_currentIndexChanged();
    /**
     * @brief on_cmbMove_currentIndexChanged action to switch the state for the
     * moving primitive
     */
    void on_cmbMove_currentIndexChanged();

private:
    Ui::MainInterfaceWindow *ui;
};

#endif // MAININTERFACEWINDOW_H
