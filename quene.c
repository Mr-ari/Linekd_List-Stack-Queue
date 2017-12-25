/*Implementation of Queue*/
//Mr.ari

#include <stdio.h>
#include<malloc.h>

typedef struct queneNode{
  int data;
  struct queneNode *next;
  struct queneNode *prev;
}queneNode;

typedef struct quene{
  queneNode *front;
  queneNode *rear;
  int count;
}quene;

// FUNCTIONS PROTOTYPES'  for normal Queue and de-Quene''''''''''''''''''''''''''''''''''''''
int normalQuene(void);
int circularQueue(void);
int deQuene(void);
//***********************************************************
void insertQuene(quene * ,int );
int deleteQuene(quene* );
void displayQuene(quene *);
quene *creatQuene(void);
//***********************************************************
void insertFront(quene *,int);
int deleteEnd(quene *);
quene creatDeQuene(void);
//***********************************************************
//Function Prototypes for circular Queue....
int enCircularQueue(quene *,queneNode *,int ,int );
int deCircularQueue(quene *);
queneNode *creatCircularQueue(int );

int main(){
int choice=1;
while (choice != 4){
  printf("Enter your choice :\n\t1.Normal Quene\n\t2.de-Queue\n\t3.Circular Queue\n\t4.Exit\n");
  scanf("%d",&choice);
  switch (choice){
    case 1:
    choice = normalQuene();
    break;
    case 2:
    choice = deQuene();
    break;
    case 3:
    choice = circularQueue();
    case 4:
    printf("\nExiting...............\n");
    break;
    default:
    printf("Enter ur choice again\n");
  }
}
  return 0;
}

int normalQuene(void){
  int choice=0,item,deletedItem;
  quene *quene1 = creatQuene();
  while(1){
    printf("Enter your choice :\n\t1.Insert element in the quene\n\t2.Delete element from the quene\n\t3.Display all the elements present on quene\n\t4.Back to Main menu\n\t5.Exit from program\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
      printf("Enter the item you want to insert :\n");
      scanf("%d",&item);
      insertQuene(quene1,item);
      break;
      case 2:
      deletedItem = deleteQuene(quene1);
      if(deletedItem != 9999) printf("\nThe item deleted from the quene is %d\n",deletedItem);
      break;
      case 3:
      displayQuene(quene1);
      break;
      case 4:
      return 0;
      case 5:
      return 4;
    }
  }
}

int deQuene(void){
  quene *quene1 = creatQuene();
  int choice,deletedItem,item;
  while (1){
    printf("Enter your choice :\n\t1.Insert element in front of the quene\n\t2.Insert element in end of the quene\n\t3.Delete element from the front of the quene\n\t4.Delete element from the end of the quene\n\t5.Display all the elements present on quene\n\t6.Back to Main menu\n\t7.Exit from program\n");
    scanf("%d",&choice);
    switch (choice){
      case 1:
      printf("Enter the data you want to insert\n");
      scanf("%d",&item);
      insertFront(quene1,item);
      break;
      case 2:
      printf("Enter the data you want to insert\n");
      scanf("%d",&item);
      insertQuene(quene1,item);
      break;
      case 3:
      deletedItem = deleteQuene(quene1);
      if(deletedItem != 9999) printf("\nThe item deleted from the quene is %d\n",deletedItem);
      break;
      case 4:
      deletedItem = deleteEnd(quene1);
      if(deletedItem != 9999) printf("\nThe item deleted from the quene is %d\n",deletedItem);
      break;
      case 5:
      displayQuene(quene1);
      break;
      case 6:
      return 0;
      case 7:
      return 4;
    }
  }
}

/*Function definitions.................
*/
quene *creatQuene(void){
  quene *newQuene = (quene *)malloc(sizeof(quene));
  newQuene->front = NULL;
  newQuene->count = 0;
  newQuene->rear = NULL;
  return newQuene;
}

void insertQuene(quene *quene1,int item){
  queneNode *newNode = (queneNode *)malloc(sizeof(queneNode));
  newNode->data = item;
  newNode->next = NULL;
  newNode->prev = NULL;
  if (quene1->count == 0) quene1->front = newNode;
  else
    quene1->rear->next = newNode;
  newNode->prev = quene1->rear;
  quene1->rear = newNode;
  quene1->count++;
}

