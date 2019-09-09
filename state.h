/**********************************************************
 *          State/Tree node class. Represents each
 *          node of the tree
 * 
 * ********************************************************/

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include "linalg.h"
#include "car.h"

using namespace std;

class State
{
public:
    State();
    State(v3d npos);
    ~State();

    v3d *getPos() { return &pos; };
    void setPos(v3d pos);

    int getGraphIndex() { return graphIndex; };
    void setGraphIndex(int index) { graphIndex = index; };

    vector<State *> getChildren() { return children; };
    void addChild(State &childState, double dist)
    {
        children.emplace_back(&childState);
        childState.parent = &(*this);
        childState.graphIndex = childState.parent->graphIndex + 1;
        childState.edgeCost = childState.parent->edgeCost + dist;
    };
    State *getParent() { return parent; };

    double getEdgeCost(){return edgeCost;};
    void setEdgeCost(double dist){this->edgeCost += dist;};

    void printChildren();
    void toString();

private:
    v3d pos;
    int graphIndex;
    State *parent;
    vector<State *> children;
    double edgeCost;
};