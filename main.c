/*
    Program: main.c
    Açıklama: Dosya üzerindeki satır ve sütunları okuduk ve kayıt ettik.
    Yazar: [Mehmet Eren Ekiz] 
    Date: 03.03.2023 
*/

#include <stdio.h>
#include "reader.h"

int main() {

    FILE *dosya = fopen(fname, "r");

    if (dosya == NULL) {

        printf("Dosya acilamadi!\n");

        return 1;
    }

 
    int lineno, colno;
    char buffer[1024];

    printf("Merhaba programa hoşgeldiniz\n");
    printf("Satir ve sutun numaralarini girin: ");
    scanf("%d %d", &lineno, &colno);

    int len = read_line(dosya, lineno, buffer);
    if (len == -1) {
        printf("Gecersiz satir numarasi!\n");
        fclose(dosya);
        return 1;
    }

    len = read_xcol(buffer, colno, buffer);
    if (len == -1) {
        printf("Gecersiz sutun numarasi!\n");
        fclose(dosya);
        return 1;
    }

    printf("%s\n", buffer);
    fclose(dosya);
    return 0;

}