/**
 *  @file HashMap.h
 * 
 *  Implementaci�n din�mica del TAD Dictionary utilizando
 *  tablas de b�squeda
 * 
 *  Estructura de Datos y Algoritmos
 *  Facultad de Inform�tica
 *  Universidad Complutense de Madrid
 * 
 * (c) Antonio S�nchez Ruiz-Granados, 2012
 */
#ifndef __HASHMAP_H
#define __HASHMAP_H

#include "Exceptions.h"

// funciones de hash a usar
#include "Hash.h"

/**
 * Implementaci�n din�mica del TAD Dictionary utilizando 
 * una tabla hash abierta
 * 
 * Las operaciones son:
 * 
 * - HashMapVacio: operaci�n generadora que construye
 * una tabla hash vac�a
 * 
 * - Insert(clave, valor): generadora que a�ade una 
 * nueva pareja (clave, valor) a la tabla. Si la
 * clave ya estaba se sustituye el valor.
 * 
 * - erase(clave): operaci�n modificadora. Elimina la
 * clave de la tabla. Si la clave no est�,
 * la operaci�n no tiene efecto.
 * 
 * - at(clave): operaci�n observadora que devuelve
 * el valor asociado a una clave. Es un error preguntar
 * por una clave que no existe.
 * 
 * - contains(clave): operaci�n observadora. Sirve para
 * averiguar si una clave est� presente en la tabla.
 * 
 * - empty(): operacion observadora que indica si
 * la tabla tiene alguna clave introducida.
 * 
 * @author Antonio S�nchez Ruiz-Granados
 */
template <class Clave, class Valor>
class HashMap {
private:
	/**
	 * La tabla contiene un array de punteros a nodos. Cada nodo contiene una 
	 * clave, un valor y un puntero al siguiente nodo.
	 */
	class Nodo {
	public:
		/* Constructores. */
		Nodo(const Clave &clave, const Valor &valor) : 
		_clave(clave), _valor(valor), _sig(NULL) {};
		
		Nodo(const Clave &clave, const Valor &valor, Nodo *sig) : 
		_clave(clave), _valor(valor), _sig(sig) {};
		
		/* Atributos p�blicos. */
		Clave _clave;    
		Valor _valor;   
		Nodo *_sig;  // Puntero al siguiente nodo.
	};  
	
public:
	
	/**
	 * Tama�o inicial de la tabla.
	 */
	static const int TAM_INICIAL = 8;    
	
	/** Constructor por defecto que implementa HashMapVacio */
	HashMap() : _v(new Nodo*[TAM_INICIAL]), _tam(TAM_INICIAL), _numElems(0) {
		for (unsigned int i=0; i<_tam; ++i) {
			_v[i] = NULL;
		}
	}
	
	/** Destructor; elimina las listas enlazadas */
	~HashMap() {
		libera();
	}
	
	/**
	 *	 Operaci�n generadora que a�ade una nueva clave/valor
	 *	 a esta tabla
	 *	 @param clave Clave nueva.
	 *	 @param valor Valor asociado a esa clave. Si la clave
	 *	 ya se hab�a insertado previamente, sustituimos el valor
	 *	 viejo por el nuevo.
	 */
	void insert(const Clave &clave, const Valor &valor) {        
		// Si la ocupaci�n es muy alta ampliamos la tabla
		float ocupacion = 100 * ((float) _numElems) / _tam; 
		if (ocupacion > MAX_OCUPACION)
			amplia();
		
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Si la clave ya exist�a, actualizamos su valor
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		if (nodo != NULL) {
			nodo->_valor = valor;
		} else {            
			// Si la clave no exist�a, creamos un nuevo nodo y lo insertamos
			// al principio
			_v[ind] = new Nodo(clave, valor, _v[ind]);
			_numElems++;
		}
	}
	
	/**
	 *	 Operaci�n modificadora que elimina una clave de la tabla.
	 *	 Si la clave no exist�a la operaci�n no tiene efecto.
	 * 
	 *	   erase(elem, EmptyHashMap) = HashMapVacio
	 *	   erase(e, insert(c, v, arbol)) = 
	 *	                     inserta(c, v, erase(e, arbol)) si c != e
	 *	   erase(e, insert(c, v, arbol)) = erase(e, arbol) si c == e
	 * 
	 *	 @param clave Clave a eliminar.
	 */
	void erase(const Clave &clave) {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos el nodo que contiene esa clave y el nodo anterior.
		Nodo *act = _v[ind];
		Nodo *ant = NULL;
		buscaNodo(clave, act, ant);
		
		if (act != NULL) {
			
			// Sacamos el nodo de la secuencia de nodos.
			if (ant != NULL) {
				ant->_sig = act->_sig;
			} else {
				_v[ind] = act->_sig;
			}
			
			// Borramos el nodo extra�do.
			delete act;
			_numElems--;
		}        
	}
	
