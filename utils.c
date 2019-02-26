#define BUFFER_SIZE 2048

#include "utils.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FILE* fp;

char** split_string(char* target, char** buffer, int amount){
    int i = 0;
    char *p = strtok (target, " \n\t");

    while (p != NULL)
    {
        buffer[i++] = p;
        p = strtok (NULL, " \n\t");
    }

    /* for (i = 0; i < 3; ++i) { */
    /*   printf("%s\n", array[i]); */
    /* } */

    return buffer;
}

int count_tokens(char* target){
    int i = 0;
    char *p = strtok (target, " \n\t");

    while (p != NULL)
    {
        i++;
        p = strtok (NULL, " \n\t");
    }
    return i;
}

char* trimwhitespace(char *str)
{
  char *end;
  while(isspace((unsigned char)*str)) {
    str++;
  }

  if(*str == 0) {
    return str;
  }

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) {
    end--;
  }

  end[1] = '\0';
  return str;
}

void runcommand(char* command){
  fp = popen(command, "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* printf("%s", command); */
  char buffer[2048];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }
  printf("\n");

  pclose(fp);
}

void prep(char* command, char* translation){
  char* start = strstr(command," ");
  char i[BUFFER_SIZE];

  strcpy(i, translation);
  strcat(i, start);
  strcat(i, "\0");

  if(strncmp(i, "cd", 2) != 0) {
    runcommand(i);
  } else{
    /* printf("%s\n", trimwhitespace(start)); */
    chdir(trimwhitespace(start));
  }
}
