//////////////////////////////////////////////////////////////
//Created by Hari Krishna (hgajarla at syr edu)
//Description: Implementation of Min Heap
//
//Creating a Heap, it takes Maximum capacity as parameter
//Usage : Heap *heap = new Heap(100);
//
//Functions:
//	Add(long int v) -> Adds elements to the heap
//	return value: 0 on successful addition
//		     -1 if max capacity of heap reached
//	
//	Delete(long int v) -> if element exits it Deletes the 
//				element in the heap
//	retun Value: 0 is returned if element is returned
//		    -1 is returned if element is not present
//
//	getMinimum() -> Returns the minimum value from the heap
//		It does not return error code, So this should be 
//		called only on non-empty heap 
//      usage: if(heap->getSize() > 0) { cout >> heap->getMinimum(); }
//
//	getSize() -> Returns current size of the heap	
//	
///////////////////////////////////////////////////////////////

#ifndef __HEAP_H_
#define __HEAP_H_

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define LEFT(i)  (2*i+1)
#define RIGHT(i) (2*i+2)

class Heap {
private:
   long int *array;
   int maxCapacity;
   int size;
   bool IsMaxHeap;
   void trickleUp(int index);
   void trickleDown(int index);
   int findElement(long int v);
   int recfind(long int v, int index);
   void swapElements(int index1, int index2);
   bool compElements(long int val1, long int val2);
public:
   Heap(int MaxSize, bool IsMaxHeap = false);
   ~Heap();
   int Add(long int v);
   int Delete(long int v);
   long int getRoot();
   int getSize();
};

#endif  
