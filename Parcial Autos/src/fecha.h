/*
 * fecha.h
 *
 *  Created on: 23 may. 2022
 *      Author: juanm
 */


#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif /* FECHA_H_ */

int validarFecha(eFecha e, int dia, int mes, int anio);

