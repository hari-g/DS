//////////////////////////////////////////////////////////////
//Created by Hari Krishna (hgajarla at syr edu)
//Description: Implementation of Heap
//
//
///////////////////////////////////////////////////////////////

#include "Heap.h"

Heap::Heap(int MaxSize, bool type) {
    array = new long int[MaxSize];
    if(array == NULL) {
        std::cerr << "Error:Memory allocation!" << std::endl;
    }
    maxCapacity = MaxSize;
    IsMaxHeap    = type;
    size        = 0;
}

Heap::~Heap(){
   delete [] array;
   array = NULL;
}

void Heap::swapElements(int index1, int index2) {
    if(index1 < size && index2 < size) {
	return;
    }
    long int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

bool Heap::compElements(long int val1, long int val2) {
	if( IsMaxHeap == true) {
		return val1 > val2 ? true : false;
	} else {
		return val1 < val2 ? true : false;
	}
}

void Heap::trickleUp(int index) {
    long int curVal = array[index];
    int parent_index = (index-1)/2;
    
    if(parent_index >=0) {
        if(compElements(curVal,array[parent_index])) {
            array[index] = array[parent_index];
            array[parent_index] = curVal;
            trickleUp(parent_index);
        }
    }
}

int Heap::recfind(long int v, int index){
    int ret = -1;

    if(index < 0 || index >= size) {
	ret = -1;
    } else if (array[index] == v) {
        ret = index;
    } else if(compElements(array[index], v)) {
        int leftVal = -1, rightVal = -1;
        
	leftVal  = recfind(v, LEFT(index));
        rightVal = recfind(v, RIGHT(index));

	ret =  (leftVal > rightVal) ? leftVal:rightVal;
    }

    return ret ;
}

int Heap::findElement(long int v) {
    return recfind(v, 0);
}

long int Heap::getRoot(){
    return array[0];
}


void Heap::trickleDown(int index) {
    // if child does not exist just point to parent, since we donot swap
    // anyway if elements are equal
    int left  = LEFT(index)<size ? LEFT(index):index;
    int right = RIGHT(index)<size ? RIGHT(index):index;
    
    int reqIndex = (compElements(array[left],array[right])) ? left:right;
    int Val    = array[reqIndex];
    int cur    = array[index];
    
    if(compElements(Val,cur)) {
	swapElements(reqIndex, index);
        trickleDown(reqIndex);
    }
}

int Heap::Delete(long int v){
    int index = findElement(v);
    
    if(index == -1) {
        return -1;
    }
    array[index] = array[size-1];
    size--;
    trickleDown(index);
    return 0;
}

// return 0 if successfully added
//       -1 if Maximum capacity is reached 
int Heap::Add(long int v) {
    int insertPos = size;

    if(size < maxCapacity) {
        size++;
        array[insertPos] = v;
	trickleUp(insertPos);
        return 0;
    }
    return -1;
}

int main() {
    int no=0,type=0;
    std::cin >> no;
    Heap *heap = new Heap(100000, true);
    for(int i=0; i<no;i++) {
	    std::cin >> type;
        switch(type){
            case 1:
            {
                long int val=0;
		std::cin >> val;
                heap->Add(val);
                break;
            }
            case 2:
            {
                long int val  = 0;
		std::cin >> val;
                heap->Delete(val);
                break;
            }
            case 3:
            {
                int min = heap->getRoot();
		std::cout << min << std::endl;
                break;
            }
        }
    }
    return 0;
}
