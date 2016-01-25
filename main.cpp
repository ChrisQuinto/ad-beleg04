//Christian Paffrath, 114980, WS2015-2016

#include <iostream>
#include <vector>
#include "dijsktra.hpp"

int main(int argc, char *argv[])
{

    std::vector<Edge> edges;
    std::vector<int> nodes;

    edges.push_back(Edge{0,1,25.0f});   // 1 -> 2
    edges.push_back(Edge{0,2,15.0f});   // 1 -> 3
    edges.push_back(Edge{1,2,10.0f});   // 2 -> 3
    edges.push_back(Edge{1,3,15.0f});   // 2 -> 4
    edges.push_back(Edge{1,5,32.0f});   // 2 -> 6
    edges.push_back(Edge{2,1,80.0f});   // 3 -> 2
    edges.push_back(Edge{2,4,30.0f});   // 3 -> 5
    edges.push_back(Edge{3,4,20.0f});   // 4 -> 5
    edges.push_back(Edge{3,6,10.0f});   // 4 -> 7
    edges.push_back(Edge{4,3,70.0f});   // 5 -> 4
    edges.push_back(Edge{4,6,6.0f});    // 5 -> 7
    edges.push_back(Edge{5,6,30.0f});   // 6 -> 7
    edges.push_back(Edge{5,7,37.0f});   // 6 -> 8
    edges.push_back(Edge{6,8,7.0f});    // 7 -> 9
    edges.push_back(Edge{7,8,69.0f});   // 8 -> 9

    nodes.push_back(0);                 //1
    nodes.push_back(1);                 //2
    nodes.push_back(2);                 //3
    nodes.push_back(3);                 //4
    nodes.push_back(4);                 //5
    nodes.push_back(5);                 //6
    nodes.push_back(6);                 //7
    nodes.push_back(7);                 //8
    nodes.push_back(8);                 //9

    std::cout << "break00" << std::endl;
    std::vector<float> distances = dijsktra(nodes,edges,0,8);
    std::cout << "breakXX" << std::endl;

    for (int i = 0; i < distances.size(); i++)
    {
        std::cout << i+1 << ": " << distances[i] << "\n";
    }

    return 0;
}
