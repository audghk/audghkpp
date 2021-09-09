#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 20
#define ERROR_CODE 250
#define STRING_SIZE 20

typedef char element;

typedef struct {
	element stack[STACK_SIZE];
	int top;
}ArrayStack;

ArrayStack* createStack() {
	ArrayStack* s = (ArrayStack*)malloc(sizeof(ArrayStack));
	s->top = -1;
	return s;
}

int isEmpty(ArrayStack* s) {
	if (s->top == -1)return 1;
	else return 0;
}

int isFull(ArrayStack* s) {
	if (s->top >= STACK_SIZE - 1) return 1;
	else return 0;
}

int push(ArrayStack* s, element data) {
	if (isFull(s)) {
		printf("stack overflow\n");
		return ERROR_CODE;
	}
	s->top++;
	s->stack[s->top] = data;
	return 1;
}

element pop(ArrayStack* s) {
	element temp;
	if (isEmpty(s)) {
		printf("stack underflow\n");
		return ERROR_CODE;
	}
	temp = s->stack[s->top];
	s->top--;
	return temp;
}

element peek(ArrayStack* s) {
	if (isEmpty(s)) {
		printf("stack is Empty\n");
		return ERROR_CODE;
	}
	return s->stack[s->top];
}

void printStack(ArrayStack* s) {
	int index;
	if (isEmpty(s)) return;
	index = s->top;
	while (index != -1) {
		printf("%d\n", s->stack[index--]);
	}
}

void reverseString(ArrayStack* s, char str[]) {
	int len = strlen(str);
	char c;

	for (int i = 0; i < len; i++) {
		c = str[i];
		push(s, c);
	}

	while (s->top != -1) {
		for (int i = 1; i < 6; i++) {
			printf("%d등 : %c\n", i, pop(s));
		}
	}

	printf("\n");
}

int main() {
	ArrayStack* s1;
	s1 = createStack();

	char str[STRING_SIZE];
    int n;

    printf("경기 참가자의 수를 입력하세요 : ");
    scanf("%d", &n);

    printf("경기 참가자의 참가 번호를 순서대로 입력하세요 : ");
	scanf("%s", str);

	reverseString(s1, str);


	return 0;
}