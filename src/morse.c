#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <morse.h> //OWN
#include <io.h>

const MorsePack morse_table[] = {
     /* letters A-Z (ReqFunc14, ReqFunc15, ReqFunc16) */
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    
    /* numbers 0-9 (ReqFunc17, ReqFunc18) */
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    
    /* text_ymbols (ReqFunc19, ReqFunc20) */
    {'.', ".-.-.-"},    /* Punkt */
    {',', "--..--"},    /* Komma */
    {':', "---..."},    /* Doppelpunkt */
    {';', "-.-.-."},    /* Strichpunkt */
    {'?', "..--.."},    /* Fragezeichen */
    
    /* mathematic symbols (ReqFunc21, ReqFunc22) */
    {'=', "-...-"},     /* Gleich */
    {'-', "-....-"},    /* Minus */
    {'+', ".-.-."},     /* Plus */
    
    /* formatting_symbols (ReqFunc23, ReqFunc24) */
    {'_', "..--.-"},    /* Unterstrich */
    {'(', "-.--."},     /* Klammer auf */
    {')', "-.--.-"},    /* Klammer zu */
    {'/', "-..-."},     /* Schrägstrich */
    {'@', ".--.-."},     /* Klammeraffe */
    {'\0', NULL}
};
/*
int morse_char_to_text(char morse_input[]){
    char buffer[20] = {0};
    for (int i = 0; morse_input[i] != '\0'; i++){
        buffer[i] = morse_input[i];
    }
    for (int i = 0; morse_table[i].character != '\0'; i++){
        if (morse_table[i].character == buffer[i])
            return MORSE_OK;
    
    }
    return MORSE_CHAR_NOT_FOUND;


}
*/

char *text_to_morse(int argc, char *argv[], char text[], int input_source){
    switch(input_source){
        case 0: //normaler string
            for (int i = 1; i < argc; i++)
            {
                if (argv[i][0] != '-'){
                    return argv[i];
                }
            }
            break;
        case 1: //pipe
        char test[BUFFER_TEXT];
        //nimmt von pipe und gibt in test ein
        if (fgets(text, BUFFER_TEXT, stdin) != NULL) {
            break;
}
        case 2: //file 
             for (int i = 1; i < argc; i++)
            {
                if (argv[i][0] != '-'){
                    FILE *output_file = fopen(argv[i], "w");
                    file_text_to_morse(argv,argc,output_file);
                    fclose(output_file);
                    
            }
            }
            break;
    }
}

void file_text_to_morse(char *argv[], int argc, FILE *output_file){
    FILE *output_stream = stdout;
    if (output_file != NULL){
        output_stream = output_file;
    }

    char buffer_input[BUFFER_TEXT];
    char buffer_output[BUFFER_MORSE];

    for (int i = 1; i < argc; i++){
        if (argv[i][0] != '-'){
            FILE *file = fopen(argv[i], "r");
            //break;
            if (file){
                while (fgets(buffer_input, sizeof(buffer_input), file)){
                    int pos = 0;
                    buffer_output[0] = '\0';
                    //buffer_input[0] = '\0';
                    for (int j = 0; j < strlen(buffer_input); j++){
                        const char *morse_code = char_to_morse(buffer_input[j]);
                        if (morse_code == NULL) continue;
                        int k = 0;
                        while (morse_code[k] != '\0' && pos < BUFFER_MORSE -2){
                            buffer_output[pos++] = morse_code[k++];
                        }
                        if (pos < BUFFER_MORSE - 1 && morse_code[k-1] != ' ') {
                            buffer_output[pos++] = ' ';
                        }
                        buffer_output[pos] = '\0';
                        
                    }
                    if (pos > 0){
                        fprintf(output_stream, "%s\n", buffer_output);
                        //fflush(output_stream);
                    } 
                    }
                fclose(file);
                }
            else {
                fprintf(stderr, "Error when trying to open file%s\n", argv[i]);
            }
            }
        }
}

    
/*
void normal_text_to_morse(){
}

void pipe_text_to_morse(){

}
*/
const char *char_to_morse(char c){
    c = toupper(c);
    if (c == '\n' || c == '\r')
    {
        c = '\0';
        return NULL; //signalisiert string Ende
    }
    if (c == ' ') return "  ";
    for (int i = 0; morse_table[i].character != '\0'; i++){
        if (morse_table[i].character == c){
            //printf("\n%s", morse_table[i].morse_text);
            return morse_table[i].morse_text;
        }
}
    return "*";

}
    

