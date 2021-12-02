#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    string name;
    list<string> nbrs;
    Node(string name){
        this->name = name;
    }
};
class Graph{
    public:
    unordered_map<string,Node*> m;
    Graph(vector<string> cities){
        for(auto city : cities){
            m[city]=new Node(city);
        }
    }
    void addEdge(string x, string y, bool undir=false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdjacencyList(){
        for(pair<string,Node*> cityPair : m){
            string city = cityPair.first;
            Node* node = cityPair.second;
            cout<<city<<"-->";
            for(string nbr:node->nbrs){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    vector<string> cities={"Delhi","London","Paris","New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");
    g.printAdjacencyList();
    return 0;
}