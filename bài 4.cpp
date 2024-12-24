#include <stdio.h>

int main() {
    FILE *fptr;
    char firstLine[100]; 

    fptr = fopen("bt01.txt", "r");

    if (fptr == NULL) {
        printf("Khong the mo file de doc!\n");
        return 1;
    }

    if (fgets(firstLine, sizeof(firstLine), fptr) != NULL) {
        printf("Dong dau tien trong file la: %s", firstLine);
    } else {
        printf("File trong hoac khong the doc dong dau tien!\n");
    }

    fclose(fptr);

    return 0;
}

