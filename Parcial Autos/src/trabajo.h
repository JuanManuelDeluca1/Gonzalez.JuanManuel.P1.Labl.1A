/*
 * trabajo.h
 *
 *  Created on: 23 sep. 2022
 *      Author: juanm
 */
#include "fecha.h"
#include "autos.h"
#include "marcas.h"
#include "color.h"
#include "servicios.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int id;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

#endif /* TRABAJO_H_ */

//inicializar
int inicializarTrabajo(eTrabajo vec[], int tam);
//buscar
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);
int buscarTrabajo(eTrabajo vec[], int tam, int id, int* pIndex);
//alta
int altaTrabajo(eTrabajo trabajo[], int tamt, eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marcas[], int tamm, eServicios servicio[], int tams,int* pId);
//mostrar
int mostrarTrabajo(eTrabajo trabajos, eServicios servicios[], int tams);
int listarTrabajos(eTrabajo trabajos[], int tamt, eServicios servicios[], int tams);

