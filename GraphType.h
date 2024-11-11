#include "QueType.h"

template<class VertexType>
// Assumption: VertexType is a type for which the "=", 
// "==", and "<<" operators are defined
class GraphType
{
public:
  GraphType();                  // Default of 50 vertices
  GraphType(int maxV);          // maxV <= 50
 ~GraphType();
  GraphType(const GraphType& other);  // Copy constructor
  GraphType& operator= (const GraphType& other);  // Assignment operator overload
//  void MakeEmpty();
//  bool IsEmpty() const;
//  bool IsFull() const;
  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  void GetToVertices(VertexType, QueType<VertexType>&);
  bool EdgeExists(VertexType fromVertex, VertexType toVertex) const;  // Check if edge exists
  void DeleteEdge(VertexType fromVertex, VertexType toVertex);  // Delete edge between vertices
  int WeightIs(VertexType fromVertex, VertexType toVertex) const;
//  void ClearMarks();
//  void MarkVertex(VertexType);
//  bool IsMarked(VertexType);
private:
  int numVertices;
  int maxVertices;
  VertexType* vertices;
  int edges[50][50];
  bool* marks;	// marks[i] is mark for vertices[i].
};

