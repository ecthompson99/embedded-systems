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
 * @file stats.h
 * @author Ethan Thompson
 * @date 15 October 2020
 * @brief Header file which declares the statistical functions implemented in stats.c.
 *
 * The program of which this file is a part can be explored in greater detail on
 * the course's website.
 *
 * @see https://www.coursera.org/learn/introduction-embedded-systems
 */

#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED


/**
 * @brief Finds the maximum value of an array of values.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It will
 * iterate through the array and return the largest value.
 *
 * @param dataset The dataset of size 40.
 *
 * @return int The maximum value of the dataset.
 */
 int find_maximum(unsigned char dataset[]);

/**
 * @brief Finds the minimum value of an array of values.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It will
 * iterate through the array and return the smallest value.
 *
 * @param dataset The dataset of size 40.
 *
 * @return int The minimum value of the dataset.
 */
 int find_minimum(unsigned char dataset[]);

/**
 * @brief Helper function, recursively partitions the array.
 *
 * This function takes as an input the indices of the left
 * and right pointers of the partition, as well as the dataset
 * to sort in place.
 *
 * @param dataset The dataset of size 40.
 * @param left The left pointer of the partition.
 * @param right The right pointer of the partition.
 *
 */
 unsigned char partition_array(unsigned char* dataset, int left, int right);

/**
 * @brief Sorts the array in place, by implementing quicksort.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It implements
 * the quicksort algorithm with average time complexity of O(nlogn).
 * The function modifies the array in place.
 *
 * @param dataset The dataset of size 40.
 *
 */
 void sort_array(unsigned char* dataset);

 /**
 * @brief Finds the median value of an array of values.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It will
 * call a sort function and iterate through the sorted array
 * to identify the median value.
 *
 * @param dataset The dataset of size 40.
 *
 * @return int The median value of the dataset.
 */
 void find_median(unsigned char* dataset);

/**
 * @brief Finds the arithmetic mean of an array of values.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It will
 * call a sort function and calculate the arithmetic mean.
 *
 * @param dataset The dataset of size 40.
 *
 * @return int The mean value rounded down to the nearest integer.
 */
 void find_mean(unsigned char* dataset);

 /**
 * @brief Prints the input array in a 5 x 8 format.
 *
 * This function loops through each element, and prints
 * out the array in 2D format, with 5 rows and 8 columns.
 *
 * @param dataset The dataset of size 40.
 */
 void print_array(unsigned char* dataset);

/**
 * @brief Prints out the dataset statistics.
 *
 * This function prints the original dataset, and
 * sorted dataset. The mean, median, minimum, and maximum
 * value are also printed to the console.
 *
 * @param dataset The dataset of size 40.
 */
 void print_statistics(unsigned char* dataset);

#endif // STATS_H_INCLUDED
