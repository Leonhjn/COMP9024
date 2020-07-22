typedef int Vertex;

typedef struct {
 	Vertex v;
 	Vertex w;
 }Edge;

typedef struct graphRep *Graph;

Graph newGraph(int);
Graph freegraph(Graph);
void showGraph(Graph);


Edge newEdge(Vertex,Vertex);
void insertEdge(Edge, Graph);     // insert an edge
void removeEdge(Edge, Graph);     // remove an edge
void showEdge(Edge);              // print an edge
int isEdge(Edge, Graph);