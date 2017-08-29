#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMovie;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void openFileSlot();

private:
    Ui::MainWindow *ui;
    QMovie *movie;
};

#endif // MAINWINDOW_H
