#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct LinkedList{
	Node* head;
	Node* tall;
	int size;
} LinkedList;

void print_list(LinkedList* list)
{
	if (list->size == 0)
	{
		printf("List is empty\n");
		return;
	}
	Node* currentNode = list->head;
	while(currentNode != NULL)
	{
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

void insert_node(LinkedList* list, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (list->size == 0)
	{
		list->head = node;
		list->tall = node;
	}
	else
	{
		list->tall->next = node;
		node->prev = list->tall;
		list->tall = node;	
	}
	(list->size)++;
}

void delete_node(LinkedList* list, int count)
{
	if(count > list->size)
	{
		printf("Element doesn't exist\n");
		return;
	}
	Node* deletedNode = (list->head);
	for (int i = 0; i < count - 1; i++)
	{
		deletedNode = deletedNode->next;
	}
	if(deletedNode->prev == NULL)
	{
		list->head = list->head->next;
		if(list->head != NULL)
		{
			list->head->prev = NULL;
		}
	}
	else if(deletedNode->next == NULL)
	{	
		list->tall = list->tall->prev;
		if(list->tall != NULL)
		{
			list->tall->next = NULL;
		}
	}
	else
	{
		deletedNode->next->prev = deletedNode->prev;
		deletedNode->prev->next = deletedNode->next;
	}
	free(deletedNode);
	(list->size)--;
}

int main()
{
	LinkedList* list = malloc(sizeof(LinkedList));
	print_list(list);
	insert_node(list, 5);
	insert_node(list, 4);
	insert_node(list, 3);
	insert_node(list, 2);
	insert_node(list, 1);
	print_list(list);
	delete_node(list, 5);
	print_list(list);
	delete_node(list, 3);
	print_list(list);	
	delete_node(list, 1);
	print_list(list);		
	delete_node(list, 1);
	print_list(list);
	delete_node(list, 1);	
	print_list(list);
	delete_node(list, 1);
	return 0;
}
