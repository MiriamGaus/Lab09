/* Task description:
Dynamic extension of strings

The strcat() function located in string.h header file concatenates
 two strings: the strcat(x, y) call adds string y to the end of string x.
For the correct operation, the array behind x must be long enough
 to accomodate the letters of y, too, otherwise the function
 overindexes the array usually leading to a crash.
It is the responsibility of the caller to ensure that the array
behind x is big enough, which makes the use of this function
rather inconvinient.

Your task is to create a more sophisticated function
to concatenate two strings. The first parameter must
be a dynamic string!
This function should be used like x = stringcat(x, y),
hence it does not add the letters y to x, but it creates
a new array of appropriate size dynamically,
assembles the concatenated string there, releases the
dynamic memory of the received x and returns the pointer
pointing to the new string.
For instance:

char *x;
x = copystring("apple");  // from the previous task
x = stringcat(x, "tree");
printf("%s\n", x);    // appletree

free(x);

Now you should write this function. Add a comment above it
describing the purpose and the usage of the function! Don't forget
to mention in the comment that the first parameter of the function
must be dynamically allocated.

Hint:
Why does the function return the address of the resulting concatenated string?
Because the concatenated string consumes more memory, a new memory
allocation is needed, thus string x is relocated in the memory. The original
string x is released (that's why x must be allocated dynamically -
we need to be able to free it), and the new location is returned.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *copystring(char const *str) { // you've done this in task1, you can copy here that as well!
    char * copy = (char*) malloc((strlen(str) + 1)* sizeof(char));
    if(!copy) return NULL;
    return strcpy(copy, str);
}

/* 
 * Allocate and return a new NUL-terminated string containing the bytes of x followed by y. The function 
 * expects x to be heap-allocated (it will free x), y may be any NUL-terminated string, and on success returns 
 * a pointer to the newly allocated concatenation (caller must free it). On allocation failure the function returns 
 * NULL (and x will have been freed), so callers should check the result. Typical usage: x = stringcat(x, "suffix");.
 * 
 */
char* stringcat(char const *x,char const *y) {
    char *str = (char*) malloc((strlen(x) + strlen(y) - 1) * sizeof(char));
    if(!str) return NULL;
    strcat(str, x);
    strcat(str + strlen(x) - 1, y);
    return str;
}

int main()
{
    char *x;
    x = copystring("apple"); /* from the previous task */
    char* y = stringcat(x, "tree");
    printf("%s\n", y); // appletree
    free(x);
    free(y);
    return 0;
}
