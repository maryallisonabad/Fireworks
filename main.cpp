#include <QApplication>
#include "mainwindow.h"
#include "firework.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    mainLaunch();

    QApplication app(argc, argv);

    // Set OpenGL version
//    QSurfaceFormat format;
//    format.setSamples(8);
//    format.setDepthBufferSize(32);
//    format.setStencilBufferSize(8);
//    format.setVersion(3, 3);
//    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
//    format.setProfile(QSurfaceFormat::CoreProfile);
//    QSurfaceFormat::setDefaultFormat(format);


    // Show main window

    //Couldn't get proper particle veiw window working

    return a.exec();
}

void MainWindow::resizeGL( int w, int h ) {
//  glViewport( 0, 0, w, qMax( h, 1 ) );
}
