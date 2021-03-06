#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef int element;
struct node{
	element data;
	struct node *link;
};
typedef struct node Node;

Node *create_node(element d);//element type의 d 값을 data 필드로 갖는 노드를 생성
	//생성된 노드의 주소값을 리턴

void insert_at_front(Node **head, Node *pn);
//첫번째 인자: head 포인터의 주소값
//두번째 인자: 추가할 노드의 주소값
//추가하는 노드는 리스트의 맨 처음에 위치함

unsigned int is_list_empty(Node **head);
//리스트가 비어있으면 즉 헤드가 널이면 1을 리턴
//그렇지 않으면 0을 리턴

unsigned int count_list(Node **head);
//리스트의 노드 갯수를 리턴

void print_list(Node **head);


#endif