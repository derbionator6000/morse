#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <options.h>
#include <io.h>
#include <morse.h>
/*gcc -I./include -o morse src/main.c src/morse.c src/options.c*/


//main loop
int main (int argc, char *argv[]){
    int optindex = 0;
    int c = 0;
    char *arg = NULL;
    FILE *output_stream = stdout;
    static int encode_flag = 2;
    static int decode_flag = 0;
    static int encode_decode_flag = 0;
    static int option_flag = 0;

    if (argc < 2){
        puts("see -h or --help for options");
        exit(EXIT_FAILURE);
    }
    else{
        while((c = getopt_long(argc,argv,"ho:ed",longopts,&optindex)) != -1){
            option_flag++;
            switch(c){
                case 'e':
                    if (!decode_flag && encode_decode_flag == 0){
                        encode_flag = 1; 
                        encode_decode_flag = 1;
                        arg = argv[optind];
                        printf("CASE ENCODE");
                        }
                    
                    else{
                        error_text();
                    }
                    break;
                case 'd':
                    if (encode_flag != 1 && encode_decode_flag == 0){
                        encode_decode_flag = 1;
                        decode_flag = 1;
                        encode_flag = 0;
                        arg = argv[optind];
                        printf("CASE DECODE");
                       }
                    else{
                        error_text();                    
                    }
                    break;
                case 'h':
                    help_text();
                    break;
                case 'o':
                    
                    printf("optind: %s", optarg);
                    FILE *output_file = fopen(optarg, "w");;
                    if (output_file == NULL){
                        printf("%s is not a file!\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                    if (output_file != NULL) {
                        printf("OUTPUT angepasst");
                        output_stream = output_file;
                    }
                    break;
                case 1:
                    info_text();
                    break;
                case '?':
                    break;

                default:
                    abort();

            
        
        }
        }
    }
    if (encode_flag){
        printf("encode loop");
        char buffer[1000000] = {0}; 
        char *text = buffer;
        if (option_flag == 0) arg = argv[1];
        if (arg != NULL){
            text = read_file(arg);
            standard_text_to_morse(text, output_stream);
            if (output_stream != stdout) fclose(output_stream);
            free(text);
            exit(EXIT_SUCCESS);
        }
        else if (is_pipe_input()){
            while (fgets(text, 10000, stdin) != NULL) {
            standard_text_to_morse(text, output_stream);
            if (output_stream != stdout) fclose(output_stream);
        }}
        else{
        fprintf(stderr, "Input is not a file");
        }
        
        exit(EXIT_SUCCESS);

        }
    
    else if (decode_flag == 1){
        printf("decode loop");
        char buffer[1000000] = {0}; 
        char *text = buffer;
        if (option_flag == 0) arg = argv[1];
        if (arg != NULL){
            text = read_file(arg);
            standard_morse_to_text(text, output_stream);
            if (output_stream != stdout) fclose(output_stream);
            free(text);
            exit(EXIT_SUCCESS);
        }
        else if (is_pipe_input()){
            while (fgets(text, 10000, stdin) != NULL) {
            standard_morse_to_text(text, output_stream);
            if (output_stream != stdout) fclose(output_stream);
        }}
        else{
        fprintf(stderr, "Input is not a file");
        }
        
        exit(EXIT_SUCCESS);

        }


    exit(EXIT_SUCCESS);




}