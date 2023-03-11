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
 * @brief Functions for providing statics on an array of numbers, and general 
 * practice in the "C" language
 *
 * <Add Extended Description Here>
 *
 * @author Akash CS
 * @date 11-02-2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


typedef struct stats{
    int *numArray;
    int arrayLength;
    int median;
    int mean;
    int max;
    int min;
} stat;

/**
 * @brief Print out all the statistics related to the array
 * 
 * @param ArrayStats Struct containing array and associated statistics
 * 
 * @return Void()
 */
void print_statistics(stat ArrayStats);

/**
 * @brief Prints the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * 
 * @return Void()
 */
void print_array(int *arrayPtr, int arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the median value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return int median value in array
 */
int find_median(int *arrayPtr, int arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the average value of the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return int average value in array
 */
int find_mean(int *arrayPtr, int arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the minimum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return int minimum value in array
 */
int find_minimum(int *arrayPtr, int arrayLength);

/**
 * @brief Given an array pointer and length of array, returns the maximum value in the array
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 * @return int maximum value in array
 */
int find_maximum(int *arrayPtr, int arrayLength);

/**
 * @brief Sorts the array inplace from largest (index 0) to smallest (index n-1)
 * 
 * @param arrayPtr Pointer to the array of data
 * @param arrayLength Number of elements in the array
 */
void sort_array(int *arrayPtr, int arrayLength);

#endif /* __STATS_H__ */
