#include <stdio.h>
#include <string.h>
#include "reader.h"

/*
    Program: reader.c
    Açıklama: Dosya üzerindeki verileri bir tane matrise yazdık ve matris üzerinde tutulan verileri kullanıcıdan satır sütun numarası alarak 
    istenilen veriyi ekrana verebildik.
    Yazar: [Mehmet Eren Ekiz] 
    Date: 03.03.2023 
*/


const char *fname = "Food_contents_2019.csv";
int read_line(FILE *file, int lineno, char buffer[]) {
    fseek(file, 0, SEEK_SET); // Dosya başına git
    int current_line = 1;

    while (current_line < lineno) {
        if (fgets(buffer, 1024, file) == NULL) {
            return -1; // Satır bulunamadı
        }
        current_line++;
    }

    if (fgets(buffer, 1024, file) != NULL) {
        return strlen(buffer); // Satır uzunluğunu return et
    } else {
        return -1; // Satır bulunamadı
    }
}

int read_xcol(const char *row, int colno, char buffer[]) {

    int current_col = 1;
    const char *token = strtok((char *)row, ",");
    while (token != NULL) {

        if (current_col == colno) {
            strcpy(buffer, token); // Sütunu buffer'a kopyala
            return strlen(buffer); // Sütun uzunluğunu return et
        }
        token = strtok(NULL, ",");
        current_col++;
    }
    return -1; // Sütun bulunamadı
}