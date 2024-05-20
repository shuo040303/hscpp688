#学生信息管理系统
##一.程序总体设计
系统以菜单方式工作，无需密码即可进行操作。
程序整体实现了学生信息的增加、删除、更改、查找、浏览（包括按照学号大小和年龄大小两种排序方式进行浏览）的功能。
程序整体通过链表的数据结构实现。
学生信息统一保存在student.txt文件中，系统工作时学生信息会同步到student.txt文件中。
程序有用户交互的地方都有用户错误输入行为的提示，即系统有一定的纠错能力。


##二.总结
经过这次课程设计，我学到了很多东西：
①巩固和加深了对编程的理解，提高综合运用本课程所学知识的能力。
②培养了我选用参考书，查阅手册及文献资料的能力。培养独立思考，深入研究，分析问题、解决问题的能力。
③经过实际编译系统的分析设计、编程调试，掌握应用软件的分析方法和工程设计方法。
④能够按要求编写课程设计报告书，能正确阐述设计和实验结果，正确绘制系统和程序框图。
这次高级语言程序设计，学生成绩管理系统，让我对高级语言有了进一步的认识。首先，想要学好这门课程，主要在于实践，要通过不断地上机操作才能更好的学习它。
之后，课程设计期间，在调试出现很多错误，很多警告的过程中我的知识也在得到不断地巩固；当你把代码输入电脑，并用编译器将其运行，发现通过不了，再来检查找出问题，这是一件非常辛苦的事情，也很浪费时间。于是在课程设计的时候，我花了好几天的时间来规划与写代码，将要实现的内容分析清楚，才把代码输入电脑。我们觉得写程序，应该先找到该程序中的核心地方，用多种方法来实现该核心，这才可能避免等到发现逻辑上或者编译器不支持上的错误，才来想补救的措施，这样花费时间在想补救措施是很不值得的。也让我学到了很多人生的哲理：懂得怎样去制定计划，怎样去实现这个计划，并掌握了在执行过程中怎样去克服心理上的不良情绪。我们对于高级语言的理解和使用还处在一个初级的阶段，我们要想掌握它，要学习的还很多，同时要懂得创新，许多的编程方法都是人们一步一步总结出来的，要努力拓展自己的思维，努力去寻求新的方法，以创造出更为完善的应用程序。
课程设计是把我们所学的理论知识进行系统的总结并应用于实践的良好机会，有利于加强我们用知识理论来分析实际问题的能力，进而加强了我们对知识认识的实践度，巩固了我们的理论知识，深化了对知识的认识，并为走向社会打下一个良好的基础。


