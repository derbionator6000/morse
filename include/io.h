#ifndef IO_H
#define IO_H

#define BUFFER_TEXT 1024
#define BUFFER_MORSE 8000

typedef enum {
    INPUT_DEFAULT,     //encode
    INPUT_PIPE,      
    INPUT_FILE
} InputSource;

int is_pipe_input();
int is_direct_input();
int is_file_input();
char *read_file(char *file);
int input_source();

#endif