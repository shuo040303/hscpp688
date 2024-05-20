#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {
    FILE* file;
    char text[100];

    // 打开文件
    file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("无法打开文件。\n");
        return 1;
    }

    printf("请输入文本：");
    fgets(text, sizeof(text), stdin);

    // 写入文本到文件
    fprintf(file, "%s", text);

    // 关闭文件
    fclose(file);

    printf("文本已成功写入文件。\n");

    return 0;
}
