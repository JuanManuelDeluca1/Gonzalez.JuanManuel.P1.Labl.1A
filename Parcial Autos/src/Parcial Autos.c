/*
 ============================================================================
 Name        : Parcail.c
 Author      : Juan Manuel Gonzalez Deluca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "autos.h"
#include "marcas.h"
#include "color.h"
#include "servicios.h"
#include "trabajo.h"

#define TAM 10
#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMT 100

int main(void)
{
	setbuf(stdout,NULL);
	int flagA = 0;
	int flagT = 0;
	int flagCargaA = 0;
	int flagCargaT = 0;
	int indice;
	int indiceT;
	char salir;
	int idAutos = 10000;
	int idTrabajo = 30000;
	eAutos autos[TAM];
	eTrabajo trabajo[TAMT];
	eMarcas marcas[TAMM] =
	{
		{1000, "Renault"},
		{1001, "Ford"},
		{1002, "Fiat"},
		{1003, "Chevrolet"},
		{1004, "Peugeot"}
	};
	eColor colores[TAMC] =
	{
		{5000, "Negro"},
		{5001, "Blanco"},
		{5002, "Rojo"},
		{5003, "Gris"},
		{5004, "Azul"}
	};
	eServicios servicios[TAMS] =
	{
		{20000, "Lavado", 450},
		{20001, "Pulido", 500},
		{20002, "Encerado", 600},
		{20003, "Completo", 900}
	};
	if(flagA == 0 && flagT == 0)
	{
		inicializarAutos(autos, TAM);
		buscarAutoLibre(autos, TAM, &indice);
		inicializarTrabajo(trabajo, TAMT);
		buscarTrabajoLibre(trabajo, TAMT, &indiceT);
		flagA = 1;
		flagT = 1;
	}
	do
	{
		switch(menu())
		{
		case 'A':
			if(flagA == 1)
			{
				altaAuto(autos, TAM, colores, TAMC, marcas, TAMM, &idAutos);
				flagCargaA = 1;
			}
			else
			{
				printf("Ya no hay mas espacio para ingresar otro auto\n");
			}
		break;
		case 'B':
			if(flagCargaA == 1)
			{
				modificarAuto(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Primero debes carga un auto");
			}
		break;
		case 'C':
			if(flagCargaA == 1)
			{
				bajaAuto(autos, TAM, colores, TAMC, marcas, TAMM);
				if(buscarAutoCargado(autos, TAM) == 0)
				{
					flagCargaA = 0;
				}
			}
			else
			{
				printf("Primero debes carga un auto");
			}
		break;
		case 'D':
			if(flagCargaA == 1)
			{
				ordenarAutosXMarcaYTipoCaja(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'E':
			listarMarcas(marcas, TAMM);
		break;
		case 'F':
			listarColor(colores, TAMC);
		break;
		case 'G':
			listarServicio(servicios, TAMS);
		break;
		case 'H':
			if(flagT == 1 && flagCargaA == 1)
			{
				altaTrabajo(trabajo, TAMT, autos, TAM, colores, TAMC, marcas, TAMM, servicios, TAMS, &idTrabajo);
				flagCargaT = 1;
			}
			else
			{
				printf("Ya no hay espacio para otro trabajo o no hay autos cargados\n");
			}

		break;
		case 'I':
			if(flagCargaT == 1)
			{
				listarTrabajos(trabajo, TAMT, servicios, TAMS);
			}
			else
			{
				printf("Debes cargar un trabajo primero\n");
			}
		break;
		case 'J':
			if(flagCargaA == 1)
			{
				mostrarAutosPorColor(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'K':
			if(flagCargaA == 1)
			{
				mostrarAutosPorMarca(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'L':
			if(flagCargaA == 1)
			{
				procentajeCajaMyCajaA(autos, TAM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'M':
			if(flagCargaA == 1)
			{
				ordenarPorCaja(autos, TAM);
				listarAuto(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'N':
			if(flagCargaA == 1)
			{
				marcaYcolor(autos, TAM, colores, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'O':
			if(flagCargaA == 1)
			{
				marcasMasElegidas(autos, TAMC, marcas, TAMM);
			}
			else
			{
				printf("Debe cargar un auto primero\n");
			}
		break;
		case 'P':
			if(flagCargaT == 1)
			{
				trabajosDeAuto(trabajo, TAMT, autos, TAM, colores, TAMC, marcas, TAMM, servicios, TAMS);
			}
			else
			{
				printf("Debe cargar un trabajo antes\n");
			}
		break;
		case 'Q':
			if(flagCargaT == 1)
			{
				costoDeAuto(trabajo, TAMT, autos, TAM, colores, TAMC, marcas, TAMM, servicios, TAMS);
			}
			else
			{
				printf("Debe cargar un trabajo antes\n");
			}
		break;
		case 'R':
			if(flagCargaT == 1)
			{
				servicioPorAuto(trabajo, TAMT, servicios, TAMS);
			}
			else
			{
				printf("Debe cargar un trabajo antes\n");
			}
		break;
		case 'S':
			if(flagCargaT == 1)
			{
				servicioPorFecha(trabajo, TAMT, servicios, TAMS);
			}
			else
			{
						printf("Debe cargar un trabajo antes\n");
			}
		break;
		case 'T':
			confirmarSalida(&salir);
		break;
		default:
			printf("Opcion incocrrecta\n");
		}
		system("pause");
	}while(salir != 's');
	return 0;
}
