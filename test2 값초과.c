#include <stdio.h>
#include <limits.h>

int main() {
    int k;

    printf("정수의 k의 최대값: %d\n", INT_MAX);
    printf("정수의 k의 최소값: %d\n", INT_MIN);

    // 정수 입력 받기
    printf("정수를 입력하세요: ");
    scanf("%d", &k);

    // 입력값이 범위를 벗어나는지 확인
    if (k > INT_MAX || k < INT_MIN) {
        printf("입력값이 정수형의 범위를 벗어납니다. 프로그램을 종료합니다.\n");
        return 1; // 비정상적인 종료를 나타내는 값 반환
    }

    // 입력값이 정상 범위 내일 경우 계속 진행
    printf("입력한 정수: %d\n", k);

    return 0; // 정상적인 종료를 나타내는 값 반환
}
