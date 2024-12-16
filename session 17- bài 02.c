#include <stdio.h>
int main() {
    char str[100];
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: {
                printf("Nhap vao chuoi: ");
                scanf("%s", str);  // Nhap chuoi voi ki tu dau tien
                break;
            }
            case 2: {
                printf("Chuoi ban da nhap: %s", str);  // In chuoi ra man hinh
                break;
            }
            case 3: {
                int count = 0;
                char *ptr = str;
                while (*ptr) {
                    if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
                        count++;  // Dem so chu cai
                    }
                    ptr++;
                }
                printf("So luong chu cai trong chuoi: %d\n", count);
                break;
            }
            case 4: {
                int count = 0;
                char *ptr = str;
                while (*ptr) {
                    if (*ptr >= '0' && *ptr <= '9') {
                        count++;  // Dem so chu so
                    }
                    ptr++;
                }
                printf("So luong chu so trong chuoi: %d\n", count);
                break;
            }
            case 5: {
                int count = 0;
                char *ptr = str;
                while (*ptr) {
                    if (!((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9') || *ptr == ' ')) {
                        count++;  // Dem so ky tu dac biet
                    }
                    ptr++;
                }
                printf("So luong ky tu dac biet trong chuoi: %d\n", count);
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);
    return 0;
}
