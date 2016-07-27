//Problem        : Finals Spring 2015 - Golf Course
//Language       : C++14
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector>

typedef std::vector<std::vector<int> > Map;

class Point
{
public:
    Point(int xx, int yy) : x(xx), y(yy) {}
    int x;
    int y;
};

int num_paths = 0;

void Traverse(const Map & m, const int node, int iteration)
{
    if (iteration == 4)
    {
        if (node == 9)
            ++num_paths;
        return;
    }
    else
    {
        for (auto it = m[node].begin(); it != m[node].end(); ++it)
        {
            Traverse(m, *it, iteration + 1);
        }
    }
        
}

int main() 
{
    Map map(10);
    map[0].push_back(4);
    map[0].push_back(6);
    map[1].push_back(6);
    map[1].push_back(8);
    map[2].push_back(7);
    map[2].push_back(9);
    map[3].push_back(4);
    map[3].push_back(8);
    map[4].push_back(9);
    map[4].push_back(3);
    map[4].push_back(0);
    //map[5].push_back()
    map[6].push_back(0);
    map[6].push_back(1);
    map[6].push_back(7);
    map[7].push_back(2);
    map[7].push_back(6);
    map[8].push_back(1);
    map[8].push_back(3);
    map[9].push_back(2);
    map[9].push_back(4);
    
//    for (unsigned int i = 0; i < map.size(); ++i)
//    {
//        Traverse(map, i, 0);
//    }
    
    Traverse(map, 2, 0);
    
    std::cout << "Number of Paths: " << num_paths << std::endl;
    
    return 0;
}
