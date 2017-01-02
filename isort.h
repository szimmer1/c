#ifndef ISORT_H
#define ISORT_H

void insertion_sort(int *array, int p, int r);
void selection_sort(int *array, int p, int r);
void merge_sort(int *array, int p, int r);
void merge(int *left, size_t lsize, int *right, size_t rsize, int *array, int p);
void quick_sort(int *array, int p, int r);
void bubble_sort(int *array, int p, int r);
void bucket_sort(int *array, int p, int r);

#endif
