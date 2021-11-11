
#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
        int edgesList;
        int edgesMat;
        int nodes;
    vector<int> *adjList;
        int *adjMatrix;
        //vector<Type> *vect = new vector<Type>

public:
        Graph(int);
        Graph();
    
        void loadGraphMat(string, int, int);
        void loadGraphList(string, int, int);
    
        void addEdgeAdjMatrix(int, int);
        void addEdgeAdjList(int, int);
    
        string DFS(int,int);
        void depthHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&);
        string BFS(int,int);
        void breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&, stringstream&);
    
        string printAdjList();
        string printAdjMat();
        string printAdjMat_clean();
        void print_visited(list<int>, stringstream&);
        void print_path(vector <vector<int>>&,int,int,stringstream&);
    
        bool contains(list<int>, int);
        void sortAdjList();
};

Graph::Graph() {
    edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
    nodes = n;
    adjList = new vector<int>[nodes];
    adjMatrix = new int [nodes*nodes];
    for (int i = 0; i < nodes*nodes; i++)
        adjMatrix[i] = 0;
    edgesList = edgesMat = 0;
}

void Graph:: loadGraphList(string name, int a, int b){
    adjList = new vector<int>[a];
    nodes = a;
        string line;
        ifstream myfile(name);
        int u, v;
        if (myfile.is_open()){
        while (getline(myfile, line)){
            u = stoi(line.substr(1,1));
            v = stoi(line.substr(4,1));
            addEdgeAdjList(u,v);
        }
        myfile.close();
        } else {
            cout << "Unable to open file";
        }
}

void Graph::loadGraphMat(string name, int a, int b){
    adjMatrix = new int [a*b];
    nodes = a;
    for (int i = 0; i < a*b; i++)
        adjMatrix[i] = 0;
        string line;
        ifstream myfile(name);
        int u, v;
        if (myfile.is_open()){
            while (getline(myfile, line)){
                u = stoi(line.substr(1,1));
                v = stoi(line.substr(4,1));
                addEdgeAdjMatrix(u,v);
            }
            myfile.close();
        } else {
            cout << "Unable to open file";
        }
}


void Graph :: addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v){
    adjMatrix[u*nodes+v] = 1;
    adjMatrix[v*nodes+u] = 1;
    edgesMat++;
}

string Graph::printAdjList(){
      stringstream aux;
        for (int i = 0; i < nodes; i++){
            aux << "vertex "
                 << i << " :";
            for (int j = 0; j < adjList[i].size(); j ++){
                             aux << " " << adjList[i][j];
                    }
            aux << " ";
    }
        return aux.str();

}

string Graph::DFS(int start, int goal){
        stack <int> st;
        list <int> visited;
        stringstream aux;
        vector <vector<int>> paths(nodes, vector<int>(1, -1));
        st.push(start);
        depthHelper(start, goal, st, visited, paths,aux);
        print_path(paths, start, goal, aux);
        string result = aux.str();
        result.pop_back();
        return result;
}

void Graph::depthHelper(int c, int g, stack<int> &st, list<int> &visited, vector<vector<int>> &paths, stringstream &a){
    if(c == g){
        print_visited(visited, a);
    }
    else if (st.empty()){
        a<<" node not found";
    }
    else{
        c = st.top();
        st.pop();
        visited.push_back(c);
        for(int i = 0; i < adjList[c].size(); i++){
            if(!contains(visited, adjList[c][i])){
                st.push(adjList[c][i]);
                paths[adjList[c][i]][0] = c;
            }
        }
        depthHelper(c, g, st, visited, paths, a);
    }
}

string Graph::BFS(int start, int goal){
        queue <int> q;
        list <int> visited;
        stringstream aux;
        vector <vector<int>> paths(nodes, vector<int>(0));
        q.push(start);
        breadthHelper(start, goal, q, visited, paths,aux);
        print_path(paths, start, goal, aux);
        string result = aux.str();
        result.pop_back();
        return result;
}

void Graph::breadthHelper(int c, int g, queue<int> &q, list<int> &visited, vector<vector<int>> &paths, stringstream &a){
    if(c == g){
        print_visited(visited, a);
    }
    else if (q.empty()){
        a<<" node not found";
    }
    else{
        c = q.front();
        q.pop();
        visited.push_back(c);
        for(int i = 0; i < adjList[c].size(); i++){
            if(!contains(visited, adjList[c][i])){
                q.push(adjList[c][i]);
                paths[adjList[c][i]].push_back(c);
            }

        }
        breadthHelper(c, g, q, visited, paths, a);
    }
}

bool Graph::contains(list<int> ls, int node){
        list<int>::iterator it;
        it = find(ls.begin(), ls.end(), node);
        if(it != ls.end())
            return true;
        else
            return false;
}

void Graph::print_visited(list<int> v, stringstream &a){
    a << "visited: ";
    while (!v.empty()){
    a << v.front() << " ";
    v.pop_front();
  }
}

void Graph::print_path(vector<vector<int>> &p, int s, int g, stringstream &a){
    int node = p[g][0];
    stack<int> reverse;
    reverse.push(g);
    a<<"path: ";
    while(node != s){
        reverse.push(node);
        node = p[node][0];
    }
    reverse.push(s);
    while (!reverse.empty()) {
        a << reverse.top() << " ";
        reverse.pop();
    }
}

string Graph::printAdjMat(){
    stringstream aux;
    for (int i = 0; i < nodes; i++){
       for (int j = 0; j < nodes; j++){
             aux << adjMatrix[i*nodes+j] << " ";
         }
  }
    return aux.str();
}

string Graph::printAdjMat_clean(){
    stringstream aux;
    aux << "\n nodes \t|";
    for (int i = 0; i < nodes; i++){
            aux << "\t" << i ;
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++){
            aux << "__________";
    }
    aux << "\n";
    for (int i = 0; i < nodes; i++){
         aux << i << "\t|";
       for (int j = 0; j < nodes; j++){
             aux << "\t" << adjMatrix[i*nodes+j];
         }
       aux << "\n";
  }
    return aux.str();
}

#endif /* Graph_H_ */