	/**
	 *	 Operaci�n observadora que devuelve el valor asociado
	 *	 a una clave dada.
	 * 
	 *	 at(e, insert(c, v, tabla)) = v si e == c
	 *	 at(e, insert(c, v, tabla)) = at(e, tabla) si e != c
	 *	 error at(EmptyHashMap)
	 * 
	 *	 @param clave Clave por la que se pregunta.
	 */
	const Valor &at(const Clave &clave) const {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		if (nodo == NULL)
			throw EClaveErronea();
		
		return nodo->_valor;
	}
	
	/**
	 *	 Operaci�n observadora que permite averiguar si una clave
	 *	 determinada est� o no en la tabla hash.
	 * 
	 *	 contains(e, EmptyHashMap) = false
	 *	 contains(e, insert(c, v, arbol)) = true si e == c
	 *	 contains(e, insert(c, v, arbol)) = contains(e, arbol) si e != c
	 * 
	 *	 @param clave Clave por la que se pregunta.
	 *	 @return true si el diccionario contiene un valor asociado
	 *	 a esa clave.
	 */
	bool contains(const Clave &clave) const {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		return nodo != NULL;
	}
	
	/**
	 *	 Operaci�n observadora que devuelve si el �rbol
	 *	 es vac�o (no contiene elementos) o no.
	 * 
	 *	 empty(EmptyHashMap) = true
	 *	 empty(insert(c, v, arbol)) = false
	 */
	bool empty() const {
		return _numElems == 0;
	}
	
	/**
	 *	 Sobrecarga del operador [] que permite acceder
	 *	 al valor asociado a una clave y modificarlo.
	 *	 Si el elemento buscado no estaba, se inserta uno
	 *	 con el valor por defecto del tipo Valor.
	 */
	Valor &operator[](const Clave &clave) {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		if (nodo == NULL) {
			// No est�, lo a�adimos y vemos d�nde qued�. 
			insert(clave, Valor());
			// ind puede cambiar si al insertar hubo expansion!
			ind = ::hash(clave) % _tam;
			nodo = buscaNodo(clave, _v[ind]);
		}        
		return nodo->_valor;
	}
	
	// //
	// ITERADOR CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 *	 Clase interna que implementa un iterador sobre
	 *	 la lista que permite recorrer la tabla pero no
	 *	 permite modificarla.
	 */
	class ConstIterator {
	public:
		void next() {
			if (_act == NULL) throw InvalidAccessException();
			
			// Buscamos el siguiente nodo de la lista de nodos.
			_act = _act->_sig;
			
			// Si hemos llegado al final de la lista de nodos, seguimos
			// buscando por el vector _v.
			while ((_act == NULL) && (_ind < _tabla->_tam - 1)) {
				++_ind;
				_act = _tabla->_v[_ind];
			}
		}
		
		const Clave &key() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_clave;
		}
		
