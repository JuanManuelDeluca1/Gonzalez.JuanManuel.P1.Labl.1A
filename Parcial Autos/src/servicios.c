/*
 * servicios.c
 *
 *  Created on: 23 sep. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

int ingresarServicio(eServicios vec[], int tam, int idServicio, char des[])
{
	int todoOk = 0;
	int flag = 1;
	if(vec != NULL && tam > 0)
	{
		todoOk = 1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id == idServicio)
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

int ingresarServicioPrecio(eServicios vec[], int tam, int idServicio, float* precio)
{
	int todoOk = 0;
	int flag = 1;
	if(vec != NULL && tam > 0)
	{
		todoOk = 1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id == idServicio)
			{
				*precio = vec[i].precio;
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

int listarServicio(eServicios vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		printf("   *** Lista de Servicios  ***\n");
		printf("  Id    Descripcion    Precios\n");
		printf("-----------------------\n");
		for(int i=0;i<tam;i++)
		{
			printf("%4d  %10s  $%.2f\n", vec[i].id, vec[i].descripcion, vec[i].precio);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}


