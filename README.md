*This project has been created as part of the 42 curriculum by vakhapil.*

# get_next_line

## Description

`get_next_line` is a 42 project that implements a function for reading from a file descriptor one line at a time.

Prototype:

`char *get_next_line(int fd);`

Each call returns the next line, including the final `\n` when present.  
The function returns `NULL` when there is nothing left to read or when an error occurs.

The project focuses on file descriptors, `read()`, dynamic memory allocation, static variables, and buffer management.

## Algorithm

The implementation uses a static variable called `stash` to keep unread data between calls.

The algorithm works as follows:

1. Read from the file descriptor into a buffer.
2. Append the buffer to `stash`.
3. Stop reading when a newline is found or EOF is reached.
4. Extract the first complete line from `stash`.
5. Save the remaining characters in a new `stash`.
6. Return the extracted line.

Example:

- `stash`: `"Hello\nWorld"`
- returned line: `"Hello\n"`
- new `stash`: `"World"`

A static variable is used because one call to `read()` may return more data than belongs to the current line. The remaining data must therefore be preserved for the next call.

This approach also allows the function to work with very small and very large `BUFFER_SIZE` values.

## Instructions

Files:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Compile with a custom buffer size:

`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c`

The project can also be compiled without `-D BUFFER_SIZE`, using the default value defined in `get_next_line.h`.

Example buffer sizes:

- `BUFFER_SIZE=1`
- `BUFFER_SIZE=42`
- `BUFFER_SIZE=9999`

## Resources

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- 42 `get_next_line` subject
- C documentation on static variables

### AI usage

AI was used to:

- review edge cases and buffer behavior
- review the implementation structure

The code was written and reviewed with the goal of understanding the behavior and logic of each part of the implementation.