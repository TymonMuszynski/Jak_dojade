//
// Created by Tymon Muszynski on 29/04/2023.
//

#pragma once
#include "BFSqueue.h"
#include "String.h"
#include "HashTable.h"
#include <iostream>
using namespace std;

class BFS {
private:
    int rowCor;
    int columnCor;
    BFSqueue *rowQueue;
    BFSqueue *columnQueue;
    int rowNumber;
    int columnNumber;
    char **map;
    bool **mapVisited;
    int moveCounter;
    int nodesLeftInLayer;
    int nodesInNextLayer;
    int vectorRow[4];
    int vectorColumn[4];
    HashTable *hashTable;
public:
    BFS(int width, int height, char **map, int numberOfCities);
    ~BFS();
    void findOptimalPath(int rootX, int rootY, bool **mapVisitedProp);
    void checkNeighbours();
    void getCityName();
    void getRootCity(int x, int y);
    bool checkEdgeRow(int x);
    bool checkEdgeColumn(int y);
    HashTable *getHashTable();
};


