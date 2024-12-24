#include <stdio.h>

int main() {
    FILE *fptr;
    int n;
    char line[100];

    fptr = fopen("bt05.txt", "w");
    if (fptr == NULL) {
        printf("Khong the mo file de ghi!\n");
        return 1;
    }

    printf("Nhap so dong: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(line, sizeof(line), stdin);
        fprintf(fptr, "%s", line);
    }

    fclose(fptr);

    fptr = fopen("bt05.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file de doc!\n");
        return 1;
    }

    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line);
    }

    fclose(fptr);

    return 0;
}

