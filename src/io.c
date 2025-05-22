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
char *read_file(char *filename){
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return NULL;
    
    // Dateigröße ermitteln
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    //for '/0' 
    char* buffer = malloc(file_size + 1);

    size_t read_size = fread(buffer, 1, file_size, file);
    fclose(file);
    buffer[file_size] = '\0';
    return buffer;
    

}