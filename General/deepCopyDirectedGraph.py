Deep Copy of a Graph

Graph {
  [V1,...,Vn]
}

Vertices  {
  int data, // int 
  [&Vi_1,...,&Vi_k]
}

# V1->[V2,V3]
# V2->[V1,V4,V3]
# V3->[V1]
# V4->[V2]

class Graph():
    def init(self, points)
        self.points = points # [], int, string

class Vertex():
    def init(self, data=0, vertices=[]):
        this.data = data
        this.vertices = vertices

points = []

def deepcopy(graph):
    globals points
    # DFS
    cloneGraph = Graph([])
    for i in range(len(graph.points)):   
        vertex = graph.points[i]
        cloneVertex = Vertex(vertex.data)
        DFS(cloneVertex, vertex, vertex.vertices)
    cloneGraph.points = points
    return cloneGraph


HashMap<Vertex, Vertex> visited = new HashMap<>();

def DFS(cloneVertex, vertex, vertices):
    globals points
    if (visited.get(vertex)):
        return
    visited.put(vertex, cloneVertex)
    for i in range(len(vertices)):
        newEdgeClone = Vertex()
        newEdgeClone.data = vertices[i].data
        DFS(newEdgeClone, vertices[i], vertices[i].vertices)
        cloneVertex.vertices.append(visited.get(vertices[i]))
    points.append(cloneVertex)
