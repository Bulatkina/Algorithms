#include <stdlib.h>
#include "stack.h"
#include "list.h"
struct Stack
{
	List *list;
};

// �������� ������� �����
Stack *stack_create()
{
	Stack* stack = new Stack;
	stack->list = list_create();
    return stack;
}

// �������� �����
void stack_delete(Stack *stack)
{
	list_delete(stack->list);
	delete stack;
}

// ��������� �������� � ����
void stack_push(Stack *stack, int Data)
{

	List* list = stack->list;
	list_insert(list, Data);
}

// ��������� ���������� �������� �����
int stack_get(Stack *stack)
{
	//if(list_first(stack->list)==NULL) {
		//list_insert(stack->list, Data);
		//return;
	return list_item_data(list_first(stack->list));
}

// ������������ �������� �� �����
void stack_pop(Stack *stack)
{
	List *list = stack->list;
	list_erase(list, list_first(list));
}

// �������� ����� �� ������� ���������
bool stack_empty(Stack *stack)
{
	if(list_first(stack->list)==NULL) {
		return true;
	} else {
		return false;
	}
}
