#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <qdebug.h>
#include <qmovie.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    movie = new QMovie();

    QAction *openFile = ui->menuBar->addAction(QStringLiteral("打开文件"));
    openFile->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    connect(openFile, &QAction::triggered, this, &MainWindow::openFileSlot);

    ui->labelImg->setMargin(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFileSlot()
{
    QString filePath = QFileDialog::getOpenFileName(this, QStringLiteral("选择文件"), ".", "*.gif *.jpg");

    if (filePath.isEmpty()) {
        return;
    }

    QFileInfo fileInfo(filePath);
    if (fileInfo.suffix() == "gif") {
        movie->setFileName(filePath);
        ui->labelImg->setMovie(movie);
        movie->setScaledSize(ui->labelImg->size());
        movie->start();
    } else {
        movie->stop();
        QImage img(filePath);
        img.invertPixels();
        ui->labelImg->setPixmap(QPixmap::fromImage(img.scaled(ui->labelImg->size(), Qt::IgnoreAspectRatio)));
    }
}
