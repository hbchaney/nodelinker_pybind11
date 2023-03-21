#include "Node.hpp"

using namespace std; 

Node::Node() {} 


void Node::set_Node(int i, int t)
{ 
    id = i; 
    type = t; 
}

Node::~Node() {} 

void Node::set_neighbors(list<Node*> n) 
{ 
    neighbors = n; 
}