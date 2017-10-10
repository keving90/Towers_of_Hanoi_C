/*****************************************************************************************
Prologue

UCSC Extension: Advanced C Programming

Instructor: Rajainder A. Yeldandi

Author: Kevin Geiszler

Assignment Number: 10, Towers of Hanoi

Topics: Recursion

File Name: assignment10_KevinGeiszler.c

Date: 2/23/2017

Objective: This program displays the "Towers of Hanoi" problem, and uses a recursive
		   implementation to solve the problem. The user has the ability to enter how
		   many disks they would like to use in the program.
		   
Comments:  The "Towers of Hanoi" problem starts with a user-defined number of disks on a
		   pole. Each disk is smaller than the disk below it. The program moves this stack
		   from Pole A to Pole C. Only one disk can be moved at a time, and a larger disk
		   cannot be placed on top of a smaller disk. There is an auxiliary pole that can
		   be used as a "place holder".

*****************************************************************************************/

//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************/

//Function prototypes
void moveDisks(FILE *pOutFile, int n, char fromPole, char toPole, char auxPole, int finalMove);

/****************************************************************************************/

//The main function
int main(int argc, char *argv[])
{
	int numDisks;
	FILE *pOutFile;
	char myString[20];
	
	//Check command line arguments
	if (argc != 2)
	{
		printf("Error! Need following file usage: %s outputFile\n", argv[0]);
		exit(1);
	}
	
	//Check if the output file has been successfully opened
	if ((pOutFile = fopen(argv[1], "w")) == NULL)
	{
		printf("Error opening output file: %s\n", argv[1]);
		exit(1);
	}

	printf("\nWelcome to the Towers of Hanoi program!\n");
	fprintf(pOutFile, "Welcome to the Towers of Hanoi program!\n");

	while(1)
	{
		printf("\n--------------------------------------------------\n");
		fprintf(pOutFile, "\n--------------------------------------------------\n");
		
		printf("\nEnter the number of disks, or enter 'q' to quit: ");
		
		if(!scanf(" %d", &numDisks))
			break;
			
		printf("\n");
	
		fprintf(pOutFile, "\nThe user chose to use %d disks.\n\n", numDisks);
	
		moveDisks(pOutFile, numDisks, 'A', 'C', 'B', numDisks);
	}
	
	printf("\nThank you for using my program.\n\n");
	fprintf(pOutFile, "\nThe user has chosen to quit the program.\n\n", numDisks);
	
	return 0;
}

/****************************************************************************************/

//Uses a recursive implementation to solve the Towers of Hanoi problem

void moveDisks(FILE *pOutFile, int n, char fromPole, char toPole, char auxPole, int finalMove)
{
	if (n == 1)
	{	
		if (finalMove == 1)
		{
			printf("Final move: ");
			fprintf(pOutFile, "Final move: ");
		}
	
		printf("Move Disk 1 from Pole %c to Pole %c.\n\n", fromPole, toPole);
		fprintf(pOutFile, "Move Disk 1 from Pole %c to Pole %c.\n\n", fromPole, toPole);
				
		return;
	}
	else
	{
		moveDisks(pOutFile, n-1, fromPole, auxPole, toPole, finalMove);
		
		if (n == finalMove)
		{
			printf("Final move: ");
			fprintf(pOutFile, "Final move: ");
		}
		
		printf("Move Disk %d from Pole %c to Pole %c.\n\n", n, fromPole, toPole);
		fprintf(pOutFile, "Move Disk %d from Pole %c to Pole %c.\n\n", n, fromPole, toPole);
		
		finalMove--;
				
		moveDisks(pOutFile, n-1, auxPole, toPole, fromPole, finalMove);
	}
}

/****************************************************************************************/