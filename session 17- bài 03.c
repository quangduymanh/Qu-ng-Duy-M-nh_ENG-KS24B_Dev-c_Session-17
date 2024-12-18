#include <stdio.h>
#include <string.h>
int main() {
    char str[1000], str2[1000];
    int choice;
    int continueProgram = 1;
    while (continueProgram) {
        printf("\nMENU\n1. Nhap vao chuoi\n2. In ra chuoi dao nguoc\n3. Dem so luong tu trong chuoi\n4. So sanh chuoi voi chuoi ban dau\n5. In hoa tat ca chu cai trong chuoi\n6. Nhap vao chuoi khac va them vao chuoi ban dau\n7. Thoat\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap vao chuoi: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                break;
            case 2:
                {
                    int len = strlen(str);
                    for (int i = 0; i < len / 2; i++) {
                        char temp = str[i];
                        str[i] = str[len - i - 1];
                        str[len - i - 1] = temp;
                    }
                    printf("Chuoi dao nguoc: %s\n", str);
                }
                break;
            case 3:
                {
                    int count = 0, inWord = 0;
                    char *ptr = str;
                    while (*ptr) {
                        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
                            inWord = 0;
                        } else if (!inWord) {
                            inWord = 1;
                            count++;
                        }
                        ptr++;
                    }
                    printf("So luong tu trong chuoi: %d\n", count);
                }
                break;
            case 4:
                printf("Nhap vao chuoi khac de so sanh: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                if (strlen(str2) < strlen(str)) {
                    printf("Chuoi nay ngan hon chuoi ban dau.\n");
                } else if (strlen(str2) > strlen(str)) {
                    printf("Chuoi nay dai hon chuoi ban dau.\n");
                } else {
                    printf("Hai chuoi co do dai bang nhau.\n");
                }
                break;
            case 5:
                {
                    char *ptr = str;
                    while (*ptr) {
                        if (*ptr >= 'a' && *ptr <= 'z') {
                            *ptr = *ptr - 'a' + 'A';
                        }
                        ptr++;
                    }
                    printf("Chuoi in hoa: %s\n", str);
                }
                break;
            case 6:
                printf("Nhap vao chuoi khac de them vao chuoi ban dau: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcat(str, str2);
                printf("Chuoi moi: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                continueProgram = 0;
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
