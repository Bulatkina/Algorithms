#include <stdlib.h>
#include "stack.h"
#include "list.h"
struct Stack
{
	List *list;
};

// создание пустого стека
Stack *stack_create()
{
	Stack* stack = new Stack;
	stack->list = list_create();
    return stack;
}

// удаление стека
void stack_delete(Stack *stack)
{
	list_delete(stack->list);
	delete stack;
}

// включение элемента в стек
void stack_push(Stack *stack, int Data)
{

	List* list = stack->list;
	list_insert(list, Data);
}

// получение последнего элемента стека
int stack_get(Stack *stack)
{
	//if(list_first(stack->list)==NULL) {
		//list_insert(stack->list, Data);
		//return;
	return list_item_data(list_first(stack->list));
}

// выталкивание элемента из стека
void stack_pop(Stack *stack)
{
	List *list = stack->list;
	list_erase(list, list_first(list));
}

// проверка стека на наличие элементов
bool stack_empty(Stack *stack)
{
	if(list_first(stack->list)==NULL) {
		return true;
	} else {
		return false;
	}
}
