/*
 * prestamo.h
 *
 *  Created on: 15 may. 2020
 *      Author: Nahu_
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct
{
	int idPrestamo;
	int idCliente;
	float importePrestamo;
	int cuotasPrestamo;
	char estadoPrestamo[51]; //|| Saldado || activo
	int isEmptyPrestamo;

}ePrestamo;
//***********************************************************************************************************************************
/** \brief Para indicar que todas las posiciones en la matriz est�n vac�as,
 * esta funci�n pone el campo isEmptyPrestamo en TRUE en todas las
 * posiciones de la matriz
 * \param array[] ePrestamo array de prestamos
 * \param size int Longitud de la matriz
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int inicializarPrestamo(ePrestamo array[], int size);
//***********************************************************************************************************************************

/** \brief Busca si hay posicion para realizar un nuevo alta
 * de prestamo.
 * \param array[] ePrestamo array de prestamos
 * \param size int Longitud de la matriz
 * \param posicion int* da a conocer la posicion disponible.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int buscarEmptyPrestamo(ePrestamo array[], int size, int* posicion);

/** \brief busca el id de un prestamo.
 * \param array[] ePrestamo array de prestamos
 * \param size int Longitud de la matriz.
 * valorBuscado int recibe un valor a buscar.
 * posicion int* da a conocer la posicion del id.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int buscarIdPrestamo(ePrestamo array[], int size, int valorBuscado, int* posicion);
//***********************************************************************************************************************************
#endif /* PRESTAMO_H_ */
