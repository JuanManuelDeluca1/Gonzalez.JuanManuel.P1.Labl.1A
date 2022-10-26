/*
 * autos.c
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "marcas.h"
#include "color.h"
#include "menu.h"

int inicializarAutos(eAutos vec[], int tam)
{
	int todoOk = 0;
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

int buscarAutoLibre(eAutos vec[], int tam, int* pIndex)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0 && pIndex != NULL)
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

int buscarAuto(eAutos vec[], int tam,int id,int* pIndex)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].isEmpty == 0 && vec[i].id == id)
			{
				*pIndex=i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarAutoXId(eAutos x[], int tam, int id)
{
	int todoOk = -1;
	if(x != NULL && tam > 0)
	{
		for(int i=0;i<tam; i++)
		{
			if(x[i].isEmpty == 0 && x[i].id == id)
			{
				todoOk = i;
				break;
			}
		}
	}
	return todoOk;
}

int buscarAutoCargado(eAutos vec[], int tam)
{
	int todoOk = -1;
	if(vec != NULL && tam > 0)
	{
		todoOk = 0;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].isEmpty == 0)
			{
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;
}


int altaAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm, int* pId)
{
	int todoOk = 0;
	int indice;
	eAutos autoAux;
	if(autos != NULL && tama > 0 && color != NULL && tamc > 0 && marca != NULL && tamm > 0 && pId != NULL)
	{
		if(buscarAutoLibre(autos, tama, &indice))
		{
			if(indice == -1)
			{
				printf("Ya no hay mas espacio\n");
			}
			else
			{
				listarMarcas(marca, tamm);

				printf("Ingrese el id de la marca de su auto:");
				scanf("%d", &autoAux.idMarca);
				while(autoAux.idMarca < 1000 || autoAux.idMarca > 1004)
				{
					printf("Id ingresado incorrecto, reingrese id:");
					scanf("%d", &autoAux.idMarca);
				}

				listarColor(color, tamc);

				printf("Ingrese el id del color de su auto: ");
				scanf("%d", &autoAux.idColor);
				while(autoAux.idColor < 5000 || autoAux.idColor > 5004)
				{
					printf("Reingrese el id del color de su auto: ");
					scanf("%d", &autoAux.idColor);
				}
				printf("Ingrese el tipo de caja de su auto m:manueal o a:auto: ");
				fflush(stdin);
				scanf("%c", &autoAux.caja);
				while(autoAux.caja != 'm' && autoAux.caja != 'a')
				{
					printf("Reingrese m o a solamente: ");
					fflush(stdin);
					scanf("%c", &autoAux.caja);
				}

				autoAux.isEmpty = 0;
				autoAux.id = *pId;
				*pId = *pId + 1;
				autos[indice] = autoAux;
				todoOk = 1;
			}
		}
		else
		{
			printf("Ya no hay espacio disponible\n");
		}
	}
	return todoOk;
}

int modificarAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm)
{
	int todoOk = 1;
	int id;
	int indice;
	char desColor [20];
	char desMarca[20];
	char salir;
	if(autos != NULL && tama > 0 && color != NULL && tamc > 0 && marca != NULL && tamm > 0)
	{
		listarAuto(autos, tama, color, tamc, marca, tamm);
		printf("Ingrese id del auto: ");
		scanf("%d", &id);
		if(buscarAuto(autos, tama, id, &indice))
		{
			if(indice == -1)
			{
				printf("No hay auto con ese id");
			}
			else
			{
				mostrarAuto(autos[indice], marca, tamm, color, tamc);
				do
				{
					switch(menuModificar())
					{
					case 1:
						listarMarcas(marca, tamm);

						if(ingresarMarcas(marca, tamm, autos[indice].idMarca, desMarca)==1)
						{
							printf("Su marca acutal es: %s\n", desMarca);
						}

						printf("Ingrese el id de su nueva marca:\n");
						scanf("%d", &autos[indice].idMarca);
						while(autos[indice].idMarca < 1000 || autos[indice].idMarca > 1004)
						{
							printf("Id ingresado incorrecto, reingrese id:");
							scanf("%d", &autos[indice].idMarca);
						}

					break;
					case 2:
						listarColor(color, tamc);

						if(ingresarColor(color, tamc, autos[indice].idColor, desColor)==1)
						{
						   printf("Su color actual es: %s\n" ,desColor);
						}

						printf("Ingrese el id de su nuevo color:\n");
						scanf("%d", &autos[indice].idColor);
						while(autos[indice].idColor < 5000 ||autos[indice].idColor > 5004)
						{
							printf("Reingrese el id del color de su auto: ");
							scanf("%d", &autos[indice].idColor);
						}
					break;
					case 3:
						confirmarSalida(&salir);
					break;
					default:
						printf("Opcion incorecta\n");
					}
				}while(salir != 's');
			}
		}


	}
	return todoOk;
}

int bajaAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirmar;
	if(autos != NULL && tama > 0 && color != NULL && tamc > 0 && marca != NULL && tamm > 0)
	{

		listarAuto(autos, tama, color, tamc, marca, tamm);
		printf("Ingrese id del auto: ");
		scanf("%d", &id);
		if(buscarAuto(autos, tama, id, &indice))
		{
			if(indice == -1)
			{
				printf("No hay auto con ese id");
			}
			else
			{
				printf("Ustes quiere dar de baja este auto s/n?: ");
				fflush(stdin);
				scanf("%c", &confirmar);
				while(confirmar != 's' && confirmar != 'n')
				{
					printf("Respuesta incorrecta solo puede poner s/n: ");
					fflush(stdin);
					scanf("%c", &confirmar);
				}
				if(confirmar == 's')
				{
					printf("Baja fue realizada correcta mente\n");
					autos[indice].isEmpty = 1;
				}
				else
				{
					printf("Se cancelo la baja correcta mente \n");
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAuto(eAutos autos, eMarcas marca[], int tamm, eColor color[], int tamc)
{
	int todoOk=0;
	char desMarca[20];
	char desColor[20];
	if(ingresarMarcas(marca, tamm, autos.idMarca, desMarca)==1 &&
	   ingresarColor(color, tamc, autos.idColor, desColor)==1)
	{
		printf("%d   %5s    %5s   %5c\n",
				autos.id,
				desMarca,
				desColor,
				autos.caja
				);
	}
	return todoOk;
}

int listarAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm)
{
	int todoOk = 0;
	if(autos != NULL && tama>0 && marca != NULL && tamm>0 && color != NULL && tamc>0)
	{
		 printf("          *** Listado de Autos ***\n\n");
		 printf("id     Marca     Color    Caja\n");
	     printf("-----------------------------------------------------\n");
	     for(int i=0;i<tama;i++)
	     {
	    	 if(autos[i].isEmpty == 0)
	    	 {
	    		 mostrarAuto(autos[i], marca, tamm, color, tamc);
	    	 }
	     }
	     todoOk = 1;
	}
	return todoOk;
}

int ordenarAutosXMarcaYTipoCaja(eAutos vec[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm)
{
    int todoOk = 0;
    int mostrar = 0;
    eAutos auxAutos;
    if(vec != NULL && tama > 0)
    {
        for(int i=0; i < tama -1; i++)
        {
            for(int j= i + 1; j < tama; j++)
            {
                if( ((vec[i].idMarca == vec[j].idMarca) &&  (vec[i].caja > vec[j].caja) )
                	|| ((vec[i].idMarca != vec[j].idMarca) &&(vec[i].idMarca > vec[j].idMarca)) )
                {
                	auxAutos = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxAutos;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" ORDENADO POR MARCA Y CAJA\n");
        	listarAuto(vec, tama,  color, tamc, marca, tamm);
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAutosPorColor(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marca[], int tamm)
{
	int todoOk = 0;
	int id;
	int flag = 0;
	if(autos != NULL && tama > 0 && colores != NULL && tamc > 0)
	{
		listarColor(colores, tamc);
		printf("ingrese id del color que quier ver los autos: ");
		fflush(stdin);
		scanf("%d", &id);
		while(id < 5000 && id > 5004)
		{
			printf("Reingrese el id del color: ");
			fflush(stdin);
			scanf("%d", &id);
		}
		printf("          *** Listado de Autos ***\n\n");
		printf("id    Marca    Color   Caja\n");
		printf("-----------------------------------------------------\n");
		for(int i=0;i<tama;i++)
		{
			if(autos[i].idColor == id)
			{
				mostrarAuto(autos[i], marca, tamm, colores, tamc);
				flag = 1;
			}
		}
	}
	if(flag == 0)
	{
		printf("No hay autos con ese color\n");
	}
	return todoOk;
}

int mostrarAutosPorMarca(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marca[], int tamm)
{
	int todoOk = 0;
	int id;
	int flag = 0;
	if(autos != NULL && tama > 0 && colores != NULL && tamc > 0)
	{
		listarMarcas(marca, tamm);
		printf("ingrese id de la marca que quier ver los autos: ");
		fflush(stdin);
		scanf("%d", &id);
		while(id < 1000 && id > 1004)
		{
			printf("Reingrese el id de la marca: ");
			fflush(stdin);
			scanf("%d", &id);
		}
		printf("          *** Listado de Autos ***\n\n");
		printf("id    Marca    Color   Caja\n");
		printf("-----------------------------------------------------\n");
		for(int i=0;i<tama;i++)
		{
			if(autos[i].idMarca == id)
			{
				mostrarAuto(autos[i], marca, tamm, colores, tamc);
				flag = 1;
			}
		}
	}
	if(flag == 0)
	{
		printf("No hay autos con ese Marca\n");
	}
	return todoOk;
}

int procentajeCajaMyCajaA(eAutos autos[], int tam)
{
	int todoOk = 0;
	int contadortotal = 0;
	int contadorManual = 0;
	int contadorAuto = 0;
	float promAuto;
	float promManual;
	if(autos != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(autos[i].isEmpty == 0)
			{
				contadortotal++;
				if(autos[i].caja == 'm')
				{
					contadorManual++;
				}
				if(autos[i].caja == 'a')
				{
					contadorAuto++;
				}
			}
		}
		promAuto = (float) contadorManual / contadortotal * 100;
		promManual = (float) contadorAuto / contadortotal * 100;
		if(contadorManual > 0)
		{
			printf("El promedio de autos con caja manual es: %.2f\n" , promManual);
		}
		else
		{
			printf("Todos los autos son automaticos\n");
		}
		if(contadorAuto > 0)
		{
			printf("El promedio de autos con caja automatica es: %.2f\n", promAuto);
		}
		else
		{
			printf("Todos los autos son manual\n");
		}
	}
	return todoOk;
}

int ordenarPorCaja(eAutos autos[], int tama)
{
	int todoOk = 0;
	char cajaAux;
	if(autos != NULL && tama > 0)
	{
		for(int i=0;i<tama-1;i++)
		{
			for(int j= i + 1;j<tama;j++)
			{
				if(autos[j].caja == 'a')
				{
					cajaAux = autos[j].caja;
					autos[j].caja = autos[i].caja;
					autos[i].caja = cajaAux;
				}
			}
		}
		todoOk =1;
	}
	return todoOk;
}

int marcaYcolor(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marcas[], int tamm)
{
	int todoOk = 0;
	int idColor;
	int idMarca;
	int flag = 0;
	if(autos != NULL && tama > 0 && colores != NULL && tamc > 0 && marcas != NULL && tamm > 0)
	{
		listarMarcas(marcas, tamm);
		printf("ingrese id de la marca que quier ver los autos: ");
		fflush(stdin);
		scanf("%d", &idMarca);
		while(idMarca < 1000 && idMarca > 1004)
		{
			printf("Reingrese el id de la marca: ");
			fflush(stdin);
			scanf("%d", &idMarca);
		}
		listarColor(colores, tamc);
		printf("ingrese id del color que quier ver los autos: ");
		fflush(stdin);
		scanf("%d", &idColor);
		while(idColor < 5000 && idColor > 5004)
		{
			printf("Reingrese el id del color: ");
			fflush(stdin);
			scanf("%d", &idColor);
		}
		for(int i=0;i < tama; i++)
		{
			if(autos[i].idMarca == idMarca && autos[i].idColor == idColor)
			{
				mostrarAuto(autos[i], marcas, tamm, colores, tamc);
				flag = 1;
			}
		}
		todoOk = 1;
	}
	if(flag == 0)
	{
		printf("No se encontro autos de esa marca y ese color\n");
	}
	return todoOk;
}

int marcasMasElegidas(eAutos autos[], int tama, eMarcas marcas[], int tamm)
{
	int todoOk = 0;
	int idmarcaMasElegida;
	int marcaMasElegida;
	int ford = 0;
	int renault = 0;
	int chevrolet = 0;
	int fiat = 0;
	int peugeot = 0;
	char desMarca[20];
	if(autos != NULL && tama > 0 && marcas != NULL && tamm > 0)
	{
		for(int i=0;i<tama;i++)
		{
			if(autos[i].idMarca == 1000)
			{
				renault++;
			}
			if(autos[i].idMarca == 1001)
			{
				ford++;
			}
			if(autos[i].idMarca == 1002)
			{
				fiat++;
			}
			if(autos[i].idMarca == 1003)
			{
				chevrolet++;
			}
			if(autos[i].idMarca == 1004)
			{
				peugeot++;
			}
		}
		if(renault > ford && renault > fiat && renault > chevrolet && renault > peugeot)
		{
			marcaMasElegida = renault;
			idmarcaMasElegida = 1000;
		}
		else if(ford > fiat && ford > chevrolet && ford > peugeot)
		{
			marcaMasElegida = ford;
			idmarcaMasElegida = 1001;
		}
		else if(fiat > ford && fiat > chevrolet && fiat > peugeot)
		{
			marcaMasElegida = fiat;
		    idmarcaMasElegida = 1002;
		}
		else if(chevrolet > peugeot)
		{
			marcaMasElegida = chevrolet;
			idmarcaMasElegida = 1003;
		}
		else
		{
			marcaMasElegida = peugeot;
			idmarcaMasElegida = 1004;
		}
		todoOk =1;
	}
	if(ingresarMarcas(marcas, tamm, idmarcaMasElegida, desMarca) == 1)
	{
		printf("La marca mas elegia es: %s con %d\n", desMarca, marcaMasElegida);
	}

	return todoOk;
}
