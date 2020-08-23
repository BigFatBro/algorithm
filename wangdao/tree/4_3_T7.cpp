/*Ҫ���жϸ�����һ�ö������Ƿ�Ϊ��ȫ������ 
�������ݽṹ������ 
�㷨˼�룺
1.������������Ķ������������սڵ�ʱҲ��� 
2.�ж϶����пսڵ����ʱ���зǿսڵ㣬���У�������ȫ������ 

*/

#include<stdio.h>
#define Maxsize 50
using namespace std;

typedef int ElemType;

//������������ 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��������
typedef struct{
	BiTree data[Maxsize];
	int front,rear;
}SqQueue;


//������صĻ�������
void InitQueue(SqQueue &Q){
	Q.rear=Q.front=0;
}

bool isEmpty(SqQueue Q){
	if(Q.front==Q.rear) return true;
	else return false;
}


bool EnQueue(SqQueue &Q,BiTree x){
	if((Q.rear+1)%Maxsize==Q.front) return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%Maxsize;
	return true;
}

bool DeQueue(SqQueue &Q,BiTree &x){
	if(Q.rear==Q.front) return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%Maxsize;
	return true;
}


//�ж϶�����bt�Ƿ�Ϊ��ȫ������ 
bool IsCbTree(BiTree bt)
{
	BiTree tempNode;
	SqQueue tempQueue;
	InitQueue(tempQueue);
	EnQueue(tempQueue,bt);
	while(!isEmpty(tempQueue))
	{
		DeQueue(tempQueue,tempNode);
		if(tempNode){
			//�����Ƿ�ΪNULL����� 
			EnQueue(tempQueue,tempNode->lchild);
			EnQueue(tempQueue,tempNode->rchild);		
		}
		else{
			//����ʱ��һ������ΪNULL�Ľڵ㣬��ʼ������������������нڵ㣬���з�NULL�ڵ㼴���ж�Ϊ����ȫ������ 
			while(!isEmpty(tempQueue))
			{
				DeQueue(tempQueue,tempNode);
				if(tempNode)
					return false;
			}
		}	
	}
	return true; 	
}

//ǰ�򴴽�������(�ݹ��㷨&����ʽ��
//�ο����ӣ�https://www.cnblogs.com/llhthinker/p/4906631.html 
void CreateTree(BiTree &bt,bool isRoot)
{
	char ch;
	if(isRoot)
		printf("Root: ");
	fflush(stdin);
	scanf("%c",&ch);
	fflush(stdin);
	
	if(ch!='#')
	{
		isRoot=false;
		bt=new BiTNode;
		bt->data=ch;
		bt->lchild=NULL;
		bt->rchild=NULL;
		printf("%c's left child is: ", bt->data);
		CreateTree(bt->lchild,isRoot);
		printf("%c's right child is: ", bt->data);
		CreateTree(bt->rchild,isRoot);
	}
}

int main()
{
	BiTree root=NULL;
	CreateTree(root,true);
	printf("������ɣ�\n");
	if(IsCbTree(root))
		printf("��һ����ȫ��������\n");
	else
		printf("����һ����ȫ��������\n");
	return 0;
}
