//Graph.h
#pragma once
#include <iostream>
#include "Data.h"

const int MAX = 50;
const int MAXCHAR = 101;

class Graph{
        public:
                Graph();
                Graph(char fileName[]);
                ~Graph();

                void Insert(Data &newData);
                void Insert(char venue[], char date[], int guests);

                void printList();
        private:

		struct Vertex;
                struct Edge {
                        Vertex* destination;
                        Edge* next;
                };

                struct Vertex {
                        Data task;
                        Vertex* next;
                        Edge* edge;
                };

                Vertex *adjacencyList;
                int size;
};

