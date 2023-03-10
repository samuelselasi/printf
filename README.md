# C - Custom printf function

## Background Context
```
Custom printf function
```
![printf](https://user-images.githubusercontent.com/85158665/213859591-8d8dbbb1-2be7-4f75-ae00-cc1b66dda46c.png)
## Requirements
### General
* Used editors: `vi`, `vim`
* All files will compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All files end with a new line
* Code for custom printf uses the `Betty` style. Checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No global variables used
* No more than 5 functions per file
* The prototypes of all your functions are included in header file called [main.h](./main.h)
* All header files are include guarded
## More Info
### Global functions and macros used
* `write` (man 2 write)
* `malloc` (man 3 malloc)
* `free` (man 3 free)
* `va_start` (man 3 va_start)
* `va_end` (man 3 va_end)
* `va_copy` (man 3 va_copy)
* `va_arg` (man 3 va_arg)
## Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```
## Tasks
[task0](./printf.c)
```
Write a function that produces output according to a format.
```
* Prototype: int _printf(const char *format, ...);
* Returns: the number of characters printed (excluding the null byte used to end output to strings)
* write output to stdout, the standard output stream
* format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
	* [c](./print_char.c)
	* [s](./print_string.c)
	* [%](./_printf.c)
* You don’t have to reproduce the buffer handling of the C library printf function
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

[task1](./_printf.c)
```
Handle the following conversion specifiers:
```
* [d](./print_int.c)
* [i](./print_int.c)

* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

[task2](./_printf.c)
```
Handle the following custom conversion specifiers:
```
* b: the unsigned int argument is converted to binary
	* [Print_Binary](./print_binary.c) 

[task3](./printf.c)
```
Handle the following conversion specifiers:
```
* u:
	* [Print_Unsigned](./print_unsigned.c)
* o:
	* [Print_Octal](./print_octal.c)
* x:
	* [Print_Hexadecimal](./print_hexadecimal.c)
	* [Print_Lower_Hex_Chars](./print_hex_lower.c)
* X:
	* [Print_Hexadecimal](./print_hexadecimal.c)
	* [Print_Upper_Hex_Chars](./print_hex_upper.c)

* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

[task4](./_printf.c)
```
Use a local buffer of 1024 chars in order to call write as little as possible.
```
* [buffer](./print_buffer.c)

[task5](./_printf.c)
```
Handle the following custom conversion specifier:
```
* S : prints the string. [Print_String](./print_string.c)
* Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
	* [Print_Non-Printable_Chars](./print_non_printable.c)


[task6](./_printf.c)
```
Handle the following conversion specifier: p.
```
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers
	* [Print_Pointer](./print_pointer.c)

[task7](./_printf.c)
```
Handle the following flag characters for non-custom conversion specifiers:
```
* [+](./get_flags.c)
* [space](./get_flags.c)
* [#](./get_flags.c)


[task8](./_printf.c)
```
Handle the following length modifiers for non-custom conversion specifiers:
```
* [l](./convert_size_number.c)

* [h](./convert_size_unsigned.c)

* Conversion specifiers to handle: d, i, u, o, x, X


[task9](./_printf.c)
```
Handle the field width for non-custom conversion specifiers.
```
* [Handle_Field_Width](./get_width.c)


[task10](./_printf.c)
```
Handle the precision for non-custom conversion specifiers.
```
* [Handle_Precision](./get_precision.c)


[task11](./_printf.c)
```
Handle the 0 flag character for non-custom conversion specifiers.
```
* [Handle_0_Flag](./nprint_int.c)


[task12](./_printf.c)
```
Handle the - flag character for non-custom conversion specifiers.
```
* [Handle_-_Flag](./get_flags.c)


[task13](./_printf.c)
```
Handle the following custom conversion specifier:
```
* r : prints the reversed string.
	* [Handle_String_Reverse](./print_reverse.c)


[task14](./_printf.c)
```
Handle the following custom conversion specifier:
```
* R: prints the rot13'ed string
	* [Rot13_Encryption](./print_rot13.c)


[task15](./_printf.c)
```
All the above options work well together.
```
* [header_file](./main.h)

## Pseudocode
[draw.io](https://drive.google.com/file/d/1PCFpX56mtAerF7RS7wzx9HCEFXc-Drib/view?usp=sharing)
[Pseudocode_For_Printf](./https://docs.google.com/document/d/1BOKUnRWP_8GRWBPqD_BZW-OB2V7Nh4YgCH765JsM1gg/edit?usp=sharing)

## Flow-Chart Diagram
![_PRINTF](https://user-images.githubusercontent.com/117751396/214351434-afbca8cb-b6d0-4494-91c8-08236143bcb8.png)
## Implementation
1. The function takes a format string and a variable number of arguments.

2. It initialises variables including an integer i, printed, printed_chars, flags, width, precision, size, buff_ind, a char buffer with a size of BUFF_SIZE and a va_list named list

3. The function checks if the format string is NULL and returns -1 if it is.

4. It initialises the variable argument list and sets the buffer index to 0 and the printed characters to 0.

5. The function iterates through the format string, for each iteration it checks if the current character is not '%'

6. If the current character is not '%', it adds the character to the buffer and increments the buffer index by 1.

7. If the buffer index reaches the size of the buffer, it calls the print_buffer function to print the buffer.

8. If the current character is "%", it calls the helper functions get_flags, get_width, get_precision, get_size and handle_print to process the formatting
9. It prints the output to the buffer and increments the printed_chars by the number of characters printed.

10. At the end of the iteration; it calls the print_buffer function to print whatever is left in the buffer.

11. The function ends the variable argument list and returns the total number of characters printed.


# Collaborators
- **Yasmine Ben Ali**
- **Samuel Selasi**
