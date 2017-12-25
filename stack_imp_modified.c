/*a program to implement the stack which can have multiple stack in the program
...........using double pointer*/

#include <stdio.h>
#include <malloc.h>

typedef struct stack{
  int data;
  struct stack *next;
}stack;

stack *stackA=NULL,*stackB=NULL;

void push(stack **,int );
int pop(stack **);
void intializeStack(stack **);
stack *newStack(int );
void displayStack(stack **);

int main(){
  int dataEntry=9999;

  intializeStack(&stackA);
  printf("This is stack A:\n");
  displayStack(&stackA);

  intializeStack(&stackB);
  printf("\nThis is stack B:\n");
  displayStack(&stackB);
  return 0;
}

void intializeStack(stack **root){
  int dataEntry=9999;
  do{
    if (dataEntry != 9999)
      push(root,dataEntry);
    printf("Enter the value to the stack\npress 9999 to exit\t");
    scanf("%d",&dataEntry);
  }
  while (dataEntry!=9999);
}

void displayStack(stack **root){

    stack *ptr = *root;
    if (ptr == NULL)
      printf("Empty Stack\n");
    else{
      while (ptr!= NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
      }
    }

}

stack *newStack(int dataEntry){

  stack *nw = (stack *)malloc(sizeof(stack));
  nw->data = dataEntry;
  nw->next = NULL;
  return nw;
}
void push(stack **root,int dataEntry){

    stack *entryStack = newStack(dataEntry);
    entryStack->next = *root;
    *root = entryStack;
}

int pop(stack **root){
  if (*root == NULL){
    return -1;
  }
  stack *temp;
  temp = *root;
  int dataPopped = temp->data;
  *root = temp->next;
  free(temp);
  return dataPopped;
}
