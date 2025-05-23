#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <options.h> 

const char * const HELPTEXT = {
    "Usage: ./morse [OPTIONS] [ARGUMENT] ...\n" \
    "Can not use -e and -d; --encode, --decode together!\n" \
    "With no OPTION selected, --encode is applied automatically\n" \
    "OPTIONS: \n\n" \
    "-h, --help                 Display this information\n" \
    "    --programmer-info      Output developers information\n" \
    "-o, --out                  takes <file> as mandatory argument\n" \
    "                           funnels output into file if possible\n" \
    "                           if not used, stdout is selected\n" \
    "-e, --encode               encodes text into morse code\n" \
    "                           symbols are seperated by a space, a word by three spaces\n" \
    "                           ./morse -e <text_file> or via pipe (| or <<<)\n" \
    "                           ./morse -e <<< text\n" \
    "                           cat Text | ./morse -e\n" \
    "                           encodes unknown letters into *\n" \
    "-d, --decode               decodes morse into text\n" \
    "                           ./morse -d <morse_file> or via pipe (| or <<<)\n" \
    "                           ./morse -d <<< ... - .. -. --. \n" \
    "                           cat morse_file | ./morse -d\n" \
    "                           decodes only into capital letters\n" \
    "                           ignores unknown symbols, e.g. € == * * *\n\n" \

    "For more information contact Robin.Bardeleben@gmx.de"
};

const char * const PROGRAMMER_INFO = {
    "\"surname\" : \"Robin\"\n" \
    "\"name\" : \"von Bardeleben\"\n" \
    "\"branch_of_study\" : \"TIT\"\n" \
    "\"contact\" : \"Robin.Bardeleben@gmx.de\"" \
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

//getopts Funktionen
void info_text(){
    puts(PROGRAMMER_INFO);
}

//outputs -help or --help text
void help_text(){
    puts(HELPTEXT);
}

//when encode and decode are used together
void error_text(){
    puts(WARNING_TEXT);
    exit(EXIT_FAILURE);
}