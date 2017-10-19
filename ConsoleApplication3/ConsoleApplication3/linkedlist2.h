
#pragma once
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef int element;
struct node {
	element data;
	struct node *link;
};
typedef struct node Node;

Node *create_node(element d);
// element type�� d ���� data �ʵ�� ���� ��带 ����
// ������ ����� �ּҰ��� ����

void insert_at_front(Node **head, Node *p);
// ù��° ����: head �������� �ּҰ�
// �ι�° ����: �߰��� ����� �ּҰ�
// �߰��ϴ� ���� ����Ʈ�� �� ó���� ��ġ��

Node *insert_at_front2(Node *head, Node *pn);

void insert_at_rear(Node **head, Node *p);

Node *search(Node *head, element key);

unsigned int is_list_empty(Node *head);
// ����Ʈ�� ��� ������ (��, head == NULL), 1�� ����
// �׷��� ������ 0�� ����

unsigned int count_list(Node *head);
// ����Ʈ�� ��� ������ ����

void print_list(Node *head);
// ����Ʈ�� ��� ������ ȭ�鿡 ���

int search_and_remove(Node **phead,element key);

void insert_after_node_p(Node *p, Node *pn);

void reverse(Node **phead);

#endif

