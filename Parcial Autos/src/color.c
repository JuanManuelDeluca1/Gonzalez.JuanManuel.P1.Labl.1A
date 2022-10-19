/*
 * color.c
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int ingresarColor(eColor vec[], int tam, int idColor, char des[])
{
	int todoOk = 1;
	int flag = 1;
	if(vec != NULL && tam > 0)
	{
		todoOk = 1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id == idColor)
			{
				strcpy(des, vec[i].descripcion);
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			todoOk = -1;
		}
	}
	return todoOk;
}

int listarColor(eColor vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		printf("   *** Lista de Colores  ***\n");
		printf("  Id    Descripcion\n");
		printf("-----------------------\n");
		for(int i=0;i<tam;i++)
		{
			printf("%4d  %10s\n", vec[i].id, vec[i].descripcion);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}





