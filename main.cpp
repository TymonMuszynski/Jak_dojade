#include <iostream>
using namespace std;
#include "String.h"
#include "mapArrey2D.h"
#include "BFS.h"
#include "Dijkstra.h"
//#include "HashTable.h"
#include <chrono>
using namespace chrono;


int main()
{
    int x = 0, y= 0, nuberOfFlights = 0, flightTime = 0;
    cin>>x>>y;
    getchar();
    mapArrey2D *mapClass = new mapArrey2D(x,y);

    // start point time tracking
    auto start = high_resolution_clock::now();

    BFS *bfsClass = new BFS(x, y, mapClass->getPtrChar(), mapClass->getNumberOfCities());
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
             if(mapClass->getPtrChar()[i][j] == '*'){
                 bfsClass->findOptimalPath(j,i, mapClass->getPtrBool());
                 mapClass->resetBoolArr();
           }
        }
    }

    // time tracking end point
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    double durationSeconds = static_cast<double>(duration.count()) / 1000000.0;
    cout << "Time taken by function: " << durationSeconds << " seconds" << endl;

    Dijkstra *dijkstraClass = new Dijkstra(bfsClass->getHashTable(), mapClass->getNumberOfCities(), new String("SOP"), new String("B"));
    dijkstraClass->showPQ();
//    cin>>nuberOfFlights;
//    for(int i=0; i<nuberOfFlights; i++){
//        flightTime = 0;
//        String *cityDeparture = new String();
//        String *cityArrival = new String();
//    }

}

