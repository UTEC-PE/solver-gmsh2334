//
// Created by GMSH on 11/09/2018.
//

#ifndef SOLVER_GMSH2334_NODE_H
#define SOLVER_GMSH2334_NODE_H


template <typename T>
struct Node {
    T data;
    struct Node* right= nullptr;
    struct Node* left= nullptr;
};


#endif //SOLVER_GMSH2334_NODE_H
