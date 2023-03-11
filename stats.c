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
 * @brief Function prototypes for providing statics on an array of numbers, 
 * and general practice in the "C" language
 *
 * @author Akash CS
 * @date 11-03-23
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


// Create Struct
  stat Array;

  // Initialize Struct
  Array.numArray = test;
  Array.arrayLength = SIZE;
  Array.max = 0;
  Array.min = 0xFF;
  Array.mean = 0;
  Array.median = 0;

  // Process Data
  sort_array(Array.numArray, Array.arrayLength);
  Array.min = find_minimum(Array.numArray, Array.arrayLength);
  Array.max = find_maximum(Array.numArray, Array.arrayLength);
  Array.mean = find_mean(Array.numArray, Array.arrayLength);
  Array.median = find_median(Array.numArray, Array.arrayLength);
  print_array(Array.numArray, Array.arrayLength);
  print_statistics(Array);
}

void print_statistics(stat ArrayStats){
  printf("Array Median: %i\n", ArrayStats.median);
  printf("Array Mean: %i\n", ArrayStats.mean);
  printf("Array Minimum: %i\n", ArrayStats.min);
  printf("Array Maximum: %i\n", ArrayStats.max);
}

void print_array(int *arrayPtr, int arrayLength){
  // Loop through and print the array
  for(int i=0; i<arrayLength; i++){
    printf("Array[%i]: %i\n", i, *(arrayPtr + sizeof(char)*i));
  }
  printf("\n");
  
}

int find_median(int *arrayPtr, int arrayLength){
  // Make sure array is sorted first
  sort_array(arrayPtr, arrayLength);

  // Case where array length is odd
  if (arrayLength%2){
    return arrayPtr[arrayLength/2];
  }

  // Case where array length is even.  Average between two middle values is necessary
  int avg = (arrayPtr[arrayLength/2 - 1]+arrayPtr[arrayLength/2])/2;
  return avg;
}

int find_mean(int *arrayPtr, int arrayLength){
  int avg=0;

  // Add up all the numbers in the array
  for(int i=0; i<arrayLength; i++){
    avg+= arrayPtr[i];
  }
  
  // Integer division using Array Length
  return (avg/arrayLength);
}

int find_minimum(int *arrayPtr, int arrayLength){
  int minValue=0xFF;

  for (int i=0; i<arrayLength; i++){
    if (arrayPtr[i] < minValue){
      minValue = arrayPtr[i];
    }
  }

  return minValue;
}

int find_maximum(int *arrayPtr, int arrayLength){
  int maxValue=0;

  for (int i=0; i<arrayLength; i++){
    if (arrayPtr[i] > maxValue){
      maxValue = arrayPtr[i];
    }
  }

  return maxValue;
}

void sort_array(int *arrayPtr, int arrayLength){
  int i, j = 0;
  int temp;
  // Sort Array
  for(i=0; i<arrayLength; i++){
    for(j=i+1; j<arrayLength; j++){
      if(arrayPtr[i]<arrayPtr[j]){
        temp = arrayPtr[i];
        arrayPtr[i]=arrayPtr[j];
        arrayPtr[j]=temp;
      }
    }
  }
}

