#include <stdio.h>

int main() {
    int n, choice, element;
    int *arr = 0;
    int continueProgram = 1;
    while (continueProgram) {
        printf("\nmenu\n1. nhap vao so phan tu va tung phan tu\n2. in ra cac phan tu la so chan\n3. in ra cac phan tu la so nguyen to\n4. dao nguoc mang\n5. sap xep mang\n1. tang dan\n2. giam dan\n6. nhap vao mot phan tu va tim kiem phan tu trong mang\n7. thoat\nnhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("nhap vao so phan tu: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                if (arr == 0) {
                    printf("khong du bo nho!\n");
                    return -1;
                }
                printf("nhap vao tung phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("phan tu %d: ", i + 1);
                    scanf("%d", arr + i);
                }
                break;
            case 2:
                printf("cac so chan: ");
                for (int i = 0; i < n; i++) {
                    if (*(arr + i) % 2 == 0) {
                        printf("%d ", *(arr + i));
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("cac so nguyen to: ");
                for (int i = 0; i < n; i++) {
                    int isPrime = 1;
                    if (*(arr + i) <= 1) isPrime = 0;
                    for (int j = 2; j * j <= *(arr + i); j++) {
                        if (*(arr + i) % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) {
                        printf("%d ", *(arr + i));
                    }
                }
                printf("\n");
                break;
            case 4:
                for (int i = 0; i < n / 2; i++) {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + n - i - 1);
                    *(arr + n - i - 1) = temp;
                }
                printf("mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            case 5:
                printf("chon loai sap xep:\n1. tang dan\n2. giam dan\nnhap lua chon: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (*(arr + i) > *(arr + j)) {
                                int temp = *(arr + i);
                                *(arr + i) = *(arr + j);
                                *(arr + j) = temp;
                            }
                        }
                    }
                } else if (choice == 2) {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (*(arr + i) < *(arr + j)) {
                                int temp = *(arr + i);
                                *(arr + i) = *(arr + j);
                                *(arr + j) = temp;
                            }
                        }
                    }
                }
                printf("mang sau khi sap xep: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", *(arr + i));
                }
                printf("\n");
                break;
            case 6:
                printf("nhap vao phan tu can tim: ");
                scanf("%d", &element);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (*(arr + i) == element) {
                        printf("phan tu %d da duoc tim thay tai vi tri %d.\n", element, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("phan tu %d khong tim thay trong mang.\n", element);
                }
                break;
            case 7:
                printf("thoat chuong trinh.\n");
                free(arr);
                continueProgram = 0;
                break;
            default:
                printf("lua chon khong hop le. vui long chon lai.\n");
        }
    }
    return 0;
}
