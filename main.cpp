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


	//ջ�ĳ�ʼ��
	initStack(stack);
	

	//��ʼ��
	InitMaze(maze,map);

	//����Ԫ��
	printMaze(maze);

	//��ӡ
	printMaze(maze);


	if(passMaze(maze,pos,&stack)){
	cout<<"��ϲ�� �Ѿ��ͳ��Թ���!"<<endl;
	}else{
		cout<<"�����ұ� ���Թ�û�г���~"<<endl;
	}

	printMaze(maze);

	system("pause");
	return 0;

	}