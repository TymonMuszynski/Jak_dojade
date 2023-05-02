//
// Created by Tymon Muszynski on 29/04/2023.
//

#include "BFS.h"


//row -> y
//column -> x

BFS::BFS(int width, int height, char **map, int numberOfCities){
    rowNumber = height;
    columnNumber = width;
    this->map = map;

   // this->mapVisited = mapVisited;
//    rowQueue = new BFSqueue();
//    columnQueue = new BFSqueue();
//    moveCounter = 0;
//    nodesLeftInLayer = 1;
//    nodesInNextLayer = 0;


    //reachedEnd = false;
    vectorRow[0] = -1;
    vectorRow[1] = 1;
    vectorRow[2] = 0;
    vectorRow[3] = 0;
    vectorColumn[0] = 0;
    vectorColumn[1] = 0;
    vectorColumn[2] = 1;
    vectorColumn[3] = -1;
    hashTable = new HashTable(numberOfCities);
}

void BFS::findOptimalPath( int rootX, int rootY,  bool **mapVisitedProp) {
    //setup
    moveCounter = 0;
    nodesLeftInLayer = 1;
    nodesInNextLayer = 0;
    rowQueue = new BFSqueue();
    columnQueue = new BFSqueue();
    this->mapVisited = mapVisitedProp;

    rowQueue->endPush(rootY);
    columnQueue->endPush(rootX);
    getRootCity(rootX, rootY);
    mapVisited[rootY][rootX] = true;
    while(rowQueue->countNodes() > 0 && columnQueue->countNodes() >0 )
    {
        rowCor = rowQueue->frontDelete();
        columnCor = columnQueue->frontDelete();
        if(rowCor != -1 && columnCor != -1){
            if (map[rowCor][columnCor] == '*' && !(rowCor == rootY && columnCor == rootX)) {
             //   cout << "Znaleziono * " << moveCounter << endl;
                getCityName();
                nodesLeftInLayer -= 1;
                if(nodesLeftInLayer == 0){
                    nodesLeftInLayer = nodesInNextLayer;
                    nodesInNextLayer = 0;
                    moveCounter += 1;
                }
                continue;
            }
        }
        else {
            break;
        }
        checkNeighbours();
        nodesLeftInLayer -= 1;
        if(nodesLeftInLayer == 0){
            nodesLeftInLayer = nodesInNextLayer;
            nodesInNextLayer = 0;
            moveCounter += 1;
        }
    }
    //hashTable->showHashTable();
    delete rowQueue;
    delete columnQueue;
}

bool BFS::checkEdgeRow(int y) {
    if (y < 0) {
        return true;
    } else if (y > rowNumber - 1) {
        return true;
    }
    return false;
}

bool BFS::checkEdgeColumn(int x){
    if (x < 0) {
        return true;
    } else if (x > columnNumber - 1) {
        return true;
    }
    return false;
}

void BFS::getRootCity(int x, int y){
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) {
                continue;
            }
            int new_y = y + dy;
            int new_x = x + dx;
            if(checkEdgeColumn(new_x) || checkEdgeRow(new_y) ){
                continue;
            }
            if(map[new_y][new_x] != '.' && map[new_y][new_x] != '#' && map[new_y][new_x] != '*'){
                int left_x = new_x - 1;
                int right_x = new_x + 1;
                if(checkEdgeColumn(right_x) || map[new_y][right_x] == '.' || map[new_y][right_x] == '#' || map[new_y][right_x] == '*'){
                   // cout << "Ostatnia litera: "<<map[new_y][new_x]<< endl;
                    String *city = new String(" ");
                    char tmp = map[new_y][new_x];
                    int leftIterator = new_x ;
                    while(tmp != '.' && tmp != '#' && tmp != '*'){
                        city->addChar(tmp);
                        leftIterator--;
                        if(checkEdgeColumn(leftIterator)) {
                            break;
                        }
                        tmp = map[new_y][leftIterator];
                    }
                    city->reverseString();
                    city->removeSpaces();
                   // cout<<"Miasto: "<<city->c_str()<<endl;
                    hashTable->addRootCity(city);
                    continue;
                }
                if(checkEdgeColumn(left_x) || map[new_y][left_x] == '.' || map[new_y][left_x] == '#' || map[new_y][left_x] == '*'){
                   // cout << "Pierwsza litera: "<<map[new_y][new_x]<< endl;
                    String *city = new String(" ");
                    char tmp = map[new_y][new_x];
                    int leftIterator = new_x ;
                    while(tmp != '.' && tmp != '#' && tmp != '*'){
                        city->addChar(tmp);
                        leftIterator++;
                        if(checkEdgeColumn(leftIterator)) {
                            break;
                        }
                        tmp = map[new_y][leftIterator];
                    }
                  //  cout<<"Miasto: "<<city->c_str()<<endl;
                    city->removeSpaces();
                    hashTable->addRootCity(city);
                    continue;
                }
            }
        }
    }
}

