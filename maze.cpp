#pragma once
#include"maze.h"




//1��ջ�ĳ�ʼ��
bool initStack(SqStack &stack){
	
	stack.base=new Elemdate[MAX_SIZE];

	if(!stack.base)return false;

	stack.top=stack.base;
	return true;

}

//2���ж�Ԫ����������
bool isFully(SqStack &stack){
	if(!stack.base)return false;

	if(stack.top-stack.base==MAX_SIZE)return true;

	return false;

}


//3��ջ����Ԫ��
bool pushStack(SqStack &stack,Elemdate date){

	if(!stack.base||isFully(stack))return false;
	//if(isFully(stack))return false;

	*(stack.top++)=date;
	return true;

}

//4���ж�ջ�Ƿ�Ϊ��
bool isEmpty(SqStack &stack){
	//if(!stack.base)return false;
	if(stack.base==stack.top)return true;
	return false;
}

//5������Ԫ��
bool popStack(SqStack &stack,Elemdate &date){
	
	//if(!stack.base||isEmpty(stack))return false;
	if(isEmpty(stack))return false;
	date=*(--stack.top);
	return true;

}

//6����ȡջ��Ԫ��
Elemdate* getfrontStack(SqStack &stack){
	if(!stack.base||isEmpty(stack))return NULL;
	//if(isEmpty(stack))return NULL;

	return (stack.top-1);

}

//7����ȡԪ�صĸ���
int countStack(SqStack &stack){
	
	return stack.top-stack.base;

}

//8������ջ
void destoyedStack(SqStack &stack){
	
	if(!stack.base)return ;

	free(stack.base);

	stack.base=NULL;
	stack.top=NULL;


}








