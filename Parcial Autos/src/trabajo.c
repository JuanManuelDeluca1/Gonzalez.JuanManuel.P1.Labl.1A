/*
 * trabajo.c
 *
 *  Created on: 23 sep. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "fecha.h"
#include "autos.h"
#include "color.h"
#include "marcas.h"
#include "servicios.h"

int inicializarTrabajo(eTrabajo vec[], int tam)
{
	int todoOk=0;
	if(vec != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
	int todoOk = 0;
	if(vec != NULL && tam>0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].isEmpty == 1)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarTrabajo(eTrabajo vec[], int tam, int id, int* pIndex)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id == id && vec[i].isEmpty == 0)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int altaTrabajo(eTrabajo trabajo[], int tamt, eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marcas[], int tamm, eServicios servicio[], int tams,int* pId)
{
	int todoOk = 0;
	int indice;
	eTrabajo trabajoAux;
	eFecha fecha;
	if(trabajo != NULL && tamt > 0 && autos != NULL && tama > 0 && pId != NULL)
	{
		if(buscarTrabajoLibre(trabajo, tamt, &indice))
		{
			if(indice == -1)
			{
				printf("Ocurrio un problema\n");
			}
			else
			{
				listarAuto(autos, tama, colores, tamc, marcas, tamm);

				printf("Ingrese el id del auto que quiera hacer el tabajo: ");
				fflush(stdin);
				scanf("%d", &trabajoAux.idAuto);

				while(buscarAutoXId(autos, tama, trabajoAux.idAuto) == -1)
				{
					listarAuto(autos, tama, colores, tamc, marcas, tamm);
					printf("El id es invalida, reingrese id: ");
					fflush(stdin);
					scanf("%d", &trabajoAux.idAuto);
				}

				listarServicio(servicio, tams);

				printf("Ingrese el id del servicio que quiera hacerle a su auto: ");
				fflush(stdin);
				scanf("%d", &trabajoAux.idServicio);

				while(trabajoAux.idServicio < 20000 || trabajoAux.idServicio > 20003)
				{
					listarServicio(servicio, tams);
					printf("Reingrese id del servicio: ");
					fflush(stdin);
					scanf("%d", &trabajoAux.idServicio);
				}

				printf("Ingrese Fecha ingreso dd/mm/aaaa: \n");
				scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
				while(validarFecha(fecha, fecha.dia, fecha.mes, fecha.anio) == 0)
                {
					printf("Reingrese Fecha ingreso dd/mm/aaaa: \n");
            	    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                }
				trabajoAux.fecha = fecha;

				trabajoAux.isEmpty = 0;
				trabajoAux.id = *pId;
				*pId = *pId + 1;
				trabajo[indice] = trabajoAux;
				todoOk = 1;
			}
		}
	}
	return todoOk;
}


int mostrarTrabajo(eTrabajo trabajos, eServicios servicios[], int tams)
{
	int todoOk = 1;
	char des[20];
	if(ingresarServicio(servicios, tams, trabajos.idServicio, des))
	{
		printf(" %d     %d     %5s   %02d/%02d/%d\n",
				trabajos.id,
				trabajos.idAuto,
				des,
				trabajos.fecha.dia,
				trabajos.fecha.mes,
				trabajos.fecha.anio);
	}
	return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tamt, eServicios servicios[], int tams)
{
    int todoOk = 0;
    int flag = 0;
    if(trabajos != NULL && tamt > 0)
    {
        system("cls");
        printf("          *** Listado de Trabajos ***\n\n");
        printf(" id      IdAuto      Servicio    F.Ingreso\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tamt; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
            	mostrarTrabajo(trabajos[i],  servicios, tams);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay trabajos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


