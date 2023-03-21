#pragma once 
#include <list>
#include <iostream>

/*!
 * @brief Node with id, type, and neighbors 
 */
struct Node
{ 
    int id = 0;
    int type = 0; 
    std::list<Node*> neighbors;

    Node();
    ~Node();

    /// @brief sets the id and type of the node
    /// @param i id (location of node)
    /// @param t type
    void set_Node(int i, int t); 

    /// @brief takes in a list of nodes to assign as neighbors
    /// @param n neighbor list 
    void set_neighbors(std::list<Node*> n); 

    //! @brief 
    //! @param x 
    //! @param y 
    void function(int x, float y); 

};