#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Ham menu chinh
void menu();
// Ham kiem tra so nguyen to
bool isPrime(int num);
// Ham tim kiem phan tu
void searchElement(int *arr, int size, int target);
// Ham in mang
void printArray(int *arr, int size);
// Ham sap xep mang tang dan
void sortArray(int *arr, int size, bool ascending);
// Ham dao nguoc mang
void reverseArray(int *arr, int size);

int main() {
    int *arr = NULL; // Con tro luu mang
    int size = 0, choice;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int)); // Cap phat bo nho dong cho mang
                if (arr == NULL) {
                    printf("Khong the cap phat bo nho!\n");
                    return -1;
                }
                for (int i = 0; i < size; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("Cac phan tu la so chan:\n");
                for (int i = 0; i < size; i++) {
                    if (arr[i] % 2 == 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < size; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            case 4: {
                printf("Mang sau khi dao nguoc:\n");
                reverseArray(arr, size);
                printArray(arr, size);
                break;
            }
            case 5: {
                int sortChoice;
                printf("1. Tang dan\n2. Giam dan\nChon: ");
                scanf("%d", &sortChoice);
                if (sortChoice == 1) {
                    sortArray(arr, size, true);
                } else if (sortChoice == 2) {
                    sortArray(arr, size, false);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                printf("Mang sau khi sap xep:\n");
                printArray(arr, size);
                break;
            }
            case 6: {
                int target;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                searchElement(arr, size, target);
                break;
            }
            case 7: {
                printf("Thoat chuong trinh.\n");
                free(arr); // Giai phong bo nho truoc khi thoat
                return 0;
            }
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (1);
}

// Ham in menu
void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu la so chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("6. Tim kiem phan tu trong mang\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham kiem tra so nguyen to
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Ham tim kiem phan tu
void searchElement(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Phan tu %d xuat hien tai vi tri %d\n", target, i);
            return;
        }
    }
    printf("Phan tu %d khong co trong mang\n", target);
}

// Ham in mang
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham sap xep mang
void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham dao nguoc mang
void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

