#include <stdio.h>
#include<string.h>

struct sinhVien{
    int id;
    char name[100];
    int age;
};

int main() {
    FILE *fptr;
    int size;
    printf("Moi ban nhap so luong sinh vien: ");
    scanf("%d", &size);
    fflush(stdin);
    struct sinhVien sv[size];
    
    for (int i = 0; i < size; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &sv[i].id);
        fflush(stdin);
        printf("Ten: ");
        fgets(sv[i].name, sizeof(sv[i].name), stdin);
        printf("Tuoi: ");
        scanf("%d", &sv[i].age);
    }
    fptr = fopen("students.txt", "w");
    if (fptr == NULL) {
        printf("Khong the mo file");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        fprintf(fptr, "%d %s %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    fclose(fptr);
    printf("Thong tin sinh vien da duoc ghi vao file");
    return 0;
}
