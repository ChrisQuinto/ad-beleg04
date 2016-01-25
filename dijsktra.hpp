//Christian Paffrath, 114980, WS2015-2016
#ifndef DIJSKTRA
#define DIJSKTRA

#include <vector>
#include <set>
#include <cmath>
#include <iostream>

struct Edge
{
    Edge(int source,int destination, float weight) :
    src{source},
    dst{destination},
    weight{weight} {}

    int src;        //source
    int dst;        //destination
    float weight;   //weight
};

std::vector<float> dijsktra(
    std::vector<int> nodes, std::vector<Edge> edges, int start, int end
) {
    std::set<int> unvisited_nodes;
    std::vector<float> distances;
    std::vector<int> prev;

    for (std::vector<int>::iterator i = nodes.begin(); i != nodes.end(); ++i)
    {
        unvisited_nodes.insert(*i);
        distances.push_back(INFINITY);
    }

    distances[start] = 0;

    while (!unvisited_nodes.empty())
    {
        float shortest = INFINITY;
        int temp_node;

        for (int i = 0; i < distances.size(); i++)
        {
            if (distances[i] < shortest)
            {
                shortest = distances[i];
                temp_node = i;
            }
        }
        unvisited_nodes.erase(temp_node);

        // Information which node is neighbor is currently only available
        // inside the "edges" vector. We need to find neighbors of the current
        // "temp_node"

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].src == temp_node) {
                // At this point, we have a neighbor of temp_node
                // edges[i].dst
                float temp_dist = distances[temp_node] + edges[i].weight;
                if (temp_dist < distances[edges[i].dst])
                {
                    std::cout << "break04" << std::endl;
                    distances[edges[i].dst] = temp_dist;
                    prev[edges[i].dst] = temp_node;
                    std::cout << "break88" << std::endl;
                }
            }
        }

    }

    std::cout << "break03" << std::endl;
    for (int i = 0; i < prev.size(); i++)
    {
        std::cout << i+1 << ": " << prev[i] << "\n";
    }

    return distances;
}

#endif

