#include <stdio.h>

int main() {
    char inputString[1000];
    FILE *fptr;

    printf("Nhap mot chuoi bat ky: ");
    fgets(inputString, sizeof(inputString), stdin);

    fptr = fopen("bt01.txt", "w");

    if (fptr == NULL) {
        printf("Khong the mo file de ghi!\n");
        return 1;
    }

    printf("Gia tri thong tin trong file bt01.txt la %s",inputString); 

    fclose(fptr);

    printf("Chuoi da duoc ghi vao file bt01.txt thanh cong.\n");

    return 0;
}