##三.源代码（分两个文件：studentsystem.cpp和singlelist.h）
```C
/*                                            学生信息管理
问题描述:
	学生信息包括：学号，姓名，年龄，性别，出生年月，地址，电话，E-mail等。试设计一学生信息管理系统，使之能提供以下功能：
系统以菜单方式工作
学生信息录入功能（学生信息用文件保存）---输入
学生信息浏览功能---输出
查询、排序功能---算法
按学号查询、按姓名查询、学生信息的删除与修改（可选项）*/


//studentsystem.cpp


#define _CRT_SECURE_NO_WARNINGS
#include"singlelist.h"

void menu();//声明菜单界面函数
void keydown();//声明功能实现函数

struct node* list = NULL;//初始化列表

int main() {
	list = createlist();//创造列表
	readfromfile("student.txt", list);//从txt文件中读取内容

	while (1) {
		menu();//菜单函数
		system("pause");
		system("cls");//清屏
	}
	return 0;
}
//实现菜单界面函数
void menu() {
	printf("************************【学生管理系统】************************\n");
	printf("\t\t\t0.退出系统\n");
	printf("\t\t\t1.增加信息\n");
	printf("\t\t\t2.删除信息\n");
	printf("\t\t\t3.更改信息\n");
	printf("\t\t\t4.查找信息\n");
	printf("\t\t\t5.浏览信息\n");//给出num升序或者age升序的打印，但不改变文本中的顺序
	printf("请输入0到5的数字：");//交互提示
	keydown();//功能函数
}
//实现功能函数
void keydown() {
	int userkey;
	struct student tempdata;//临时数据
	scanf("%d", &userkey);//读取用户输入
	switch (userkey)//实现用户输入选项
	{
	case 0:
		printf("\t\t\t您正在执行【0.退出系统】操作\n");//功能提示
		system("pause");
		exit(0);//退出
		break;
	case 1:
		printf("\t\t\t您正在执行【1.增加信息】操作\n");//功能提示
		printf("请输入姓名，年龄，学号，性别，出生日期，电话，E-mail，家庭住址：");//交互提示
		scanf("%s%d%s%s%s%s%s%s", tempdata.name, &tempdata.age, tempdata.num, tempdata.sex, tempdata.birth, tempdata.tel, tempdata.email, tempdata.addr);//信息输入
		headinsert(list, tempdata);//插入列表（头插法）
		savetofile("student.txt", list);//保存更改到文件
		break;
	case 2:
		printf("\t\t\t您正在执行【2.删除信息】操作\n");//功能提示
		printf("请输入要删除的学生的姓名：");//交互提示
		scanf("%s", tempdata.name);
		deletenodename(list, tempdata.name);//实现列表内容删除
		savetofile("student.txt", list);//保存更改到文件
		break;
	case 3:
		printf("\t\t\t您正在执行【3.更改信息】操作\n");//功能提示
		printf("请输入要修改信息的学生的姓名：");//交互提示
		scanf("%s", tempdata.name);
		if (searchndoename(list, tempdata.name) != NULL) {
			struct node* tempnode = searchndoename(list, tempdata.name);//查找信息
			printf("请输入修改后的学生信息,姓名，年龄，学号，性别，出生日期，电话，E-mail，家庭住址：");//交互提示
			scanf("%s%d%s%s%s%s%s%s", tempnode->data.name, &tempnode->data.age, tempnode->data.num, tempnode->data.sex, tempnode->data.birth,  tempnode->data.tel, tempnode->data.email, tempnode->data.addr);//信息输入
			savetofile("student.txt", list);//保存操作到文件
		}
		else
			printf("未找到想要修改的学生信息!\n");//未找到结果的提示
		break;
	case 4:
		printf("\t\t\t您正在执行【4.查找信息】操作\n");//功能提示
		printf("请输入你想要查找的学生的姓名：");//交互提示
		scanf("%s", tempdata.name);
		if (searchndoename(list, tempdata.name) != NULL) {
			nodeprint(searchndoename(list, tempdata.name));//打印节点
		}
		else
			printf("未找到想要查找的学生信息！\n");//未找到结果的提示
		break;
	case 5:
		printf("\t\t\t您正在执行【5.浏览信息】操作\n");//功能提示
		printf("\t\t\t请选择你想要的排列方式：\n");//交互提示
		printf("\t\t\t1.按照学号大小进行排序\n");
		printf("\t\t\t2.按照年龄大小进行排序\n");
		int userkey2;
		printf("请输入1或2：");//交互提示
		scanf("%d", &userkey2);//用户输入
		switch (userkey2)
		{
		case 1:
			sortlist_by_num(list);//按照学号大小排序
			listprint(list);//打印列表
			break;
		case 2:
			sortlist_by_age(list);//按照年龄大小排序
			listprint(list);//打印列表
			break;
		default:
			printf("\t\t\t您的输入有误！\n");//错误输入
			break;
		}
		break;
	default:
		printf("\t\t\t输入错误，请您重新输入！\n");//错误输入
	}
}

//singlelist.h


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//实现数据结构
struct student {
	char name[20];
	int age;
	char num[10];
	char sex[10];
	char birth[20];
	char tel[20];
	char email[30];
	char addr[20];
};

//定义节点
struct node
{
	struct student data;
	struct node* next;
};
//创建列表
struct node* createlist()
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	headnode->next = NULL;
	return headnode;
};
//创建节点
struct node* createnode(struct student data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
};
//插入节点
void headinsert(struct node* headnode, struct student data) {
	struct node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
}
//查找节点
struct node* searchndoename(struct node* headnode, char* name) {
	struct node* p = headnode->next;
	if (p == NULL) {
		return p;
	}
	else {
		while (strcmp(p->data.name,name)) {
			p = p->next;
			if (p == NULL) {
				return p;
			}
		}
		return p;
	}
}
//删除节点
void deletenodename(struct node* headnode, char* name) {
	struct node* frontnode = headnode;
	struct node* posnode = headnode->next;//要删除的节点
	if (posnode == NULL) {
		printf("没有相关内容可以删除！");
		return;
	}
	else {
		while (strcmp(posnode->data.name ,name))
		{
			frontnode = posnode;
			posnode = posnode->next;
			if (posnode == NULL) {
				printf("未找到要删除的内容");
				return;
			}
		}
		frontnode->next = posnode->next;
		free(posnode);
	}
}
//节点打印
void nodeprint(struct node* tempnode) {
	printf("姓名\t年龄\t学号\t性别\t出生日期\t电话\t\tE-mail\t\t家庭住址\n");
	printf("%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", tempnode->data.name, tempnode->data.age, tempnode->data.num, tempnode->data.sex, tempnode->data.birth, tempnode->data.tel, tempnode->data.email,tempnode->data.addr);
}
//列表打印
void listprint(struct node* headnode) {
	struct node* p = headnode->next;
	printf("姓名\t年龄\t学号\t性别\t出生日期\t电话\t\tE-mail\t\t家庭住址\n");
	while (p)
	{
		printf("%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", p->data.name, p->data.age, p->data.num, p->data.sex, p->data.birth, p->data.tel, p->data.email, p->data.addr);
		p = p->next;
	}
	printf("\n");
}
//根据num进行列表排序
void sortlist_by_num(struct node* headnode) {
	int swapped;
	struct node* p;
	struct node* last = NULL;

	if (headnode == NULL)
		return;

	do {
		swapped = 0;
		p = headnode->next;

		while (p->next != last) {
			if (strcmp(p->data.num, p->next->data.num) > 0) {
				struct student tempdata = p->data;
				p->data = p->next->data;
				p->next->data = tempdata;
				swapped = 1;
			}
			p = p->next;
		}
		last = p;
	} while (swapped);
}
// 根据age进行列表排序
void sortlist_by_age(struct node* headnode) {
	int swapped;
	struct node* p;
	struct node* last = NULL;

	if (headnode == NULL)
		return;

	do {
		swapped = 0;
		p = headnode->next;

		while (p->next != last) {
			if (p->data.age > p->next->data.age) {
				struct student tempdata = p->data;
				p->data = p->next->data;
				p->next->data = tempdata;
				swapped = 1;
			}
			p = p->next;
		}
		last = p;
	} while (swapped);
}





//文件读取
void readfromfile(const char* filename,struct node* headnode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename,"w");
	}
	struct student tempdata;
	while (fscanf(fp, "%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", tempdata.name, &tempdata.age, tempdata.num, tempdata.sex, tempdata.birth, tempdata.tel, tempdata.email, tempdata.addr) != EOF) {
		headinsert(headnode, tempdata);
		memset(&tempdata, 0, sizeof(tempdata));
	}
	fclose(fp);
}
//保存操作到文件
void savetofile(const char* filename, struct node* headnode) {
	FILE* fp = fopen(filename, "w");
	struct node* p = headnode->next;
	while (p)
	{
		fprintf(fp, "%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", p->data.name, p->data.age, p->data.num, p->data.sex, p->data.birth, p->data.tel, p->data.email, p->data.addr);
		p = p->next;
	}
	fclose(fp);
}
```