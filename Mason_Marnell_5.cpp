/* Homework #5, Mason Marnell*/

//Fully functional DFS. Can find minimum path between two user inputted nodes using BFS

#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    vector<int>* adj; //second adj list

public:

    map<int, bool> visited;

    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int startVertex);
    bool BFSpath(int startVertex, int endVertex, int predecessors[]);
    void printMinPath(int startVertex, int distance);

};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    adj = new vector<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adj[src].push_back(dest); //second adj list used for minimum path search
    //if graph is a non-dir-graph, copy and flip both lines
}

bool Graph::BFSpath(int src, int desti, int pred[]){

    //queue for BFS
    list<int> queue;

    //array for visited nodes
    bool* visited = new bool[numVertices];

    // set all vertices and pred to default
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        pred[i] = -1;
    }


    visited[src] = true;
    queue.push_back(src);
    
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                //when destination found, stop
                if (adj[u][i] == desti)
                    return true;
            }
        }
    }

    return false;
}

void Graph::printMinPath(int src, int desti){

    int pred[18]; //wasn't sure how to get around this, just hard coded the number of vertices

    if (BFSpath(src, desti, pred) == false) {
        cout << "Given source and destination"
            << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = desti;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // prints path
    cout << endl << "Minimum path is: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        if (path[i] == 1) {
            cout << "A";
        }
        if (path[i] == 2) {
            cout << "B";
        }
        if (path[i] == 3) {
            cout << "C";
        }
        if (path[i] == 4) {
            cout << "D";
        }
        if (path[i] == 5) {
            cout << "E";
        }
        if (path[i] == 6) {
            cout << "F";
        }
        if (path[i] == 7) {
            cout << "G";
        }
        if (path[i] == 8) {
            cout << "H";
        }
        if (path[i] == 9) {
            cout << "I";
        }
        cout << " ";

    }
}

void Graph::DFS(int start){
    // set node as visited
    visited[start] = true;

    if (start == 1) {
        cout << "A";
    }
    if (start == 2) {
        cout << "B";
    }
    if (start == 3) {
        cout << "C";
    }
    if (start == 4) {
        cout << "D";
    }
    if (start == 5) {
        cout << "E";
    }
    if (start == 6) {
        cout << "F";
    }
    if (start == 7) {
        cout << "G";
    }
    if (start == 8) {
        cout << "H";
    }
    if (start == 9) {
        cout << "I";
    }
    cout << " ";

    //recursive way to search
    list<int>::iterator i;
    for (i = adjLists[start].begin(); i != adjLists[start].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}


int menuSwitch(int menuChoice) {

    Graph g(18); //creating the graph given
    g.addEdge(1, 2); //A
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5); //B
    g.addEdge(3, 2); //C
    g.addEdge(3, 7);
    g.addEdge(4, 3); //D
    g.addEdge(4, 7);
    g.addEdge(5, 3); //E
    g.addEdge(5, 6);
    g.addEdge(6, 3); //F
    g.addEdge(6, 8);
    g.addEdge(7, 6); //G
    g.addEdge(7, 8);
    g.addEdge(7, 9);
    g.addEdge(8, 5); //H
    g.addEdge(8, 9);
    g.addEdge(9, 6); //I

    string data;
    int dataint = 0;
    string data2;
    int data2int = 0;
    switch (menuChoice) {
    case 0: //Depth-First Search (stack)
        cout << "Enter Starting Node: ";
        cin >> data;

        //have to convert between letters and ints
        if (data == "A") {
            dataint = 1;
        }
        if (data == "B") {
            dataint = 2;
        }
        if (data == "C") {
            dataint = 3;
        }
        if (data == "D") {
            dataint = 4;
        }
        if (data == "E") {
            dataint = 5;
        }
        if (data == "F") {
            dataint = 6;
        }
        if (data == "G") {
            dataint = 7;
        }
        if (data == "H") {
            dataint = 8;
        }
        if (data == "I") {
            dataint = 9;
        }

        g.DFS(dataint);
        //call DFS with dataint
        break;
    case 1: //Minimum Path Search (queue) (BFS)
        cout << "Enter Starting Node: ";
        cin >> data;
        cout << endl << "Enter End Node: ";
        cin >> data2;
        
        //have to convert between letters and ints
        if (data == "A") {
            dataint = 1;
        }
        if (data == "B") {
            dataint = 2;
        }
        if (data == "C") {
            dataint = 3;
        }
        if (data == "D") {
            dataint = 4;
        }
        if (data == "E") {
            dataint = 5;
        }
        if (data == "F") {
            dataint = 6;
        }
        if (data == "G") {
            dataint = 7;
        }
        if (data == "H") {
            dataint = 8;
        }
        if (data == "I") {
            dataint = 9;
        }

        if (data2 == "A") {
            data2int = 1;
        }
        if (data2 == "B") {
            data2int = 2;
        }
        if (data2 == "C") {
            data2int = 3;
        }
        if (data2 == "D") {
            data2int = 4;
        }
        if (data2 == "E") {
            data2int = 5;
        }
        if (data2 == "F") {
            data2int = 6;
        }
        if (data2 == "G") {
            data2int = 7;
        }
        if (data2 == "H") {
            data2int = 8;
        }
        if (data2 == "I") {
            data2int = 9;
        }

        g.printMinPath(dataint, data2int);
        cout << endl;
        break;
    case 3:
        exit(0);
    default:
        cout << "Pick a valid number" << endl;
        break;
    }

    return 0;
}

int menu() { //displays the menu and returns the number chosen
    int choice;
    cout << endl;
    cout << "               M E N U" << endl << endl;
    cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    cout << "Exit Program (3)" << endl << endl << "Choose? ";
    cin >> choice;
    return choice;
}


int main() {

    while (true) { //loops indefinitely (until exit is called)
        menuSwitch(menu()); //menu() is passed in, passing an int to menuSwitch
    }

    return 0;
}


// thank you :)