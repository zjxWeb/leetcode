#include<iostream>
#include <string>
#include <vector>


using namespace std;

string coolest(istream& input){
    BasicGraph graph;
    string nume1,nume2;
    // read file into graph
    while(input >> nume1 >> nume2){
        graph.addVertex(name1);
        graph.addVertex(nume2);
        graph.addEdge(nume1,nume2);
    }
    // learn who has most F-o-F
    int maxFof = 0;
    string coolName = "";
    for(Vertex* v : graph.getVertexSet()){
        // count fof of this vertex v
        Set<string> fofs;
        for(Vertex* neighbor : graph.getNeighbors(v)){
            for(Vertex* fof : graph.getNeighbors(neighbor)){
                fofs.add(fof->getName());
            }
        }
        cout << v-> name << " fofs " << fofs << endl;
        if(fofs.size() > maxFof){
            maxFof = fofs.size();
            coolName = v->getName();
        }
    }
    cout << graph << endl;
    return "?";
}

string 
int main(){
    cout << bool(~(-2)) << endl;
}