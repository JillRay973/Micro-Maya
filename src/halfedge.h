#ifndef HALFEDGE_H
#define HALFEDGE_H

#include <QListWidget>
#include <vertex.h>
#include <face.h>
#include <la.h>
#include <joint.h>

class Vertex;
class Face;



class HalfEdge : public QListWidgetItem
{
public:
    static int lastHalfEdge;
    HalfEdge* next;     // pointer to the next HalfEdge in the loop of HalfEdges that lie on this HalfEdge's Face
    HalfEdge* symm;     // this HalfEdge's symmetrical HalfEdge
    Face* face;         // pointer to the Face on which this HalfEdge lies
    Vertex* vertex;     // pointer to the Vertex between this HalfEdge and its next HalfEdge
    int id;             // unique integer to identify the HalfEdge
    HalfEdge* between;
    QString name;
    Joint* inf1; // joint influencer 1
    Joint* inf2; // joint influencer 2

    float weight1;
    float weight2;
    glm::vec3 pos;
    HalfEdge();
    HalfEdge* he;
    HalfEdge(const HalfEdge &halfEdge);

};

#endif // HALFEDGE_H
