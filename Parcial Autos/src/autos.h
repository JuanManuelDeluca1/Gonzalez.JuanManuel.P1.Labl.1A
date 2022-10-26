/*
 * autos.h
 *
 *  Created on: 21 sep. 2022
 *      Author: juanm
 */
#include "marcas.h"
#include "color.h"

#ifndef AUTOS_H_
#define AUTOS_H_

typedef struct
{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAutos;


#endif /* AUTOS_H_ */
//inicializar
int inicializarAutos(eAutos vec[], int tam);
int buscarAutoLibre(eAutos vec[], int tam, int* pIndex);
//buscar
int buscarAuto(eAutos vec[], int tam,int id,int* pIndex);
int buscarAutoXId(eAutos x[], int tam, int id);
int buscarAutoCargado(eAutos vec[], int tam);
//alta
int altaAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm, int* pId);
//modificar
int modificarAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm);
//baja
int bajaAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm);
//mostrar
int mostrarAuto(eAutos autos, eMarcas marca[], int tamm, eColor color[], int tamc);
int listarAuto(eAutos autos[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm);
int ordenarAutosXMarcaYTipoCaja(eAutos vec[], int tama, eColor color[], int tamc, eMarcas marca[], int tamm);


int mostrarAutosPorColor(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marca[], int tamm);
int mostrarAutosPorMarca(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marca[], int tamm);
int procentajeCajaMyCajaA(eAutos autos[], int tam);
int ordenarPorCaja(eAutos autos[], int tama);;
int marcaYcolor(eAutos autos[], int tama, eColor colores[], int tamc, eMarcas marcas[], int tamm);
int marcasMasElegidas(eAutos autos[], int tama, eMarcas marcas[], int tamm);
