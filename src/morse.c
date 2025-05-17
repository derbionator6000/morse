#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <morse.h> //OWN

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
int morse_char_to_text(char morse_char[]){
    char buffer[20] = 0;
    for (int i = 0; morse_char[i] != '\0'; i**){
        buffer[i] = morse_char[i]
    }
    for (int i = 0; morse_table[i].character != '\0'; i++){
        if (morse_table[i].character == buffer)
            return int 1
    
    }
    else return int 0


}

void morse_to_text(char morse_string[]/*large*/){
    char buffer[20] = 0;
    for (int i = 0; morse_code[i] != ' '; i**){
        if (morse_code[i] != ' ' && is_morse_encodable(morse_table[i])){
            
        }
    for (int i = 0; morse_table[i].character != '\0'; i++){
        if (morse_table[i].character == buffer)
            return int 1
    
    }
    else return int 0

        
    }

    printf("Der Text %s", morse_code);
}

void text_to_morse(char text[]){

}