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
 #include <stats.h>

 // Define size of the dataset
 #define DATASET_SIZE 40


 int main() {

 // Dataset from Alex Fosdick's sample implementation
 unsigned char test[DATASET_SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                     114,  88,  45,  76, 123,  87,  25,  23,
                                     200, 122, 150,  90,  92,  87, 177, 244,
                                     201,   6,  12,  60,   8,   2,   5,  67,
                                       7,  87, 250, 230,  99,   3, 100,  90};

 }
