#include "SqList_SeqList.h"

// ��̬�����һά����ʵ�֡�
#define MAX_SIZE 50
typedef struct{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

// ��̬�����һά����ʵ�֡�
#define INIT_SIZE 100
typedef struct{
	ElemType *data;
	int MAX_SIZE,length;
}SeqList;
