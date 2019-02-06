/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_entry(char *entry, int *array, int *size){
  char ent;
  while(1==1){
    if (feof(stdin)){
      break;
    }
    scanf("%s\n",entry);
    if (*size>10){
      printf("Too many numbers, please enter Ctrl + D\n");
      continue;
    }
    if(strlen(entry)>10){
      printf("Please enter a number that is 10 digits or less\n");
      continue;
    }
    if (entry!="0" & atoi(entry)==0){
      printf("Please enter a valid number\n");
      continue;
    }
    array[*size]=atoi(entry);
  (*size)++;
  }
}

int add(int *array, int *size){
  int count = 0;
  for (int i = 0; i<*size;i++){
    count+=array[i];
  }
  return count;
}

void main()
{
    int  size = 0;
    int array[10];
    char entry[10];
    printf("Please enter an Interger on each line. Press Crtl+Dwhen you wish to stop\n");
    get_entry(entry,array,&size);
    int sum = add(array,&size);
    printf("%d\n",sum);
}
