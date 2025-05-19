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
    static int encode_flag = 2;
    static int decode_flag = 0;

    if (argc < 2){
        puts("see -h or --help for options");
        exit(EXIT_FAILURE);
    }
    else
        while((c = getopt_long(argc,argv,"ho:e::d::",longopts,&optindex)) != -1){
            switch(c){
                case 'e':
                    if (decode_flag != 1){
                        encode_flag = 1;
                        arg = optarg;
                        printf("das argument: %s", optarg);
                    }
                    else{
                        error_text();
                    }
                    break;
                case 'd':
                    if (encode_flag != 1){
                        decode_flag = 1;
                        arg = optarg;
                    }
                    else{
                        error_text();                    
                    }
                    break;
                case 'h':
                    help_text();
                    break;
                case 'o':
                    FILE *output_file = fopen(optarg, "w");
                    printf("%s", optarg);
                    if (output_file == NULL){
                        printf("%s is not a file!\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                    if (encode_flag){
                        file_text_to_morse(argv,argc,NULL); //output_file kann man hier reinschreiben
                    }
                    else{
                        //file_morse_to_text(argv,argc,output_file);
                    }
                    if (output_file != NULL) fclose(output_file);
                    break;
                case 1:
                    info_text();
                    break;
                default:
                arg = optarg;
                    abort();

            }
        
        }
    if (encode_flag){
        int c = input_source(argc, argv);
        printf("YAY, HIER %d", c);
        char buffer[BUFFER_TEXT];
        switch (c){
            case 0:
                standard_text_to_morse(arg);
            case 1:
                standard_text_to_morse(fgets(buffer, BUFFER_TEXT, stdin));
            case 2:
                FILE *file = fopen(arg, "r");
                printf("die Datei: %s", arg);
                if (file == NULL){
                    printf("File: %s empty or not processable", optarg);
                    exit(EXIT_FAILURE);
                }
                standard_text_to_morse(fgets(buffer, BUFFER_TEXT, file));
                fclose(file);

        }
    }
    else if (decode_flag == 1){
        
    }
    /*
    if (encode_flag == 1){
        int source = input_source(argc,argv);
        switch (source){
            case 0:
            case 1:
            case 2:
        }
    }
    else if (decode_flag == 1){
        int source = input_source(argc,argv);
        switch (source){
            case 0:
            case 1:
            case 2:
        }
    }*/
    exit(EXIT_SUCCESS);




}