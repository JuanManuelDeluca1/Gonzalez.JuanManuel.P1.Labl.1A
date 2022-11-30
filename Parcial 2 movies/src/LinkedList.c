#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex); //NO SE TOCA WACHIN
static int addNode(LinkedList* this, int nodeIndex,void* pElement);//NO SE TOCAN

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
	if(this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int todoOk = -1;
	if(this != NULL)
	{
		todoOk = this->size;
	}
    return todoOk;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodo = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		nodo = this->pFirstNode;
		while(nodeIndex > 0)
		{
			nodo = nodo->pNextNode;
			nodeIndex--;
		}
	}
    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)//NO SE TOCA WACHIN
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int todoOk = -1;
	Node* nodo = NULL;
	Node* aux = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		nodo = (Node*)malloc(sizeof(Node));
		if(nodo != NULL)
		{
			nodo->pElement = pElement;
			if(nodeIndex == 0)
			{
				nodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nodo;
			}
			else
			{
				nodo->pNextNode = getNode(this, nodeIndex);
				aux = getNode(this, nodeIndex -1);
				aux->pNextNode = nodo;
			}
			this->size++;
			todoOk = 0;
		}
	}
    return todoOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)//NO SE TOCA
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int todoOk = -1;
	if(this != NULL)
	{
		if(!addNode(this, ll_len(this), pElement))
		{
			todoOk = 0;
		}
	}
    return todoOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* todoOk = NULL;
	Node* nodo = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		nodo = getNode(this, index);
		if(nodo != NULL)
		{
			todoOk = nodo->pElement;
		}
	}
    return todoOk;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int todoOk = -1;
	Node* nodo = NULL;
	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		nodo = getNode(this, index);
		if(nodo != NULL)
		{
			nodo->pElement = pElement;
			todoOk = 0;
		}
	}
	   return todoOk;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int todoOk = -1;
	Node* nodo = NULL;
	Node* aux;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		nodo = getNode(this, index);
		if(index == 0)
		{
			this->pFirstNode = nodo->pNextNode;
		}
		else
		{
			aux = getNode(this, index -1);
			aux->pNextNode = nodo->pNextNode;
			free(aux);
		}
		free(nodo);
		this->size--;
		todoOk = 0;
	}
    return todoOk;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int todoOk = -1;
	int flag = 1;
	if(this != NULL)
	{
		while(ll_len(this) >= 0)
		{
			if(ll_remove(this, 0) == -1)
			{
				flag = 0;
				break;
			}
		}
	}
	if(flag == 0)
	{
		todoOk = 0;
	}
    return todoOk;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int todoOk = -1;
	if(this != NULL)
	{
		if(ll_clear(this) == 0)
		{
			free(this);
			todoOk = 0;
		}
	}
    return todoOk;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int todoOk = -1;
	if(this != NULL)
	{
		for(int i =0;i<ll_len(this);i++)
		{
			if(ll_get(this,i) == pElement)
			{
				todoOk = i;
				break;
			}
		}
	}
    return todoOk;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int todoOk = -1;
	if(this != NULL)
	{
		todoOk = 0;
		if(ll_len(this)==0)
		{
			todoOk =1;
		}
	}
    return todoOk;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* todoOk = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		todoOk = ll_get(this, index);
		ll_remove(this, index);
	}
    return todoOk;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int todoOk = -1;
	if(this != NULL)
	{
		todoOk = 0;
		if(ll_indexOf(this, pElement) != -1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int todoOk = -1;
	int tam;
	if(this != NULL && this2 != NULL)
	{
		tam = ll_len(this2);
		todoOk = 1;
		for(int i=0;i<tam;i++)
		{
			if(ll_contains(this, ll_get(this2, i)) == 0)
			{
				todoOk = 0;
				break;
			}
		}
	}
    return todoOk;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* this2= NULL;
	void* element = NULL;
	if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
	{
		this2 = ll_newLinkedList();
		if(this2 != NULL)
		{
			for(int i=from;i<to;i++)
			{
				element = ll_get(this, i);
				ll_add(this2, element);
			}
		}
	}
    return this2;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int todoOk = -1;
	int tam;
	void* auxJ =NULL;
	void* auxI =NULL;
	if(this != NULL && pFunc != NULL && order >= 0 && order <=1)
	{
		tam = ll_len(this);
		for(int i=0;i<tam-1;i++)
		{
			for(int j= i+1;j<tam;j++)
			{
				auxI = ll_get(this, i);
				auxJ = ll_get(this, j);
				if((pFunc(auxI, auxJ) > 0 && order) ||
				   (pFunc(auxI, auxJ) < 0 && !order))
				{
					ll_set(this, i , auxJ);
					ll_set(this, j, auxI);
				}
			}
		}
		todoOk = 0;
	}
    return todoOk;

}

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
	LinkedList* newList = NULL;
	void* pElement;
	int tam;
	if(this != NULL && pFunc != NULL)
	{
		newList = ll_newLinkedList();
		if(newList != NULL)
		{
			tam = ll_len(this);
			for(int i=0;i<tam;i++)
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement)==1)
				{
					if(ll_add(newList, pElement)!=0)
					{
						ll_deleteLinkedList(newList);
						newList = NULL;
						break;
					}
				}
			}
		}
	}
	return newList;
}

LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void*))
{
	LinkedList* newList = NULL;
	void* pElement;
	void* auxpElement;
	int tam;
	if(this != NULL && pFunc != NULL)
	{
		newList = ll_newLinkedList();
		if(newList != NULL)
		{
			tam = ll_len(this);
			for(int i=0;i<tam;i++)
			{
				auxpElement = ll_get(this, i);
				pElement = pFunc(auxpElement);
				if(pElement != NULL)
				{
					if(ll_add(newList, pElement)==1)
					{
						break;
					}
				}

			}
		}
	}
	return newList;
}
