/*Ҫ��������������к�����������н��������� 
�������ݽṹ�������� 
�㷨˼�룺
1.������������ȷ�����ڵ㣬�ɴ������������������������һ���֣�����������һ���� 
2.�ݹ齨����������ֱ��������Ϊ�� 
3.�ݹ齨����������ֱ��������Ϊ�� 
*/
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef int ElemType;

//������������ 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//�����������������У����������� 
BiTree PreInCreate(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2)
//A��B�ֱ�Ϊ������������У�l1��h1,l2��h2�ֱ�Ϊ�������к��������еĵ�һ��Ԫ���±�����һ��Ԫ�ص��±�
//��ʼʱl1=l2=1,h1=h2=n 
{
	int i;
	//�½�һ���ڵ�
	BiTree root=(BiTNode*)malloc(sizeof(BiTNode)); 
	//ȷ�����ڵ��ֵ 
	root->data=A[l1];
	//ȷ�����ڵ�������������λ��i
	for(i=l2;B[i]!=root->data;i++);
	//������������Ľ�����
	int llen=i-l2;
	int rlen=h2-i;
	//��������Ϊ��ʱ���ݹ齨�������� 
	if(llen)
		root->lchild=PreInCreate(A,B,l1+1,l1+llen,l2,l2+llen-1);
	else
		root->lchild=NULL;
	//��������Ϊ��ʱ���ݹ齨�������� 
	if(rlen)
		root->rchild=PreInCreate(A,B,h1-rlen+1,h1,h2-llen+1,h2);
	else
		root->rchild=NULL;
	
	
	return root;
}

//������ͺ������У�����������
BiTree PostInCreate(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2)
//A��B�ֱ�Ϊ������������У�l1��h1,l2��h2�ֱ�Ϊ�������к��������еĵ�һ��Ԫ���±�����һ��Ԫ�ص��±�
//��ʼʱl1=l2=1,h1=h2=n 
{
	int i;
	BiTree root=(BiTNode*)malloc(sizeof(BiTNode));
	//ȷ�����ڵ��ֵ
	root->data=A[h1];
	//ȷ�����ڵ�����������е�λ��
	for(i=l2;B[i]!=root->data;i++);
	int llen=i-l2;
	int rlen=h2-i;
	//��������Ϊ��ʱ���ݹ齨�������� 
	if(llen)
		root->lchild=PostInCreate(A,B,l1,l1+llen-1,l2,l2+llen-1);
	else
		root->lchild=NULL;
	//��������Ϊ��ʱ���ݹ齨�������� 
	if(rlen)
		root->rchild=PostInCreate(A,B,h1-rlen,h1-1,h2-rlen+1,h2);
	else
		root->rchild=NULL;
	
	return root;
	
}




//�ݹ�����㷨��ǰ�� 
void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf(" %d ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	} 
	
}

//�ݹ�����㷨������
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf(" %d ",bt->data);
		InOrder(bt->rchild);
	}	
}

//�ݹ�����㷨������ 
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf(" %d ",bt->data);
	}	
}

int main()
{
	int A[8]={0,1,2,4,5,3,6,7};//���� 
	int B[8]={0,4,2,5,1,6,3,7};//���� 
	int C[8]={0,4,5,2,6,7,3,1};//���� 
	BiTree root1,root2;
	root1=PreInCreate(A,B,1,7,1,7);
	root2=PostInCreate(C,B,1,7,1,7);
	printf("��������������й������������ĺ������У�\n");
	PostOrder(root1);
	printf("\n�ɺ�����������й��������������������У�\n");
	PreOrder(root2);
	return 0;
}