		const Valor &value() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_valor;
		}
		
		bool operator==(const ConstIterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const ConstIterator &other) const {
			return !(this->operator==(other));
		}
		
		ConstIterator &operator++() {
			next();
			return *this;
		}
		
		ConstIterator operator++(int) {
			ConstIterator ret(*this);
			operator++();
			return ret;
		}
		
	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class HashMap;
		
		ConstIterator(const HashMap* tabla, Nodo* act, unsigned int ind) 
			: _tabla(tabla), _act(act), _ind(ind) { }
		
		const HashMap *_tabla;  ///< Tabla que se est� recorriendo
		Nodo* _act;             ///< Puntero al nodo actual del recorrido
		unsigned int _ind;      ///< �ndice actual en el vector _v
	};
	
	/**
	 *	 Devuelve el iterador constante al principio del
	 *	 diccionario (clave m�s peque�a).
	 *	 @return iterador al principio del recorrido;
	 *	 coincidir� con cend() si el diccionario est� vac�o.
	 */
	ConstIterator cbegin() const {
		unsigned int ind = 0;
		Nodo *act = _v[0];
		while (ind < _tam-1 && act == NULL) {
			ind++;
			act = _v[ind];
		}
		return ConstIterator(this, act, ind);
	}
	
	/**
	 *	 @return Devuelve un iterador al final del recorrido
	 *	 (fuera de �ste).
	 */
	ConstIterator cend() const {
		return ConstIterator(this, NULL, 0);
	}
	
	/**
	 *	 @return Devuelve un iterador a la posicion de 
	 *	 clave, o al final del recorrido si clave no encontrada
	 */
	ConstIterator find(const Clave &clave) const {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		
		// si nodo == NULL, devuelve en realidad cend()
		return ConstIterator(this, nodo, ind);
	}
	
	// //
	// ITERADOR NO CONSTANTE Y FUNCIONES RELACIONADAS
	// //
	
	/**
	 *	 Clase interna que implementa un iterador sobre
	 *	 la �rbol de b�squeda que permite recorrer la lista e incluso
	 *	 alterar el valor de sus elementos.
	 */
	class Iterator {
	public:
		void next() {
			if (_act == NULL) throw InvalidAccessException();
			
			// Buscamos el siguiente nodo de la lista de nodos.
			_act = _act->_sig;
			
			// Si hemos llegado al final de la lista de nodos, seguimos
			// buscando por el vector _v.
			while ((_act == NULL) && (_ind < _tabla->_tam - 1)) {
				++_ind;
				_act = _tabla->_v[_ind];
			}
		}
		
		const Clave &key() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_clave;
		}
		
		Valor &value() const {
			if (_act == NULL) throw InvalidAccessException();
			return _act->_valor;
		}
		
		bool operator==(const Iterator &other) const {
			return _act == other._act;
		}
		
		bool operator!=(const Iterator &other) const {
			return !(this->operator==(other));
		}
		
		Iterator &operator++() {
			next();
			return *this;
		}
		
		Iterator operator++(int) {
			Iterator ret(*this);
			operator++();
			return ret;
		}
		
	protected:
		// Para que pueda construir objetos del tipo iterador
		friend class HashMap;
		
		Iterator(const HashMap* tabla, Nodo* act, unsigned int ind) 
		: _tabla(tabla), _act(act), _ind(ind) { }
		
		const HashMap *_tabla;  ///< Tabla que se est� recorriendo
		Nodo* _act;             ///< Puntero al nodo actual del recorrido
		unsigned int _ind;      ///< �ndice actual en el vector _v
	};
	
	/**
	 *	 Devuelve el iterador al principio de la lista.
	 *	 @return iterador al principio de la lista;
	 *	 coincidir� con final() si la lista est� vac�a.
	 */
	Iterator begin() {
		unsigned int ind = 0;
		Nodo *act = _v[0];
		while (ind < _tam-1 && act == NULL) {
			ind++;
			act = _v[ind];
		}
		return Iterator(this, act, ind);        
	}
	
	/**
	 *	 @return Devuelve un iterador al final del recorrido
	 *	 (fuera de �ste).
	 */
	Iterator end() const {
		return Iterator(this, NULL, 0);
	}
	
	/**
	 *	 @return Devuelve un iterador a la posicion de 
	 *	 clave, o al final del recorrido si clave no encontrada
	 */
	Iterator find(const Clave &clave) {
		// Obtenemos el �ndice asociado a la clave.
		unsigned int ind = ::hash(clave) % _tam;
		
		// Buscamos un nodo que contenga esa clave.
		Nodo *nodo = buscaNodo(clave, _v[ind]);
		
		// si nodo == NULL, devuelve en realidad cend()
		return Iterator(this, nodo, ind);
	}
	
	
	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //
	
	/** Constructor copia */
	HashMap(const HashMap<Clave, Valor> &other) {
		copia(other);
	}
	
	/** Operador de asignaci�n */
	HashMap<Clave, Valor> &operator=(const HashMap<Clave, Valor> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}
	
