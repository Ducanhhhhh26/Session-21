#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char ch;

    sourceFile = fopen("bt01.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file bt01.txt de doc!\n");
        return 1;
    }

    destinationFile = fopen("bt06.txt", "w");
    if (destinationFile == NULL) {
        printf("Khong the mo file bt06.txt de ghi!\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("Noi dung da duoc sao chep tu bt01.txt sang bt06.txt thanh cong!\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

