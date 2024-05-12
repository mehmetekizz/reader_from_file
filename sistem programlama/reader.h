#ifndef READER_H
#define READER_H

 

extern const char *fname;

 

int read_line(FILE *file, int lineno, char buffer[]);

int read_xcol(const char *row, int colno, char buffer[]);

 

#endif