#include "laundryday.h"
#include <string>
#include <vector>
#include <iostream>

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <map>
#include <vector>

bool compare (const std::pair<std::string, int> & lhs, const std::pair<std::string, int> & rhs)
{
    int pos1 = lhs.first.find("sock");
    int pos2 = rhs.first.find("sock");
    if (pos1 != std::string::npos && pos2 != std::string::npos)
    {
        if (lhs.first < rhs.first)
            return true;
        else if (lhs.second > rhs.second)
            return true;
        else
            return false;
    }
    else
    {
        return lhs.first < rhs.first;
    }
     
}

void LaundryDay::Run()
{
    std::vector<std::string> v = {"white shirt",
                                  "polka dot sock",
                                  "red sock",
                                  "superhero shirt",
                                  "torn jeans",
                                  "polka dot sock",
                                  "white shirt",
                                  "polka dot sock", "a sock"};
    std::map<std::string, int> map;
    
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        auto findit = map.find(*it);
        if (findit == map.end())
        {
            map[*it] = 0;
        }
        map[*it] += 1;
    }
    
    std::vector<std::pair<std::string, int> > vectorPair;
    for (auto it = map.begin(); it != map.end(); ++it)
        vectorPair.push_back(*it);
    
    std::sort(vectorPair.begin(), vectorPair.end(), compare);
    
//    for (auto it = vectorPair.begin(); it != vectorPair.end(); ++it)
//    {
//        std::cout << it->second << "|" << it->first << std::endl;
//    }
        
    
    for (auto it = vectorPair.begin(); it != vectorPair.end(); ++it)
    {
        auto findit = it->first.find("sock");
        if (findit != std::string::npos)
        {
            int start = it->second;
            if (start % 2 == 1)
                start--;
            if (start == 0)
                start = 1;
            
            for (int i = start - 1; i >= 0; --i)
            {
                std::cout << i << "|" << it->first << std::endl;
            }
        }
        else
        {
            std::cout << it->second << "|" << it->first << std::endl;
        }
    }
}