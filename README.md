*This project has been created as part of the 42 curriculum by ahtiftik.*

# get_next_line

## Description
`get_next_line` is a C programming project that implements a function to read a single line from a file descriptor. The primary goal of this project is to understand and manage static variables, dynamic memory allocation, and file I/O operations in C. It handles consecutive calls to read a file line by line until the end of the file (EOF) is reached.

## Algorithm Explanation and Justification
The project utilizes a static variable (`mem`) to retain data between consecutive function calls. Because the `read()` function reads a fixed number of bytes (`BUFFER_SIZE`) regardless of newline characters, the buffer often contains parts of the next line. 

The algorithm is divided into a pipeline to manage memory safely and adhere to the 25-line function limit:
1.  **Reading (`read_to_mem`)**: A loop reads from the file descriptor into a temporary buffer. The newly read data is immediately appended to the static `mem` variable using a custom `strjoin` function that frees the old `mem` pointer to prevent memory leaks. The loop breaks when a newline character `\n` is found or `read` returns 0 (EOF).
2.  **Extraction (`extract_line`)**: The static `mem` string is parsed to extract characters up to and including the first `\n`. This extracted string is allocated dynamically and returned to the caller.
3.  **Updating (`update_mem`)**: The characters remaining in the static `mem` after the extracted `\n` are copied into a newly allocated memory space. The old `mem` is freed, and the static pointer is updated to point to this new space, preserving the leftover data for the next function call.

This algorithm is chosen because it strictly guarantees zero memory leaks across unknown file lengths and variable buffer sizes, while isolating the logic to prevent buffer overflows.

## Instructions
This project does not require a Makefile for submission. To compile the function alongside a test `main.c` file, use the `gcc` or `cc` compiler. You must specify the `BUFFER_SIZE` macro during compilation.

**Compilation:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Execution:**
```bash
./gnl
```

**Usage Example in C:**
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Resources
* **Documentation**: Linux manual pages for `read(2)`, `malloc(3)`, and `free(3)`.
* **AI Usage**: AI was used as an interactive pedagogical tool during the development of this project. Specifically:
    * **Memory Management**: Used to identify the exact point of memory leaks within the custom `strjoin` implementation (Use-After-Free errors) and to debug segmentation faults caused by dereferencing NULL pointers during the initial static variable allocation.
    * **Norminette Optimization**: Used to refactor the algorithmic logic to comply with the 42 standard 25-line limit by splitting the core logic into modular helper functions (`read_to_mem`, `extract_line`, `update_mem`).