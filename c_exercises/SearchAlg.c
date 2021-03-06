// TO DO, pass by reference and pass by ????
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h>

/* Inputs
void linearSearch(
  int passArray[]   pointer to array
  int target        pass value
  int *retIndex     pointer to address)

int binarySearch(
  int* p_Array      pointer to array
  int target        pass value
  int size_t        pass value)

Array is from txt file simple 1 digit numbers with no garbage to parse
Using int fgetc(FILE *stream) it returns char so convert to int.
void jumpSearch(
  int* target       pass pointer to address
  int size_t        pass value)


using fgets(), lets grab the buffer size, if whole string lets parse

using fscanf(FILE *stream, const char *format, ...)

*/

// Linear Search
// Input: (1D array passed by unsized array:int, search value:int, and varable pointer to store index:int* )
// return: void
void linearSearch(int passArray[], int target, int *retIndex, int size){


  // cannot use size unless you count it in this scope, so terminate on special char
  //for (int index = 0; passArray[index] != '\0'; index ++){
  for (int index = 0; index < size; index ++){
    // if value of pointer t matches the searched value, store it in and break
    if(passArray[index] == target){
      *retIndex = index;  // pointer value points to another value. Set the value pointed by retIndex to index
      // So when it leaves this scope the value is assigned to another address in main
      break;
    }
  }

}

int char_linearSearch(char passArray[], char target, int size){
  int found = -1;
  // cannot use size unless you count it in this scope, so terminate on special char
  for (int index = 0; index < size; index ++){

    // if value of pointer t matches the searched value, store it in and break
    if(passArray[index] == target){
      found = index;  // pointer value points to another value. Set the value pointed by retIndex to index
      // So when it leaves this scope the value is assigned to another address in main
      break;
    }


  }

  return found;

}

// binary Search
// Input: (1D array passed by pointer: int, search value:int, array size:int)
// return: index of found:int
int binarySearch(int* p_Array, int target, int size){
  int count = 0;
  // Passing an array pointer as arg
  // Can use indexing p_Array[index] or *(p_Array + index) for the value
  int curr;

  int low = 0;
  int high = size;
  int pivot;
  int found = -1;

  while (low <= high){
    count ++; // just to keep track

    pivot = floor((low + high) /2);

    curr = *(p_Array+pivot);


    //printf("pivot: %d and value: %d ; high: %d : low: %d\n", pivot, curr, high, low);
    // if if value matches target
    if(curr == target){
      found = pivot;
      break;
    } else {
      // if value is less than the pivot means the next section is to the left.
      if (target < curr){
        high = pivot - 1;
      } else {  // to the right
        low = pivot + 1;
      }
    }

  }
  //printf("\ncount: %d\n", count);

  return found;
}

// binary Search for CHAR array
// Input: (1D array passed by pointer: int, search value:int, array size:int)
// return: index of found:int
int char_binarySearch(char* p_Array, char target, int size){
  int count = 0;
  // Passing an array pointer as arg
  // Can use indexing p_Array[index] or *(p_Array + index) for the value
  char curr;
  //printf("binary search: %s\n", p_Array);
  int low = 0;
  int high = size-1;
  int pivot;
  int found = -1;

  while (low <= high){
    //printf("Char search: %d, high: %d, low: %d. \n", count, high, low);

    pivot = low + ((high - low) /2);

    curr = *(p_Array+pivot);


    //printf("pivot: %d and value: %d ; high: %d : low: %d\n", pivot, curr, high, low);
    // if if value matches target
    if(curr == target){
      count ++; // just to keep track of value looking
      found = pivot;
      break;
    } else {
      // if value is less than the pivot means the next section is to the left.
      if (target < curr){
        high = pivot - 1;
      } else {  // to the right
        low = pivot + 1;
      }
    }

  }
  //printf("\ncount: %d\n", count);

  return found;
}

char *strip_chars(char *string, char *chars);

int int_min(int a, int b);


// Input: address of target pointer:int*, size of array:int

