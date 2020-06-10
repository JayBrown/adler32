/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  adler32 calc program
 *
 *        Version:  1.0.1
 *        Created:  02/27/2014 12:22:10 PM
 *       Revision:  06/10/2020 (Joss Brown)
 *       Compiler:  gcc
 *
 *         Author:  Darwin
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t fadler32(FILE *fp);

int main(int argc, char **argv)
{
  if(argc < 2) {
    printf("v1.0.1rev - usage: %s <PATH>\n", argv[0]);
    exit(1);
  }

  FILE *fp;
  fp = fopen(argv[1], "r");

  if(fp != NULL) {
    printf("%x\n", fadler32(fp));
    fclose(fp);
    return 0;
  }
  else
    fprintf(stderr, "Error: file doesn't exist!\n");

  return 1;
}

uint32_t fadler32(FILE *fp)
{
  int i;
  int c;
  uint32_t a = 1, b = 0;

  while((c = fgetc(fp)) != EOF) {
    a = (a + c) % 65521;
    b = (b + a) % 65521;
  }

  return (b << 16) | a;
}
