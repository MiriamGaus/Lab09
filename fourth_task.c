/* Task description:Removing parts from strings
Visit HP too!

Write the inverse of the previous function: the part delimited 
by the start and end indices should be removed from the original 
text, and the rest is kept! 
The function should not modify the source string received as a 
parameter, a brand new string should be created dynamically, and 
returned by the function.

Write a C program to demonstrate the usage of the function. 
Don't forget to release the memory at the end.


*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * removeSubstring(char* const original, int end, int start) {
  int len = end + strlen(original) - start;
  int oriLen = strlen(original);
  if(end < 0 || start > oriLen) {
    printf("Error: Index out of bounds.\n");
    return NULL;
  } else if (end > start) {
    printf("Error: Wrong indexes.\n");
    return NULL;
  }
  char * substr = (char *) malloc((len + 1) * sizeof(char));
  if(!substr) {
    printf("Error while allocating memory.\n");
    return NULL;
  }
  memcpy(substr, original, end);
  memcpy(substr + end, original + start, oriLen - start);
  substr[len] = '\0';
  return substr;
}

int main(){
  char string[101] = "This is a text not containing anything rude or harsh.\n"; // this is an array on the stack, mutable!
  char *substr = removeSubstring(string, 4, 9);
  printf("%s", substr);
  free(substr);
  return 0;
}
