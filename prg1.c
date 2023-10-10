/*Implement a queue using singly linked list without header node.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* next;
	int data;
};

typedef struct Node* node;

node insertAtEnd(node head, int data)
{
	node new = (node)malloc(sizeof(struct Node));
	new->data=data;
	new->next=NULL;

	if(head==NULL)
	{
		head = new;
	}
	else
	{
		node ptr = head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new;
	}
	return head;
}

node deleteAtFirst(node head)
{
	if(head==NULL)
	{
		return NULL;
	}
	node n=head;
	head=head->next;
	printf("Data deleted : %d\n",n->data);
	free(n);
	return head;
}

void show(node head)
{
	node ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	node head = (node)malloc(sizeof(struct Node));
	head=NULL;
	int flag=1;
	int ch, data;
	do
	{
		printf("Enter your choice\n1.Enqueue, 2.Dequeue : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter data : ");
					scanf("%d", &data);
					head = insertAtEnd(head, data);
					show(head);
					break;

			case 2: head=deleteAtFirst(head);
					show(head);
					break;

			default: flag=0;
		}
	}while(flag);
	return 0;
}