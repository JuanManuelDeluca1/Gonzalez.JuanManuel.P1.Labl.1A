/*
 * Parser.c
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"
#include "LinkedList.h"
#include "movies.h"

int parser_MoviesFromText(FILE* pFile , LinkedList* pArrayListMovies)
{
	int todoOk = -1;
	char id[50];
	char nombre[50];
	char genero[50];
	char tiempo[30];
	char encabezado[3][20];
	eMovies* auxMovie;
	if(pArrayListMovies != NULL && pFile != NULL)
	{
		todoOk = 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", encabezado[0], encabezado[1], encabezado[2], encabezado[3]);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, genero, tiempo);
			auxMovie = mov_newParametros(id, nombre, genero, tiempo);
			if(auxMovie != NULL)
			{
				if(ll_add(pArrayListMovies, auxMovie) == 0)
				{
					todoOk = 1;
				}
			}
		}

	}
	fclose(pFile);
    return todoOk;
}
