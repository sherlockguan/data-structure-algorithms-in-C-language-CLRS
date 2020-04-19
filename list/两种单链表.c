#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;//指针的嵌套，指针没内存不能直接当变量去剥洋葱，要先动态内存申请
};

struct Node* createList()//用表头来表示整个链表
{
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));//创建表头，不放数据
	list->next = NULL;
	return list;
}
struct Node*createNode(int data)//用户输入的数据变成一个结构体变量,才能插入链表中
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertByHead(struct Node*list, int data)
{
	struct Node*newNode = createNode(data);
	newNode->next = list->next;//新节点的下一个要指向头节点的下一个
	list->next = newNode;
}

void printList(struct Node*list)
{
	//表头里面没有数据，从第二个节点开始打印
	struct Node *pMove = list->next;
	while (pMove != NULL)
	{
		printf("%d\t", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//第二种方式 再封装，面向对象的思想
struct List
{
	struct Node*headNode;
	int listSize;
};
int isEmptyList(struct List*list)
{
	return list->listSize;
}
struct List*createListSecond()
{
	struct List* list = (struct List*)malloc(sizeof(struct List));
	list->headNode = createList();//调用上面的
	list->listSize = 0;
	return list;
}
void insertByHeadSecond(struct List*list, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = list->headNode->next;
	list->headNode->next = newNode;
	// insertByHead(list,data)

}
void printListSecond(struct List*list)
{
	struct Node*pMove = list->headNode->next;
	while (pMove != NULL)
	{
		printf("%d\t", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
int main()
{
	struct Node*list = createList();
	for (int i = 0; i < 4; i++)
	{
		insertByHead(list, i);
	}
	printList(list);
	//第二种方法
	struct List* listSecond = createListSecond();
	for (int i = 0; i < 5; i++)
	{
		insertByHeadSecond(listSecond, i);
	}
	printListSecond(listSecond);
	system("pause");
	return 0;
}
	
