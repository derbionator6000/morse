#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <io.h> 

int is_pipe_input(){
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
    }
    return 0;
}

int is_direct_input(){
    return isatty(fileno(stdin));
}


int input_source(int argc, char *argv[]){
    if (is_pipe_input()) return INPUT_PIPE;
    if (is_file_input(argc, argv)) return INPUT_FILE; //GANZ WICHTIG HIER MUSS NOCH EINE NACHRICHT FALLS FILE ABER NICHT MÖGLICH ZU ÖFFNEN
    if (is_direct_input()) return INPUT_DEFAULT;
    
}
char *read_file(char *filename){
    check_status(filename, "rb");
    FILE* file = fopen(filename, "rb");
    if (file == NULL){
    return NULL;
    }
    
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

void check_status(char *filename, char *mode){
    FILE *file = fopen(filename, mode);
     if (file != NULL) {
        fclose(file);
        return;
    }
    switch(errno){
        case EACCES:  // Permission denied
                fprintf(stderr, "you dont have permission to open %s\n", filename);
                exit(EXIT_FAILURE);
        
        case ENOENT:  // No such file or directory
                fprintf(stderr, "file %s does not exist\n", filename);
                exit(EXIT_FAILURE);
            
            
        case EISDIR:  // Is a directory
                fprintf(stderr, "file %s is a directory\n", filename);
                exit(EXIT_FAILURE);
            
        default:{
                fprintf(stderr, "file %s can not be opened\n", filename);
                exit(EXIT_FAILURE);
            
    
}
    }
}
