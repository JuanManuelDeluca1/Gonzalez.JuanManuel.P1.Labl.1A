/*
 * movies.h
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm
 */

#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct
{
	int id;
	char nombre[50];
	char genero[20];
    int tiempo;
}eMovies;

#endif /* MOVIES_H_ */

eMovies* mov_new();
eMovies* mov_newParametros(char* idStr,char* nombreStr,char* generoStr, char* tiempoStr);
void mov_delete(eMovies* mov);
int mov_setId(eMovies* this,int id);
int mov_getId(eMovies* this,int* id);
int mov_getIdCadena(eMovies* this, char* id);
int mov_setNombre(eMovies* this,char* nombre);
int mov_getNombre(eMovies* this,char* nombre);
int mov_setGenero(eMovies* this,char* genero);
int mov_getGenero(eMovies* this,char* genero);
int mov_setTiempo(eMovies* this,int tiempo);
int mov_getTiempo(eMovies* this,int* tiempo);
int mov_getTiempoCadena(eMovies* this, char* tiempo);
//Validacion
int validarGenero(char* genero);
//pedir
int pedirGenero(char* genero);
//ordenar
int ordenarGenero(void* primerParametro, void* segundoParametro);
//filtrar
int filtrarPeliculasGenero(void* pElement);
//generrar
void* mapTiempo(void* pElement);
