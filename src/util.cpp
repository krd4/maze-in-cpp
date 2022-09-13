#pragma once
#include <vector>
#include <utility>
#include <unordered_map>
#include <cstdlib>

template<typename T>
std::vector<int> keys(std::unordered_map<int, T> map)
{
    std::vector<int> keys;
    for(auto item : map) keys.push_back(item.first);
    return keys;
}

template<typename T>
std::vector<std::vector<T>> init_2d_vec(int row, int col, T item) {
    return std::vector<std::vector<T>> (row, std::vector<T> (col) );
}

template<typename T>
std::pair<int, int> size_2d_vec(std::vector<std::vector<T>> vec) {
    return std::pair<int, int>(vec.size(), vec[0].size());
}

int randint(int lower, int upper) {
    int n = std::rand();
    return (n - lower) % upper;
}