/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @author Ethan Thompson
 * @date 15 October 2020
 * @brief File which implements statistical operations on a dataset.
 *
 * Takes an array of unsigned char data items and returns the max, min, mean,
 * and median of the dataset.
 *
 * @see https://www.coursera.org/learn/introduction-embedded-systems
 */

 #include <stdio.h>
 #include "stats.h"

 // Define size of the dataset
 #define DATASET_SIZE 40

 int counter = 0;
 int main() {

 // Dataset from Alex Fosdick's sample implementation
    unsigned char test[DATASET_SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                         114,  88,  45,  76, 123,  87,  25,  23,
                                         200, 122, 150,  90,  92,  87, 177, 244,
                                         201,   6,  12,  60,   8,   2,   5,  67,
                                           7,  87, 250, 230,  99,   3, 100,  90};
    sort_array(test);
 }

 int find_maximum(unsigned char dataset[]) {
     // Since all values are guaranteed to be positive, initialize to zero.
     int cur_max = 0;
     for (int i = 0; i <= DATASET_SIZE; i++) {
        if (dataset[i] > cur_max) {
            cur_max = dataset[i];
        }
     }
     return cur_max;
 }

 int find_minimum(unsigned char dataset[]) {
    // Initialize to max integer value.
    int cur_min = 2147483627;
    int i;

    // Iterate through array keeping track of smallest value seen.
    for (i = 0; i <= DATASET_SIZE; i++) {
        if (dataset[i] < cur_min) {
            cur_min = dataset[i];
        }
     }
     return cur_min;
 }

 unsigned char partition_array(unsigned char dataset[], int left, int right) {

      int pivot = left;
      int i = left;
      int j = right;
      int temp;

      if (left < right) {
          while (i < j) {
                // Increment left pointer until a value larger than the pivot is found.
                while (dataset[i] <= dataset[pivot] && i < right) {
                    i++;
                }
                // Decrement right pointer until a value smaller than the pivot is found.
                while (dataset[j] > dataset[pivot]) {
                    j--;
                }
                // Swap values if the right pointer is still ahead of the left pointer.
                if (i < j) {
                    temp = dataset[i];
                    dataset[i] = dataset[j];
                    dataset[j] = temp;
                }
          }

        // Swap pivot value with middle partition value.
        temp = dataset[j];
        dataset[j] = dataset[pivot];
        dataset[pivot] = temp;

        // Arrange left partition.
        partition_array(dataset, left, j-1);

        // Arrange right partition.
        partition_array(dataset, j+1, right);
      }

}

 unsigned char sort_array(unsigned char dataset[]) {
    int left = 0;
    int right = DATASET_SIZE - 1;

    partition_array(dataset, left, right);

    return dataset;
 }

  int find_median(unsigned char dataset[]) {
     unsigned char sorted_dataset[DATASET_SIZE] = sort_array(dataset);
     int median_1;
     int median_2;

     if (DATASET_SIZE % 2) {
        median_1 = DATASET_SIZE / 2;
        median_2 = median_1 + 1;
     } else {
         median_1 = median_2 = DATASET_SIZE / 2 + 1;
     }

     return 0.5 * (sorted_dataset[median_1] + sorted_dataset[median_2]);

 }

 find_mean(unsigned char dataset[]) {
     unsigned char sorted_dataset[DATASET_SIZE] = sort_array(dataset);
     unsigned float weight = 1 / DATASET_SIZE;
     int mean, i;
     for (i = 0; i <= DATASET_SIZE; i++) {
        mean += weight * dataset[i];
     }
     return mean
 }
