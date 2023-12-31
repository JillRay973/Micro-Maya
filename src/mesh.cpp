#include "mesh.h"
#include "iostream"
#include <QFile>
#include <unordered_set>
#include <vertex.h>



Mesh::Mesh(OpenGLContext* context)
    : Drawable(context), faces{}, halfEdges{}, vertices{}, binded(false)
{}

Mesh::~Mesh()
{}

// helper
int getNumSides(Face *face) {
    HalfEdge* curr = face->edge;
    int numSides = 0;

    do {
        curr = curr->next;
        numSides++;
    } while (curr != face->edge);

    return numSides;
}

void Mesh::create() {
    std::vector<glm::vec4> pos;
    std::vector<glm::vec4> nor;
    std::vector<glm::vec4> color;
    std::vector<GLuint> idx;
    std::vector<glm::vec2> weights;
    std::vector<glm::ivec2> jointIDs;

    for (uPtr<Face> &f : faces) {
        HalfEdge *currEdge = f->edge;
        int firstCount = pos.size();

        do {
            HalfEdge* curr = currEdge;
            glm::vec3 v1 = curr->next->vertex->pos - curr->vertex->pos;
            glm::vec3 v2 = curr->next->next->vertex->pos - curr->next->vertex->pos;


            while (glm::length(glm::cross(v1, v2)) < FLT_EPSILON) {
                curr = curr->next;
                v1 = curr->next->vertex->pos - curr->vertex->pos;
                v2 = curr->next->next->vertex->pos - curr->next->vertex->pos;
            }



            pos.push_back(glm::vec4(currEdge->vertex->pos, 1));

            color.push_back(glm::vec4(f->color, 1));

             glm::vec4 normal = glm::vec4(glm::normalize(glm::cross(v1, v2)), 0);
             nor.push_back(normal);
             Vertex* vertex = currEdge->vertex;
             currEdge = currEdge->next;

             if (binded) {
                weights.push_back(glm::vec2(curr->between->weight1, curr->between->weight2));
                jointIDs.push_back(glm::ivec2(curr->between->inf1->id, curr->between->inf2->id));
             }
        } while (currEdge != f->edge);

        // mesh indices
        int i = 0;
        while (i < getNumSides(f.get()) - 2) {
            idx.push_back(firstCount);
            idx.push_back(firstCount + i + 1);
            idx.push_back(firstCount + i + 2);
            i++;
        }

    }

    count = idx.size();

    generateIdx();
    bindIdx();
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, idx.size() * sizeof(GLuint), idx.data(), GL_STATIC_DRAW);

    generatePos();
    bindPos();
    mp_context->glBufferData(GL_ARRAY_BUFFER, pos.size() * sizeof(glm::vec4), pos.data(), GL_STATIC_DRAW);

    generateNor();
    bindNor();
    mp_context->glBufferData(GL_ARRAY_BUFFER, nor.size() * sizeof(glm::vec4), nor.data(), GL_STATIC_DRAW);

    generateCol();
    bindCol();
    mp_context->glBufferData(GL_ARRAY_BUFFER, color.size() * sizeof(glm::vec4), color.data(), GL_STATIC_DRAW);

    generateJointIDs();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufJointIDs);
    mp_context->glBufferData(GL_ARRAY_BUFFER, jointIDs.size() * sizeof(glm::ivec2), jointIDs.data(), GL_STATIC_DRAW);

    generateWeights();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufWeights);
    mp_context->glBufferData(GL_ARRAY_BUFFER, weights.size() * sizeof(glm::vec2), weights.data(), GL_STATIC_DRAW);

}

GLenum Mesh::drawMode() {
    return GL_TRIANGLES;
}


void Mesh::setHalfEdgeVertices(int x, int y, int z, int vert) {
    halfEdges.at(x)->vertex = vertices.at(vert).get();
    halfEdges.at(y)->vertex = vertices.at(vert).get();
    halfEdges.at(z)->vertex = vertices.at(vert).get();
}


void Mesh::assignSymm(std::vector<uPtr<HalfEdge>> *in_edges,
                      std::vector<uPtr<HalfEdge>> *out_edges,
                      std::vector<uPtr<HalfEdge>> *newHalfEdges) {

    int last = in_edges->size() - 1;

    in_edges->at(last)->symm = out_edges->at(0).get();
    out_edges->at(0)->symm = in_edges->at(last).get();

    for (int i = 0; i < last; i++) {
        in_edges->at(i)->symm = out_edges->at(i + 1).get();
        out_edges->at(i + 1)->symm = in_edges->at(i).get();
    }

    for (uPtr<HalfEdge> &he : *in_edges) {
        newHalfEdges->push_back(std::move(he));
    }

    for (uPtr<HalfEdge> &he : *out_edges) {
        newHalfEdges->push_back(std::move(he));
    }
}

