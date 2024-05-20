#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// 定义火车时刻表结构体
typedef struct Train {
    char train_num[10];       // 车次
    char start_station[20];   // 始发站
    char end_station[20];     // 终点站
    char start_time[10];      // 发车时间
    char end_time[10];        // 到达时间
    int price;                // 票价
    struct Train* next;       // 指向下一个火车时刻信息的指针
} Train;

// 火车时刻表链表的头指针
Train* head = NULL;

// 从文件中读取火车时刻表信息，返回火车时刻表链表的头指针
Train* readFromFile() {
    Train* p, * q;
    char buffer[100];  // 用于存储每一行数据
    FILE* fp = fopen("hchsk.txt", "r");  // 打开文件用于读取数据

    if (fp == NULL) {  // 如果文件不存在，则返回空指针
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {  // 从文件中读取每一行数据，并创建链表节点
        p = (Train*)malloc(sizeof(Train));
        sscanf(buffer, "%s%s%s%s%d", p->train_num, p->start_station, p->end_station, p->start_time, &p->price);

        p->next = NULL;
        if (head == NULL) {  // 如果链表为空，则将新节点设为链表头
            head = p;
        }
        else {  // 否
            q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }

    fclose(fp);
    return head;
}

void messageinput() {
    Train* p, * q;
    char buffer[100];  // 用于存储每一行数据
    FILE* fp = fopen("hchsk.txt", "a");  // 打开文件用于写入数据

    if (fp == NULL) {
        printf("打开文件失败！\n");
        return;
    }

    printf("请输入车次：");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // 移除换行符
    p = (Train*)malloc(sizeof(Train));
    strcpy(p->train_num, buffer);

    printf("请输入始发站：");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // 移除换行符
    strcpy(p->start_station, buffer);

    printf("请输入终点站：");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // 移除换行符
    strcpy(p->end_station, buffer);

    printf("请输入发车时间：");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // 移除换行符
    strcpy(p->start_time, buffer);

    printf("请输入到达时间：");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // 移除换行符
    strcpy(p->end_time, buffer);

    printf("请输入票价：");
    scanf("%d", &p->price);
    getchar(); // 读取多余的换行符

    p->next = NULL;
    if (head == NULL) {  // 如果链表为空，则将新节点设为链表头
        head = p;
    }
    else {  // 否则将新节点插入到链表尾部
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }

    fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%d\n", p->train_num, p->start_station, p->end_station, p->start_time, p->end_time, p->price); // 将数据写入文件
    fclose(fp);
    printf("火车时刻信息录入成功！\n");
}


void messagelooking() {
    Train* p = readFromFile();  // 读取文件中的火车时刻信息并创建链表

    if (p == NULL) {  // 如果链表为空，说明文件中没有火车时刻信息
        printf("暂无火车时刻信息，请先录入火车时刻信息！\n");
        return;
    }

    printf("请输入您要查询的车次：");
    char trainNum[20];
    scanf("%s", trainNum);

    int flag = 0;  // 标记是否找到了要查询的车次

    // 遍历链表，查找要查询的车次
    while (p != NULL) {
        if (strcmp(p->train_num, trainNum) == 0) {
flag = 1; // 找到了要查询的车次
printf("车次：%s 始发站：%s 终点站：%s 出发时间：%s 到达时间：%s 票价：%d\n",
p->train_num, p->start_station, p->end_station, p->start_time, p->end_time, p->price);
break;
}
p = p->next;
}
if (flag == 0) {
    printf("抱歉，未找到您要查询的车次！\n");
}
}
//统计
void statistics() {
    // 打开文件
    FILE* fp = fopen("hchsk.txt", "r");
    if (fp == NULL) {
        printf("打开文件失败！\n");
        return;
    }

    // 读取文件内容，统计车次数量
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
    }

    // 关闭文件
    fclose(fp);

    // 输出结果
    printf("车次数量为：%d\n", count);
}