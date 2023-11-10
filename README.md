# Micro-Maya
A mini version of Autodesk Maya, complete with mesh and joint editing

MESH CLASS:
  Stores Half Edges, Faces, and Vertices. This class also inherits from Drawable, and is drawn in MyGL()::paintGL().

OBJ IMPORTING:
  Clicking the corresponding GUI button allows the user to select an OBJ file to be read, and from it, generates a half-edge data structure from the input and then renders the resulting mesh using VBOs, each face being assigned a random color. Meshes are closed and manifold. Once mesh is built, it can be replaced with any other OBJ mesh uploaded 

GRAPHICAL USER INTERFACE:
  QListWidgets allow user to view and select faces, half-edges, and vertices of uploaded mesh. 
  When a face/half-edge/vertex is selected in one of these lists, there is a visual indication of this selection in the GL window:
    A selected HalfEdge should be represented as a single GL_LINES. The line should gradiate from red to yellow, with the yellow end corresponding to the Vertex to which the HalfEdge points.
    A selected Vertex should be represented as a white GL_POINTS.
    A selected Face should be surrounded by a strip of GL_LINES colored with the opposite color of the Face. 

VISUAL DEBUGGING:
  N: selects NEXT half-edge of the currently selected half-edge
  M: selects SYM half-edge of the currently selected half-edge
  F: selects FACE of the currently selected half-edge
  V: selects VERTEX of the currently selected half-edge
  H: selects HALF-EDGE of the currently selected vertex
  Shift + H: selects HALF-EDGE of the currently selected face

POLAR SPHERICAL CAMERA:
  The camera moves along the surface of a sphere at the origin when rotated, following the polar spherical camera model. The camera translates along its forward vector when it is zoomed in and out, and both the camera and its reference point translates along the camera's right and up vectors when the camera is panned.

MESH TOPOLOGY:
  GUI button adds a vertex as a midpoint to the currently selected half-edge, and the new vertex as well as the two newly formed half-edges should be listed in corresponding ListWidget.
  GUI button that triangulates selected face.

CATMULL-CLARK SUBDIVISION:
  GUI button allows user to subdivide any given polygon mesh using Catmull-Clark Subdivision. 

JOINT CLASS:
  Respresents a joint in a virtual skeleton structure. Each joint contains:
      Name: The name of this joint which will be displayed in your QTreeWidget of joints.
      Parent: The joint that is the parent of this joint.
      Children: The set of joints that have this joint as their parent.
      Position: The position of this joint relative to its parent joint.
      Rotation: The quaternion that represents this joint's current orientation. 
      Bind Matrix: The inverse of the joint's compound transformation matrix at the time a mesh is bound to the joint's skeleton.
  Joints are drawn as wireframe spheres.

SKELETON JSON FILE READER:
  GUI button enables user to load a JSON file and parse it to create a skeleton joint heirarchy. Skeleton is interactive such that user can select and rotate/move joints.
