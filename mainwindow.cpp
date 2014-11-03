#include <QtWidgets>
#include "mainwindow.h"
#include "scribblearea.h"
#include "customdialog.h"


MainWindow::MainWindow()
{
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);

    createActions();
    createMenus();

    setWindowTitle(tr("ShapeDrawn"));
    resize(500, 500);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
            scribbleArea->openImage(fileName);
    }
}

void MainWindow::save()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    if (newColor.isValid())
        scribbleArea->setPenColor(newColor);
}

void MainWindow::penWidth()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        scribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        scribbleArea->setPenWidth(newWidth);
}


//shapes
void MainWindow::drawLine()
{
   int x1=0,y1=0,x2=0,y2=0;
   CustomDialog d("Properties",this);
   d.addSpinBox("Start x: ", 0, 500,&x1,1);
   d.addSpinBox("Start y: ", 0, 500,&y1,1);
   d.addSpinBox("End x: ", 0, 500,&x2,1);
   d.addSpinBox("End y: ", 0, 500,&y2,1);
   //d.addCustomButton("Create");

   d.exec();

   if(d.wasCancelled())
       return;

   Line* line=new Line(Qt::red,Qt::blue,1,x1,y1,x2,y2);
   shapesCollection.append(line);
   scribbleArea->drawLine(line->getStartX(),line->getStartY(),line->getEndX(),line->getEndY());
}

void MainWindow::drawOval()
{
    int centerX=100, centerY=100,radiusX=40,radiusY=30;
    CustomDialog d("Properties",this);
    d.addSpinBox("centerX: ", 0, 500,&centerX,1);
    d.addSpinBox("centerY: ", 0, 500,&centerY,1);
    d.addSpinBox("radiusX: ", 0, 500,&radiusX,1);
    d.addSpinBox("radiusY: ", 0, 500,&radiusY,1);

    d.exec();

    if(d.wasCancelled())
        return;

    Oval* oval=new Oval(Qt::red, Qt::blue, 1,centerX,centerY,radiusX,radiusY);
    shapesCollection.append(oval);
    scribbleArea->drawEllipse(oval->getStartX(),oval->getStartY(),oval->getRadiusX(),oval->getRadiusY());
}

void MainWindow::drawRectangle()
{
    int top=0, left=0,bottom=100,right=100;
    CustomDialog d("Properties",this);
    d.addSpinBox("Top: ", 0, 500,&top,1);
    d.addSpinBox("Left: ", 0, 500,&left,1);
    d.addSpinBox("Bottom: ", 0, 500,&bottom,1);
    d.addSpinBox("Right: ", 0, 500,&right,1);

    d.exec();

    if(d.wasCancelled())
        return;

    //Rectangle* rectangle=new Rectangle(Qt::red, Qt::blue, 1,top,left,right-left,top-bottom);
    //shapesCollection.append(rectangle);
    //ScribbleArea->drawRectangle(rectangle->getStartX(),rectangle->getStartY(),rectangle->getWidth(),rectangle->getHeight());
    scribbleArea->drawRectangle(top,left, bottom, right);
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About Scribble"),
            tr("<b>ShapeDrawn beta 1.0</b>"));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        saveAsActs.append(action);
    }

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    penColorAct = new QAction(tr("&Pen Color..."), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    penWidthAct = new QAction(tr("Pen &Width..."), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            scribbleArea, SLOT(clearImage()));

    /*shape actions*/
    drawLineAct = new QAction(tr("&Lines"),this);
    connect(drawLineAct, SIGNAL(triggered()), this, SLOT(drawLine()));
    drawRectangleAct = new QAction(tr("&Rectangle"),this);
    connect(drawRectangleAct, SIGNAL(triggered()),this,SLOT(drawRectangle()));
    drawOvalAct = new QAction(tr("&Oval"),this);
    connect(drawOvalAct,SIGNAL(triggered()),this,SLOT(drawOval()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    /*Shape menu*/
    shapeMenu = new QMenu(tr("&Shapes"),this);
    shapeMenu->addAction(drawLineAct);//line
    shapeMenu->addAction(drawRectangleAct);//rect
    shapeMenu->addAction(drawOvalAct);//oval

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(shapeMenu);
    menuBar()->addMenu(helpMenu);
}

bool MainWindow::maybeSave()
{
    if (scribbleArea->isModified()) {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("Scribble"),
                          tr("The image has been modified.\n"
                             "Do you want to save your changes?"),
                          QMessageBox::Save | QMessageBox::Discard
              | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            return saveFile("png");
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(fileFormat.toUpper()))
                               .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty()) {
        return false;
    } else {
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}
