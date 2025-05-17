
typedef enum {
    INPUT_DEFAULT,     //encode
    INPUT_PIPE,      
    INPUT_FILE
} InputSource;

int is_pipe_input();
int is_direct_input();
int is_file_input();

int input_source()
   