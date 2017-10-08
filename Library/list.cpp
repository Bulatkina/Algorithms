#include <stdlib.h>
#include "list.h"
#include <iostream>

using namespace std;

struct ListItem
{
	int data;
	ListItem *next;
};

struct List
{
	ListItem *head;
	
};

// �������� ������
List *list_create()
{
	
	List *list = new List;

	list->head = NULL;
    return list;
}

// �������� ������
void list_delete(List *list)
{
	ListItem *prev = NULL;
	ListItem *item = list->head;
	while(item != NULL) {
		prev = item;
		item = item->next;
		delete prev;
	}
}

// �������� ������ ������� ������
ListItem *list_first(List *list)
{
	
	return list->head;
}

// ������� ������ �� �������� ������
int list_item_data(ListItem *item)
{
	return item->data;
}

// �������� ��������� ������� ������
ListItem *list_item_next(ListItem *item)
{
	return item->next;
}

// �������� ���������� ������� ������
/*ListItem *list_item_prev(ListItem *item)
{
    return NULL;
}*/

// �������� ������ � ������ ������
ListItem *list_insert(List *list, int data)
{
	ListItem *next = list->head;
	ListItem *item = new ListItem;
	item->data = data;
	item->next = next;
	return list->head = item;
}

// �������� ������ ����� ��������� ��������
ListItem *list_insert_after(List *list, ListItem *item, int data)
{
	ListItem *middle = new ListItem;
	middle->data = data;
	middle->next = item->next;
	return item->next = middle;
}

// ������� �������� ������� ������
ListItem *list_erase(List *list, ListItem *item)
{
	ListItem **indirect = &list->head;
	while ((*indirect) != item)
		indirect = &(*indirect)->next;
	ListItem* next = item->next;
	delete(*indirect);
	return *indirect = next;
}

//������� ������� ������, ��������� �� ��������
ListItem *list_erase_next(List *list, ListItem *item)
{
	ListItem *middle = item->next;
	if(middle != NULL) {
		item->next = middle->next;
		delete middle;
	}
	return item;
}
