#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QOpenGLWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeGL(int x, int y);
//    void initializeGL(); // QGLWidget OpenGL interface
//    void paintGL();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
