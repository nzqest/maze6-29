#include"maze.h"

typedef struct _Maze{
	int map[ROW][COL];

}Maze;


void initback();
void InitMaze(Maze &maze,int map[ROW][COL]);
void printMaze(Maze &maze);
bool isEnter(Maze &maze,Postion pos);
bool IsNextPass(Maze &maze,Postion cur,Postion next);
bool isValidExit(Maze &maze,Postion cur,Postion Enter);
bool passMaze(Maze &maze,Postion Enter,SqStack *stack);