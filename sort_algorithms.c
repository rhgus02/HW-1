#include <stdio.h>
#include "sort_algorithms.h"

// 배열 출력
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// // 배열 복사 함수 :동일한 입력 데이터를 유지하기 위해
// void copy_array(int source[], int dest[], int n) {
//     for (int i = 0; i < n; i++) {
//         dest[i] = source[i];
//     }
// }


//Problem 1 주어진 입력 데이터의 크기에 무관한 정렬 함수의 구현 함수들
// Bubble sort algorithm : 두 인접한 값을 비교하여 정렬 순서에 따라 교환*
// 매 반복마다 가장 큰값 또는 작은 값을 갖는 값을 선택하여 위치시킴*
// 큰 값을 뒤로 이동시키는 방식
void bubble(int* arr, int size) {
    int i, j, val;

    for (i = size-1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                val = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = val;
            }
        }
    }
}


// Insertion sort algorithm : arr[i]를 정렬되어 있는 배열의 왼쪽 부분에 삽입*
void insertion(int* arr, int size) {
    int i, j, temp;

    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i;

        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }

        arr[j] = temp;
    }
}


// Selection sort algorithm : 배열에서 가장 작은 값을 선택하여 앞에 놓는 방식
void selection(int *arr, int size) {
    int i, j, least, val;
    

    for (i = 0; i < size - 1; i++) {
        least = i;

        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[least])
                least = j;
        }

        val = arr[least];
        arr[least] = arr[i];
        arr[i] = val;
    }
}