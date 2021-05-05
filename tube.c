#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tube.h"

int transform(void * tube_buffer) {
  char * ptr = NULL;
  char vowels[] = "aeiou";
  ptr = (char *) tube_buffer;
  ptr = strpbrk((char *) tube_buffer, vowels);
  while (ptr != '\0') {
    ptr = strpbrk(ptr, vowels);
    if (ptr == '\0') return SUCCESS; // a chance to exit loop before segfault
    char upper_case = (char) toupper(*ptr);
    *ptr = upper_case;
    ptr++;
  }
  return SUCCESS;
}

#ifdef MAIN
int main (void) {
  return tube();
}
#endif

extern int tube(void) {
  /* Iteratively copy all input from stdin to stdout */

  /*******************************************/
  /* Declaration Section                     */
  ssize_t num_read;
  void * tube_buffer = NULL;
  ssize_t count;
  void * last_byte;
  void * stop_in_the_name_of_love;
  char * ptr = NULL;
  int words = 0;
  int new_lines = 0;
  //int total_words = 0;
  //int total_lines = 0;
  /******************************************/
  /* Initialization and Allocation Section  */
  tube_buffer= (void *) malloc((TUBE_BUFFER_SIZE * sizeof(BYTE)) + 1 * sizeof(BYTE));
  // setting NULL character
  last_byte = tube_buffer + (TUBE_BUFFER_SIZE);

  /* Body Section                           */
  num_read = read(STDIN, tube_buffer, TUBE_BUFFER_SIZE);
  stop_in_the_name_of_love = tube_buffer + (num_read + sizeof(BYTE) );
  (* (BYTE* ) stop_in_the_name_of_love) = '\0'; 
  count = num_read;
  while (num_read != ZERO) {
    /* Process the buffer based upon the semantics of the program. */
    transform(tube_buffer);     
    write(STDOUT, tube_buffer, num_read);
    /* wc                                   */
    ptr = (char *) tube_buffer;
    while ((ptr != '\0') && (*ptr != '\n') ) {
      if (ptr == '\0') return SUCCESS;
      if (*ptr == ' ' || *ptr == '\t') words++;
      else if (*ptr == '\n') new_lines++;
      ptr++;
      if (*ptr == '\n') new_lines++; //check now that the ptr has moved
    }
    words++; //bc it counts only whitespaces, add 1 word to account for the one at the beginning of each newline
    num_read = read(STDIN, tube_buffer, TUBE_BUFFER_SIZE);
    count = count + num_read;
  }
  printf("%d %d %d \n", new_lines, words, (int)count);

  /* Deallocation and Cleanup Section      */
  free(tube_buffer);
  return SUCCESS;
  
}

