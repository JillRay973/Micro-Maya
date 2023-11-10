#include "vertex.h"

int Vertex::lastVertex = 1;


Vertex::Vertex()
    : QListWidgetItem(), pos(glm::vec3()),
    edge(nullptr), id(0), name("vertex "), inf1(nullptr), inf2(nullptr), weight1(1000.f), weight2(1000.f)
{
    id = lastVertex++;
    name.append(QString::number(id));
    this->setText(name);
}

Vertex::Vertex(const Vertex &vertex)
    : QListWidgetItem(), pos(vertex.pos),
    edge(vertex.edge), id(vertex.id),
    name(vertex.name), inf1(nullptr), inf2(nullptr), weight1(1000.f), weight2(1000.f)
{}
void Vertex::findJoints(Joint* j) {

    j -> computeBind();
    float dist = glm::distance(glm::vec4(pos, 1), j->computeOverallT() * glm::vec4(0,0,0,1));

    if (dist < weight1 || dist < weight2) {
        if (weight1 < weight2) {
            weight2 = dist ;
            inf2 = j;
        } else {
            weight1 = dist;
            inf1 = j;
        }
    }

    for (int i = 0; i < j->children.size(); i ++) {
        j -> children.at(i).get()->computeBind();
        findJoints(j->children.at(i).get());
    }
}

Vertex::Vertex(glm::vec3 p)
    :pos(p), id(lastVertex++), he(), inf1(nullptr), inf2(nullptr), weight1(1000.f), weight2(1000.f)
{

    QListWidgetItem::setText("Vertex " + QString::number(id));
}
