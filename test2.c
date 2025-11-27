#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    int* ptr = arr; // 배열의 첫 번째 요소를 가리키는 포인터

    for (int i = 0; i < 10; i++) {
        sum = sum + *ptr; // 포인터가 가리키는 값을 더함
        ptr++; // 다음 요소로 포인터 이동
    }

    printf("배열 원소의 합: %d\n", sum);

    return 0;
}

