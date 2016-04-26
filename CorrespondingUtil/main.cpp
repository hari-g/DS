#include "correspondingutil.h"

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