void Mesh::setFaces(std::vector<HalfEdge*> *temp_he, Face *f, int n) {

    f->setColor();

    temp_he->at(n)->face = f;
    f->edge = temp_he->at(n);

    temp_he->at(n)->next->face = f;
    f->edge = temp_he->at(n)->next;

    temp_he->at(n)->next->next->face = f;
    f->edge = temp_he->at(n)->next->next;

    temp_he->at(n)->next->next->next->face = f;
    f->edge = temp_he->at(n)->next->next;
}

std::vector<uPtr<Face>> Mesh::quadFaces(std::vector<HalfEdge*> *temp_he, Face *f) {
    std::vector<uPtr<Face>> quad_faces;

    for (int i = 0; i < (int)temp_he->size() - 1; i++) {
        uPtr<Face> face = mkU<Face>();
        setFaces(temp_he, face.get(), i);
        quad_faces.push_back(std::move(face));
    }
    setFaces(temp_he, f, temp_he->size() - 1);

    return quad_faces;
}

void Mesh::centroid(std::map<Face*, Vertex*> *centroid_map,
                    std::vector<uPtr<Vertex>> *newVertices) {

    // for the original faces
    for (uPtr<Face> &f : faces) {
        uPtr<Vertex> centroid = mkU<Vertex>();
        glm::vec3 centroid_pos = glm::vec3();

        HalfEdge *curr = f->edge;
        do {
            centroid_pos += curr->vertex->pos;
            curr = curr->next;
        } while (curr != f->edge);

        centroid_pos /= getNumSides(f.get());
        centroid->pos = centroid_pos;

        centroid_map->insert({f.get(), centroid.get()});
        newVertices->push_back(std::move(centroid));
    }
}

void Mesh::midpoint(std::map<Face*, Vertex*> *centroid_map,
                    std::map<HalfEdge*, Vertex*> *midpoint_map,
                    std::set<HalfEdge*> *edge_split,
                    std::vector<uPtr<Vertex>> *newVertices) {

    // for each eadge in the set of edges to split
    for (HalfEdge* he : *edge_split) {

        HalfEdge *prev = he->symm;

        glm::vec3 v1 = prev->vertex->pos;
        glm::vec3 v2 = he->vertex->pos;
        glm::vec3 f1 = centroid_map->find(he->face)->second->pos;
        glm::vec3 f2 = centroid_map->find(prev->face)->second->pos;

        // border edge
        glm::vec3 e = (v1 + v2 + f1) / 3.f;

        if (prev) {
            e = (v1 + v2 + f1 + f2) / 4.f;
        }

        uPtr<Vertex> midPoint = mkU<Vertex>();
        midPoint->pos = e;

        midpoint_map->insert({he, midPoint.get()});
        newVertices->push_back(std::move(midPoint));
    }
}

void Mesh::smooth(std::map<Face*, Vertex*> *centroid_map,
                  std::map<HalfEdge*, Vertex*> *midpoint_map) {

    // smooth all old vertices
    for (uPtr<Vertex> &v : vertices) {

        HalfEdge *curr = v->edge;

        // sum of all adjacent midpoints
        glm::vec3 sum_e = glm::vec3();

        // sum of the centroids of all faces incident to v
        glm::vec3 sum_f = glm::vec3();

        // number of adjacent midpoints
        float n = 0;

        do {
            glm::vec3 midpt_sum = midpoint_map->find(curr)->second->pos;
            glm::vec3 centroid_sum = centroid_map->find(curr->face)->second->pos;

            if (midpoint_map->find(curr->symm) != midpoint_map->end()){
                midpt_sum = midpoint_map->find(curr->symm)->second->pos;
            }
            sum_e += midpt_sum;
            sum_f += centroid_sum;

            n++;
            curr = curr->next->symm;
        } while (curr != v->edge);

        sum_e /= (n * n);
        sum_f /= (n * n);

        glm::vec3 position = (n - 2.f) * v->pos / n + sum_e + sum_f;
        v->pos = position;
    }
}


