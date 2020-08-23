/*要求：判断给定的一棵二叉树是否为完全二叉树 
所需数据结构：队列 
算法思想：
1.层序遍历给定的二叉树，遇到空节点时也入队 
2.判断队列中空节点后面时候还有非空节点，若有，则不是完全二叉树 

*/

#include<stdio.h>
#define Maxsize 50
using namespace std;

typedef int ElemType;

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


//判断二叉树bt是否为完全二叉树 
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
			//无论是否为NULL都入队 
			EnQueue(tempQueue,tempNode->lchild);
			EnQueue(tempQueue,tempNode->rchild);		
		}
		else{
			//出队时第一次遇到为NULL的节点，则开始遍历队列中在其后所有节点，如有非NULL节点即可判定为非完全二叉树 
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
	BiTree root=NULL;
	CreateTree(root,true);
	printf("创建完成！\n");
	if(IsCbTree(root))
		printf("是一棵完全二叉树！\n");
	else
		printf("不是一棵完全二叉树！\n");
	return 0;
}
