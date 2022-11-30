/*
 * miBibloteca.c
 *
 *  Created on: 13 oct. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "miBibloteca.h"

int menu()
{
	int opcion;
	printf("1) Carga de archivos\n");
	printf("2) Imprimir Lista\n");
	printf("3) Asignar Tiempo\n");
	printf("4) Filtrar genero\n");
	printf("5) Ordenar peliculas\n");
	printf("6) Guardar peliculas\n");
	printf("7) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}
void confirmarSalida(char* p)
{
	char confirmar;
	printf("Confirmar salida?:");
	fflush(stdin);
	scanf("%c", &confirmar);

	*p = confirmar;
}


int isValidarCadena(char* cadena, int longitud)
{
	int todoOk = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(int i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

int isValidarPosicion(char* cadena, int longitud)
{
	int todoOk = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(int i=0;i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

int pedirEntero(char* mensaje, int* entero)
{
	char numero[50];
	int tam;
	int todoOk = 0;
	while(todoOk == 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		tam = strlen(numero);
		for(int i=0;i<tam;i++)
		{
			if((i==0 && numero[i]=='-') || (isdigit(numero[i])==1))
			{
				todoOk = 1;
			}
			else
			{
				printf("Ocurrio un error\n");
			}
		}
	}
	*entero = atoi(numero);
	return todoOk;
}

int pedirNombreEnetero(char* cadena, char* mensaje, int tam)
{
	int todoOk = 0;
	if(cadena != NULL && mensaje != NULL)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
		while(isValidarCadena(cadena, tam)==1)
		{
			printf("Reingrese Cadena\n");
			fflush(stdin);
			scanf("%[^\n]", cadena);
		}
		todoOk = 1;
	}
	return todoOk;
}

int pedirCadena(char* cadena, char* mensaje, int tam)
{
	int todoOk = 0;
	if(cadena != NULL && mensaje != NULL)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		while(isValidarCadena(cadena, tam)==1)
		{
			printf("Reingrese Cadena\n");
			fflush(stdin);
			gets(cadena);
		}
		todoOk = 1;
	}
	return todoOk;
}

int pedirOpcion(char* mensaje, int min, int max)
{
	int opcion;
	printf(mensaje);
	fflush(stdin);
	scanf("%d", &opcion);
	while(opcion<min||opcion>max)
	{
		printf("Error\n");
		printf(mensaje);
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}