void Mesh::quadrangulate(std::set<HalfEdge*> *edge_split,
                         std::map<Face*, Vertex*> *centroid_map,
                         std::map<HalfEdge*, Vertex*> *midpoint_map,
                         std::vector<uPtr<HalfEdge>> *newHalfEdges,
                         std::vector<uPtr<Face>> *newFaces) {

    // adding in midpoints (slightly modified splitEdge function)
    for (HalfEdge *he1: *edge_split) {
        HalfEdge* he2 = he1->symm;

        Vertex *midpoint = midpoint_map->find(he1)->second;

        Vertex* v1 = he1->vertex;
        Vertex* v2 = he2->vertex;

        uPtr<HalfEdge> he1B = mkU<HalfEdge>();
        uPtr<HalfEdge> he2B = mkU<HalfEdge>();

        he1B->vertex = v1;
        he2B->vertex = v2;

        he1B->face = he1->face;
        he1->face->edge = he1B.get();

        he2B->face = he2->face;
        he2->face->edge = he2B.get();

        he1->symm = he2B.get();
        he2B->symm = he1;
        he2->symm = he1B.get();
        he1B->symm = he2;

        he1B->next = he1->next;
        he2B->next = he2->next;
        he1->next = he1B.get();
        he2->next = he2B.get();

        he1->vertex->edge = he1B.get();
        he2->vertex->edge = he2B.get();

        he1->vertex = midpoint;
        he2->vertex = midpoint;


        newHalfEdges->push_back(std::move(he1B));
        newHalfEdges->push_back(std::move(he2B));
    }

    for (uPtr<Face> &f : faces) {
        HalfEdge *curr = f->edge;

        //storing the half edges temporarily
        std::vector<HalfEdge*> temp_he;
        // point towards centroid
        std::vector<uPtr<HalfEdge>> in_edges;
        // points from centroid (towards midpoint)
        std::vector<uPtr<HalfEdge>> out_edges;
        // access next half edge given id
        std::map<int, HalfEdge*> map_next;
        //the quadrangulated faces
        std::vector<uPtr<Face>> quad_faces;

        // storing temporary half edges
        do {
            temp_he.push_back(curr);
            curr = curr->next->next;
        } while (curr != f->edge);

        HalfEdge *next = temp_he.at(temp_he.size() - 1)->next;

        for (HalfEdge *he: temp_he) {
            map_next.insert({he->id, next});
            next = he->next;
        }

        for (HalfEdge *he : temp_he) {
            uPtr<HalfEdge> to_centroid = mkU<HalfEdge>();
            uPtr<HalfEdge> from_centroid = mkU<HalfEdge>();

            Vertex *cent_vert = centroid_map->find(he->face)->second;
            to_centroid->vertex = cent_vert;
            cent_vert->edge = to_centroid.get();

            Vertex *next_vert = map_next[he->id]->vertex;
            from_centroid->vertex = next_vert;
            next_vert->edge = from_centroid.get();

            // half edge ring
            he->next->next = to_centroid.get();
            to_centroid->next = from_centroid.get();
            from_centroid->next = he;

            in_edges.push_back(std::move(to_centroid));
            out_edges.push_back(std::move(from_centroid));
        }

        assignSymm(&in_edges, &out_edges, newHalfEdges);

        quad_faces = quadFaces(&temp_he, f.get());
        for (uPtr<Face> &face : quad_faces) {
            newFaces->push_back(std::move(face));
        }
    }
}

void Mesh::subdivide() {

    // store new primitives
    std::vector<uPtr<Vertex>> newVertices;
    std::vector<uPtr<HalfEdge>> newHalfEdges;
    std::vector<uPtr<Face>> newFaces;

    // set of edges to split
    std::set<HalfEdge*> edge_split;
    // access a centroid given its corresponding face
    std::map<Face*, Vertex*> centroid_map;
    // access a midpoint given its corresponding edge
    std::map<HalfEdge*, Vertex*> midpoint_map;

    // populate set of half edges to split
    for (uPtr<HalfEdge> &he: halfEdges) {
        if (std::find(edge_split.begin(), edge_split.end(),
                      he.get()->symm) == edge_split.end()) {
            edge_split.insert(he.get());
        }
    }


    centroid(&centroid_map, &newVertices);

    midpoint(&centroid_map, &midpoint_map, &edge_split, &newVertices);

    smooth(&centroid_map, &midpoint_map);

    quadrangulate(&edge_split, &centroid_map, &midpoint_map,
                  &newHalfEdges, &newFaces);

    // update originals
    for (uPtr<Vertex> &v : newVertices) {
        vertices.push_back(std::move(v));
    }

    for (uPtr<HalfEdge> &he : newHalfEdges) {
        halfEdges.push_back(std::move(he));
    }

    for (uPtr<Face> &face : newFaces) {
        faces.push_back(std::move(face));
    }
}

