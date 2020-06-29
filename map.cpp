#include"map.h"
#include<assert.h>

//1、初始化迷宫
void InitMaze(Maze &maze,int map[ROW][COL]){
	

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
		
			maze.map[i][j]=map[i][j];

			}
		}

}

//2、打印迷宫
void printMaze(Maze &maze){
	for(int i=0;i<ROW;++i){
		for(int j=0;j<COL;++j){
		
			printf("%d ",maze.map[i][j]);

			}
		cout<<"\n";
	
		}
	printf("\n");

}

//3、判断是否为入口点
bool isEnter(Maze &maze,Postion cur){
	assert(&maze);

	//cur为传入的小人当前(x,y)坐标，入口点的条件应该是，入口点在四条边  并且当前位置是地板
	if((cur._x==0||cur._x==ROW-1||cur._y==0||cur._y==COL-1)&&(maze.map[cur._x][cur._y]==1))return true;

	return false;

}
//4、判断当前节点的下一个节点能否走通
bool IsNextPass(Maze &maze,Postion cur,Postion next){
	assert(&maze);

	//判断下一个位置next是否是在小人相邻的四周位置
	if(((cur._x==next._x)&&(cur._y==next._y-1||cur._y==next._y+1))||
		((cur._y==next._y)&&(cur._x==next._x-1||cur._x==next._x+1))){
		
			//满足四周之后紧着判断，下一个位置是不是地板并且在这个6x6的迷宫格子内
			if(((next._x>=0&&next._x<ROW)||(next._y<COL&&next._y>=0))&&maze.map[next._x][next._y]==1)return true;

	}
	return false;

}

//5、判断当前节点是否为出口点
bool isValidExit(Maze &maze,Postion cur,Postion Enter){
	assert(&maze);

	if(Enter._x==cur._x&&Enter._y==cur._y)return false;

	if((cur._x==0||cur._x==ROW-1||cur._y==COL-1||cur._y==0))return true;

	return false;

	/*if ((cur._x != Enter._x || cur._y != Enter._y) &&
		((cur._x == 0 || cur._x == ROW - 1) || (cur._y == 0 || cur._y == COL - 1))) { 
			return true; 
	}else{
		return false;
	}*/
}

//6、找迷宫通路
bool passMaze(Maze &maze,Postion Enter,SqStack *stack){
	
	assert(&maze&&isEnter(maze,Enter)==1);

	//定义一个当前节点和下一个节点
	Postion cur=Enter;
	Postion next;

	//将入口压入栈中
	pushStack(*stack,cur);
	//并且将当前小人位置的置为2,也就是入口置为2
	maze.map[cur._x][cur._y]=2;

	while(!isEmpty(*stack)){

		cur=*getfrontStack(*stack);

		if(isValidExit(maze,cur,Enter))return true;

		//尝试向左一步
		next=cur;
		next._y=cur._y-1;

		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
			
			continue;
		}

		//尝试向上走一步
		next=cur;
		next._x=cur._x-1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
		
			continue ;
		
			}

		//尝试向下走一步
		next=cur;
		next._y=cur._y+1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
			
			continue ;
		
			}

		//尝试向右走一步
		next=cur;
		next._x=cur._x+1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
		
			continue ;
		
			}

		//走到这里说明四个方向都走不通，这里进行回溯，踢掉首元素
		Postion tmp;
		popStack(*stack,tmp);

	}
	return false;
}
