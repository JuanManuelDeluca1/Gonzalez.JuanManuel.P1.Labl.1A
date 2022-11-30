/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "miBibloteca.h"


int main(void)
{
	setbuf(stdout,NULL);
	srand(time(NULL));
	char salir;
	LinkedList* listMovies = ll_newLinkedList();
	int flagCarga = 0;
	int flagOrden = 0;
	do
	{
		switch(menu())
		{
		case 1:
			if(controller_cargarPeluclasTexto("movies.csv", listMovies)==1)
			{
				printf("El archivo se cargpo correcta mente\n");
				flagCarga = 1;
			}
			else
			{
				printf("Ocurrio un problema\n");
			}
		break;
		case 2:
			if(flagCarga == 1)
			{
				controller_listarMovies(listMovies);
			}
			else
			{
				printf("Primero debe cargar el archivo\n");
			}
		break;
		case 3:
			if(flagCarga == 1)
			{
				listMovies= controller_generarTiempo(listMovies);
				if(listMovies != NULL)
				{
					printf("Se genero el rating correcta mente\n");
				}
				else
				{
					printf("Ocurrio un problema al generar el rating\n");
				}
			}
			else
			{
				printf("Primero debe cargar el archivo\n");
			}
		break;
		case 4:
			if(flagCarga == 1)
			{
				if(controller_guardarPeliculasConGenero("moviesGenero.csv", listMovies)==1)
				{
					printf("Se guardo correcta mente\n");
				}
				else
				{
					printf("Ocurrio un problema\n");
				}
			}
			else
			{
				printf("Primero debe cargar el archivo\n");
			}
		break;
		case 5:
			if(flagCarga == 1)
			{
				 if( controller_ordenarMovies(listMovies)==1)
				 {
					 printf("Se ordeno correcta mente\n");
					 flagOrden = 1;
				 }
			}
			else
			{
				printf("Primero debe cargar el archivo\n");
			}
		break;
		case 6:
			if(flagCarga == 1)
			{
				if(flagOrden == 1)
				{
					if(controller_guardarPelisTexto("moviesOrdenadas.txt", listMovies)==1)
					{
						printf("Se guardo el archivo correctamente\n");
					}
					else
					{
						printf("Ocurrio un problema\n");
					}
				}
				else
				{
					printf("Primero debes ordenar las pelis\n");
				}
			}
			else
			{
				printf("Primero debe cargar el archivo\n");
			}
		break;
		case 7:
			confirmarSalida(&salir);
		break;
		default:
			printf("Ingrese una opcion valida\n");
		}
	}while(salir != 's');
	ll_deleteLinkedList(listMovies);
	return 0;
}
