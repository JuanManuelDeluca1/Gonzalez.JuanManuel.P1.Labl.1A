/*
 * marcas.c
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcas.h"

int ingresarMarcas(eMarcas vec[], int tam, int idMarcas, char des[])
{
	int todoOk = 1;
	int flag = 1;
	if(vec != NULL && tam > 0)
	{
		todoOk = 1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id == idMarcas)
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


int listarMarcas(eMarcas vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		printf("   *** Lista de Marcas  ***\n");
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









