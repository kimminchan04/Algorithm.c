#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int* x, int* y) {
    int t = * x;
    * x = * y;
    * y = t;
} 
void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int e = 0;
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
                e++;
            }
        }
        if (e == 0) {
            break;
        }
    }
}
void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}
void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}
void shell(int arr[], int n) {
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i - h; j >= 0 && arr[j] > temp; j -= h) {
                arr[j + h] = arr[j];
            }
            arr[j + h] = temp;
        }
    }
}
void quick(int arr[], int left, int right) {
    int pl = left;
    int pr = right;
    int x = arr[(pl + pr) / 2];
    do {
        while (arr[pl] < x) {
            pl++;
        }
        while (arr[pr] > x) {
            pr--;
        }
        if (pl <= pr) {
            swap(&arr[pl], &arr[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    if (left < pr) {
        quick(arr, left, pr);
    }
    if (pr < right) {
        quick(arr, pl, right);
    }
}
int* buff;
void __mergesort(int arr[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        int p = 0;
        int i;
        int j = 0;
        int k = left;
        __mergesort(arr, left, center);
        __mergesort(arr, center + 1, right);
        for (i = left; i <= center; i++) {
            buff[p++] = arr[i];
        }
        while (i <= right && j < p) {
            arr[k++] = (buff[j] <= arr[i]) ? buff[j++] : arr[i++];
        }
        while (k < p) {
            arr[k++] = buff[j++];
        }
    }
}
int mergesort(int arr[], int n) {
    if ((buff = calloc(n, sizeof(int))) == NULL) {

        return -1;
    }
    __mergesort(arr, 0, n - 1);
    free(buff);

    return 0;
}
void downheap(int arr[], int left, int right) {
    int temp = arr[left];
    int child;
    int parent;
    for (parent = left; parent < (right + 1) / 2; parent = child) {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && arr[cr] > arr[cl]) ? cr : cl;
        if (temp >= arr[child]) {
            break;
        }
        arr[parent] = arr[child];
    }
    arr[parent] = temp;
}
void heapsort(int arr[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        downheap(arr, i, n - 1);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        downheap(arr, 0, i - 1);
    }
}
void counting(int arr[], int n, int max) {
    int* f = calloc(max + 1, sizeof(int));
    int* b = calloc(n, sizeof(int));
    for (int i = 0; i <= max; i++) {
        f[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        f[arr[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        f[i] += f[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        b[--f[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = b[i];
    }
    free(b);
    free(f);
}
int main() {
    srand(time(NULL));
    int length[] = {10000, 20000, 30000, 40000, 50000};
    for (int i = 0; i < 5; i++) {
        int* a = malloc(length[i] * sizeof(int)); 
        for (int j = 0; j < length[i]; j++) {
            a[j] = rand() % 1000;
        }
        int* arr = malloc(length[i] * sizeof(int));
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start1 = clock();
        bubble(arr, length[i]);
        clock_t end1 = clock();
        double time1 = (double) (end1 - start1) / CLOCKS_PER_SEC * 1000;
        printf("Bubble, %d: %.2fms\n", length[i], time1);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start2 = clock();
        selection(arr, length[i]);
        clock_t end2 = clock();
        double time2 = (double) (end2 - start2) / CLOCKS_PER_SEC * 1000;
        printf("Selection, %d: %.2fms\n", length[i], time2);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start3 = clock();
        insertion(arr, length[i]);
        clock_t end3 = clock();
        double time3 = (double) (end3 - start3) / CLOCKS_PER_SEC * 1000;;
        printf("Insertion, %d: %.2fms\n", length[i], time3);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start4 = clock();
        shell(arr, length[i]);
        clock_t end4 = clock();
        double time4 = (double) (end4 - start4) / CLOCKS_PER_SEC * 1000;;
        printf("Shell, %d: %.2fms\n", length[i], time4);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start5 = clock();
        quick(arr, 0, length[i] - 1);
        clock_t end5 = clock();
        double time5 = (double) (end5 - start5) / CLOCKS_PER_SEC * 1000;;
        printf("Quick, %d: %.2fms\n", length[i], time5);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start6 = clock();
        mergesort(arr, length[i]);
        clock_t end6 = clock();
        double time6 = (double) (end6 - start6) / CLOCKS_PER_SEC * 1000;;
        printf("Merge, %d: %.2fms\n", length[i], time6);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start7 = clock();
        heapsort(arr, length[i]);
        clock_t end7 = clock();
        double time7 = (double) (end7 - start7) / CLOCKS_PER_SEC * 1000;;
        printf("Heap, %d: %.2fms\n", length[i], time7);
        memcpy(arr, a, length[i] * sizeof(int));
        clock_t start8 = clock();
        counting(arr, length[i], 1000);
        clock_t end8 = clock();
        double time8 = (double) (end8 - start8) / CLOCKS_PER_SEC * 1000;;
        printf("Counting, %d: %.2fms\n", length[i], time8);
    }

    return 0;
} 