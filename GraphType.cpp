#include "GraphType.h"
#include <stdexcept>

const int NULL_EDGE = 0;

template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for  
//       marks and vertices.  numVertices is set to 0; 
//       maxVertices is set to 50.
{
  numVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
  for (int i = 0; i < maxV; ++i) {
    for (int j = 0; j < maxV; ++j) {
        edges[i][j] = 0;
    }
  }
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for  
//       marks and vertices.  
//       numVertices is set to 0; maxVertices is set to maxV.
{
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
    
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set 
//       to NULL_EDGE.
//       numVertices has been incremented.
{
  vertices[numVertices] = vertex;

  for (int index = 0; index < numVertices; index++)
  {
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;
  }
  numVertices++;
}

template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
// Post: Returns the index of vertex in vertices.
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;  
  return index;
}       

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
     VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex)
  edges[row][col] = weight;
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, 
     QueType<VertexType>& adjVertices)
// Post: 
{
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      adjVertices.Enqueue(vertices[toIndex]);
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete[] vertices;
    delete[] marks;
}

template <class VertexType>
GraphType<VertexType>::GraphType(const GraphType& other)
{
    numVertices = other.numVertices;
    maxVertices = other.maxVertices;

    vertices = new VertexType[maxVertices];
    marks = new bool[maxVertices];

    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = other.vertices[i];
        marks[i] = other.marks[i];
    }
    for (int i = 0; i < maxVertices; ++i) {
        for (int j = 0; j < maxVertices; ++j) {
            edges[i][j] = other.edges[i][j];
        }
    }
}

template <class VertexType>
GraphType<VertexType>& GraphType<VertexType>::operator=(const GraphType& other)
{
    if (this == &other) {
        return *this;
    }
    delete[] vertices;
    delete[] marks;

    numVertices = other.numVertices;
    maxVertices = other.maxVertices;

    vertices = new VertexType[maxVertices];
    marks = new bool[maxVertices];
    
    for (int i = 0; i < maxVertices; ++i) {
        for (int j = 0; j < maxVertices; ++j) {
            edges[i][j] = other.edges[i][j];
        }
    }

    for (int i = 0; i < numVertices; ++i) {
        vertices[i] = other.vertices[i];
        marks[i] = other.marks[i];
    }

    return *this;
}

template <class VertexType>
bool GraphType<VertexType>::EdgeExists(VertexType fromVertex, VertexType toVertex) const
{
    int fromIndex = IndexIs(fromVertex);
    int toIndex = IndexIs(toVertex);

    return (fromIndex != -1 && toIndex != -1 && edges[fromIndex][toIndex] != 0);
}

template <class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex)
{
    int fromIndex = IndexIs(fromVertex);
    int toIndex = IndexIs(toVertex);

    if (fromIndex != -1 && toIndex != -1) {
        edges[fromIndex][toIndex] = 0;
    }
    else {
        std::cerr << "Error: One or both vertices not found." << std::endl;
    }
}

template <class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex) const
{
    int fromIndex = IndexIs(fromVertex);
    int toIndex = IndexIs(toVertex);

    if (fromIndex == -1 || toIndex == -1) {
        throw std::invalid_argument("One or both vertices not found.");
    }

    if (edges[fromIndex][toIndex] == NULL_EDGE) {
        throw std::invalid_argument("No edge exists between the given vertices.");
    }

    return edges[fromIndex][toIndex];
}
