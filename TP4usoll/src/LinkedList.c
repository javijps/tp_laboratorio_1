#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Pide espacio en memoria para una estructura de tipo Node
 *
 *
 */
Node* node_new()
{
	return malloc(sizeof(Node));
}

/** \brief Libera espacio de memoria por medio de free
 *
 *
 */
void node_delete(Node* this)
{
	free(this);
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Libera espacio de memoria por medio de free
 *
 *
 */
void ll_delete(LinkedList* this)
{
	free(this);
}


/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
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
	Node* pNode = NULL;//buffer
	int i;//variable de control.

	if(this!=NULL && nodeIndex>=0 && nodeIndex<this->size)//chequeo q la lista no sea null, q el index sea mayor a 0 y menor al tamaño de la lista
	{
		pNode = this->pFirstNode;//asigna al buffer la direccion de memoria del 1er nodo de la lista.
		for(i=0;i<nodeIndex;i++)//recorre de nodo en nodo,hasta la posicion del nodo indicado
		{
			pNode = pNode->pNextNode;//iguala en cada iteracion con la direccion de memoria del nodo siguiente.
			                         //cuando llegue a la direccion anterior a la del nodo indicado, va a devolver la direccion del siguiente, que seria el buscado
		}
	}
	return pNode;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
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
    int returnAux = -1;
    Node* pNodo;
    Node* pNodoAnterior;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size)
	{
		pNodo = node_new();
		if(pNodo == NULL) return -1;

		returnAux = 0;
		this->size++;
		pNodo->pElement = pElement;
		if(nodeIndex == 0)
		{
			pNodo->pNextNode = this->pFirstNode;
			this->pFirstNode = pNodo;
		}
		else
		{
			pNodoAnterior = getNode(this,nodeIndex-1);
			pNodo->pNextNode = pNodoAnterior->pNextNode;
			pNodoAnterior->pNextNode = pNodo;
		}
	}
    return returnAux;
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
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
	int returnAux = -1;
	int llLen = ll_len(this);

	if(this!=NULL && addNode(this,llLen,pElement)==0)
	{
		{
			returnAux = 0;
		}
	}
	return returnAux;
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
    void* returnAux = NULL;
    Node* pNode;

    if(this!=NULL && index>=0 && index<this->size)
    {
    	pNode = getNode(this,index);
    	returnAux = pNode->pElement;
    }
    return returnAux;
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
    int returnAux = -1;
    Node* pNode;

    if(this!=NULL && index>=0 && index<this->size)
    {
    	pNode = getNode(this,index);
    	pNode->pElement = pElement;
    	returnAux = 0;
    }


    return returnAux;
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
	int returnAux = -1;
	Node* pNodeDelete;
	Node* pNodeAnterior;
	Node* pNodePosterior;

	if(this!=NULL && index>=0 && index<this->size)
	{
		this->size--;
		returnAux = 0;

		if(index==0)
		{
			pNodeDelete = getNode(this,index);//busco el nodo a borrar
			pNodePosterior = getNode(this,index+1);
			this->pFirstNode = pNodePosterior;
			node_delete(pNodeDelete);// VA O NO? FUNCIONA DE LAS 2 MANERAS
		}
		else
		{
			pNodeDelete = getNode(this,index);
			pNodeAnterior = getNode(this,index-1);
			pNodeAnterior->pNextNode = pNodeDelete->pNextNode;
			node_delete(pNodeDelete);
		}
	}
	return returnAux;
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
    int returnAux = -1;
    int i;
    int lenLL;

    lenLL = ll_len(this);

    if(this!=NULL && lenLL>0)
    {
    	for(i=0;i<lenLL;i++)
    	{
    		ll_remove(this,i);
    		returnAux = 0;
    	}
    }
    return returnAux;
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
    int returnAux = -1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	ll_delete(this);
    	returnAux = 0;
    }

    return returnAux;
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
    int returnAux = -1;
    int i;
    int lenLL;
    Node* pNode;

    lenLL = ll_len(this);
    if(this!=NULL && lenLL>0)
    {
    	for(i=0;i<lenLL;i++)
    	{
    		pNode = getNode(this,i);
			if(pNode->pElement == pElement)
    		{
				returnAux = i;
				break;
    		}
    	}
    }
    return returnAux;
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
    int returnAux = -1;
    int lenLL;

    lenLL = ll_len(this);

    if(this!=NULL)
    {
    	if(lenLL>0)
    	{
    		returnAux = 0;
    	}

    	else if(lenLL==0)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
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
    int returnAux = -1;

    if(this!=NULL && index>=0 && index <= this->size)
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
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
    void* returnAux = NULL;
    Node* pNode;


    if(this!=NULL && index>=0 && index < this->size)
    {
    	pNode = getNode(this,index);
    	returnAux = pNode->pElement;
    	this->size--;
    	node_delete(pNode);
//    	ll_remove(this,index); XQ NO ANDA CON REMOVE?

    }
    return returnAux;
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
	int returnAux = -1;
	int i;
	Node* pNode;

	if(this!=NULL)
	{
		returnAux = 0;
		for(i=0;i<ll_len(this);i++)
		{
			pNode = getNode(this,i);
			if(pNode->pElement == pElement)
			{
				returnAux = 1;
				break;
			}
		}
	}
	return returnAux;
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
	int returnAux = -1;
	int i;
	Node* pNode1;

	if(this!=NULL && this2!=NULL)
	{
		returnAux = 0;
		for(i=0;i<ll_len(this2);i++)
		{
			pNode1 = getNode(this2,i);
			if(ll_contains(this,pNode1->pElement)==1)
			{
				returnAux = 1;
			}
			else
			{
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
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
    LinkedList* cloneArray = NULL;
    int lenll = ll_len(this);
    int i;
    Node* pNode;

    if(this!=NULL && from>=0 && from<=lenll && to>=from && to<=lenll)
    {
    	cloneArray = ll_newLinkedList();
    	for(i=from;i<to;i++)
    	{
    		pNode = ll_get(this,i);
    		ll_add(cloneArray,pNode);
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int lenll = ll_len(this);
    int i;
    Node* pNode;

    if(this!=NULL && lenll>0)
    {
    	cloneArray = ll_newLinkedList();
    	for(i=0;i<lenll;i++)
    	{
    		pNode = ll_get(this,i);
    		ll_add(cloneArray,pNode);
    	}
    }
    return cloneArray;
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
    int returnAux =-1;
    Node* pNode1;
    Node* pNode2;
    Node* pNodeBuffer;
    int i;
    int j;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL && order>=0 && order <=1)
    {
    	for(i=0;i<llLen;i++)
    	{
    		pNode1 = ll_get(this,i);//tomo el 1er elemento de la lista

    		for(j=i+1;j<llLen;j++)//itero sobre el resto de la lista para comparar el elemento pnodo 1 contra el resto de los elementos de la lista
    		{
    			pNode2 = ll_get(this,j); //tomo el 2do elemento de la lista en el 1er caso,despues se va corriendo +1
    			if(order==0)//si el orden es descendente
    			{
    				if(pFunc(pNode1,pNode2)<0)//si la f criterio me dice que pnodo1 es menor a pnodo 2, hago el swap para q el mas alto quede 1ro
    				{
    					pNodeBuffer = pNode2;//el 2do(mas alto) va al buffer
    					pNode2 = pNode1;//el 1 va al 2
    					pNode1 = pNodeBuffer;//el buffer(que era el 2) va al 1
    				}
    			}
    			else if(pFunc(pNode1,pNode2)>0)// el unico otro caso es que order sea desc
    				//si la f criterio me dice que pnodo1 es mayor a pnodo 2, hago el swap, para que quede el mas bajo(pnodo 2 en este caso), 1ro
    			{
    				pNodeBuffer = pNode1;
    				pNode1 = pNode2;
    				pNode2 = pNodeBuffer;
    			}
    			ll_set(this,i,pNode1);//hago el set para asentar las modificaciones
    			ll_set(this,j,pNode2);
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}



int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int returnAux =-1;
    Node* pNode1;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
    	for(i=0;i<llLen;i++)
    	{
    		pNode1 = ll_get(this,i);
    		pFunc(pNode1);//imprimir un elemento
    		ll_set(this,i,pNode1);
    	}
    	returnAux = 0;
    }
    return returnAux;
}




LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))//1 cumple criterio -1 no
{
	int criterio;
	LinkedList* cloneArray=NULL;
    Node* pNode;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
		cloneArray = ll_newLinkedList();
    	for(i=0;i<llLen;i++)
    	{
    		pNode = ll_get(this,i);
    		criterio = pFunc(pNode);//imprimir un elemento
    		if(criterio ==1)
    		{
    			ll_add(cloneArray,pNode);
    		}
    	}
    }
    return cloneArray;
}

LinkedList* ll_reduce(LinkedList* this, int (*pFunc)(void*))//1 cumple criterio -1 no
{
	int criterio;
    Node* pNode;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
    	for(i=0;i<llLen;i++)
    	{
    		pNode = ll_get(this,i);
	 		criterio = pFunc(pNode);//imprimir un elemento
    		if(criterio ==0)//no cumple el requisito
    		{
    			ll_remove(this,i);
    			i--;
    			llLen--;
    		}
    	}
    }
    return this;
}












/*PRUEBA CON TP 3








void emp_printAemployeeIdMap(void* employee)
{
	int bEmployee_id = ((Employee*)employee)->id;

	if(employee!=NULL)
	{
		printf("\nID: %d\n",
				bEmployee_id);
	}
}












int emp_filterEmployeeById(void* employee)
{
	int bEmployee_id = ((Employee*)employee)->id;

	if(bEmployee_id>=950 && bEmployee_id<=1000)
	{
		return 1;
	}
	else
		return 0;

	return -1;
}



int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int returnAux =-1;
    Node* pNode1;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
    	for(i=0;i<llLen;i++)
    	{
    		pNode1 = ll_get(this,i);
    		pFunc(pNode1);//imprimir un elemento
    		ll_set(this,i,pNode1);
    	}
    	returnAux = 0;
    }
    return returnAux;
}




LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))//1 cumple criterio -1 no
{
	int criterio;
	LinkedList* cloneArray=NULL;
    Node* pNode;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
		cloneArray = ll_newLinkedList();
    	for(i=0;i<llLen;i++)
    	{
    		pNode = ll_get(this,i);
    		criterio = pFunc(pNode);//imprimir un elemento
    		if(criterio ==1)
    		{
    			ll_add(cloneArray,pNode);
    		}
    	}
    }
    return cloneArray;
}



LinkedList* ll_reduce(LinkedList* this, int (*pFunc)(void*))//1 cumple criterio -1 no
{
	int criterio;
    Node* pNode;
    int i;
    int llLen = ll_len(this);

    if(this!=NULL && pFunc!=NULL)
    {
    	for(i=0;i<llLen;i++)
    	{
    		pNode = ll_get(this,i);
	 		criterio = pFunc(pNode);//imprimir un elemento
    		if(criterio ==0)//no cumple el requisito
    		{
    			ll_remove(this,i);
    			i--;
    			llLen--;
    		}
    	}
    }
    return this;
}



int controller_pruebaReduce(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{

		pArrayListEmployee = ll_reduce(pArrayListEmployee,emp_filterEmployeeById);//1 y 0 desc
		if(pArrayListEmployee!=NULL)
		{
			printf("Lista reducida(criterio id entre 950 y 1000!\n");
			retorno = 0;
		}
	}
	else
	{
		printf("No existen datos cargados a filtrar!\n");
	}
	return retorno;
}










int controller_pruebaMap(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		ll_map(pArrayListEmployee,emp_printAemployeeIdMap);//1asc y 0 desc
		retorno = 0;
	}
	else
	{
		printf("No existen datos cargados a mapear!\n");
	}
	return retorno;
}



int controller_pruebaFilter(LinkedList* pArrayListEmployee)
{
	LinkedList* lista_Filtrada = NULL;
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		lista_Filtrada = ll_filter(pArrayListEmployee,emp_filterEmployeeById);//1 y 0 desc
		if(lista_Filtrada!=NULL)
		{
			controller_ListEmployee(lista_Filtrada);
			retorno = 0;
		}
	}
	else
	{
		printf("No existen datos cargados a filtrar!\n");
	}
	return retorno;
}






*/



