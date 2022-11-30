/*
 * Controller.h
 *
 *  Created on: 23 nov. 2022
 *      Author: juanm
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
//cargar
int controller_cargarPeluclasTexto(char* path , LinkedList* pArrayListMovies);
//listar
int controller_listarMovies(LinkedList* pArrayListMovies);
//generar
LinkedList* controller_generarTiempo(LinkedList* pArrayListMovies);
//guardar con generp
int controller_guardarPeliculasConGenero(char* path,  LinkedList* pArrayListMovies);
//Ordenar
int  controller_ordenarMovies(LinkedList* pArrayListMovies);
//guardar
int controller_guardarPelisTexto(char* path , LinkedList* pArrayListMovies);




