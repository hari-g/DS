//////////////////////////////////////////////////////////////
//Created by Hari Krishna (hgajarla at syr edu)
//Description: Implementation of Heap
//
//
///////////////////////////////////////////////////////////////

#include "Heap.h"

Heap::Heap(int MaxSize) {
    array = (long int *) malloc(sizeof(long int)*MaxSize);
    if(array == NULL) {
        std::cerr << "Error:Memory allocation!" << std::endl;
    }
    maxCapacity = MaxSize;
    heapType = "MinHeap";
    size     = 0;
}

Heap::~Heap(){
   delete(array);
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

void Heap::trickleUp(int index) {
    long int val = array[index];
    int parent_index = (index-1)/2;
    if(parent_index >=0) {
        if(val<array[parent_index]) {
            array[index] = array[parent_index];
            array[parent_index] = val;
            trickleUp(parent_index);
        }
    }
}

int Heap::recfind(long int v, int index){
    if(array[index] == v){
        return index;
    }
    
    if(array[index] < v) {
        int left = 2*index+1, right = 2*index+2;
        int leftVal, rightVal;
        if(left < size && right < size) {
            leftVal = recfind(v,left);
            rightVal = recfind(v,right);
            return leftVal>rightVal? leftVal:rightVal;
        } else if(left < size) {
            leftVal = recfind(v,left);
            return leftVal;
        } else if(right < size){
            rightVal = recfind(v,right);
            return rightVal;
        }
        
    }
    return 0;
}

int Heap::findElement(long int v) {
    return recfind(v, 0);
}

long int Heap::getMinimum(){
    return array[0];
}


void Heap::trickleDown(int index) {
    // if child does not exist just point to parent, since we donot swap
    // anyway if elements are equal
    int left  = LEFT(index)<size ? LEFT(index):index;
    int right = RIGHT(index)<size ? RIGHT(index):index;
    int minIndex = (array[left]<array[right]) ? left:right;
    int minVal = array[minIndex];
    int cur    = array[index];
    
    if(minVal < cur) {
	swapElements(minIndex, index);
        trickleDown(minIndex);
    }
}

int Heap::Delete(long int v){
    int index = findElement(v);
    if(array[index] != v) {
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
    if(size<=maxCapacity){
        array[size]=v;
        trickleUp(size);
        size++;
        return 0;
    }
    return -1;
}

/* Unit Test
int main() {
    int no=0,type=0;
    std::cin >> no;
    Heap *heap = new Heap(100000);
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
                int min = heap->getMinimum();
		std::cout << min << std::endl;
                break;
            }
        }
    }
    return 0;
}
*/
