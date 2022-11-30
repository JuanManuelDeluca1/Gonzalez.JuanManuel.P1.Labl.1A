/*
 * Controller.c
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "movies.h"
#include "miBibloteca.h"

int controller_cargarPeluclasTexto(char* path , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	FILE* f;
	if(pArrayListMovies !=NULL)
	{
		f = fopen(path, "r");
		if(f != NULL)
		{
			if(parser_MoviesFromText(f, pArrayListMovies)==1)
			{
				todoOk=1;
			}
		}
	}
	fclose(f);
    return todoOk;
}

int controller_listarMovies(LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	int tam;
	int id;
	char nombre[100];
	char genero[30];
	int tiempo;
	eMovies* auxMovies;
	if(pArrayListMovies != NULL)
	{
		tam=ll_len(pArrayListMovies);
		printf("\nId|Pelicula|Genero|Rating\n");
		for(int i=0;i<tam;i++)
		{
			auxMovies=(eMovies*)ll_get(pArrayListMovies, i);
			mov_getId(auxMovies, &id);
			mov_getNombre(auxMovies, nombre);
			mov_getGenero(auxMovies, genero);
			mov_getTiempo(auxMovies, &tiempo);
			printf("%d,%s,%s,%d\n", id, nombre, genero, tiempo);
			todoOk = 1;
		}
	}
    return todoOk;
}


LinkedList* controller_generarTiempo(LinkedList* pArrayListMovies)
{
	LinkedList* auxList = NULL;
	if(pArrayListMovies != NULL)
	{
		auxList = ll_map(pArrayListMovies, mapTiempo);
		if(auxList != NULL)
		{
			controller_listarMovies(auxList);

		}
	}
	return auxList;
}


int controller_guardarPeliculasConGenero(char* path,  LinkedList* pArrayListMovies)
{
	int todoOk = -1;
	int tamAux;
	char generoAux[10];
	int id;
	char nombre[50];
	char genero[10];
	int tiempo;
	eMovies* auxMovies;
	LinkedList* auxList = NULL;
	FILE* f;
	if(pArrayListMovies != NULL)
	{
		f = fopen(path, "w");
		if(f != NULL)
		{
			auxList = ll_filter(pArrayListMovies, filtrarPeliculasGenero);
			if(auxList != NULL)
			{
				todoOk = 0;
			}
		}
	}
	if(todoOk == 0)
	{
		pedirGenero(generoAux);
		tamAux = ll_len(auxList);
		for(int i=0;i<tamAux;i++)
		{
			auxMovies = (eMovies*)ll_get(auxList, i);
			if(strcmp(generoAux, auxMovies->genero)==0)
			{
				mov_getId(auxMovies, &id);
				mov_getNombre(auxMovies, nombre);
				mov_getGenero(auxMovies, genero);
				mov_getTiempo(auxMovies, &tiempo);
				fprintf(f,"%d,%s,%s,%d\n", id, nombre, genero, tiempo);
				todoOk = 1;
			}
		}
		if(todoOk == 0)
		{
			printf("No se encotro ningun pelicula con ese genero\n");
		}
	}
	fclose(f);
	ll_deleteLinkedList(auxList);
    return todoOk;
}

int controller_ordenarMovies(LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	if(pArrayListMovies != NULL)
	{
		ll_sort(pArrayListMovies, ordenarGenero, 1);
		todoOk = 1;

	}
    return todoOk;
}

int controller_guardarPelisTexto(char* path , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	int tam;
	int id;
	char nombre[50];
	char genero[20];
	int tiempo;
	FILE* f;
	eMovies* auxMovies=NULL;
	tam=ll_len(pArrayListMovies);
	if(path != NULL && pArrayListMovies != NULL)
	{
		f = fopen(path, "w");
		if(f != NULL)
		{
			fprintf(f,"\nId|Pelicula|Genero|Duracion\n");
			for(int i=0;i<tam;i++)
			{
				auxMovies = (eMovies*)ll_get(pArrayListMovies, i);
				mov_getId(auxMovies, &id);
				mov_getNombre(auxMovies, nombre);
				mov_getGenero(auxMovies, genero);
				mov_getTiempo(auxMovies, &tiempo);
				fprintf(f,"%d,%s,%s,%d\n", id, nombre, genero, tiempo);
				todoOk = 1;

			}
		}
	}
	fclose(f);
    return todoOk;
}






