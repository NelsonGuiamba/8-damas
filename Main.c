
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool coluna(int c,int f,char map[8][8]);
bool diagonal(int c,int f,char map[8][8]);
void print(char mat[8][8]);
void backtrack(int *pos,char map[8][8],char *ant);
int main(){
	char map[8][8] = {0};// usar char para poupar memoria
	char pos[2] = {9,9};
	int c,j,d=0,i=0;
	bool estado;
	short recur=0;
	while(d != 8){
		estado=true;
		for(;i<64;i++){
			c = i/8;
			j = i%8;
			if(pos[0] == c && pos[1] == j){
				printf("%d %d == %d %d\n",pos[0],pos[1],c,j);
				exit(5);
			continue;
				}
			if(coluna(c, j, map)){
				if(diagonal(c, j, map)){
					map[c][j] = 1;
					d++;
					estado=false;
				}
			}
		}
		if(estado){
			d--;
			/*printf("\n\nAntes Backtrack\n\n");
			print(map);
			getchar();*/
			backtrack(&i,map,pos);/*
			printf("Depois backtrack\n\n");
			print(map);
			getchar();*/
			recur++;
		}
		
		if(recur == 9000){
			perror("Max recursion depth");
			exit(1);
		}
	}
	print(map);
	printf("Recursividade %d\n",recur);
}


bool coluna(int c,int f,char  map[8][8]){
	int i,j;
	for(i=c+1,j=f;i<=7;i++)	{
		if(map[i][j] == 1) return false;
	}
	for(i=c-1,j=f;i>=0;i--)	{// coluna para baixo
		if(map[i][j] == 1) return false;
	}
	for(i=c,j=f+1;j<=7;j++)	{//fileira para direira
		if(map[i][j] == 1) return false;
	}
	for(i=c,j=f-1;j>=0;j--)	{//fileira pra esquerda
		if(map[i][j] == 1) return false;
	}
	return true;
}

bool diagonal(int c,int f,char  map[8][8]){
	int i,j;
	for(i=c+1,j=f+1;i<= 7 && j<= 7;i++,j++){
		if(map[i][j] == 1) return false;
	}
	for(i=c,j=f;i>= 0 && j>= 0;i--,j--){
		if(map[i][j] == 1) return false;
	}
	for(i=c-1,j=f+1;i>= 0 && j<= 7;i--,j++){
		if(map[i][j] == 1) return false;
	}
	for(i=c+1,j=f-1;i<= 7 && j>= 0;i++,j--){
		if(map[i][j] == 1) return false;
	}
	return true;
}

void print(char  mat[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}


void backtrack(int *pos,char map[8][8],char *ant){
	int c,j;
	bool ja = false;
	//printf("pos antiga %d ",*pos);
	for(int i=64;i>0;i--){
		c = i/8;
		j = i%8;
		if(map[c][j] == 1){
			map[c][j] = 0;
			(*pos) = i;
			ant[0] = c;
			ant[1] = j;
			break;
		}
	}
	(*pos)++;
	//printf(" pos nova %d\n",*pos);
	
}
