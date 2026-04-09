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
    return 0;
}
