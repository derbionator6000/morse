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
    static int encode_decode_flag = 0;

    if (argc < 2){
        puts("see -h or --help for options");
        exit(EXIT_FAILURE);
    }
    else
        while((c = getopt_long(argc,argv,"ho:e::d::",longopts,&optindex)) >= 0){
            switch(c){
                case 'e':
                    if (!encode_decode_flag){
                        //morse_to_text(argv[2]);
                        input_source()
                    }
                    else{
                        error_text();
                    }
                    break;
                case 'd':
                    if (!encode_decode_flag){

                    }
                    else{
                        error_text();                    
                    }
                    break;
                case 'h':
                    help_text();
                    break;
                case 'o':
                    break;
                case 1:
                    info_text();
                    break;
                default:
                    exit(EXIT_FAILURE);

            }
        }
    exit(EXIT_SUCCESS);



}