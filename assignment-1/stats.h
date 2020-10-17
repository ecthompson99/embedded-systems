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
 int find_median(unsigned char dataset[]);


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
 int find_mean(unsigned char dataset[]);

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
 * @brief Sorts the array in place, by implementing quicksort.
 *
 * This function takes as an input an array of size 40
 * where each element is an unsigned 8-bit char. It implements
 * the quicksort algorithm with average time complexity of O(nlogn).
 * The function will return the modified array.
 *
 * @param dataset The dataset of size 40.
 *
 * @return char[40] The sorted array.
 */
unsigned char sort_array(unsigned char dataset[]);

#endif // STATS_H_INCLUDED
