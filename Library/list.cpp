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

// создание списка
List *list_create()
{
	
	List *list = new List;

	list->head = NULL;
    return list;
}

// удаление списка
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

// получить первый элемент списка
ListItem *list_first(List *list)
{
	
	return list->head;
}

// извлечь данные из элемента списка
int list_item_data(ListItem *item)
{
	return item->data;
}

// получить следующий элемент списка
ListItem *list_item_next(ListItem *item)
{
	return item->next;
}

// получить предыдущий элемент списка
/*ListItem *list_item_prev(ListItem *item)
{
    return NULL;
}*/

// вставить данные в начало списка
ListItem *list_insert(List *list, int data)
{
	ListItem *next = list->head;
	ListItem *item = new ListItem;
	item->data = data;
	item->next = next;
	return list->head = item;
}

// вставить данные после заданного элемента
ListItem *list_insert_after(List *list, ListItem *item, int data)
{
	ListItem *middle = new ListItem;
	middle->data = data;
	middle->next = item->next;
	return item->next = middle;
}

// удалить заданный элемент списка
ListItem *list_erase(List *list, ListItem *item)
{
	ListItem **indirect = &list->head;
	while ((*indirect) != item)
		indirect = &(*indirect)->next;
	ListItem* next = item->next;
	delete(*indirect);
	return *indirect = next;
}

//удалить элемент списка, следующий за заданным
ListItem *list_erase_next(List *list, ListItem *item)
{
	ListItem *middle = item->next;
	if(middle != NULL) {
		item->next = middle->next;
		delete middle;
	}
	return item;
}
