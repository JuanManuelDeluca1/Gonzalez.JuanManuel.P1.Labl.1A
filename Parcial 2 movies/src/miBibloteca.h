/*
 * miBibloteca.h
 *
 *  Created on: 13 oct. 2022
 *      Author: juanm
 */

#ifndef MIBIBLOTECA_H_
#define MIBIBLOTECA_H_



#endif /* MIBIBLOTECA_H_ */
//menus
int menu();
void confirmarSalida(char* p);
//validaciones
int isValidarCadena(char* cadena, int longitud);
int isValidarPosicion(char* cadena, int longitud);
//Pedir
int pedirEntero(char* mensaje, int* entero);
int pedirNombreEnetero(char* cadena, char* mensaje, int tam);
int pedirCadena(char* cadena, char* mensaje, int tam);
int pedirOpcion(char* mansaje, int min, int max);
