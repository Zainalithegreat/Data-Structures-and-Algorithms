//Graph.cpp
// Graph.cpp

#include "Data.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Graph::Graph() {
    adjacencyList = nullptr;
    size = 0;
}

Graph::Graph(char fileName[]) {
    adjacencyList = nullptr; // Initialize to null
    size = 0;

    int guests;
    char venue[MAXCHAR], date[MAXCHAR];
    ifstream inFile;
    Data BTS;

    inFile.open(fileName);

    if (!inFile.is_open()) {
        cout << "file did not open" << endl;
        exit(1);
    }

    while (inFile >> guests) {
        inFile.ignore(100, ';');
        inFile.getline(venue, MAXCHAR, ';');
        inFile.getline(date, MAXCHAR);

        BTS.setGuests(guests);
        BTS.setVenue(venue);
        BTS.setDate(date);
        Insert(BTS);
    }

    inFile.close();
}

Graph::~Graph() {
    Vertex* currentVertex = adjacencyList;
    while (currentVertex) {
        Edge* edge = currentVertex->edge;
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            delete temp;
        }
        Vertex* tempVertex = currentVertex;
        currentVertex = currentVertex->next;
        delete tempVertex;
    }
}

void Graph::Insert(Data& newData) {
    Vertex* newVertex = new Vertex;
    newVertex->task = newData;
    newVertex->next = nullptr;
    newVertex->edge = nullptr;

    if (!adjacencyList) {
        adjacencyList = newVertex;
    } else {
        Vertex* lastVertex = adjacencyList;
        while (lastVertex->next) {
            lastVertex = lastVertex->next;
        }
        lastVertex->next = newVertex;
    }

    size++;
}

void Graph::Insert(char venue[], char date[], int guests) {
    Data BTS;
    BTS.setVenue(venue);
    BTS.setDate(date);
    BTS.setGuests(guests);
    Insert(BTS);
}

void Graph::printList() {
    Vertex* currentVertex = adjacencyList;
    int i = 0;
    while (currentVertex) {
        cout << i + 1 << ". ";
        currentVertex->task.print();
        currentVertex = currentVertex->next;
        i++;
    }
}


