/*
 * linear_list.c
 *
 *  Created on: 2019/5/04
 *      Author: Mo
 */


#include "common.h"
#include "linear_list_modules.h"
#include "linear_list.h"


Status DisplayLNodeMenu(void);
Status LNodeMenuSelect(void);

Status CreateList(l_node_s *L); // 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量）
Status HeadInsert(l_node_s *L); // 单链表的多个节点创建并插入（头插法）
Status FootInsert(l_node_s *L); // 单链表的多个节点创建并插入（尾插法）


/*
 * Main function
 */
Status SqListSeqList(void)
{
	system("cls");
	DisplayLNodeMenu();
	LNodeMenuSelect();

	return OK;
}


/*
 * Sub function
 */
Status DisplayLNodeMenu(void)
{
	printf("# LNode #\n");
	printf("# 1 CreateList()\n");
	printf("# 2 HeadInsert(l_node_s *L)\n");
	printf("# 3 FootInsert(l_node_s *L)\n");



	printf("# b Back!\n");
	printf("# q Exit!\n");

	return OK;
}


Status LNodeMenuSelect(void)
{
	l_node_s *listcase; // 定义一个单链表类型的指针变量 listcase，注意，在之后指向头节点地址才表示该单链表存在
	listcase = NULL; // 暂时设置此单链表还未被创建（还没指向头节点）

	while(TRUE)
	{
		char selectnum;
		printf("Please enter number to select:");
		scanf("%c", &selectnum);
		getchar(); // 读入 scanf() 函数留下的回车

		switch(selectnum)
		{
			case '1': // 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量）
				if(CreateList(&listcase) == OK)
				{
					printf("CreateList successed!");
				}
				else
				{
					printf("CreateList false!");
				}
				break;

			case '2': // 单链表的多个节点创建并插入（头插法）
				if(HeadInsert(&listcase) == OK)
				{
					printf("HeadInsert successed!");
				}
				else
				{
					printf("HeadInsert false!");
				}
				break;

			case '3': // 单链表的多个节点创建并插入（尾插法）
				if(FootInsert(&listcase) == OK)
				{
					printf("FootInsert successed!");
				}
				else
				{
					printf("FootInsert false!");
				}
				break;

			case '4': // 单链表的插入节点
				break;

			case '5': // 单链表的删除节点
				break;

			case '6': // 单链表的按序号查找节点
				break;

			case '7': // 单链表的按值查找节点
				break;

			case '8': // 单链表的求表长
				break;

			case '9': // 单链表的销毁
				if(DestroyList(&listcase) == OK)
				{
					printf("DestroyList successes!\n");
				}
				else
				{
					printf("DestroyList false!\n");
				}
				break;
		}

	}

}


/* 单链表的头节点创建（创建一个头节点，将头节点地址赋给单链表指针变量） */
Status CreateList(l_node_s *L)
{
	*L = (l_node_s *)malloc(sizeof(l_node_s));
	if(*L != NULL)
	{
		*L->next = NULL;
		return OK;
	}
	else
	{
		return ERROR;
	}
}


/* 单链表的多个节点创建并插入（头插法） */
Status HeadInsert(l_node_s *L)  // 传入的是单链表头节点指针的地址
{
	l_node_s *one_node;
	ElemType e;

	printf("Please enter e, enter \'q\' to end input!");
	scanf("%c", &e);
	getchar();

	while(e != 'q')
	{
		one_node = (l_node_s *)malloc(sizeof(l_node_s));
		one_node->data = e;
		one_node->next = *L->next; // 将头节点的 next 域赋给往头节点后面插入的节点
		*L->next = one_node; // 将插入节点的地址赋给头节点的 next 域

		scanf("%c", &e);
		getchar();
	}

	return OK;
}


/* 单链表的多个节点创建并插入（尾插法） */
Status FootInsert(l_node_s *L)  // 传入的是单链表头节点指针的地址
{
	l_node_s *one_node;
	ElemType e;

	printf("Please enter e, enter \'q\' to end input!");
	scanf("%c", &e);
	getchar();

	while(e != 'q')
	{
		one_node = (l_node_s *)malloc(sizeof(l_node_s));
		one_node->data = e;
		one_node->next = NULL;

		l_node_s *end_node;
		end_node = L; // 先将头节点当作是最后一个节点
		while(end_node->next != NULL) // 如果不是最后一个节点的话
		{
			end_node = end_node->next; // 将下一个节点当作是最后一个节点
		}

		end_node->next = one_node; // 将此节点地址赋给最后一个节点的指针域

		scanf("%c", &e);
		getchar();
	}

	return OK;
}


/* 单链表的插入节点 */



/* 单链表的删除节点 */



/* 单链表的按序号查找节点 */



/* 单链表的按值查找节点 */



/* 单链表的求表长 */



/* 单链表的销毁 */

