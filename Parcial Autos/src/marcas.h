/*
 * marcas.h
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */

#ifndef MARCAS_H_
#define MARCAS_H_

typedef struct
{
	int id;
	char descripcion[20];
}eMarcas;


#endif /* MARCAS_H_ */
int ingresarMarcas(eMarcas vec[], int tam, int idMarcas, char des[]);
int listarMarcas(eMarcas vec[], int tam);