void jumpSearch(int* target, int size){

  char white = ' ';
  int ch_val;
  char *new;
  char symbols[3] = ",;+";

  int array[size];

  int index = 0;

  //long ret;
  //int *p;
  //int out;

  //int buffer[8];  // max 255 later use fseek() and ftell() to dynamically change buffer size to fit any input from file

  // Open file
  // 1. FILE pointer to keep track of the file being accesses.
  FILE *fp;

  // 2. Returns a file pointer to the specified file`
  fp = fopen("arr_file_singleLine.txt", "r");

  if(fp == NULL) {
      perror("Error in opening file.");

  } else {

    while ((ch_val = fgetc(fp)) != EOF){

      // file finished or error.
      // fscanf(FILE *stream, format, ..)
      // store string in address i_val
      //if(fscanf(fp, "%s", &ch_val) != 1){ // if set to %s it corrupts my index for some reason.
      //  break;
      //}

      // https://stackoverflow.com/questions/9685391/getting-words-from-text-file-to-an-array
      /* Probably better
      for(i = 0; i < 4; i++)
            fscanf(data, "%s", array[i]);  // no need for & with %s
      */

      //printf(" yo: %c\n", ch_val);
      //printf(" yo: %d\n", ch_val);

      //Got the string now parse the garbage off it.
      //new = strip_chars(&ch_val, symbols);

      //ret = strtol(ch_val, &p,10);
      //out = (int) ret;
      //ret = strtol(&ch_val, &p, 10);
      //out = (int) ret;

      // Dont convert space or new line (so dumb).
      if (ch_val != white && ch_val != 10){
        int out = ch_val - '0';
        //printf(" dig: %d\n", out);

        array[index] = out;
        index ++;
      }

      //printf(" grab: %c ", ch_val);
      //array[*ok] = out;
      //printf(" index: %d ", index);
      //printf(" ok: %s ", new);

      //free(new);

    }
  }

  //for( int i = 0; i < size; i++){
  //  printf("a: %d ", array[i]);
  //}

  // close the file after use
  fclose(fp);

  // FINALLY built array, now can search
  int prev = 0;
  int jumpStep = 0;
  int fixedJump = 2;  // Jump by 2

  int searchIn = 0;
  int local_tar = *target;

  //printf("pointer: %d\n", *target);
  //printf("local: %d\n", local_tar);

  // 0 not Found
  // 1 found
  int found = 0;

  // find the range to search
  // The min takes care of out of bounds, will loop until it is greater than the target
  while (array[ int_min(jumpStep, size) - 1] < local_tar){

    prev = jumpStep;  // keep the previous jump so dont need to back track
    jumpStep += fixedJump;

    // if prev becomes bigger than size and still in this loop it means the target is greater than all the values in the array
    if (prev >= size){
      found = 0;
      break;
    }
  }


  // Will get here if range found
  // linear search from prev to the jump max or size
  // loops until the target it found or greater than
  while(array[prev] < *target){

    prev ++;

    if(prev == int_min(jumpStep, size)){
      found = 0;
      break;
    }
  }


  if (array[prev] == *target){
    found = 1;
  }


  if (found == 1){
    printf("target found at index: %d. \n", prev);
  } else if (found == 0){
    printf("Not in array.\n");
  }

}

/*
int current, prev = 0;
    int jump = 2;
    int count = 0;
    int size = 10;
    int target = 1;
    
    int range_found = 1;
    
    int yeet[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int max_tested = 1;
    
    for (current = 0; current < size; current = current + jump){
        printf("index %i \n", current);
        
        if (yeet[current] == target){
            printf("Found at %i.\n", current);
            range_found = 2;
            break;
        } else if (yeet[current] < target){
            prev = current;
            
        } else if(yeet[current] > target){
            range_found = 0;
            break;
        }
        
        //printf("\n");
        if(max_tested == 0){
            break;
        }
        if((current + jump) >= size){
            current = (size-1) - jump; // set to max
            max_tested = 0;
        }
    }
    
    printf("\n");
    int found_flag = 1;
    
    if(range_found == 1){
        printf("Not found.\n");
    } else if(range_found == 0){
        for(prev; prev <= current; prev ++){
            if (yeet[prev] == target){
                printf("Found at %i. \n", prev);
                found_flag = 0;
                break;
            }
        }
        if (found_flag == 1){
            printf("Not found.\n");
        }
    } else if(range_found == 2){
        // pass
    }
  */

int int_min(int a, int b)
{
  if(a > b){
    return b;
  } else if (a < b){
    return a;
  } else {
    return a;
  }
}

/* removes all chars from string */
char *strip_chars(char *string,char *chars)
{
  char * newstr = malloc(strlen(string) + 1);
  int counter = 0;

  for ( ; *string; string++) {
    if (!strchr(chars, *string)) {
      newstr[ counter ] = *string;
      ++ counter;
    }
  }

  newstr[counter] = 0;
  return newstr;
}
