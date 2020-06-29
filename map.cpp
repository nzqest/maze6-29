#include"map.h"
#include<assert.h>

//1����ʼ���Թ�
void InitMaze(Maze &maze,int map[ROW][COL]){
	

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
		
			maze.map[i][j]=map[i][j];

			}
		}

}

//2����ӡ�Թ�
void printMaze(Maze &maze){
	for(int i=0;i<ROW;++i){
		for(int j=0;j<COL;++j){
		
			printf("%d ",maze.map[i][j]);

			}
		cout<<"\n";
	
		}
	printf("\n");

}

//3���ж��Ƿ�Ϊ��ڵ�
bool isEnter(Maze &maze,Postion cur){
	assert(&maze);

	//curΪ�����С�˵�ǰ(x,y)���꣬��ڵ������Ӧ���ǣ���ڵ���������  ���ҵ�ǰλ���ǵذ�
	if((cur._x==0||cur._x==ROW-1||cur._y==0||cur._y==COL-1)&&(maze.map[cur._x][cur._y]==1))return true;

	return false;

}
//4���жϵ�ǰ�ڵ����һ���ڵ��ܷ���ͨ
bool IsNextPass(Maze &maze,Postion cur,Postion next){
	assert(&maze);

	//�ж���һ��λ��next�Ƿ�����С�����ڵ�����λ��
	if(((cur._x==next._x)&&(cur._y==next._y-1||cur._y==next._y+1))||
		((cur._y==next._y)&&(cur._x==next._x-1||cur._x==next._x+1))){
		
			//��������֮������жϣ���һ��λ���ǲ��ǵذ岢�������6x6���Թ�������
			if(((next._x>=0&&next._x<ROW)||(next._y<COL&&next._y>=0))&&maze.map[next._x][next._y]==1)return true;

	}
	return false;

}

//5���жϵ�ǰ�ڵ��Ƿ�Ϊ���ڵ�
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

//6�����Թ�ͨ·
bool passMaze(Maze &maze,Postion Enter,SqStack *stack){
	
	assert(&maze&&isEnter(maze,Enter)==1);

	//����һ����ǰ�ڵ����һ���ڵ�
	Postion cur=Enter;
	Postion next;

	//�����ѹ��ջ��
	pushStack(*stack,cur);
	//���ҽ���ǰС��λ�õ���Ϊ2,Ҳ���������Ϊ2
	maze.map[cur._x][cur._y]=2;

	while(!isEmpty(*stack)){

		cur=*getfrontStack(*stack);

		if(isValidExit(maze,cur,Enter))return true;

		//��������һ��
		next=cur;
		next._y=cur._y-1;

		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
			
			continue;
		}

		//����������һ��
		next=cur;
		next._x=cur._x-1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
		
			continue ;
		
			}

		//����������һ��
		next=cur;
		next._y=cur._y+1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
			
			continue ;
		
			}

		//����������һ��
		next=cur;
		next._x=cur._x+1;
		if(IsNextPass(maze,cur,next)){
			pushStack(*stack,next);
			maze.map[next._x][next._y]=maze.map[cur._x][cur._y]+1;
		
			continue ;
		
			}

		//�ߵ�����˵���ĸ������߲�ͨ��������л��ݣ��ߵ���Ԫ��
		Postion tmp;
		popStack(*stack,tmp);

	}
	return false;
}
