#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef int element;
struct node{
	element data;
	struct node *link;
};
typedef struct node Node;

Node *create_node(element d);//element type�� d ���� data �ʵ�� ���� ��带 ����
	//������ ����� �ּҰ��� ����

void insert_at_front(Node **head, Node *pn);
//ù��° ����: head �������� �ּҰ�
//�ι�° ����: �߰��� ����� �ּҰ�
//�߰��ϴ� ���� ����Ʈ�� �� ó���� ��ġ��

unsigned int is_list_empty(Node **head);
//����Ʈ�� ��������� �� ��尡 ���̸� 1�� ����
//�׷��� ������ 0�� ����

unsigned int count_list(Node **head);
//����Ʈ�� ��� ������ ����

void print_list(Node **head);


#endif