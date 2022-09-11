#include <vector>
#include <unordered_map>

template<typename T>
std::vector<int> keys(std::unordered_map<int, T> map)
{
    std::vector<int> keys;
    for(auto item : map) keys.push_back(item.first);
    return keys;
}