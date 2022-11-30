/*
 * movies.c
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"
#include "LinkedList.h"

eMovies* mov_new()
{
	eMovies* newMovies = (eMovies*)malloc(sizeof(eMovies));
	if(newMovies != NULL)
	{
		newMovies->id = 0;
		strcpy(newMovies->nombre, " ");
		strcpy(newMovies->genero, " ");
		newMovies->tiempo = 0;
	}
	return newMovies;
}

eMovies* mov_newParametros(char* idStr,char* nombreStr,char* generoStr, char* tiempoStr)
{
	eMovies* newMovies = mov_new();
	if(newMovies != NULL)
	{
		if(!(mov_setId(newMovies, atoi(idStr))&&
		mov_setNombre(newMovies, nombreStr)&&
		mov_setGenero(newMovies, generoStr)&&
		mov_setTiempo(newMovies, atoi(tiempoStr))))
		{
			mov_delete(newMovies);
			newMovies = NULL;
		}
	}
	return newMovies;
}

void mov_delete(eMovies* mov)
{
	free(mov);
}

int mov_setId(eMovies* this,int id)
{
	int todoOk = 0;
	if(this != NULL )
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int mov_getId(eMovies* this,int* id)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int mov_getIdCadena(eMovies* this, char* id)
{
	int todoOk = 0;
	if(this != NULL)
	{
		sprintf(id, "%d", this->id);
		todoOk = 1;
	}
	return todoOk;
}

int mov_setNombre(eMovies* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && strlen(nombre)< 100)
	{
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}
	return todoOk;
}
int mov_getNombre(eMovies* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int mov_setGenero(eMovies* this,char* genero)
{
	int todoOk = 0;
	if(this != NULL && strlen(genero) < 30)
	{
		strcpy(this->genero, genero);
		todoOk = 1;
	}
	return todoOk;
}
int mov_getGenero(eMovies* this,char* genero)
{
	int todoOk = 0;
	if(this != NULL)
	{
		strcpy(genero, this->genero);
		todoOk = 1;
	}
	return todoOk;
}

int mov_setTiempo(eMovies* this,int tiempo)
{
	int todoOk = 0;
	if(this != NULL && tiempo > -1)
	{
		this->tiempo = tiempo;
		todoOk = 1;
	}
	return todoOk;
}
int mov_getTiempo(eMovies* this,int* tiempo)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*tiempo = this->tiempo;
		todoOk = 1;
	}
	return todoOk;
}

int mov_getTiempoCadena(eMovies* this, char* tiempo)
{
	int todoOk = 0;
	if(this != NULL)
	{
		sprintf(tiempo, "%d", this->tiempo);
		todoOk = 1;
	}
	return todoOk;
}

int validarGenero(char* genero)
{
	int todoOk = 0;
	if(genero != NULL)
	{
		if(strcmp(genero, "Drama")==0 || strcmp(genero, "Comedy")==0 ||
		   strcmp(genero, "Animation")==0 || strcmp(genero, "Action")==0 ||
		   strcmp(genero, "Horror")==0 || strcmp(genero, "Musical")==0 ||
		   strcmp(genero, "Western")==0 || strcmp(genero, "Adventure")==0 ||
		   strcmp(genero, "Romance")==0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int ordenarGenero(void* primerParametro, void* segundoParametro)
{
	int todoOk;
	char generoP[50];
	char generoS[50];
	eMovies* newMoviesP;
	eMovies* newMoviesS;
	newMoviesP = (eMovies*)primerParametro;
	newMoviesS = (eMovies*)segundoParametro;
	mov_getGenero(newMoviesP, generoP);
	mov_getGenero(newMoviesS, generoS);
	todoOk = strcmp(generoP, generoS);
	return todoOk;
}

int pedirGenero(char* genero)
{
	int todoOk = 0;
	if(genero != NULL)
	{
		printf("Ingrese el genero de las peliculas que quiere guardar: ");
		fflush(stdin);
		scanf("%s", genero);
		while(validarGenero(genero) == 0)
		{
			printf("Reingrese el genero de las peliculas que quiere guardar: ");
			fflush(stdin);
			scanf("%s", genero);
		}
		todoOk = 1;
	}
	return todoOk;
}

int filtrarPeliculasGenero(void* pElement)
{
	int todoOk = 0;
	char genero[20];
	eMovies* auxMovies;
	auxMovies = (eMovies*)pElement;
	mov_getGenero(auxMovies, genero);
	if(strcmp(genero, "Drama")==0 || strcmp(genero, "Comedy")==0 ||
	   strcmp(genero, "Animation")==0 || strcmp(genero, "Action")==0 ||
	   strcmp(genero, "Horror")==0 || strcmp(genero, "Musical")==0 ||
	   strcmp(genero, "Western")==0 || strcmp(genero, "Adventure")==0 ||
	   strcmp(genero, "Romance")==0)
	{
		todoOk = 1;
	}
	return todoOk;
}

void* mapTiempo(void* pElement)
{
	int min = 100;
	int max = 240;
	int num = 0;
	eMovies* auxMovies = NULL;
	char id[10];
	char nombre[50];
	char genero[20];
	char tiempo[10];
	if(pElement != NULL)
	{
		if( mov_getIdCadena(pElement, id) == 1 &&
		mov_getNombre(pElement, nombre) == 1 &&
		mov_getGenero(pElement, genero) == 1 &&
		mov_getTiempoCadena(pElement, tiempo) == 1)
		{
			auxMovies =  mov_newParametros(id, nombre, genero, tiempo);
			if(auxMovies != NULL)
			{
			    num = rand() % (max - min + 1) + min;
				auxMovies->tiempo = num;
			}
		}
	}
	return auxMovies;
}




