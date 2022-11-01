#include <stdio.h>
#include <stdlib.h>

// Q. 실제로 해보니까 data에 아무것도 fread안되는데?
int main() {
    FILE* file = fopen("test.txt", "r");
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    // printf("%d", size);
    char* data = (char*)malloc(1 * size);
    // char* data = (char*)malloc(size+1);
    fread(data, size, 1, file);
    printf("%c", *data);
    fclose(file);
}

// <파일 읽기>
//
//
// int main() {
//     FILE* file = fopen("test.txt", "r");
//     if (file == NULL) {
//         return -1;
//     }

//     fseek(file, 0, SEEK_END);
//     int size = ftell(file);
//     printf("%d", size);
// }