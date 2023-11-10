#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vertex.h>
#include <face.h>
#include <halfedge.h>
#include <mesh.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionCamera_Controls_triggered();






    void on_importJSON_clicked();

    void on_bindskeletonButton_clicked();

    void on_jointwidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_translatej_x_valueChanged(double arg1);
    void on_translatej_y_valueChanged(double arg1);
    void on_translatej_z_valueChanged(double arg1);

    void update_rlabel();
    void update_tlabel();

    void on_rotatejointx_clicked();

    void on_rotatejointy_clicked();

    void on_rotatejointz_clicked();

public slots:
    void slot_receiveVertexData(Mesh *mesh);
    void slot_receiveFaceData(Mesh *mesh);
    void slot_receiveHalfEdgeData(Mesh *mesh);
    void slot_addJoint(QTreeWidgetItem*);
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
