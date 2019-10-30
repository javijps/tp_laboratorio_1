/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//nueva linked
int ll_len(LinkedList* this);//longitud de ll
Node* test_getNode(LinkedList* this, int nodeIndex);//
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//
int ll_add(LinkedList* this, void* pElement);//todas reciben el contexto(this).recibe contexto y agrega al final elemento(puntero a void xq es generico)
void* ll_get(LinkedList* this, int index);////a partir del index(pos)trae el contexto
int ll_set(LinkedList* this, int index,void* pElement);//a partir del index agrega un elemento.existe lista?existe index?paso elemento. srive para ordenar
int ll_remove(LinkedList* this,int index);//recibe index y lo hace desaparecer.existe el index?
int ll_clear(LinkedList* this);//borrar todo el ll. clear lleva el ll al momento del ll_new.
int ll_deleteLinkedList(LinkedList* this);//hace clear y despues el free de la ll
int ll_indexOf(LinkedList* this, void* pElement);//recorre ll y chequea x cada uno de los elementos y se fija si coincide con el elemento que le pasamos por aprametro, devuelve el indice del 1ro q encuentra
int ll_isEmpty(LinkedList* this);//te dice si la ll esta vaica(verdadero)
int ll_push(LinkedList* this, int index, void* pElement);//permite insertar donde yo quiera el elemento(el add es un caso partiicular del pus)
void* ll_pop(LinkedList* this,int index);//hace get y remove de una,me devuelve el puntero antes de hacer remove para q lo tenga.
int ll_contains(LinkedList* this, void* pElement);//me dice verdadero o falso si un elemento esta o no en la lista(prevenir duplicados)
int ll_containsAll(LinkedList* this,LinkedList* this2);//pregunta si la lista this2 es un subconjunto de la lista uno, si todos sus elementos estan en la lista 1
LinkedList* ll_subList(LinkedList* this,int from,int to);//genero una lista nueva a partir de una existente(un slice de la lista original)
LinkedList* ll_clone(LinkedList* this);//clona la lista. caso particular de sublist.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//el algoritmo de ordenamiento se hace solo una vez, en una funcion(puntero a funcion criterio),se usa siempre y solo cambia los criterios de ordenamiento.





///////////////
