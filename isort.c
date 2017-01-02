#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "isort.h"
#include "printa.h"

/*
  All functions take a pointer to an array of integers,
  as well as the starting and ending indeces of the portion
  to sort

  Each function has a brief description of the algorithm
  and gives the average time-complexity and worst case
  space-complexity
*/

void selection_sort(int array[], int p, int r) {
    /*
      Linear search at each index, find the min, and
      replace with number at that index
      T = O(n^s)
      S = O(1)
    */
    int i, j, min, tmp;
    for (i = p; i < r; i++) {
        min = i;
        for (j = i; j <= r; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

void insertion_sort(int array[], int p, int r) {
    /*
      Takes number at index i, compares to i-i...0 and inserts
      where appropriate. Better than selection sort in best case
      (already sorted) scenario
      T = O(n^2)
      S = O(1)
    */
    int k, tmp;
    for (int i=p; i <= r; i++) {
        k = i;
        while (k > p && array[k - 1] > array[k]) {
            tmp = array[k];
            array[k] = array[k - 1];
            array[k - 1] = tmp;
            k--;
        }
    }
}

void merge_sort(int array[], int p, int r) {
    /*
      Splits array in halves recursively until only single-member
      arrays are left, then merges everything while sorting it
      T = O(n*log n)
      S = O(n)
    */
    int diff = r - p, k;
    if (diff > 0) {
        int *left, *right;
        size_t leftbytes, rightbytes, leftlength, rightlength;

        k = diff / 2;
        merge_sort(array, p, k);
        merge_sort(array, k + 1, r);

        leftlength = k - p + 1;
        rightlength = r - k + 2;
        leftbytes = leftlength * sizeof(int);
        rightbytes = rightlength * sizeof(int);
        left = malloc(leftbytes);
        right = malloc(rightbytes);
        memcpy(left, array, leftbytes);
        memcpy(right, array + k, rightbytes);
        printf("Merging: ");
        printa(left, leftlength);
        printf(" and ");
        printa(right, rightlength);
        merge(left, leftlength, right, rightlength, array, p);

        free(left);
        free(right);
    }
}

void merge(int left[], size_t lsize, int right[], size_t rsize, int array[], int p) {
    int i = 0, j = 0, k = p;
    while (k < (p + lsize + rsize)) {
        if (i < lsize && j < rsize) {
            // we haven't reached the end of either array, so compare
            if (left[i] > right[j]) {
                array[k] = right[j];
                j++;
            } 
            else {
                array[k] = left[i];
                i++;
            }
        }
        else if (i < lsize) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
        }
        k++;
    }
}

void quicksort(int array[], int p, int r) {
    /*
      Partition the array, recursively, around a randomly chosen pivot index
      by moving number less than below and numbers greater than high.
      Better best case than mergesort, while keeping same average. Worst case is
      worse than merge sort worst case, however is very unlikely
    */
}
