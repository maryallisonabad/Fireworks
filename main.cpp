#include <QApplication>
#include "mainwindow.h"
#include "firework.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    mainLaunch();

    return a.exec();
}

void MainWindow::resizeGL( int w, int h ) {
//  glViewport( 0, 0, w, qMax( h, 1 ) );
}
