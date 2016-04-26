#include "correspondingutil.h"

template <class T>
CorrespondingUtil<T>::CorrespondingUtil()
{

}

template <class T>
void CorrespondingUtil<T>::corresponding_swap(T vec, std::size_t ipointer, std::size_t jpointer)
{
    for(auto value: vec) {
        auto temp  = *(value.first +ipointer);
        *(value.first+ipointer) = *(value.second-jpointer);
        *(value.second-jpointer) = temp;
    }
}

template <class T>
void CorrespondingUtil<T>::corresponding_sort(T vec)
{
    if(vec.empty() || vec.at(0).first >= vec.at(0).second)
        return;

    auto start = vec.at(0).first;
    auto end   = vec.at(0).second;
    size_t ipointer = 1, jpointer = 0;

    while(start+ipointer < end-jpointer) {
        while(start+ipointer <=end && *(start+ipointer) <= *start) {
            ++ipointer;
        }
        while(end-jpointer>=start && *(end-jpointer) > *start) {
            ++jpointer;
        }
        if(start+ipointer < end-jpointer) {
            corresponding_swap(vec,ipointer,jpointer);
            ++ipointer;
            ++jpointer;
        }
    }
    corresponding_swap(vec,0, jpointer);

    T vec1, vec2;
    for(auto v : vec) {
        vec1.push_back(std::make_pair(v.first,v.second-jpointer-1));
    }
    corresponding_sort(vec1);

    for(auto v : vec) {
        vec2.push_back(std::make_pair(v.second-jpointer+1,v.second));
    }
    corresponding_sort(vec2);
}



using itrvec = std::vector<std::pair<std::vector<int>::iterator, std::vector<int>::iterator>>;
template class CorrespondingUtil<itrvec>;

/*
int main() {
    std::vector<int> arr  = {3,5,4,1,9,7,8,6,2,0};
    std::vector<int> arr2 = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> arr3 = {0,1,2,3,4,5,6,7,8,9};
    using itrvec = std::vector<std::pair<std::vector<int>::iterator, std::vector<int>::iterator>>;
    itrvec vec = {{arr.begin(),arr.end()-1}, {arr2.begin(),arr2.end()-1}, {arr3.begin(), arr3.end()-1}};
    CorrespondingUtil<itrvec> ctl;

    ctl.corresponding_sort(vec);

    for(auto u : arr)
       std::cout << u << " ";
    std::cout << std::endl;
    for(auto u : arr2)
       std::cout << u << " ";
    std::cout <<std::endl;
    for(auto u : arr3)
       std::cout << u << " ";
}
*/

