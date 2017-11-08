#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild,*rchild;
}BiNode, *BiTree;

Status CreatBiTree(BiTree *T)
{
    TElemType e;
    scanf("%d", &e);
    if(e == 0)
	*T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiNode));
	if(!T)
	{
	    exit(OVERFLOW);
	}
	(*T)->data = e;
	CreatBiTree(&((*T)->lchild));
	CreatBiTree(&((*T)->rchild));
    }
    return OK;
}

void visit(TElemType e)
{	
    printf("%d ", e);
}

Status PreOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if(!T)
    {
	visit(T->data);
	PreOrderTraverse(T->lchild, visit);
	PreOrderTraverse(T->rchild, visit);

    }
 //   return OK;
}

Status PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
    if(!T)
    {
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	visit(T->data);
    }
   // return OK;

}

int main(void)
{

    BiTree T;
    printf("Creat Tree, \'zero\'means null tree \n");
    CreatBiTree(&T);
    printf("PreOrder Traverse:  \n");
    PreOrderTraverse(T, *visit);

    return 0;
}
