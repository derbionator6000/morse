#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <io.h> //OWN

int is_pipe_input(){
    /*
    int c = getc(stdin);
    if (c == EOF) return 0;
    ungetc(c, stdin);
    return 1;
    */
   return !isatty(fileno(stdin)) && !feof(stdin);
}

int is_file_input(int argc, char *argv[]){
    //if file
    for (int i = 1; i < argc; i++){
        printf("Oben");
        FILE *file = fopen(argv[i], "r");
        printf("Mitte");
        if (file != NULL){
            printf("Geöffnet");
            fclose(file);
            return 1;
        }
        printf("In for loop");
    }
    printf("AUßerhalb for loop");
    return 0;
}

int is_direct_input(){
    return isatty(fileno(stdin));
}
/*
int is_file_input(){

}
*/

int input_source(int argc, char *argv[]){
    if (is_pipe_input()) return INPUT_PIPE;
    if (is_file_input(argc, argv)) return INPUT_FILE; //GANZ WICHTIG HIER MUSS NOCH EINE NACHRICHT FALLS FILE ABER NICHT MÖGLICH ZU ÖFFNEN
    if (is_direct_input()) return INPUT_DEFAULT;
    
}