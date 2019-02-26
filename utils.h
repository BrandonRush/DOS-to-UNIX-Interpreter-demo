#ifndef UTILS_H_
#define UTILS_H_

char** split_string(char* target, char** buffer, int amount);

int count_tokens(char* target);

char* trimwhitespace(char *str);

void runcommand(char* command);

void prep(char* command, char* translation);

#endif 