void BFS::getCityName() {
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) {
                continue;
            }
            int new_y = rowCor + dy;
            int new_x = columnCor + dx;
            if(checkEdgeColumn(new_x) || checkEdgeRow(new_y) ){
                continue;
            }
            if(map[new_y][new_x] != '.' && map[new_y][new_x] != '#' && map[new_y][new_x] != '*'){
                int left_x = new_x - 1;
                int right_x = new_x + 1;
                if(checkEdgeColumn(right_x) || map[new_y][right_x] == '.' || map[new_y][right_x] == '#' || map[new_y][right_x] == '*'){
                   // cout << "Ostatnia litera: "<<map[new_y][new_x]<< endl;
                    String *city = new String(" ");
                    char tmp = map[new_y][new_x];
                    int leftIterator = new_x ;
                    while(tmp != '.' && tmp != '#' && tmp != '*'){
                        city->addChar(tmp);
                        leftIterator--;
                        if(checkEdgeColumn(leftIterator)) {
                            break;
                        }
                        tmp = map[new_y][leftIterator];
                    }
                    city->reverseString();
                    //cout<<"Miasto: "<<city->c_str()<<endl;
                    city->removeSpaces();
                    hashTable->addNeighbourCity(city, moveCounter);
                    continue;
                }
                if(checkEdgeColumn(left_x) || map[new_y][left_x] == '.' || map[new_y][left_x] == '#' || map[new_y][left_x] == '*'){
                   // cout << "Pierwsza litera: "<<map[new_y][new_x]<< endl;
                    String *city = new String(" ");
                    char tmp = map[new_y][new_x];
                    int leftIterator = new_x ;
                    while(tmp != '.' && tmp != '#' && tmp != '*'){
                        city->addChar(tmp);
                        leftIterator++;
                        if(checkEdgeColumn(leftIterator)) {
                            break;
                        }
                        tmp = map[new_y][leftIterator];
                    }
                    //cout<<"Miasto: "<<city->c_str()<<endl;
                    city->removeSpaces();
                    hashTable->addNeighbourCity(city, moveCounter);
                    continue;
                }
            }
        }
    }
}

void BFS::checkNeighbours(){
    int checkCoordinatesRow = 0;
    int checkCoordinatesColumn =0;
    for(int i=0; i<4; i++) {
        checkCoordinatesRow = rowCor + vectorRow[i];
        checkCoordinatesColumn = columnCor + vectorColumn[i];

        if (checkCoordinatesRow < 0 || checkCoordinatesColumn < 0) {
            continue;
        }
        if (checkCoordinatesRow >= rowNumber || checkCoordinatesColumn >= columnNumber) {
            continue;
        }
        if(mapVisited[checkCoordinatesRow][checkCoordinatesColumn]){
            continue;
        }
        if(map[checkCoordinatesRow][checkCoordinatesColumn] != '#' && map[checkCoordinatesRow][checkCoordinatesColumn] != '*'){
            continue;
        }
        rowQueue->endPush(checkCoordinatesRow);
        columnQueue->endPush(checkCoordinatesColumn);
        mapVisited[checkCoordinatesRow][checkCoordinatesColumn] = true;
        nodesInNextLayer++;
    }


}

HashTable *BFS::getHashTable() {
    return hashTable;
}