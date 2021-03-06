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
// element type의 d 값을 data 필드로 갖는 노드를 생성
// 생성된 노드의 주소값을 리턴
{
	Node *pn=NULL;
	pn = (Node *)malloc(sizeof(Node));

	pn->data = d;
	pn->link = NULL;

	return pn;
}

Node *insert_at_front(Node *head, int data)
// 첫번째 인자: head 포인터의 주소값
// 두번째 인자: 추가할 노드의 주소값
// 추가하는 노드는 리스트의 맨 처음에 위치함
{
	// head 포인터가 설정 안된 경우, (즉 *phead == NULL)

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
// 첫번째 인자: head 포인터의 주소값
// 두번째 인자: 추가할 노드의 주소값
// 추가하는 노드는 리스트의 맨 처음에 위치함
{
	Node *temp=NULL;
	// head 포인터가 설정 안된 경우, (즉 *phead == NULL)
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
// pn 포인터가 가리키는 노드를 p 포인터가 가리키는 노드 다음에 추가
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
// 리스트가 비어 있으면 (즉, head == NULL), 1을 리턴
// 그렇지 않으면 0을 리턴
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

unsigned int count_list(Node *head)
// 리스트의 노드 갯수를 리턴
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
// 리스트의 노드 값들을 화면에 출력
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
