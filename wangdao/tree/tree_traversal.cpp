#include<stdio.h>
#define Maxsize 50

using namespace std;

typedef char ElemType;

//二叉树的声明 
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//栈的声明 
typedef struct{
	BiTree data[Maxsize];
	int top;
}SqStack; 

//队列声明
typedef struct{
	BiTree data[Maxsize];
	int front,rear;
}SqQueue;

//栈相关的基本操作 
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

//三种递归遍历算法：前序 
void PreOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		printf(" %c ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	} 
	
}

//三种递归遍历算法：中序
void InOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf(" %c ",bt->data);
		InOrder(bt->rchild);
	}	
}

//三种递归遍历算法：后序 
void PostOrder(BiTree bt)
{
	if(bt!=NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf(" %c ",bt->data);
	}	
}


//二叉树遍历的非递归实现:前序
//算法思路：利用栈，最先开始栈中只有根节点，随后循环出栈，每次出栈就将出栈的节点的子节点入栈（先右后左）
void PreOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("空二叉树！\n");
		return;
	}
	
	SqStack tempStack;
	InitStack(tempStack);
	Push(tempStack,bt);
	
	while(!StackEmpty(tempStack)){	
		BiTree temp_node;
		
		//出栈
		Pop(tempStack,temp_node);
		printf(" %c ",temp_node->data);
		//压入右孩子
		if(temp_node->rchild!=NULL)
			Push(tempStack,temp_node->rchild);
		//压入左孩子 
		if(temp_node->lchild!=NULL)
			Push(tempStack,temp_node->lchild);
	}	
}


//二叉树遍历的非递归实现 ：中序
//数据结构：一个栈tempStack
//算法思想：从根节点开始，将根节点的左孩子，左孩子的左孩子，左孩子的左孩子的左....等等都压入栈中，直到到达叶节点时，开始出栈，然后再处理右边 
void InOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("空二叉树！\n");
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
 
 
 
//二叉树遍历的非递归实现：后序
//数据结构：两个栈stack1和stack2。
//算法思路：stack1入栈顺序是：中左右 （父节点出栈后左右节点再入栈），然后出栈：中右左 ，出栈后压入stack2，所以stack2出栈顺序为：左右中 
void PostOrder_ByIter(BiTree bt)
{
	if(bt==NULL)
	{
		printf("空二叉树！\n");
		return;
	}
	
	SqStack stack1,stack2;
	InitStack(stack1);
	InitStack(stack2);
	Push(stack1,bt);
	while(!StackEmpty(stack1))
	{
		BiTree temp_node;
		//当前节点从stack1出栈
		Pop(stack1,temp_node);
		//当前节点压入stack2
		Push(stack2,temp_node);
		//子节点压入stack1
		if(temp_node->lchild!=NULL)
			Push(stack1,temp_node->lchild);
		if(temp_node->rchild!=NULL)
			Push(stack1,temp_node->rchild);
	}
	
	//弹出stack中所有值即为后序遍历序列
	while(!StackEmpty(stack2))
	{
		BiTree temp_node;
		Pop(stack2,temp_node);
		printf(" %c ",temp_node->data);
	}
	return;
	
}


//层次遍历
//数据结构：队列
//算法思想：根节点先入队，然会队列开始循环出队，直到队空，每一个元素出队后，将其左孩子和右孩子分别入队 
void LevelOrder(BiTree bt)
{
	if(bt==NULL)
	{
		printf("空二叉树！\n");
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
	printf("创建完成！\n");
	printf("前序：\n");
	PreOrder(root);
	printf("\n中序：\n");
	InOrder(root);
	printf("\n后序：\n");
	PostOrder(root);
	
	printf("\n\n非递归前序：\n");
	PreOrder_ByIter(root);
	printf("\n非递归中序：\n");
	InOrder_ByIter(root);
	printf("\n非递归后序：\n");
	PostOrder_ByIter(root); 
	
	printf("\n\n层次遍历：\n");
	LevelOrder(root);
	return 0;
}



