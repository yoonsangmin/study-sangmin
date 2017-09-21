#include< stdio.h>
#define N 100;
//100-> N���� �ٲ����

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

//list ����ü ������� �ʱ�ȭ
void initialize(ArrayList *pl) {
	int i;
	
	pl->length = 0;	//����Ʈ �� ������ ���� 0���� �ʱ�ȭ
	for (int i = 0; i < 100; i++)
	{
		pl->element[i] = NULL;
	}
}


//�迭��� ����Ʈ�� full ���� check
//full �̸� 1�� return,
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

//����Ʈ ���� �׸���� return
unsigned count_list(ArrayList *pl) {
	return(pl->length);
}

//����Ʈ ���� Ư�� �ε��� ���� return
char *get_entry(ArrayList *pl, unsigned index) {
	if (index >= 0 && index < 100)
		return (pl->element[index]);
	else
		return NULL;
}