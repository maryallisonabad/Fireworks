#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void GLview::initializeGL()
//{
//  initializeOpenGLFunctions();

//  // Set the clear color to black
//  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
//  m_colorBuffer.create();
//  m_colorBuffer.setUsagePattern( QOpenGLBuffer::StaticDraw );
//  if ( !m_colorBuffer.bind() )  {
//    qWarning() << "Could not bind vertex buffer to the context";
//    return;
//  }
//  // Uniforms must be set last.
//  m_shader.bind();
//  m_shader.setUniformValue("uVertexScale", (float)g_objScale);
//  m_shader.setUniformValue("uTexUnit0", (int)0);

//}
