/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCamera_Controls;
    QWidget *centralWidget;
    MyGL *mygl;
    QListWidget *vertsListWidget;
    QListWidget *halfEdgesListWidget;
    QListWidget *facesListWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *vertPosXSpinBox;
    QDoubleSpinBox *vertPosYSpinBox;
    QDoubleSpinBox *vertPosZSpinBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *faceBlueSpinBox;
    QLabel *label_10;
    QDoubleSpinBox *faceGreenSpinBox;
    QDoubleSpinBox *faceRedSpinBox;
    QLabel *label_11;
    QPushButton *ImportObj;
    QPushButton *subdivideButton;
    QPushButton *triangulateButton;
    QPushButton *addvertexButton;
    QPushButton *importJSON;
    QLabel *label_12;
    QTreeWidget *jointwidget;
    QDoubleSpinBox *translatej_x;
    QDoubleSpinBox *translatej_y;
    QDoubleSpinBox *translatej_z;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *rotatejointx;
    QPushButton *rotatejointy;
    QPushButton *rotatejointz;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1057, 492);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCamera_Controls = new QAction(MainWindow);
        actionCamera_Controls->setObjectName(QString::fromUtf8("actionCamera_Controls"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QString::fromUtf8("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 432));
        vertsListWidget = new QListWidget(centralWidget);
        vertsListWidget->setObjectName(QString::fromUtf8("vertsListWidget"));
        vertsListWidget->setGeometry(QRect(660, 10, 81, 261));
        halfEdgesListWidget = new QListWidget(centralWidget);
        halfEdgesListWidget->setObjectName(QString::fromUtf8("halfEdgesListWidget"));
        halfEdgesListWidget->setGeometry(QRect(760, 10, 81, 261));
        facesListWidget = new QListWidget(centralWidget);
        facesListWidget->setObjectName(QString::fromUtf8("facesListWidget"));
        facesListWidget->setGeometry(QRect(860, 10, 81, 261));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 280, 111, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 280, 111, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(850, 280, 111, 16));
        label_3->setAlignment(Qt::AlignCenter);
        vertPosXSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosXSpinBox->setObjectName(QString::fromUtf8("vertPosXSpinBox"));
        vertPosXSpinBox->setGeometry(QRect(720, 300, 62, 22));
        vertPosXSpinBox->setMinimum(-99.989999999999995);
        vertPosYSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosYSpinBox->setObjectName(QString::fromUtf8("vertPosYSpinBox"));
        vertPosYSpinBox->setGeometry(QRect(800, 300, 62, 22));
        vertPosYSpinBox->setMinimum(-99.989999999999995);
        vertPosZSpinBox = new QDoubleSpinBox(centralWidget);
        vertPosZSpinBox->setObjectName(QString::fromUtf8("vertPosZSpinBox"));
        vertPosZSpinBox->setGeometry(QRect(880, 300, 62, 22));
        vertPosZSpinBox->setMinimum(-99.989999999999995);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 300, 71, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(720, 320, 61, 16));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(800, 320, 61, 16));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(880, 320, 61, 16));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(880, 360, 61, 16));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(720, 360, 61, 16));
        label_9->setAlignment(Qt::AlignCenter);
        faceBlueSpinBox = new QDoubleSpinBox(centralWidget);
        faceBlueSpinBox->setObjectName(QString::fromUtf8("faceBlueSpinBox"));
        faceBlueSpinBox->setGeometry(QRect(880, 340, 62, 22));
        faceBlueSpinBox->setMaximum(1.000000000000000);
        faceBlueSpinBox->setSingleStep(0.050000000000000);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 340, 71, 21));
        faceGreenSpinBox = new QDoubleSpinBox(centralWidget);
        faceGreenSpinBox->setObjectName(QString::fromUtf8("faceGreenSpinBox"));
        faceGreenSpinBox->setGeometry(QRect(800, 340, 62, 22));
        faceGreenSpinBox->setMaximum(1.000000000000000);
        faceGreenSpinBox->setSingleStep(0.050000000000000);
        faceRedSpinBox = new QDoubleSpinBox(centralWidget);
        faceRedSpinBox->setObjectName(QString::fromUtf8("faceRedSpinBox"));
        faceRedSpinBox->setGeometry(QRect(720, 340, 62, 22));
        faceRedSpinBox->setMaximum(1.000000000000000);
        faceRedSpinBox->setSingleStep(0.050000000000000);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(800, 360, 61, 16));
        label_11->setAlignment(Qt::AlignCenter);
        ImportObj = new QPushButton(centralWidget);
        ImportObj->setObjectName(QString::fromUtf8("ImportObj"));
        ImportObj->setGeometry(QRect(970, 390, 80, 21));
        subdivideButton = new QPushButton(centralWidget);
        subdivideButton->setObjectName(QString::fromUtf8("subdivideButton"));
        subdivideButton->setGeometry(QRect(970, 360, 80, 21));
        triangulateButton = new QPushButton(centralWidget);
        triangulateButton->setObjectName(QString::fromUtf8("triangulateButton"));
        triangulateButton->setGeometry(QRect(960, 330, 91, 21));
        addvertexButton = new QPushButton(centralWidget);
        addvertexButton->setObjectName(QString::fromUtf8("addvertexButton"));
        addvertexButton->setGeometry(QRect(970, 300, 80, 21));
        importJSON = new QPushButton(centralWidget);
        importJSON->setObjectName(QString::fromUtf8("importJSON"));
        importJSON->setGeometry(QRect(970, 420, 80, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(980, 280, 49, 16));
        jointwidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        jointwidget->setHeaderItem(__qtreewidgetitem);
        jointwidget->setObjectName(QString::fromUtf8("jointwidget"));
        jointwidget->setGeometry(QRect(960, 10, 81, 261));
        translatej_x = new QDoubleSpinBox(centralWidget);
        translatej_x->setObjectName(QString::fromUtf8("translatej_x"));
        translatej_x->setGeometry(QRect(720, 380, 62, 25));
        translatej_y = new QDoubleSpinBox(centralWidget);
        translatej_y->setObjectName(QString::fromUtf8("translatej_y"));
        translatej_y->setGeometry(QRect(800, 380, 62, 25));
        translatej_z = new QDoubleSpinBox(centralWidget);
        translatej_z->setObjectName(QString::fromUtf8("translatej_z"));
        translatej_z->setGeometry(QRect(880, 380, 62, 25));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(640, 380, 49, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(740, 400, 49, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(830, 400, 49, 16));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(900, 400, 49, 16));
        rotatejointx = new QPushButton(centralWidget);
        rotatejointx->setObjectName(QString::fromUtf8("rotatejointx"));
        rotatejointx->setGeometry(QRect(710, 420, 71, 24));
        rotatejointy = new QPushButton(centralWidget);
        rotatejointy->setObjectName(QString::fromUtf8("rotatejointy"));
        rotatejointy->setGeometry(QRect(790, 420, 71, 24));
        rotatejointz = new QPushButton(centralWidget);
        rotatejointz->setObjectName(QString::fromUtf8("rotatejointz"));
        rotatejointz->setGeometry(QRect(870, 420, 71, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1057, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuFile->addSeparator();
        menuHelp->addAction(actionCamera_Controls);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OpenGLDemo", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCamera_Controls->setText(QCoreApplication::translate("MainWindow", "Camera Controls", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Half-Edges", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Faces", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Vertex Position", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Face Color", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        ImportObj->setText(QCoreApplication::translate("MainWindow", "Import Obj", nullptr));
        subdivideButton->setText(QCoreApplication::translate("MainWindow", "Subdivide", nullptr));
        triangulateButton->setText(QCoreApplication::translate("MainWindow", "Triangulate Face", nullptr));
        addvertexButton->setText(QCoreApplication::translate("MainWindow", "Add Vertex", nullptr));
        importJSON->setText(QCoreApplication::translate("MainWindow", "Import Json", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Joints", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Joints", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotatejointx->setText(QCoreApplication::translate("MainWindow", "Rotate X", nullptr));
        rotatejointy->setText(QCoreApplication::translate("MainWindow", "Rotate Y", nullptr));
        rotatejointz->setText(QCoreApplication::translate("MainWindow", "Rotate Z", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
