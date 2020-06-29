#include<Windows.h>
#include"map.h"

int main(void){

	SqStack stack;
	Maze maze;
	Postion pos;
	pos._x=0;
	pos._y=2;

	int map[ROW][COL]={
	0,0,1,0,1,0,
	0,0,1,1,1,0, 
	0,0,1,0,0,0, 
	0,1,1,1,1,0, 
	0,0,1,0,1,1, 
	0,0,0,0,0,0
	};


	//栈的初始化
	initStack(stack);
	

	//初始化
	InitMaze(maze,map);

	//插入元素
	printMaze(maze);

	//打印
	printMaze(maze);


	if(passMaze(maze,pos,&stack)){
	cout<<"恭喜你 已经掏出迷宫了!"<<endl;
	}else{
		cout<<"不是我笨 是迷宫没有出口~"<<endl;
	}

	printMaze(maze);

	system("pause");
	return 0;

	}