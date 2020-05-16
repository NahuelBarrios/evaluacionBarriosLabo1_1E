/*
 * cliente.h
 *
 *  Created on: 14 may. 2020
 *      Author: Nahu_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int idCliente;
	char nombreCliente[51];
	char apellidoCliente[51];
	char cuilCliente[15];
	int masPrestamoActivo;
	int masPrestamoSaldo;
	int isEmptyCliente;

}eCliente;

//***********************************************************************************************************************************
/** \brief Para indicar que todas las posiciones en la matriz est�n vac�as,
 * esta funci�n pone el campo isEmptyCliente en TRUE en todas las
 * posiciones de la matriz
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int inicializarCliente(eCliente array[], int size);


/** \brief Carga los datos pasados por los parametros y realiza un alta
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz
 * \param id int recibe un entero(un id)
 * \param nombre[] char recibe un array de char(Un nombre de cliente)
 * \param apellido[] char recibe un array de char(Un apellido de cliente)
 * \param cuil[] char recibe un array de char(Un cuil de cliente)
 */
void hardCodeCliente(eCliente array[],int size,int id,char nombre[],char apellido[],char cuil[]);
//***********************************************************************************************************************************

/** \brief Realiza un alta de clientes a traves de la consola.
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz
 * \param contadorID int* puntero de un contador de id autoincremental.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int altaCliente(eCliente array[], int size, int* contadorID);


/** \brief Busca si hay posicion para generar un nuevo alta
 * de cliente.
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz
 * \param posicion int* da a conocer la posicion disponible.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int buscarEmptyCliente(eCliente array[], int size, int* posicion);
//***********************************************************************************************************************************

/** \brief El usuario puede modificar Nombre,Apellido,Cuil
 * de un cliente.
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int modificarCliente(eCliente array[], int sizeArray);


/** \brief busca el id de un cliente.
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz.
 * valorBuscado int recibe un valor a buscar.
 * posicion int* da a conocer la posicion del id.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int buscarIdCliente(eCliente array[], int size, int valorBuscado, int* posicion);
//***********************************************************************************************************************************

/** \brief imprime un listado de los clientes dados de alta.
 * \param array[] eCliente array de clientes
 * \param size int Longitud de la matriz.
 * \return int Retorna (-1) si el Error es [Longitud inv�lida o puntero NULO] - Retorna (0) si esta todo Ok
 */
int listarCliente(eCliente array[], int size);
#endif /* CLIENTE_H_ */
