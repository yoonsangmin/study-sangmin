#include< stdio.h>
#define N 100;
//100-> N으로 바꿔야함

struct listType {
	char *element[100];
	unsigned length;
};
typedef struct listType ArrayList;
int add_last(ArrayList *pl, char*str);
int is_full(ArrayList *pl);
void initialize(ArrayList *pl);
unsigned count_list(ArrayList *pl);
char *get_entry(ArrayList *pl, unsigned index);


int main(void) {
	int i;
	ArrayList myList;
	
	initialize(&myList);
	
	
	if (!(add_last(&myList, "cornchip")))
		printf("An item is added\n");
	else
		printf("Addition is failled\n");

	printf("The current number of items is %u.\n", count_list(&myList));

	if (!(add_last(&myList, "egg")))
		printf("An item is added\n");
	else
		printf("Addition is failled\n");

	printf("The current number of items is %u.\n", count_list(&myList));
	
	for (i = 0; i < count_list(&myList); i++)
		printf("index %3d : %s\n", i, get_entry(&myList, i));

	return 0;

}

//list 구조체 멤버들의 초기화
void initialize(ArrayList *pl) {
	int i;
	
	pl->length = 0;	//리스트 내 아이템 수를 0으로 초기화
	for (int i = 0; i < 100; i++)
	{
		pl->element[i] = NULL;
	}
}


//배열기반 리스트가 full 인지 check
//full 이면 1을 return,
int is_full(ArrayList *pl) {
	if (pl->length < 100)
		return 0;
	else
		return 1;
}

int add_last(ArrayList *pl, char*str) {
	if (is_full(pl))
		return -1;
	else {
		pl->element[pl->length] = str;
		(pl->length)++;
	}
	return 0;
}

//리스트 내의 항목수를 return
unsigned count_list(ArrayList *pl) {
	return(pl->length);
}

//리스트 내의 특정 인덱스 값을 return
char *get_entry(ArrayList *pl, unsigned index) {
	if (index >= 0 && index < 100)
		return (pl->element[index]);
	else
		return NULL;
}