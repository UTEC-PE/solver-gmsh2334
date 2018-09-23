//
// Created by GMSH on 11/09/2018.
//

#ifndef SOLVER_GMSH2334_CASES_H
#define SOLVER_GMSH2334_CASES_H

#include <iostream>
#include "node.h"
#include <string>
#include <vector>
#include <regex>
#include <tuple>

using namespace std;

template <typename T>

class Tree {
private:
    Node<T> *head;

    tuple<int, T> pars(T str) {

        vector<pair<char, int>> vtr;
        pair<char, int> PR;

        int j = 0;

        for (auto f : str) {
            if ((f == '/') || (f == '*') || (f == '+') || (f == '-') || (f == '^')) {
                PR = make_pair(f, j);
                vtr.push_back(PR);
            }
            j++;
        }

        int num = vtr.size();
        bool cnt = true;
        T f1;
        int f2 = 0;

        for (int i = 0; i < num; i++) {
            auto fst = vtr[num - 1 - i];
            if ((fst.first == '+') || (fst.first == '-')) {
                cnt = false;
                f1 = fst.first;
                f2 = fst.second;
                break;
            }
        }
        if (cnt) {
            for (int i = 0; i < num; i++) {
                auto fst = vtr[num - 1 - i];
                if ((fst.first == '*') || (fst.first == '/')) {
                    cnt = false;
                    f1 = fst.first;
                    f2 = fst.second;
                    break;
                }
            }
        }
        if (cnt) {
            for (int i = 0; i < num; i++) {
                auto fst = vtr[num - 1 - i];
                if (fst.first == '^') {
                    f1 = fst.first;
                    f2 = fst.second;
                    break;
                }
            }
        }

        return {f2, f1};
    };


public:
    Tree() {
        head = nullptr;
    };

    explicit Tree(T str) {
        auto[position, value]= pars(str);
        auto *n = new Node<T>();
        n->data = value;
        head = n;
        string right, left;
        int size = str.size();
        right = str.substr(position + 1, size - position - 1);
        left = str.substr(0, position);

        create_node(left, true, head);
        create_node(right, false, head);
    }

    void create_node(T str, bool path, Node<T> *current) {

        if (str.size() == 1) {
            auto *n = new Node<T>();
            n->data = str;
            if (path) {
                current->left = n;
            } else {
                current->right = n;
            }

        } else {
            auto[position, value]= pars(str);

            create_node(value, path, current);
            if (path) { current = current->left; } else { current = current->right; }
            string right, left;
            int size = str.size();
            right = str.substr(position + 1, size - position - 1);
            left = str.substr(0, position);

            create_node(left, true, current);
            create_node(right, false, current);
        }


    }
    bool is_op(T fact){
        return (fact == "/") || (fact == "*") || (fact == "+") || (fact == "-") || (fact == "^");
    };


    float operate(Node<T>* left, Node<T>* middle, Node<T>* right){
        float L, R;
        if(is_op(left->data)){L= operate(left->left, left, left->right);} else{L= stof(left->data);}
        if(is_op(right->data)){R= operate(right->left, right, right->right);} else{R= stof(right->data);}

        if(middle->data== "+"){
            return L+R;
        }
        if(middle->data== "-"){
            return L-R;
        }
        if(middle->data== "/"){
            return L/R;
        }
        if(middle->data== "*"){
            return L*R;
        }
        if(middle->data== "^"){
            return pow(L,R);
        }
        return 0;

    };



    float start(){

        return operate(head->left, head, head->right);

    };




};

//~List();


#endif //SOLVER_GMSH2334_CASES_H
