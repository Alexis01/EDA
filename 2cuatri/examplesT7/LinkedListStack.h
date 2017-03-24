/**
  @file LinkedListStack.h

  Implementaci�n del TAD Pila utilizando una
  lista enlazada de nodos.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio G�mez Mart�n, 2012
*/
#ifndef __PILA_LISTA_ENLAZADA_H
#define __PILA_LISTA_ENLAZADA_H

#include "Exceptions.h"
#include <iostream>
#include <iomanip>

/**
 Implementaci�n del TAD Pila utilizando una lista enlazada de nodos.

 Las operaciones son:

 - EmptyStack: -> Stack. Generadora implementada en el
   constructor sin par�metros.
 - Push: Stack, Elem -> Stack. Generadora
 - pop: Stack - -> Stack. Modificadora parcial.
 - top: Stack - -> Elem. Observadora parcial.
 - empty: Stack -> Bool. Observadora.
 - size: Stack -> Entero. Observadora.

 @author Marco Antonio G�mez Mart�n
 */
template <class T>
class LinkedListStack {
public:

	/** Constructor; operaci�n PilaVacia */
	LinkedListStack() : _cima(NULL), _numElems(0) {
	}

	/** Destructor; elimina la lista enlazada. */
	~LinkedListStack() {
		libera();
		_cima = NULL;
	}

	/**
	 Apila un elemento. Operaci�n generadora.

	 @param elem Elemento a apilar.
	*/
	void push(const T &elem) {
		_cima = new Nodo(elem, _cima);
		_numElems++;
	}
	
	/**
	 Desapila un elemento. Operaci�n modificadora parcial,
	 que falla si la pila est� vac�a.

	 pop(Push(elem, p) = p
	 error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException("Cannot pop. The stack is empty");
		Nodo *aBorrar = _cima;
		_cima = _cima->_sig;
		delete aBorrar;
		--_numElems;
	}

	/**
	 Devuelve el elemento en la cima de la pila. Operaci�n
	 observadora parcial, que falla si la pila est� vac�a.

	 top(Push(elem, p) = elem
	 error: top(EmptyStack)

	 @return Elemento en la cima de la pila.
	 */
	const T &top() const {
		if (empty())
			throw EmptyStackException("Cannot get top. The stack is empty");
		return _cima->_elem;
	}

	/**
	 Devuelve true si la pila no tiene ning�n elemento.

	 empty(EmptyStack) = true
	 empty(Push(elem, p)) = false

	 @return true si la pila no tiene ning�n elemento.
	 */
	bool empty() const {
		return _cima == NULL;
	}

	/**
	 Devuelve el n�mero de elementos que hay en la
	 pila.
	 size(EmptyStack) = 0
	 size(Push(elem, p)) = 1 + size(p)

	 @return N�mero de elementos.
	 */
	int size() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	LinkedListStack(const LinkedListStack<T> &other) : _cima(NULL) {
		copia(other);
	}

	/** Operador de asignaci�n */
	LinkedListStack<T> &operator=(const LinkedListStack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const LinkedListStack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		bool iguales = true;
		Nodo *cima1 = _cima;
		Nodo *cima2 = rhs._cima;
		while ((cima1 != NULL) && (cima2 != NULL) && iguales) {
			if (cima1->_elem != cima2->_elem)
				iguales = false;
			else {
				cima1 = cima1->_sig;
				cima2 = cima2->_sig;
			}
		}
		return iguales;
	}

	bool operator!=(const LinkedListStack<T> &rhs) const {
		return !(*this == rhs);
	}

	/** Escribe la pila en el flujo. Se usa desde operator<< */
	void write(std::ostream& sOut) {
		Nodo* aux = _cima;
		while (aux != NULL){
			sOut << "|" << setw(3) << aux->_elem << "|" << endl;
			aux = aux->_sig;
		}
		sOut << "|___|" << endl;
	}

protected:

	void libera() {
		libera(_cima);
	}

	void copia(const LinkedListStack &other) {

		if (other.empty()) {
			_cima = NULL;
			_numElems = 0;
		} else {
			Nodo *act = other._cima;
			Nodo *ant;
			_cima = new Nodo(act->_elem);
			ant = _cima;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_numElems = other._numElems;
		}
	}

private:

	/**
	 Clase nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que podr�a ser NULL si
	 el nodo es el �ltimo de la lista enlazada.
	 */
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) : 
		    _elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	/**
	 Elimina todos los nodos de la lista enlazada cuyo
	 primer nodo se pasa como par�metro.
	 Se admite que el nodo sea NULL (no habr� nada que
	 liberar).
	 */
	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	/** Puntero al primer elemento */
	Nodo *_cima;

	/** N�mero de elementos */
	int _numElems;
};

template<class T>
std::ostream& operator<<(std::ostream& sOut, LinkedListStack<T>& s) {
	s.write(sOut);
	return sOut;
}

#endif // __PILA_LISTA_ENLAZADA_H
