#ifndef MYGL_H
#define MYGL_H

#include <openglcontext.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/squareplane.h>
#include "camera.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <QListWidget>
#include "joint.h"
#include <mesh.h>
#include <vertexdisplay.h>
#include <facedisplay.h>
#include <halfedgedisplay.h>


class MyGL
    : public OpenGLContext
{
    Q_OBJECT
private:
    SquarePlane m_geomSquare;// The instance of a unit cylinder we can use to render any cylinder
    ShaderProgram m_progLambert;// A shader program that uses lambertian reflection
    ShaderProgram m_progFlat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
        // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera m_glCamera;

public:
    explicit MyGL(QWidget *parent = nullptr);
    ~MyGL();



    // Have an instance of [...]Display that is
    // drawn in paintGL, and has VBO data representing
    // the position of the currently selected [...] so
    // it can be drawn as a GL_POINTS
    VertexDisplay m_vertDisplay;
    FaceDisplay m_faceDisplay;
    HalfEdgeDisplay m_halfEdgeDisplay;
    Mesh m_mesh;
    uPtr<Joint> m_geomJoint;
    QListWidgetItem* m_selected;
    glm::vec3 color;

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void createMesh(QString filename);
    void init_edges(QStringList line_list);
    void createSkeleton(QString filename);
    void updateLists();
    Joint* loadJson(QJsonObject, Joint*);

    void drawJoints(Joint* parent);



    Joint *selectedJoint;

    ShaderProgram m_progSkeleton;

    bool jointsLoaded;


protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void slot_vertPosX(double x);
    void slot_vertPosY(double y);
    void slot_vertPosZ(double z);

    void slot_faceRed(double red);
    void slot_faceGreen(double green);
    void slot_faceBlue(double blue);

    void slot_setSelectedVertex(QListWidgetItem *v);
    void slot_setSelectedFace(QListWidgetItem *f);
    void slot_setSelectedHalfEdge(QListWidgetItem *he);

    void slot_importOBJ();
    void slot_subdivide();
    void slot_addvertex();
    void slot_triangulate();


signals:
    void sig_sendVertexData(Mesh *mesh);
    void sig_sendFaceData(Mesh *mesh);
    void sig_sendHalfEdgeData(Mesh *mesh);
    void sig_sendJoint(QTreeWidgetItem*);
};


#endif // MYGL_H
