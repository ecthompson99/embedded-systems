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
 #include <math.h>
 #include "stats.h"

 // Define size of the dataset
 #define DATASET_SIZE 40

 int mean, median, min, max;

 int main() {

 // Dataset from Alex Fosdick's sample implementation
    unsigned char dataset[DATASET_SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                           114,  88,  45,  76, 123,  87,  25,  23,
                                           200, 122, 150,  90,  92,  87, 177, 244,
                                           201,   6,  12,  60,   8,   2,   5,  67,
                                             7,  87, 250, 230,  99,   3, 100,  90};
    print_statistics(dataset);
 }

 int find_maximum(unsigned char dataset[]) {
     // Since all values are guaranteed to be positive, initialize to zero.
     max = 0;
     for (int i = 0; i <= DATASET_SIZE; i++) {
        if (dataset[i] > max) {
            max = dataset[i];
        }
     }
     return max;
 }

 int find_minimum(unsigned char dataset[]) {
    // Initialize to max integer value.
    min = 2147483627;
    int i;

    // Iterate through array keeping track of smallest value seen.
    for (i = 0; i <= DATASET_SIZE; i++) {
        if (dataset[i] < min) {
            min = dataset[i];
        }
     }
     return min;
 }

 unsigned char partition_array(unsigned char* dataset, int left, int right) {
      // Implements in-place quicksort algorithm
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

 void sort_array(unsigned char* dataset) {
    int left = 0;
    int right = DATASET_SIZE - 1;

    partition_array(dataset, left, right);
 }

void find_median(unsigned char* dataset) {
    sort_array(dataset);
    int median_1;
    int median_2;

    if (DATASET_SIZE % 2 == 0) {
        // If the set has an even number of values, there will be two middle values.
        median_1 = DATASET_SIZE / 2 - 1;
        median_2 = median_1 + 1;
        // Take the average of the two middle values.
        median = 0.5 * (dataset[median_1] + dataset[median_2]);
    } else {
        // If the set has an odd number of values, take the middle value.
        median = (DATASET_SIZE - 1) / 2 ;
    }
}

void find_mean(unsigned char* dataset) {
     sort_array(dataset);
     int i;
     int sum = 0;
     // Sum all values in the dataset, and divide by the length of the dataset.
     for (i = 0; i < DATASET_SIZE; i++) {
        sum += dataset[i];
     }
     mean = sum / DATASET_SIZE;
}

void print_array(unsigned char* dataset) {
    int i;
    for (i = 0; i < DATASET_SIZE; i++) {
        if (i % 8 == 0) {
            printf("\n\t");
        }
        printf("%4.d", dataset[i]);
    }
}

void print_statistics(unsigned char* dataset) {
    printf("\n\n ========== DATASET STATISTICS ==========\n\n");
    printf("Original Dataset:\n");
    print_array(dataset);
    printf("\n\n");
    printf("Sorted Dataset:\n");
    sort_array(dataset);
    print_array(dataset);
    printf("\n\n");

    find_mean(dataset);
    find_median(dataset);
    find_minimum(dataset);
    find_maximum(dataset);

    printf("\tMean: %d \t Min: %d\n\tMedian: %d \t Max: %d", mean, min, median, max);

    printf("\n\n");
}
