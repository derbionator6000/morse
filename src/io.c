#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <io.h> //OWN

InputSource detect_input_source(int argc)
int is_pipe_input(){
    int c = getc(stdin)
    if (c == EOF) return 0;
    ungetc(c, stdin);
    return 1;
}

int is_direct_input(){
    return isatty(fileno(stdin));
}

int is_file_input(){

}

int input_source(){
    if (is_direct_input()) return INPUT_DEFAULT;
    if (is_pipe_input()) return INPUT_PIPE;
    else return INPUT_FILE;
}