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

- [op_call.c](https://github.com/KristiSeraj/monty/blob/main/op_call.c) - C file that calls all operations

- [open_file.c](https://github.com/KristiSeraj/monty/blob/main/open_file.c) - C file that opens monty files

- [stack_math_op.c](https://github.com/KristiSeraj/monty/blob/main/stack_math_op.c) -  C file that executes functions for math operations

- [stack_op.c](https://github.com/KristiSeraj/monty/blob/main/stack_op.c) - C file that executes basic operation functions

- [stack_op2.c](https://github.com/KristiSeraj/monty/blob/main/stack_op2.c) - C file that executes char operation functions

- [stack_util.c](https://github.com/KristiSeraj/monty/blob/main/stack_util.c) - C file that executes swap and nop function operations

**The push opcode**

The opcode push pushes an element to the stack.

- Usage: `push <int>`
  - where `<int>` is an integer
- If `<int>` is not an integer or if there is no argument given to `push`, prints the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
   - where is the line number in the file

**The pall opcode**

The opcode pall prints all the values on the stack, starting from the top of the stack.

- Usage `pall`
- If the stack is empty, don’t print anything

```
root$ cat bytecodes/00.m
push 1
push 2
push 3
pall
root$ ./monty bytecodes/00.m
3
2
1
```

**The pint opcode**

The opcode pint prints the value at the top of the stack, followed by a new line.

- Usage: `pint`
- If the stack is empty, prints the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

```
root$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
root$ ./monty bytecodes/06.m
1
2
3
```
