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
