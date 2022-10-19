/*
 * servicios.h
 *
 *  Created on: 23 sep. 2022
 *      Author: juanm
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct
{
	int id;
	char descripcion[20];
	float precio;
}eServicios;

#endif /* SERVICIOS_H_ */

int ingresarServicio(eServicios vec[], int tam, int idServicio, char des[]);
int ingresarServicioPrecio(eServicios vec[], int tam, int idServicio, float* precio);
int listarServicio(eServicios vec[], int tam);
