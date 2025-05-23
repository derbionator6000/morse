#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <options.h>
#include <io.h>
#include <morse.h>
/*gcc -I./include -o morse src/main.c src/morse.c src/options.c*/


int main (int argc, char *argv[]){
    int optindex = 0;
    int c = 0;
    char *arg = NULL;
    FILE *output_stream = stdout;
    static int encode_flag = 2;
    static int decode_flag = 0;
    static int out_flag = 0;
    static int encode_decode_flag = 0;
    static int option_flag = 0;

    if (argc < 2 && !is_pipe_input){
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
                        }
                    
                    else{
                        error_text();
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'd':
                    if (encode_flag != 1 && encode_decode_flag == 0){
                        encode_decode_flag = 1;
                        decode_flag = 1;
                        encode_flag = 0;
                       }
                    else{
                        error_text();
                        exit(EXIT_FAILURE);                   
                    }
                    break;
                case 'h':
                    help_text();
                    break;
                case 'o':
                    out_flag = 1;
                    check_status(optarg, "w");
                    FILE *output_file = fopen(optarg, "w");;
                    if (output_file == NULL){
                        //printf("%s is not a file!\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                    if (output_file != NULL) {
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
    arg = argv[optind];
    if (encode_flag){
        char buffer[1000000] = {0}; 
        char *text = buffer;
        if (option_flag == 0) arg = argv[1];
        if (is_pipe_input()){
            while (fgets(text, 10000, stdin) != NULL) {
            standard_text_to_morse(text, output_stream);
            }
            fprintf(output_stream, "\n");
            if (output_stream != stdout) fclose(output_stream);
        }
        else if (arg != NULL){
            text = read_file(arg);
            standard_text_to_morse(text, output_stream);
            fprintf(output_stream, "\n");
            if (output_stream != stdout) fclose(output_stream);
            free(text);
            exit(EXIT_SUCCESS);
        }
        
        exit(EXIT_SUCCESS);

        }
    
    else if (decode_flag == 1){
        char buffer[1000000] = {0}; 
        char *text = buffer;
        if (option_flag == 0) arg = argv[1];
        if (is_pipe_input()){
            while (fgets(text, 10000, stdin) != NULL) {
            standard_morse_to_text(text, output_stream);
            }
            fprintf(output_stream, "\n");
            if (output_stream != stdout) fclose(output_stream);
        }
        else if (arg != NULL){
            text = read_file(arg);
            standard_morse_to_text(text, output_stream);
            fprintf(output_stream, "\n");
            if (output_stream != stdout) fclose(output_stream);
            free(text);
            exit(EXIT_SUCCESS);
        }
        exit(EXIT_SUCCESS);

        }


    exit(EXIT_SUCCESS);




}