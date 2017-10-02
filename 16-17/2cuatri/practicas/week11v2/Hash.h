/**
 @file Hash.h
 
 Declaraci�n e implementaci�n de funciones de localizaci�n para
 tipos b�sicos y funci�n gen�rica que conf�a en la existencia
 del m�todo m�todo hash de las clases.
 
 Estructura de Datos y Algoritmos
 Facultad de Inform�tica
 Universidad Complutense de Madrid
 
 (c) Antonio S�nchez Ruiz-Granados, 2012
 */

#ifndef __HASH_H
#define __HASH_H

#include <string>

// ----------------------------------------------------
//
// Funciones hash para distintos tipos de datos b�sicos
//
// ----------------------------------------------------


inline unsigned int hash(unsigned int clave) {
	return clave;
}

inline unsigned int hash(int clave) {
	return (unsigned int) clave;
}

inline unsigned int hash(char clave) {
	return clave;
}

// Fowler/Noll/Vo (FNV) -- adaptada de http://bretmulvey.com/hash/6.html 
inline unsigned int hash(std::string clave) {
	const unsigned int p = 16777619; // primo grande
	unsigned int hash = 2166136261;  // valor inicial
	for (unsigned int i=0; i<clave.size(); i++)
		hash = (hash ^ clave[i]) * p; // ^ es xor binario
	// mezcla final
	hash += hash << 13;
	hash ^= hash >> 7;
	hash += hash << 3;
	hash ^= hash >> 17;
	hash += hash << 5;
	return hash;
}

/**
 * Funci�n hash gen�rica para clases que implementen un
 * m�todo publico hash.
 */
template<class C>
unsigned int hash(const C &clave) {
	return clave.hash();
}


#endif // __HASH_H
