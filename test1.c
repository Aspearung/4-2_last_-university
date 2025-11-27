#include <stdio.h>

int main(void){

    char a[5] = "apple";
    char b[5];
    int i;
    int j = 0;

    for(i=0 ; i < 5; i++){
        printf("%c",a[i]);
    }
    printf("\n");

    for(i=5; i > 0; i--){
        a[i] = b[j];
        j++;
    }

    for(i=0 ; i < 5; i++){
        printf("%c",b[i]);
    }
}
