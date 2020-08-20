#include<stdio.h>
#define Maxsize 50

using namespace std;

typedef char ElemType;

//������������ 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//ջ������ 
typedef struct{
	BiTree data[Maxsize];
	int top;
}SqStack; 

//��������
typedef struct{
	BiTree data[Maxsize];
	int front,rear;
}SqQueue;

//ջ��صĻ������� 
void InitStack(SqStack &S)
{
	S.top=-1;
}

bool StackEmpty(SqStack S){
	if(S.top==-1)
		return true;
	else
		return false;
}

bool Push(SqStack &S,BiTree x)
{
	if(S.top==Maxsize-1)
		return false;
	S.data[++S.top]=x;
	return true;
}

bool Pop(SqStack &S,BiTree &x)
{
	if(S.top==-1)
		return false;
	
	x=S.data[S.top--];
	return true;
}

bool GetTop(SqStack &S,BiTree &x)
{
	if(S.top==-1)
		return false;
	
	x=S.data[S.top];
	return true;
}

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

//���ֵݹ�����㷨��ǰ�� 
void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf(" %c ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	} 
	
}

//���ֵݹ�����㷨������
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf(" %c ",bt->data);
		InOrder(bt->rchild);
	}	
}

//���ֵݹ�����㷨������ 
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf(" %c ",bt->data);
	}	
}


//�����������ķǵݹ�ʵ��:ǰ��
//�㷨˼·������ջ�����ȿ�ʼջ��ֻ�и��ڵ㣬���ѭ����ջ��ÿ�γ�ջ�ͽ���ջ�Ľڵ���ӽڵ���ջ�����Һ���
void PreOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("�ն�������\n");
		return;
	}
	
	SqStack tempStack;
	InitStack(tempStack);
	Push(tempStack,bt);
	
	while(!StackEmpty(tempStack)){	
		BiTree temp_node;
		
		//��ջ
		Pop(tempStack,temp_node);
		printf(" %c ",temp_node->data);
		//ѹ���Һ���
		if(temp_node->rchild!=NULL)
			Push(tempStack,temp_node->rchild);
		//ѹ������ 
		if(temp_node->lchild!=NULL)
			Push(tempStack,temp_node->lchild);
	}	
}


//�����������ķǵݹ�ʵ�� ������
//���ݽṹ��һ��ջtempStack
//�㷨˼�룺�Ӹ��ڵ㿪ʼ�������ڵ�����ӣ����ӵ����ӣ����ӵ����ӵ���....�ȵȶ�ѹ��ջ�У�ֱ������Ҷ�ڵ�ʱ����ʼ��ջ��Ȼ���ٴ����ұ� 
void InOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("�ն�������\n");
		return;
	}
	
	SqStack tempStack;
	InitStack(tempStack);
	
	
	while(!StackEmpty(tempStack)||bt!=NULL)
	{
		if(bt!=NULL){
			
			while(bt!=NULL)
			{
				Push(tempStack,bt);
				bt=bt->lchild;
			}		
		}
		else{
			BiTree temp_node;
			Pop(tempStack,temp_node);
			printf(" %c ",temp_node->data);
			bt=temp_node->rchild;		
		}
		
	}
	
	return; 
}
 
 
 
//�����������ķǵݹ�ʵ�֣�����
//���ݽṹ������ջstack1��stack2��
//�㷨˼·��stack1��ջ˳���ǣ������� �����ڵ��ջ�����ҽڵ�����ջ����Ȼ���ջ�������� ����ջ��ѹ��stack2������stack2��ջ˳��Ϊ�������� 
void PostOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("�ն�������\n");
		return;
	}
	
	SqStack stack1,stack2;
	InitStack(stack1);
	InitStack(stack2);
	Push(stack1,bt);
	while(!StackEmpty(stack1))
	{
		BiTree temp_node;
		//��ǰ�ڵ��stack1��ջ
		Pop(stack1,temp_node);
		//��ǰ�ڵ�ѹ��stack2
		Push(stack2,temp_node);
		//�ӽڵ�ѹ��stack1
		if(temp_node->lchild!=NULL)
			Push(stack1,temp_node->lchild);
		if(temp_node->rchild!=NULL)
			Push(stack1,temp_node->rchild);
	}
	
	//����stack������ֵ��Ϊ�����������
	while(!StackEmpty(stack2))
	{
		BiTree temp_node;
		Pop(stack2,temp_node);
		printf(" %c ",temp_node->data);
	}
	return;
	
}


//��α���
//���ݽṹ������
//�㷨˼�룺���ڵ�����ӣ�Ȼ����п�ʼѭ�����ӣ�ֱ���ӿգ�ÿһ��Ԫ�س��Ӻ󣬽������Ӻ��Һ��ӷֱ���� 
void LevelOrder(BiTree bt)
{
	if(bt==NULL)
	{
		printf("�ն�������\n");
		return;
	}
	
	SqQueue tempQueue;
	InitQueue(tempQueue);
	EnQueue(tempQueue,bt);
	while(!isEmpty(tempQueue)){
		BiTree temp_node;
		DeQueue(tempQueue,temp_node);
		printf(" %c ",temp_node->data);
		if(temp_node->lchild!=NULL)
			EnQueue(tempQueue,temp_node->lchild);
		if(temp_node->rchild!=NULL)
			EnQueue(tempQueue,temp_node->rchild);	
	}
	return; 
}


int main()
{
	BiTree root=NULL;
	CreateTree(root,true);
	printf("������ɣ�\n");
	printf("ǰ��\n");
	PreOrder(root);
	printf("\n����\n");
	InOrder(root);
	printf("\n����\n");
	PostOrder(root);
	
	printf("\n\n�ǵݹ�ǰ��\n");
	PreOrder_ByIter(root);
	printf("\n�ǵݹ�����\n");
	InOrder_ByIter(root);
	printf("\n�ǵݹ����\n");
	PostOrder_ByIter(root); 
	
	printf("\n\n��α�����\n");
	LevelOrder(root);
	return 0;
}