void Mesh::addvertex(HalfEdge *he1) {
    HalfEdge* he2 = he1->symm;

    // create the new vertex V3
    uPtr<Vertex> v3 = mkU<Vertex>();

    // V3’s pos is the average of V1’s and V2’s
    Vertex* v1 = he1->vertex;
    Vertex* v2 = he2->vertex;

    glm::vec3 avg = 0.5f * (v1->pos + v2->pos);
    v3->pos = avg;
    v3->edge = he1;

    // create the two new half-edges HE1B and HE2B needed to surround V3
    uPtr<HalfEdge> he1B = mkU<HalfEdge>();
    uPtr<HalfEdge> he2B = mkU<HalfEdge>();

    // HE1B points to V1 and HE2B points to V2
    he1B->vertex = v1;
    he2B->vertex = v2;

    // set the correct face pointers for HE1B and HE2B
    he1B->face = he1->face;
    he2B->face = he2->face;

    // adjust the symm, next, and vert pointers of HE1, HE2, HE1B, and HE2B
    he1->symm = he2B.get();
    he2B->symm = he1;
    he2->symm = he1B.get();
    he1B->symm = he2;

    he1B->next = he1->next;
    he2B->next = he2->next;
    he1->next = he1B.get();
    he2->next = he2B.get();

    he1->vertex->edge = he1B.get();
    he2->vertex->edge = he2B.get();

    he1->vertex = v3.get();
    he2->vertex = v3.get();

    vertices.push_back(std::move(v3));
    halfEdges.push_back(std::move(he1B));
    halfEdges.push_back(std::move(he2B));
}

void Mesh::triangulate(Face *face) {

    HalfEdge* he_0 = face->edge;

    for (int i = 0; i < getNumSides(face) - 3; i++) {

        // create two new half-edges HE_A and HE_B
        uPtr<HalfEdge> he_A = mkU<HalfEdge>();
        uPtr<HalfEdge> he_B = mkU<HalfEdge>();

        // HE_A points to HE_0.vert
        he_A->vertex = he_0->vertex;

        // HE_B points to HE_0.next.next.vert
        he_B->vertex = he_0->next->next->vertex;

        // HE_A and HE_B have each other for syms
        he_A->symm = he_B.get();
        he_B->symm = he_A.get();

        // create a second face FACE2
        uPtr<Face> face_2 = mkU<Face>();

        // HE_A, HE_0.next, and HE_0.next.next now all point to FACE2
        he_A->face = face_2.get();
        he_0->next->face = face_2.get();
        he_0->next->next->face = face_2.get();

        // HE_B points to FACE1
        he_B->face = face;

        // FACE2’s arbitrary half-edge pointer can be HE_A
        face_2->edge = he_A.get();

        // set FACE2 color
        face_2->color = face->color;

        // fix up the next pointers for our half-edges

        // HE_B.next = HE_0.next.next.next
        he_B->next = he_0->next->next->next;

        // HE_0.next.next.next = HE_A
        he_0->next->next->next = he_A.get();

        // HE_A.next = HE_0.next
        he_A->next = he_0->next;

        // HE_0.next = HE_B
        he_0->next = he_B.get();

        faces.push_back(std::move(face_2));
        halfEdges.push_back(std::move(he_A));
        halfEdges.push_back(std::move(he_B));
    }
}

void Mesh::bind(Joint* root) {

    binded = true;

    for (int i = 0; i < vertices.size(); i++) {

        Vertex* v = vertices[i].get();

        Joint* j1 = nullptr;
        Joint* j2 = nullptr;
        float d1 = std::numeric_limits<float>::max();
        float d2 = std::numeric_limits<float>::max();
        findJoint(v->pos, root, j1, j2, d1, d2);

        float denom = d1 + d2;
        v->weight1 = d2 / denom;
        v->weight2 = d1 / denom;
        v->inf1 = j1;
        v->inf2 = j2;

    }

}

void Mesh::findJoint(glm::vec3 pos, Joint* curr, Joint*& j1, Joint*& j2, float& d1, float& d2) {

    float dist = glm::distance(glm::vec4(pos, 1), curr->computeOverallT() * glm::vec4(0,0,0,1));

    // d1 is smallest, d2 is second smallest

    if (dist < d1) {

        j2 = j1;
        d2 = d1;
        j1 = curr;
        d1 = dist;

    } else if (dist < d2) {
        j2 = curr;
        d2 = dist;
    }

    for (auto& child : curr->children) {
        findJoint(pos, child.get(), j1, j2, d1, d2);
    }
}


