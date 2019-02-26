#define BUFFER_SIZE 2048 

#include "utils.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void exitHandler() {
    printf("\x1B[32m" "\nExiting...\n" "\x1B[0m");
    exit(0);
}


int main(int argc, const char **argv) {
    signal(SIGINT, exitHandler);

    char i[BUFFER_SIZE];
    printf("\x1B[32m" "Type Ctrl-C to exit.\n" "\x1B[0m");
    while (1) {
        printf("\x1B[31m" ">> " "\x1B[0m");
        fgets(i, BUFFER_SIZE, stdin);
        /* char* trimmed_string = trimwhitespace(strdup(i)); */
        /* int counted_tokens = count_tokens(trimmed_string); */

        if(strncmp(i, "cd", 2) == 0){
          prep(i, "cd");
        } else if (strncmp(i, "dir", 3) == 0){
          prep(i, "ls");
        } else if (strncmp(i, "type", 4) == 0){
          prep(i, "cat");
        } else if (strncmp(i, "del", 3) == 0){
          prep(i, "rm");
        } else if (strncmp(i, "ren", 3) == 0){
          prep(i, "mv");
        } else if (strncmp(i, "copy", 4) == 0){
          prep(i, "cp");
        } else{
          printf("\x1B[31m" "Did not recognize that command. Try again.\n" "\x1B[0m");
        }
    }
}
