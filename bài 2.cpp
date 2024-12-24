#include <stdio.h>

int main() {
    FILE *fptr;
    char firstChar;

     fptr= fopen("bt01.txt", "r");

    if (fptr == NULL) {
        printf("Khong the mo file de doc!\n");
        return 1;
    }

    firstChar = fgetc(fptr);

        printf("Ky tu dau tien trong file la: %c\n", firstChar);


    fclose(fptr);

    return 0;
}

