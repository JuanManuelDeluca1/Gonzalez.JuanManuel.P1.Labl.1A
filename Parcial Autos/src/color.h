/*
 * color.h
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
	int id;
	char descripcion[20];
}eColor;

#endif /* COLOR_H_ */
int ingresarColor(eColor vec[], int tam, int idColor, char des[]);
int listarColor(eColor vec[], int tam);
