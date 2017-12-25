#include<stdio.h>
#include<malloc.h>
//--------------creating node----------------------------------------
typedef struct node {

	int info;
	struct node *link;
}node;
//---------------------------------------------------------------------------------------
node *start;
//-----------------------------------Fuctions created-------------------------------
void Display ();
int SEARCH(int );
void DELETION(int );
void Insertion(int ,int );
//--------------------------------------------------------------------------
int main(){
	int n,info,count=0,item,choice,res,pos;
	node *head,*temp,*first;
	//......................Storing the variables...........................................
	printf("Enter how many value u want to store?\t");
	scanf("%d",&n);

	while (count < n){
		printf("Enter the value :\n");
		scanf("%d",&info);
		head = (node *)malloc(sizeof (node));

		if (count == 0){
			head->info = info;
			start = head;
			temp = head;
		}
		else {
			head->info = info;
			temp->link = head;
			temp = head;

		}
		count++;
	}
	temp->link = NULL;
	//...............................................................................................

	//--------------------------------------------switch case part ------------------------------------------------
char loopFlag = 'y';
while (loopFlag == 'y') {
	printf("\n\n");
	printf("Enter As per ur choice :\n\t1.Display the list\n\t2.Search a item from the list\n\t3.Delete a item form the list\n\t4.insertion\n\t5.Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			Display();
			break;
		case 2:

			printf("Enter the data item u want to search:\t");
			scanf("%d",&item);
			res=SEARCH(item);
			if (res == -1)
			printf("\nSearch Unsuccesful");
			else
			printf("\nItem found in the %d th positon",res);
			break;
		case 3:
			printf("Enter the position to Delete:\n");
			scanf("%d",&item);
			DELETION(item);
			break;
		case 4:
			printf("Enter the data item u want to insert\n");
			scanf("%d",&item);
			printf("Enter the position where u want to enter it \n");
			scanf("%d",&pos);
			Insertion(item,pos);
			break;
		case 5:
		printf("Exiting.........\n");
			loopFlag = 'n';
			break;
		default:
				printf("Enter ur choice correctly....\n");
	}
}

	//-------------------------------------------------------------------------
	return 0;
}

void Display (){
	node *ptr;

	ptr = start ;

	while (ptr != NULL){
		printf ("%d\t", ptr->info );

		ptr = ptr->link;
	}
}

int SEARCH(int ITEM){
	node *ptr;
	ptr = start;
	int LOC = 0;
	while (ptr != NULL){
		if (ptr->info == ITEM)
		return LOC+1;
		else {
			ptr = ptr -> link;
			LOC ++;
		}
	}
	return -1 ;
}

void DELETION(int pos){
	int count = 1;
	node *ptr ;
	node *temp ;
	ptr = start ;

	if (pos < 1){
		printf("Enter a valid number\n");
	}

	else if (pos == 1)
	{
		start = start->link;

	}

	else {

		while (count<=pos){

			if (count == pos && ptr->link != NULL){
				ptr = ptr->link;
				temp->link = ptr;
			}

			else if(count == pos && ptr->link == NULL){
				temp->link = NULL;

			}
			else{
				temp = ptr;
				ptr = ptr->link;
			}

			count++;
		}
	}
}


void Insertion(int data,int pos){

	node *newNode = (node *)malloc(sizeof(node)),*temp,*ptr = start;
	newNode->info = data;
	int count = 2;
	if (pos < 1) printf("u entered wrong nuber sorry try again\n\n");
	else if (pos == 1) {
		newNode->link = start;
		start = newNode;
	}
	else {
		while (count <= pos){
			if (pos == count && ptr != NULL){
				temp = ptr->link;
				ptr->link = newNode;
				newNode->link = temp;
			}
			else if (pos == count && ptr == NULL){
				newNode->link = NULL;
				ptr->link = newNode;
			}
			ptr = ptr->link;
			count ++;
		}
	}
}
