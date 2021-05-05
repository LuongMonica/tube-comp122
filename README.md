# tube

This is a simple C program to get you started.

The tube program simply passes all input (via stdin) to the output file (i.e., stdout).  The program also emits a summary message to stderr to indicate the number of bytes processed.

Usage: tube < input_file > output_file

Example:

    $ cat >input_file
    hello this is a sample
    input file
    that has
    been processed by the
    tube program.

    $ ./tube <input_file >output_file
    The number of bytes processed: 0

    $ cat output_file
    hello this is a sample
    input file
    that has
    been processed by the
    tube program.

Assignment: Make the following changes to the program.

    1. Via the appropriate git commands, clone the repo onto your ssh.sandbox.csun.edu account
    
    2. Correct the warning on line 33, and then
       - Merge your code into the Master branch
    
    3. Update the program to report the total number of bytes processed,
       - Merge your code into the Master branch

    4. Enhance the program by transforming each vowel to its capitalized form.
       - Use the strpbrk() routine to find each vowel
       - Use the toupper() routine to transe the vowel to its upper-case form
       - Merge your code into the Master branch

    5. (Bonus) Revamp the program to modify the output so that it reports
        - the number of lines (each line is separated by a single newline character (\n))
        - the number of words (each word is separated by one or more whitespaces)
        - the number of characters (i.e., bytes)

    Example:
        $ ./tube <input_file >outpufile
              5      15      96

Resources:

    man strpbrk
    
    man toupper
