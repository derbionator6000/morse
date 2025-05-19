#ifndef MORSE_H
#define MORSE_H

//consists of for example char 'A' ans string ".-" 

typedef struct{
    const char character;
    const char *morse_text;
} MorsePack;

extern const MorsePack morse_table[];

typedef struct{
    //configs
    int encode_mode;       /* 1 = encode, 0 = decode */
    int slash_wordspacer;  /* 1 = verwende "/" als Worttrenner */
    char *input_filename;  /* Eingabedateiname oder NULL für stdin */
    char *output_filename; /* Ausgabedateiname oder NULL für stdout */
    
    //status flags
    int input_is_pipe;     /* 1 = Eingabe kommt von Pipe, 0 = nicht */
    int input_is_file;     /* 1 = Eingabe kommt aus Datei, 0 = nicht */
    int input_is_terminal; /* 1 = Eingabe kommt direkt vom Terminal, 0 = nicht */
    
    int output_is_pipe;    /* 1 = Ausgabe geht zu einer Pipe, 0 = nicht */
    int output_is_file;    /* 1 = Ausgabe geht in eine Datei, 0 = nicht */
    int output_is_terminal;/* 1 = Ausgabe geht direkt ans Terminal, 0 = nicht */
} MorseConfig;
 

 //MORSE 
 #define MORSE_CHAR_SEPERATOR ' '
 #define MORSE_WORD_SEPERATOR "   "

 //FLAGS
 #define MORSE_OK 0
 #define MORSE_ERROR_FILE_NOT_FOUND 1
 #define MORSE_ERROR_INVALID_ARGS 2
 #define MORSE_CHAR_NOT_FOUND '*'

//MORSE FUNCTIONS
void file_text_to_morse(char *argv[], int argc, FILE *output_file);
const char *char_to_morse(char c);
void standard_text_to_morse(char *str);
void pipe_text_to_morse();
void normal_text_to_morse();

#endif