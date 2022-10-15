/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "lifegame.h"
#include <stdlib.h>
#include <unistd.h>
/* added the libary to use printf because it was not included*/
#include <stdio.h>

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50
#define worldWidth 25
#define worldHeigth 25 

#define gridWidth 3
#define gridHeigth 3

/* add whatever other includes here */
/* making the functions here*/
int finalStates ();
void makeWorld();

int world[worldHeigth][worldWidth];

/* functions to implement */

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(void){
	int n;

	/* TODO: initialize the world */
	makeWorld();


	for (n = 0; n < NUM_GENERATIONS; n++){
		next_generation();
		/* TODO (optional): Visualise world in each generation */
	}

	/* TODO: output final world state */


	return 0;
}
void makeWorld(){ 
	for (int i=0; i <= worldHeigth; i++){ 
		for (int j=0; j <= worldWidth; j++){ 
			world[i][j] = 0;
		}
	} 
	
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) and set_next_state(x,y) */
		/* loop over the world with using a grid*/ 
		int topLeft, top, topRight, right, bottomRight, bottom, bottomLeft, Left; 
		

		for (int i = 0; i <worldHeigth; i++){ 
			for (int j =0; j<worldWidth; j++){ 
				/* world = [height][width]*/
				/* the 8 cell around the current cell*/
				topLeft = world[i-1][j-1]; 
				top = world[i-1][j]; 
				topRight = world[i-1][j +1]; 
				right = world[i][j+1]; 
				bottomRight = world[i+1][j+1]; 
				bottom = world[i+1][j]; 
				bottomLeft = world [i][j-1]; 
				Left = world[i][j-1]; 
				int grid [gridWidth * gridHeigth] = {topLeft,top,topRight,right,bottomRight,bottom,bottomLeft,Left};
				
				/* if it is 0 it is death*/
				if (world[i][j] == 0){
					int aliveCell = 0;
					int deathCell = 0;  
					for (int a =0; a <= (gridWidth*gridHeigth); a++) { 						
						if (grid [a] == 1){ 
							++aliveCell;
						}
						else if (grid[a] == 0){ 
							++deathCell; 
						}					
					}
					if (aliveCell < 2 || aliveCell > 3) {
						world[i][j] = 0; 
					}
					else if (deathCell == 3) {
						world[i][j] = 1; 
					}
				}
			}
		
		}

	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */

}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */

}

int finalStates (){ 
	return 0; 
}
