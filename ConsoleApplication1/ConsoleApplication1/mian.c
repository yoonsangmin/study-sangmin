#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main(void)
{
	int i;
	Node *head1 = NULL;

	for(i = 0;i < 10;i++)
		insert_at_front(&head1, create_node(i*2));

	printf("The number of node in the list : %d\n", count_list(&head1));
	print_list(&head1);

	return 0;
}

Node *create_node(element d){
	Node *pn=NULL;
	pn = (Node *)malloc(sizeof(Node));//�Ҵ� �̸�ŭ ũ�⸦ ��������ͷ� ���

	pn->data = d;
	pn->link = NULL;

	return pn;
}

void insert_at_front(Node **head, Node *pn){
	//����Ʈ�� ����ִ� ��� (�� *head == NULL)
	if(is_list_empty(head))
		*head = pn;
	else{
		pn->link = *head;
		*head = pn;
	}

	return;

}

void insert_after_node_p(Node **head, Node *p, Node *pn)
//pn �����Ͱ� ����Ű�� ��带 p �����Ͱ� ����Ű�� ��� ������ �߰�
{

}

unsigned int is_list_empty(Node **head){
	if (head==NULL)
		return 1;
	else
		return 0;
}

unsigned int count_list(Node **head){
	Node *temp = NULL;
	unsigned int count = 0;
	
	temp = *head;
	while (temp != NULL){
		count++;
		temp = temp ->link;
	}
	
	return count;
}

void print_list(Node **head){
	Node *temp = NULL;

	temp = *head;
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->link;
	}
	
	return;
}