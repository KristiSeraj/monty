# Monty interpreter

Monty 0.98 is a scriptig language that is first compiled into Monty byte codes. It relies on a uniques stack, with specific instructions to manipulate it. This projects is an intrerpreter for Monty ByteCode files.

**The monty program**

- Usage: `monty file`
  - where `file` the path to the file containing Monty byte code
- If the user does not give any  file or more than one argument to the program, prints the error message `Usage: monty file`, followed by a new file, and exit status `EXIT_FAILURE`
- If, for any reason, it's not possible to open the file, prints the error message `Error: Can't open file <file>` followed by a new line, and exit with the status `EXIT_FAILURE`
  - where `<file>` is the name of the file
- If the file contains an invalid instruction, prints the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured

**File description**

- [bytecodes](https://github.com/KristiSeraj/monty/tree/main/bytecodes) - Contains monty files (`.m`) 

- [error.c](https://github.com/KristiSeraj/monty/blob/main/error.c) - C file that executes all error messages

- [main.c](https://github.com/KristiSeraj/monty/blob/main/main.c) - Entry point for monty program

- [monty](https://github.com/KristiSeraj/monty/blob/main/monty) - Monty executable file 

- [monty.h](https://github.com/KristiSeraj/monty/blob/main/monty.h) - Header file that contains all structures and function prototypes

- [op_call.c](https://github.com/KristiSeraj/monty/blob/main/op_call.c) - C file that calls all opcodes

- [open_file.c](https://github.com/KristiSeraj/monty/blob/main/open_file.c) - C file that opens monty files

- [stack_math_op.c](https://github.com/KristiSeraj/monty/blob/main/stack_math_op.c) -  C file that executes math opcodes

- [stack_op.c](https://github.com/KristiSeraj/monty/blob/main/stack_op.c) - C file that executes basic opcodes

- [stack_op2.c](https://github.com/KristiSeraj/monty/blob/main/stack_op2.c) - C file that executes char opcodes

- [stack_util.c](https://github.com/KristiSeraj/monty/blob/main/stack_util.c) - C file that executes swap and nop opcode

**Monty opcode**

- `push`
  - Pushes an element to the stack
- `pall`
  - Prints all the values on the stack, starting from the top of the stack
- `pint`
  - Prints the value at the top of the stack, followed by a new line
- `pop`
  - Removes the top element of the stack
- `swap`
  - Swaps the top two elements of the stack
- `add`
  - Adds the top two elements of the stack
  - The top element of the stack contains the result
- `nop`
  - Doesn't do anything
- `sub`
  - Substracts the top element of the stack from the second top element of the stack
  - The top element of the stack contains the result
- `div`
   - Divides the second element of the stack by the top element of the stack
   - The top element of the stack contains the result
  - Prints error if the top element of the stack is `0`
- `mul`
   - Multiplies the second top element of the stack with the top element of the stack
   - The top element of the stack contains the result
- `mod`
  - Computes the rest of the division of the second top element of the stack by the top element of the stack
  - The top element of the stack contains the result
  - Prints error if the top element of the stack is `0`
- `pchar`
   - Prints the char at the top of the stack, followed by a new line
   - The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- `pstr`
  - Prints the string at the top of the stack, followed by a new line
  - The integer stored in each element of the stack is treated as the ascii value of the character to be printed
  - The string stops when either:
    - the stack is over
    - the value of the element is 0
    - the value of the element is not in the ascii table
- `rotl`
  - Rotates the stack to the top
  - The top element of the stack becomes the last one, and the second top element of the stack becomes the first
- `rotr`
  - Rotates the stack to the bottom
  - The last element of the stack becomes the top element of the stack

