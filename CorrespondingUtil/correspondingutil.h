#ifndef CORRESPONDINGUTIL_H
#define CORRESPONDINGUTIL_H

#include <iostream>
#include <utility>
#include <iterator>
#include <vector>

template<typename T>
class CorrespondingUtil
{
public:
    CorrespondingUtil();
    void corresponding_sort(T vec);
    void corresponding_swap(T vec, std::size_t ipointer, std::size_t jpointer);
};

#endif // CORRESPONDINGUTIL_H
