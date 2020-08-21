/*要求：实现一个非递归算法，计算二叉树的高度
所需数据结构：队列
算法思想：
1.用变量height记录深度，用队列实现层次遍历，
2.用一个指针last_for_level指向当前层的最右端节点，另一个last_for_Queue指针指向此时刻队尾节点 
3.遍历每一层，每次有节点出队时，比较当前节点是否等于last_for_level
4.如果相等，则说明当前出队的节点为当前层的最右端节点，hegith++，此时last_for_level更改为指向下一层的最右端的一个节点last_for_Queue（即此时刻队尾节点）
5.遍历下一层
*/

#include<stdio.h>
#define Maxsize 50

using namespace std;

typedef char ElemType;
//二叉树的声明 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//队列声明
typedef struct{
	BiTree data[Maxsize];
	int front,rear;
}SqQueue;

//队列相关的基本操作
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

 
//计算二叉树高度的非递归算法 
int Calculate_height(BiTree bt)
{
	//空二叉树 
	if(bt==NULL)
		return 0;
	
	//非空二叉树
	int height=0;
	SqQueue tempQueue;
	BiTree temp_node;
	BiTree last_for_level=bt;//指向每一层的最后一个节点 
	BiTree last_for_Queue=bt;//指向当前时刻队尾元素
	InitQueue(tempQueue);
	EnQueue(tempQueue,bt);
	
	while(!isEmpty(tempQueue)){
		DeQueue(tempQueue,temp_node);
		if(temp_node->lchild!=NULL)
		{
			EnQueue(tempQueue,temp_node->lchild);
			last_for_Queue=temp_node->lchild;//更新当前时刻队尾元素指针 
		}
			
			
		if(temp_node->rchild!=NULL)
		{
			EnQueue(tempQueue,temp_node->rchild);
			last_for_Queue=temp_node->rchild;//更新当前时刻队尾元素指针 
		}
			
		if(temp_node==last_for_level){
			height++;
			last_for_level=last_for_Queue;   //last_for_Queue是当前时刻队尾元素指针，也是下一层的最右端节点 
		}
	}
	
	return height; 
	
}

//计算二叉树高度的递归算法 
int Calculate_height_by_recursion(BiTree bt)
{
	//空二叉树 
	if(bt==NULL)
		return 0;
	int lheight=Calculate_height_by_recursion(bt->lchild);
	int rheight=Calculate_height_by_recursion(bt->rchild);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}



//前序创建二叉树(递归算法&交互式）
//参考链接：https://www.cnblogs.com/llhthinker/p/4906631.html 
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
	printf("创建完成！\n");
	height1=Calculate_height(root);
	printf("非递归算法计算出的树的高度为： %d  \n",height1);
	height2=Calculate_height_by_recursion(root);
	printf("递归算法计算出的树的高度为： %d  \n",height2);
	return 0;
	
}
