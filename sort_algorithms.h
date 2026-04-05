#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

// 배열을 이용하는 정렬 알고리즘 구현을 위한 함수 선언
// 주어진 입력 데이터의 크기에 무관하게 사용할 수 있도록 설계

// 배열 출력 함수
void print_array(int arr[], int n);

// // 배열 복사 함수: 동일한 입력 데이터를 유지하기 위해
// void copy_array(int source[], int dest[], int n);

// Bubble sort algorithm
void bubble(int arr[], int n);

// Insertion sort algorithm
void insertion(int arr[], int n);

// Selection sort algorithm
void selection(int arr[], int n);

#endif