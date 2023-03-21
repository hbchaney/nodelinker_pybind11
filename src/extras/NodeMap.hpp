#pragma once 

#include "Node.hpp"
#include <vector> 
#include <iostream>

class NodeMap 
{ 
    
    std::vector<Node> nodes; //dynamic array of nodes 
    std::list<std::list<const Node*>> connect_nodes; //list for storing the 
    std::list<const Node*> wait_list; 
    std::vector<bool> check_list;

    int iterator = 0; 
    int last_stop = 0; 

    /*!
     * @brief adds node to wait list if not checked also pushes to web
     * @param n_node 
     */
    void check_Node(const Node* n_node); 
    void check_neighbors(const Node* n_node);
    int pull_check_list();  

    public:
    NodeMap(); 

    /// @brief creates a node map and reserves the correct size 
    /// @param n_number number of node elements 
    void NodeMap_setup (int n_number);
    ~NodeMap (); 

    /*!
     * @brief sets a single node in the node array
     * @param id id of the node
     * @param type atom type of the node 
     */
    void SetNode (int id, int type, std::list<int> neigh_ids); 

    /*!
     * @brief creates neighborhoods and assigns them to the node_webs 
     * @param max_parm = 100 max number that the create will go 
     * @param max_on = whether to use max number or not 
     */
    void CreateNeighborhoods (); 

    /*!
     * @brief print out the molecules (used for debugging)
     */
    void print_connections(); 

    /*!
     * @brief must be called after the create molecules command 
     * @return returns a list of lists contiaing the nodes 
     */
    std::list<Node> PullMolecules(); 
};
