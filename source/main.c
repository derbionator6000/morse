#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

//getopts Konstanten
const char * const HELPTEXT = {
    "Usage: ./morse [OPTIONS] [ARGUMENT] ...\n" \
    "Can not use -e and -d; --encode, --decode together!\n" \
    "With no OPTION selected, --encode is applied automatically\n" \
    "OPTIONS: \n\n" \
    "-h, --help                 Display this information\n" \
    "    --programmer-info      Output developers information\n" \
    "-o, --out                  takes <file> as argument\n" \
    "                           funnels output into file\n" \
    "-e, --encode               encodes text into morse code\n" \
    "                           optional arguments: <file>, <string> example:\n" \
    "                           NOT FINISHED YET, DECODE NOT EITHER\n" \
    "                           supports piping\n" \
    "-d, --decode               translates morse into text\n" \
    "                           optional arguments: <file>, <string>\n" \
    "                           supports piping\n" \
    "\n" \
    "For more information contact Robin.Bardeleben@gmx.de"
};

const char * const PROGRAMMER_INFO = {
    "surname : Robin\n" \
    "name : von Bardeleben\n" \
    "branch_of_study : TIT\n" \
    "contact : Robin.Bardeleben@gmx.de\n" \
};

//Warning Text for decode/encode used together
const char * const WARNING_TEXT = {
    "Please refrain from using -e and -d\n" \
    "or --encode and --decode together\n" \
    "since they cancel each other out"
};


const struct option longopts[] = {
    {"help", no_argument, NULL, 'h'},
    {"programmer-info", no_argument, NULL, 1},
    {"encode", optional_argument, NULL, 'e'},
    {"decode", optional_argument, NULL, 'd'},
    {"out", required_argument, NULL, 'o'},
    {0, 0, 0, 0}
    //opt {slash_wordspacer}
};
// getopts Funktionen
void info_text(){
    puts(PROGRAMMER_INFO);
}

void help_text(){
    puts(HELPTEXT);
}

//when encode and decode are used together
void error_text(){
    puts(WARNING_TEXT);
    exit(EXIT_FAILURE);
}





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
                        printf("Erfolgreich, e");
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