/*
 * fecha.c
 *
 *  Created on: 23 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"


int validarFecha(eFecha e, int dia, int mes, int anio)
{
	int todoOk = 1;
	if(dia > 31 || mes > 12 || anio < 2019)
	{
	 todoOk = 0;
	}
	return todoOk;
}





