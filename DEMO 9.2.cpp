#include <stdio.h>
#include <string.h>

struct book {
    char bookID[20];
    char title[30];
    char author[30];
    float price;
    char category[30];
};

void addBooks(struct book books[], int *n);
void saveBooks(struct book books[], int n);
void loadBooks(struct book books[], int *n);
void displayBooks(struct book books[], int n);

int main() {
    int choice;
    struct book books[100];
    int n = 0;

    do {
        printf("\t   MENU\n");
        printf("1: Nhap so luong va thong tin sach\n");
        printf("2: Luu thong tin vao file \n");
        printf("3: Lay thong tin sach tu file\n");
        printf("4: Hien thi thong tin sach\n");
        printf("5: Thoat\n");
        printf("Moi ban nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBooks(books, &n);
                break;
            case 2:
                saveBooks(books, n);
                break;
            case 3:
                loadBooks(books, &n);
                break;
            case 4:
                displayBooks(books, n);
                break;
            case 5:
                printf("Ban da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addBooks(struct book books[], int *n) {
    printf("Moi ban nhap so luong sach: ");
    scanf("%d", n);
    getchar();

    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);

        printf("Ma sach: ");
        fgets(books[i].bookID, sizeof(books[i].bookID), stdin);
        books[i].bookID[strcspn(books[i].bookID, "\n")] = 0;

        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;

        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        printf("Gia sach: ");
        scanf("%f", &books[i].price);
        getchar();

        printf("The loai: ");
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = 0;
    }
}

void saveBooksToFileBinary(struct book books[], int n) {
    FILE *file = fopen("books.bin", "wb");
    if (file == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }

    fwrite(books, sizeof(struct book), n, file);

    fclose(file);
    printf("Thong tin sach da duoc luu vao file books.bin\n");
}

void loadBooksFromFileBinary(struct book books[], int *n) {
    FILE *file = fopen("books.bin", "rb");
    if (file == NULL) {
        printf("Khong mo duoc file de doc!\n");
        return;
    }

    *n = fread(books, sizeof(struct book), 100, file);

    fclose(file);
    printf("Thong tin sach da duoc lay tu file books.bin\n");
}

void displayBooks(struct book books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %s\n", books[i].bookID);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia sach: %.2f\n", books[i].price);
        printf("The loai: %s\n\n", books[i].category);
    }
}