int deleteQuene(quene *quene1){
  int itemDeleted;queneNode *temp;
  if (quene1->count == 0) {
    printf("The Quene is Empty\n");
    return 9999;
  }
  else{
    itemDeleted = quene1->front->data;
    temp = quene1->front;
    quene1->front = quene1->front->next;
    quene1->front->prev = NULL;
    free(temp);
    (quene1->count)--;
    return itemDeleted;
  }
}

void displayQuene(quene *quene1){
  queneNode *ptr = quene1->front;int i;
  if (quene1->count == 0) printf("The quene is empty!!Insert some data to it\n");
  else{
    printf("\nQuene elements are:\n");
    for(i=1;i<=quene1->count;i++){
      printf("%d  ",ptr->data);
      ptr = ptr->next;
    }
  }
    printf("\n");
  }

//Function definitions for de quene

void insertFront(quene *quene1,int item){
  queneNode *newNode = (queneNode *)malloc(sizeof(queneNode));
  newNode->data = item;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (quene1->count == 0) {
    quene1->front = newNode;
    quene1->rear = newNode;
  }
  else{
    quene1->front->prev = newNode;
    newNode->next = quene1->front;
    quene1->front = newNode;
  }
  (quene1->count)++;
}

int deleteEnd(quene *quene1){
  if (quene1->count == 0){
    printf("\nQuene is Empty\n");
    return 9999;
  }
  else{
    queneNode *temp;
    temp = quene1->rear;
    int item = temp->data;
    quene1->rear = quene1->rear->prev;
    quene1->rear->next = NULL;
    free(temp);
    quene1->count --;
     return item;
  }
}

//********************************************************************************
//Function Definition for Circular Queue.
int circularQueue(void){
  int bound,choice=0,item,deletedItem,returned;
  printf("\nEnter the number of blocks in circular Queue:\n");
  scanf("%d",&bound);
  quene *quene1 = creatQuene();
  queneNode *head = creatCircularQueue(bound);
  while(1){
    printf("Enter your choice :\n\t1.Insert element in the circular quene\n\t2.Delete element from the circular quene\n\t3.Display all the elements present in the circular quene\n\t4.Back to Main menu\n\t5.Exit from program\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
      printf("Enter the item you want to insert :\n");
      scanf("%d",&item);
      returned = enCircularQueue(quene1,head,item,bound);
      if (returned == 9999) printf("Queue is full!!\n");
      else printf("Inserting succesful\n");
      break;
      case 2:
      deletedItem = deCircularQueue(quene1);
      if(deletedItem == 9999) printf("The Queue is Empty Cannot delete element!!\n");
      else
      printf("\nThe item deleted from the quene is %d\n",deletedItem);
      break;
      case 3:
      displayQuene(quene1);
      break;
      case 4:
      return 0;
      case 5:
      return 4;
    }
  }
}
queneNode *creatCircularQueue(int bound){
  int i;queneNode *head,*temp=NULL,*newNode;
  for (i=1;i<=bound;i++){
    newNode = (queneNode *)malloc(sizeof(queneNode));
    if (i == 1) head = newNode;
    newNode->prev = temp;
    if (i != 1) temp->next = newNode;
    newNode->data = 9999;
    temp = newNode;
  }
  newNode->next = head;
  head->prev = newNode;
  return head;
}
int enCircularQueue(quene *quene1,queneNode *head,int item,int bound){
  if(quene1->count == bound) return 9999;
  if(quene1->count == 0) quene1->front = quene1->rear = head;
  else{
    quene1->rear = quene1->rear->next;
  }
  quene1->count ++;
  quene1->rear->data = item;
  return 0;
}
int deCircularQueue(quene *quene1){
  int element;
  if (quene1->count == 0) return 9999;
  else{
    element = quene1->front->data;
    quene1->front->data = 9999;
    quene1->front = quene1->front->next;
    quene1->count --;
    return element;
  }
}
