#include "NodeMap.hpp"

void NodeMap::check_Node(const Node* n_node) 
{ 
        //check if the node id is 1 in the check_list

        if (check_list[n_node->id]) 
        { 
            return;     
        }
        wait_list.push_back(n_node); //add node to wait list
        connect_nodes.back().push_back(n_node); //add node to the node web 
        check_list[n_node->id] = true; 

}

void NodeMap::check_neighbors(const Node* n_node) 
{ 
    for (const Node* neighs : n_node->neighbors) 
    { 
        check_Node(neighs); 
    }
}

int NodeMap::pull_check_list() 
{ 
    //returns 0 if there are no more atoms 
    
    for (int i = last_stop ;i < check_list.size(); i++) 
    { 
        if(check_list[i] == false) 
        { 
            last_stop = i; 
            return i; 
        }
    }
    return 0; 

}

NodeMap::NodeMap() {} 

void NodeMap::NodeMap_setup(int n_number)
{ 
    Node Base; 
    nodes.reserve(n_number + 1); //the 0 position will be the the null node 
    for (int i= 0; i < nodes.capacity(); i++)
    { 
        nodes.push_back(Base); 
    }
    for (int i= 0; i < n_number + 1; i++) 
    { 
        check_list.push_back(false); 
    }
    check_list[0] = true; //the value at 0 must be set to true because no ids are 0
}

NodeMap::~NodeMap() 
{

} 

void NodeMap::SetNode(int id, int type, std::list<int> neigh_ids)
{ 
    nodes[id].set_Node(id,type); 
    std::list<Node*> n_list; 
    for (int i_ids : neigh_ids) 
    { 
        n_list.push_back(&nodes[i_ids]); 
    }
    nodes[id].set_neighbors(n_list); 
}

void NodeMap::CreateNeighborhoods() 
{ 
    //find a new node 
    int next_pick = pull_check_list(); 
    while (next_pick != 0) 
    { 
        //create a new molecule list and search for the first nodes neighbors 
        connect_nodes.push_back(std::list<const Node*>{}); 
        check_Node(&nodes[next_pick]);
        check_neighbors(&nodes[next_pick]); 

        //if more neighbors exist keep checking 
        while (!wait_list.empty())
        { 
            check_neighbors(wait_list.front()); 
            wait_list.pop_front();  
        }
        
        //find if there are more nodes to check
        next_pick = pull_check_list(); 
    }

}

void NodeMap::print_connections() 
{ 
    for (std::list<const Node*> l : connect_nodes) 
    { 
        std::cout << "Here is a molecule : " << std::endl; 
        for (const Node* v : l ) 
        { 
            std::cout << " " << v->id; 
        }
        std::cout << std::endl; 
    }
}

std::list<Node> NodeMap::PullMolecules() 
{ 
    std::list<Node> current_mol; 
    int counter = 0; 
    
    for (std::list<const Node*> i : connect_nodes)
    { 
        //check to see if its the right node 
        if (counter == iterator)
        {  
            for (const Node* v : i) 
            { 
                current_mol.push_back(*v); 
            }
            iterator += 1; 
            return current_mol; 
        }
        else
        { 
            counter += 1; 
        }
    }

    //if no more nodes than return empty 
    return std::list<Node>(); 
    
}