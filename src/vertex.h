#ifndef VERTEX_H
#define VERTEX_H

#include <QListWidget>
#include <halfedge.h>
#include <joint.h>
#include <la.h>

class HalfEdge;

class Vertex : public QListWidgetItem
{
public:
    static int lastVertex;

    glm::vec3 pos;      // storing position
    HalfEdge* edge;     // pointer to one of the HalfEdges that points to this Vertex
    int id;             // unique integer to identify the Vertex
    QString name;
    Joint* inf1; // joint influencer 1
    Joint* inf2; // joint influencer 2
    Vertex* between;
    float weight1;
    float weight2;
    void findJoints(Joint* j);

    HalfEdge* he;
    // store which joints influence its transformation and by how much they influence it
    // pairs of joint ids and joint weights
    std::vector<std::pair<int, float>> influences;
    Vertex(glm::vec3 p);
    Vertex();
    Vertex(const Vertex &vertex);
};

#endif // VERTEX_H
