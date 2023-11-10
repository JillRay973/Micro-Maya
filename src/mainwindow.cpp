#include "mainwindow.h"
#include <ui_mainwindow.h>
#include "cameracontrolshelp.h"
#include <QFileDialog>
#include "mesh.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    connect(ui->mygl, SIGNAL(sig_sendVertexData(Mesh*)),
            this, SLOT(slot_receiveVertexData(Mesh*)));
    connect(ui->mygl, SIGNAL(sig_sendFaceData(Mesh*)),
            this, SLOT(slot_receiveFaceData(Mesh*)));
    connect(ui->mygl, SIGNAL(sig_sendHalfEdgeData(Mesh*)),
            this, SLOT(slot_receiveHalfEdgeData(Mesh*)));

    connect(ui->vertsListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            ui->mygl, SLOT(slot_setSelectedVertex(QListWidgetItem*)));
    connect(ui->facesListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            ui->mygl, SLOT(slot_setSelectedFace(QListWidgetItem*)));
    connect(ui->halfEdgesListWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            ui->mygl, SLOT(slot_setSelectedHalfEdge(QListWidgetItem*)));

    //Vertex Boxes
    connect(ui->vertPosXSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_vertPosX(double)));
    connect(ui->vertPosYSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_vertPosY(double)));
    connect(ui->vertPosZSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_vertPosZ(double)));

    //Color boxes
    connect(ui->faceRedSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_faceRed(double)));
    connect(ui->faceGreenSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_faceGreen(double)));
    connect(ui->faceBlueSpinBox, SIGNAL(valueChanged(double)),
            ui->mygl, SLOT(slot_faceBlue(double)));
    //Obj Import
    connect(ui->ImportObj, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_importOBJ()));

    //Catmull Clark Subdivide
    connect(ui->subdivideButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_subdivide()));

    //Mesh Topology Operations
    connect(ui->addvertexButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_addvertex()));
    connect(ui->triangulateButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_triangulate()));

    connect(ui -> mygl, SIGNAL(sig_sendJoint(QTreeWidgetItem*)), this, SLOT(slot_addJoint(QTreeWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::slot_receiveVertexData(Mesh *mesh) {
    for (const uPtr<Vertex> &v : mesh->vertices) {
        ui->vertsListWidget->addItem(v.get());
    }
}

void MainWindow::slot_receiveFaceData(Mesh *mesh) {
    for (const uPtr<Face> &f : mesh->faces) {
        ui->facesListWidget->addItem(f.get());
    }
}

void MainWindow::slot_receiveHalfEdgeData(Mesh *mesh) {
    for (const uPtr<HalfEdge> &he : mesh->halfEdges) {
        ui->halfEdgesListWidget->addItem(he.get());
    }
}


void MainWindow::on_importJSON_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, QString(""), QDir::currentPath().append(QString("../..")), QString("*.json"));

    if ( !filename.isNull() ) {
        qDebug() << "selected file path :" << filename.toUtf8();
        ui->mygl->createSkeleton(filename);
    }

    ui -> mygl -> update();
}


void MainWindow::on_bindskeletonButton_clicked()
{
    if (ui -> mygl -> m_geomJoint.get() != nullptr) {

        glm::mat4 t[100];
        glm::mat4 b[100];

        ui -> mygl -> jointsLoaded = true;

        ui -> mygl -> m_mesh.bind(ui -> mygl -> m_geomJoint.get());

        ui -> mygl -> m_geomJoint -> computeBind();

        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_geomJoint -> getAllBinds(b);

        ui -> mygl -> m_progSkeleton.setTransformationMat(t);
        ui -> mygl -> m_progSkeleton.setBindMat(b);

        ui -> mygl -> m_mesh.create();
        ui -> mygl -> update();

    }
}

void MainWindow::update_rlabel() {
    float w = ui -> mygl -> selectedJoint -> rotate.w;
    float x = ui -> mygl -> selectedJoint -> rotate.x;
    float y = ui -> mygl -> selectedJoint -> rotate.y;
    float z = ui -> mygl -> selectedJoint -> rotate.z;

}

void MainWindow::update_tlabel() {
    float x = ui -> mygl -> selectedJoint -> translate.x;
    float y = ui -> mygl -> selectedJoint -> translate.y;
    float z = ui -> mygl -> selectedJoint -> translate.z;
}

void MainWindow::slot_addJoint(QTreeWidgetItem * item) {
    ui -> jointwidget -> addTopLevelItem(item);
}

void MainWindow::on_jointwidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui -> mygl -> selectedJoint = (Joint*)item;
    ui->mygl->m_geomJoint->createClicked(item);
    update_rlabel();
    ui -> mygl -> update();
    update_tlabel();
}

void MainWindow::on_translatej_x_valueChanged(double arg1)
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->translate.x = arg1;
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_tlabel();
    }
}

void MainWindow::on_translatej_y_valueChanged(double arg1)
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->translate.y = arg1;
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_tlabel();
    }
}

void MainWindow::on_translatej_z_valueChanged(double arg1)
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->translate.z = arg1;
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_tlabel();
    }
}





void MainWindow::on_rotatejointx_clicked()
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->rotate *= glm::quat(glm::angleAxis(0.5f, glm::vec3(1,0,0)));
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_rlabel();

    }
}



void MainWindow::on_rotatejointy_clicked()
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->rotate *= glm::quat(glm::angleAxis(0.5f, glm::vec3(0,1,0)));
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_rlabel();
    }
}


void MainWindow::on_rotatejointz_clicked()
{
    if (ui -> mygl -> selectedJoint != nullptr) {
        ui -> mygl -> selectedJoint->rotate *= glm::quat(glm::angleAxis(0.5f, glm::vec3(0,0,1)));
        ui-> mygl-> m_geomJoint->createClicked(ui -> mygl -> selectedJoint);

        glm::mat4 t[100];
        ui -> mygl -> m_geomJoint -> getAllTransformations(t);
        ui -> mygl -> m_progSkeleton.setTransformationMat(t);

        ui -> mygl -> update();
        update_rlabel();
    }
}