private:
	
	// Para que el iterador pueda acceder a la parte privada
	friend class Iterador;    
	
	/**
	 * Libera toda la memoria din�mica reservada para la tabla.
	 */
	void libera() {
		
		// Liberamos las listas de nodos.
		for (unsigned int i=0; i<_tam; i++) {
			liberaNodos(_v[i]);
		}
		
		// Liberamos el array de punteros a nodos.
		if (_v != NULL) {
			delete[] _v;
			_v = NULL;
		}
	}
	
	/**
	 * Libera un nodo y todos los siguientes.
	 *
	 * @param prim puntero al primer nodo de la lista a liberar.
	 */
	static void liberaNodos(Nodo *prim) {
		
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}       
	}
	
	/**
	 * Hace una copia de la tabla que recibe como par�metro. Antes de llamar
	 * a este m�todo se debe invocar al m�todo "libera".
	 *
	 * @param other tabla que se quiere copiar.
	 */
	void copia(const HashMap<Clave,Valor> &other) {
		_tam = other._tam;
		_numElems = other._numElems;
		
		// Reservar memoria para el array de punteros a nodos.
		_v = new Nodo*[_tam];
		for (unsigned int i=0; i<_tam; ++i) { 
			_v[i] = NULL;
			
			// Copiar la lista de nodos de other._v[i] a _v[i].
			// La lista de nodos queda invertida con respecto a la original.
			Nodo *act = other._v[i];
			while (act != NULL) {
				_v[i] = new Nodo(act->_clave, act->_valor, _v[i]); 
				act = act->_sig;
			}
		}
	}
	
	/**
	 * Este m�todo duplica la capacidad del array de punteros actual.
	 */
	void amplia() {
		// Creamos un puntero al array actual y anotamos su tama�o.
		Nodo **vAnt = _v;
		unsigned int tamAnt = _tam;
		
		// Duplicamos el array en otra posici�n de memoria.
		_tam *= 2; 
		_v = new Nodo*[_tam];
		for (unsigned int i=0; i<_tam; ++i)
			_v[i] = NULL;
		
		// Recorremos el array original moviendo cada nodo a la nueva 
		// posici�n que le corresponde en el nuevo array.
		for (unsigned int i=0; i<tamAnt; ++i) {
			
			// IMPORTANTE: Al modificar el tama�o tambi�n se modifica el �ndice
			// asociado a cada nodo. Es decir, los nodos se mueven a posiciones
			// distintas en el nuevo array.
			
			// NOTA: por eficiencia movemos los nodos del array antiguo al 
			// nuevo, no creamos nuevos nodos. 
			
			// Recorremos la lista de nodos
			Nodo *nodo = vAnt[i];
			while (nodo != NULL) {
				Nodo *aux = nodo;
				nodo = nodo->_sig;
				
				// Calculamos el nuevo �ndice del nodo, lo desenganchamos del 
				// array antiguo y lo enganchamos al nuevo.
				unsigned int ind = ::hash(aux->_clave) % _tam;
				aux->_sig = _v[ind];
				_v[ind] = aux;
			}
		}
		
		// Borramos el array antiguo (ya no contiene ning�n nodo).
		delete[] vAnt;
	}
	
	/**
	 * Busca un nodo a partir del nodo "act" que contenga la clave dada. Si lo 
	 * encuentra, "act" quedar� apuntando a dicho nodo y "ant" al nodo anterior.
	 * Si no lo encuentra "act" quedar� apuntando a NULL.
	 *
	 * @param clave clave del nodo que se busca.
	 * @param act [in/out] inicialmente indica el primer nodo de la b�squeda y 
	 *            al finalizar indica el nodo encontrado o NULL.
	 * @param ant [out] puntero al nodo anterior a "act" o NULL.
	 */
	static void buscaNodo(const Clave &clave, Nodo* &act, Nodo* &ant) {
		ant = NULL;
		bool encontrado = false;
		while ((act != NULL) && !encontrado) {
			
			// Comprobar si el nodo actual contiene la clave buscada
			if (act->_clave == clave) {
				encontrado = true;
			} else {
				ant = act;
				act = act->_sig;
			}
		}
	}
	
	/**
	 * Busca un nodo a partir de "prim" que contenga la clave dada. A 
	 * diferencia del otro m�todo "buscaNodo", este no devuelve un puntero al
	 * nodo anterior.
	 *
	 * @param clave clave del nodo que se busca.
	 * @param prim nodo a partir del cual realizar la b�squeda. 
	 * @return nodo encontrado o NULL.
	 */
	static Nodo* buscaNodo(const Clave &clave, Nodo* prim) {
		Nodo *act = prim;
		Nodo *ant = NULL;
		buscaNodo(clave, act, ant);
		return act;
	}
	
	/**
	 * Ocupaci�n m�xima permitida antes de ampliar la tabla en tanto por cientos.
	 */
	static const unsigned int MAX_OCUPACION = 80;
	
	
	Nodo **_v;               ///< Array de punteros a Nodo.
	unsigned int _tam;       ///< Tama�o del array _v.
	unsigned int _numElems;  ///< N�mero de elementos en la tabla.      
};

#endif // __HASHMAP_H
