// linkedlist2.c

#include<stdio.h>
#include<stdlib.h>
#include"linkedlist2.h"

int main(void)
{
	int i, key;
	Node *head1 = NULL;
	Node *head2 = NULL;
	
	head1 = insert_at_front(head1, 1);
	head1 = insert_at_front(head1, 3);
	head1 = insert_at_front(head1, 5);
	head1 = insert_at_front(head1, 7);

	printf("The number of nodes in the list1 is %d\n",count_list(head1));
	print_list(head1);

	head2 = reverse(head1);

	printf("The number of nodes in the list1 is %d\n",count_list(head2));
	print_list(head2);

	return 0;
}

Node *create_node(element d)
// element type�� d ���� data �ʵ�� ���� ��带 ����
// ������ ����� �ּҰ��� ����
{
	Node *pn=NULL;
	pn = (Node *)malloc(sizeof(Node));

	pn->data = d;
	pn->link = NULL;

	return pn;
}

Node *insert_at_front(Node *head, int data)
// ù��° ����: head �������� �ּҰ�
// �ι�° ����: �߰��� ����� �ּҰ�
// �߰��ϴ� ���� ����Ʈ�� �� ó���� ��ġ��
{
	// head �����Ͱ� ���� �ȵ� ���, (�� *phead == NULL)

	Node *pn=NULL;

	pn=(Node *)malloc(sizeof(Node));
	if(pn==NULL)
	{
		exit(1);
	}
	pn->data = data;
	pn->link = NULL;

	pn->link = head;
	head = pn;

	return head;
}

Node *insert_at_front2(Node *head, Node *pn)

{
	pn->link = head;
	head = pn;

	return head;
}

void insert_at_rear(Node **phead, Node *pn)
// ù��° ����: head �������� �ּҰ�
// �ι�° ����: �߰��� ����� �ּҰ�
// �߰��ϴ� ���� ����Ʈ�� �� ó���� ��ġ��
{
	Node *temp=NULL;
	// head �����Ͱ� ���� �ȵ� ���, (�� *phead == NULL)
	if (phead == NULL)
	{
		printf("No head pointer is assigned!!\n");
		exit(1);
	}
	//Empty list
	if(*phead == NULL)
		*phead = pn;
	//Non-empty list
	else
	{
		//Find the last node
		temp = *phead;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = pn;

	}

	return;
}


void insert_after_node_p(Node *p, Node *pn)
// pn �����Ͱ� ����Ű�� ��带 p �����Ͱ� ����Ű�� ��� ������ �߰�
{
	Node *temp = NULL;
	temp=p->link;
	p->link=pn;
	pn->link=temp;
}

Node *search(Node *head, element key)
{
	Node *temp;
	temp = head;

	while (temp != NULL)
	{
		if (temp->data == key)
			return temp;	// Key is found
		temp = temp->link;
	}

	// The key is not found
	return NULL;
}

int search_and_remove(Node **phead,element key)
{
	Node *temp = NULL;
	Node *before = NULL;
	int flag = 0;
	//Search the node to delete
	temp = *phead;
	while (temp!=NULL)
	{
		if(temp->data==key)
		{
			if(before==NULL)
				*phead=temp->link;
			else
				before->link=temp->link;
			flag=1;
			free(temp);
			break;
		}
		else
		{
			before=temp;
			temp=temp->link;	
		}
		
	}
	if(flag==1)
		return 0;
	else
		return -1;
}

unsigned int is_list_empty(Node *head)
// ����Ʈ�� ��� ������ (��, head == NULL), 1�� ����
// �׷��� ������ 0�� ����
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

unsigned int count_list(Node *head)
// ����Ʈ�� ��� ������ ����
{
	Node *temp = NULL;
	unsigned int count = 0;

	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}

	return count;
}

void print_list(Node *head)
// ����Ʈ�� ��� ������ ȭ�鿡 ���
{
	Node *temp = NULL;
	
	temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");

	return;
}

Node *reverse(Node *head)
{
	Node *cur = NULL, *prev = NULL, *next = NULL;

	cur=head;
	next=head;

	if(head == NULL)
		exit(1);

	while(cur !=NULL)
	{
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
