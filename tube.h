/***********************************/
/* A simple header file            */
/*                                 */
/* File: tube.h                    */
/* Author: SMF                     */
/* Date: 2/4/20                    */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ZERO    (0)
#define SUCCESS (0)
#define FAIL    (-1)
#define BYTE    char

#define STDIN  (0)
#define STDOUT (1)
#define STDERR (2)

#define TUBE_BUFFER_SIZE (1024)

extern int tube();
    /* A simple C fuction (routine) that copies all input from stdin to stdout */


/***************************************************************/
/* The following system calls are used:                        */
/* read()    defined in <unistd.h>: See also "man 2 read"      */
/* write()   defined in <unistd.h>: See also "man 2 read"      */
/* fprintf() defined in <stdio.h>:  See also "man 3 printf"    */
/* malloc()  defined in <stdlib.h>: See also "man 3 malloc"    */
/* free()    defined in <stdlib.h>: See also "man 3 free"      */
/***************************************************************/

