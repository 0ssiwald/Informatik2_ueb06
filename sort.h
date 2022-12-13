/*******************************************
* includes functions for the quick sort algorithm
********************************************/
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


/****************************************
* void QSort(sPlayer *, int, int (*)(sPlayer*, sPlayer*))
* Applies Quick Sort algorithm to sort Players by a selected sort function (3. parameter)
* Parameters: 1. Pointer start of sPlayer array
              2. Number of elements in the array
              3. Pointer  to the selected sort function
****************************************/
void QSort(sPlayer *, int, int (*)(sPlayer*, sPlayer*));


#endif // SORT_H_INCLUDED
