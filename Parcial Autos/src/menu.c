/*
 * menu.c
 *
 *  Created on: 29 ago. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
	char opcion;
	printf("A) Alta Auto\n");
	printf("B) Modiciar Auto\n");
	printf("C) Baja Auto\n");
	printf("D) Listar Auto\n");
	printf("E) Listar Marcas\n");
	printf("F) Listar Colores\n");
	printf("G) Listar Servicio\n");
	printf("H) Alta Trabajo\n");
	printf("I) Listar Trabajo\n");
	printf("J) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%c", &opcion);

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
int menuModificar()
{
	int opcion;
	printf("1) Modificar Marca\n");
	printf("2) Modificar Color\n");
	printf("3) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}
