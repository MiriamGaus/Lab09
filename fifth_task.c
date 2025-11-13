/* Task description:Inserting strings into strings

This task is similar to the previous ones: the function receives a string, and creates a new one.

This time, however, the task is not to remove/cut something from a string,
but to insert another string to somewhere into the original string.
For instance, the result of insertstring("hello!", 5, ", world") is a new string
containing hello, world!: the second string has been inserted between letters "o" and "!".
*/

#include <stdio.h> //don't forget to include the required libraries
#include <stdlib.h>
#include <string.h>

char * insertstring(char* const original, int start, char *input) {
  int oriLen = strlen(original);
  int inLen = strlen(input);
  int len = oriLen + inLen;
  if(start < 0 || start > oriLen) {
    printf("Error inserting at the given index not possible.\n");
    return NULL;
  }
  char *str = (char*) malloc((len + 1) * sizeof(char));
  if(!str) {
    printf("Error while allocating memory.\n");
    return NULL;
  }
  memcpy(str, original, start);
  memcpy(str + start, input, inLen);
  memcpy(str + start + inLen, original + start, oriLen - start);
  str[len] = '\0';
  return str;
}

int main() {
  char* str;
  str = insertstring("hello!", 5, ", world");
  printf("%s", str);
  free(str);
  return 0;
}
