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
    static int encode_flag = 2;
    static int decode_flag = 0;

    if (argc < 2){
        puts("see -h or --help for options");
        exit(EXIT_FAILURE);
    }
    else
        while((c = getopt_long(argc,argv,"ho:e::d::",longopts,&optindex)) >= 0){
            switch(c){
                case 'e':
                    if (decode_flag != 1){
                        encode_flag = 1;
                        /*FILE *file = fopen("output.txt", "w");
                        file_text_to_morse(argv, argc, file);
                        */
                    }
                    else{
                        error_text();
                    }
                    break;
                case 'd':
                    if (encode_flag != 1){
                        decode_flag = 1;

                        

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
                        printf("%s ist keine Datei\n", optarg);
                        exit(EXIT_FAILURE);
                    }
                    file_text_to_morse(argv,argc,output_file);
                    if (output_file != NULL) fclose(output_file);
                    break;
                case 1:
                    info_text();
                    break;
                default:
                    exit(EXIT_FAILURE);

            }
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