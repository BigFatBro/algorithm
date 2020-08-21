/*Ҫ��ʵ��һ���ǵݹ��㷨������������ĸ߶�
�������ݽṹ������
�㷨˼�룺
1.�ñ���height��¼��ȣ��ö���ʵ�ֲ�α�����
2.��һ��ָ��last_for_levelָ��ǰ������Ҷ˽ڵ㣬��һ��last_for_Queueָ��ָ���ʱ�̶�β�ڵ� 
3.����ÿһ�㣬ÿ���нڵ����ʱ���Ƚϵ�ǰ�ڵ��Ƿ����last_for_level
4.�����ȣ���˵����ǰ���ӵĽڵ�Ϊ��ǰ������Ҷ˽ڵ㣬hegith++����ʱlast_for_level����Ϊָ����һ������Ҷ˵�һ���ڵ�last_for_Queue������ʱ�̶�β�ڵ㣩
5.������һ��
*/

#include<stdio.h>
#define Maxsize 50

using namespace std;

typedef char ElemType;
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

 
//����������߶ȵķǵݹ��㷨 
int Calculate_height(BiTree bt)
{
	//�ն����� 
	if(bt==NULL)
		return 0;
	
	//�ǿն�����
	int height=0;
	SqQueue tempQueue;
	BiTree temp_node;
	BiTree last_for_level=bt;//ָ��ÿһ������һ���ڵ� 
	BiTree last_for_Queue=bt;//ָ��ǰʱ�̶�βԪ��
	InitQueue(tempQueue);
	EnQueue(tempQueue,bt);
	
	while(!isEmpty(tempQueue)){
		DeQueue(tempQueue,temp_node);
		if(temp_node->lchild!=NULL)
		{
			EnQueue(tempQueue,temp_node->lchild);
			last_for_Queue=temp_node->lchild;//���µ�ǰʱ�̶�βԪ��ָ�� 
		}
			
			
		if(temp_node->rchild!=NULL)
		{
			EnQueue(tempQueue,temp_node->rchild);
			last_for_Queue=temp_node->rchild;//���µ�ǰʱ�̶�βԪ��ָ�� 
		}
			
		if(temp_node==last_for_level){
			height++;
			last_for_level=last_for_Queue;   //last_for_Queue�ǵ�ǰʱ�̶�βԪ��ָ�룬Ҳ����һ������Ҷ˽ڵ� 
		}
	}
	
	return height; 
	
}

//����������߶ȵĵݹ��㷨 
int Calculate_height_by_recursion(BiTree bt)
{
	//�ն����� 
	if(bt==NULL)
		return 0;
	int lheight=Calculate_height_by_recursion(bt->lchild);
	int rheight=Calculate_height_by_recursion(bt->rchild);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
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
	int height1,height2;
	BiTree root=NULL;
	CreateTree(root,true);
	printf("������ɣ�\n");
	height1=Calculate_height(root);
	printf("�ǵݹ��㷨����������ĸ߶�Ϊ�� %d  \n",height1);
	height2=Calculate_height_by_recursion(root);
	printf("�ݹ��㷨����������ĸ߶�Ϊ�� %d  \n",height2);
	return 0;
	
}
