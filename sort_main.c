// 정렬 알고리즘의 실행 시간을 측정하는 코드


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_algorithms.h"

// 정렬 알고리즘은 데이터 크기 별 5개이상의 입력 데이터에 대한 실행시간 측정*
#define TEST_COUNT 5

int main() {

    // // 테스트할 데이터 크기들 세 개 "일단 출력되는지 확인하려고 만 단위부터 함!! 바꿔야함!!"
    // int sizes[] = {10000, 50000, 100000};
    // int num_sizes = 3;

    while (1)
    {
        clock_t start, end;

        int size;
        printf("\nEnter the size of the array to sort:(0 to exit) ");
        scanf("%d", &size);

        if (size == 0) {
            printf("Exiting...\n");
            break;
        }

        // random 함수 초기화
        srand(time(0));

        int* arr = (int*)malloc(sizeof(int) * size);

        if (arr == NULL) {
            printf("memory allocation failed\n");
            return 1;
        }

        // random 함수 데이터 생성
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100000;
        }

        start = clock();
        insertion(arr, size);
        end = clock();
        double insertion_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\ninsertion sorted array:\n");
        //print_array(arr, size);
        printf("Insertion sort time: %lf seconds\n", insertion_time);

        start = clock();    
        selection(arr, size);
        end = clock();
        double selection_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nselection sorted array:\n");
        //print_array(arr, size);
        printf("Selection sort time: %lf seconds\n", selection_time);

        start = clock();
        bubble(arr, size);
        end = clock();
        double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;
        
        printf("\nbubble sorted array:\n");
        //print_array(arr, size);
        printf("Bubble sort time: %lf seconds\n", bubble_time);

        free(arr);
    }
    
    // // 각 데이터 크기마다 반복
    // for (int s = 0; s < num_sizes; s++) {

    //     int n = sizes[s];

    //     // 동적 배열 생성
    //     int *original = (int*)malloc(sizeof(int) * n);
    //     int *arr1 = (int*)malloc(sizeof(int) * n);
    //     int *arr2 = (int*)malloc(sizeof(int) * n);
    //     int *arr3 = (int*)malloc(sizeof(int) * n);

    //     // 메모리 할당 실패 확인
    //     if (original == NULL || arr1 == NULL || arr2 == NULL || arr3 == NULL) {
    //         printf("memory allocation failed\n");
    //         return 1;
    //     }

    //     // 시간 측정을 위한 변수들
    //     clock_t start, end;

    //     double bubble_total = 0;
    //     double insertion_total = 0;
    //     double selection_total = 0;


    //     // 같은 크기로 5번 반복
    //     for (int t = 0; t < TEST_COUNT; t++) {

    //         // random 함수 데이터 생성
    //         for (int i = 0; i < n; i++) {
    //             original[i] = rand() % 100000;
    //         }

    //         // 배열 복사 : 동일한 입력 데이터를 각 정렬 알고리즘에 적용하기 위해
    //         copy_array(original, arr1, n);
    //         copy_array(original, arr2, n);
    //         copy_array(original, arr3, n);

    //         // Bubble sort 시간 측정
    //         start = clock();
    //         bubble(arr1, n);
    //         end = clock();
    //         bubble_total += (double)(end - start) / CLOCKS_PER_SEC;

    //         // Insertion sort 시간 측정
    //         start = clock();
    //         insertion(arr2, n);
    //         end = clock();
    //         insertion_total += (double)(end - start) / CLOCKS_PER_SEC;

    //         // Selection sort 시간 측정
    //         start = clock();
    //         selection(arr3, n);
    //         end = clock();
    //         selection_total += (double)(end - start) / CLOCKS_PER_SEC;
    //     }

    //     // 평균 실행 시간 계산
    //     double bubble_avg = bubble_total / TEST_COUNT;
    //     double insertion_avg = insertion_total / TEST_COUNT;
    //     double selection_avg = selection_total / TEST_COUNT;

    //     // 결과 출력
    //     printf("=====================================\n");
    //     printf("data size: %d\n", n);
    //     printf("Bubble average time: %f seconds\n", bubble_avg);
    //     printf("Insertion average time: %f seconds\n", insertion_avg);
    //     printf("Selection average time: %f seconds\n", selection_avg);
    //     printf("\n");

    //     // 동적 메모리 해제(malloc으로 할당한 메모리는 free로 해제해야함!!)
    //     free(original);
    //     free(arr1);
    //     free(arr2);
    //     free(arr3);
    // }

    return 0;
}