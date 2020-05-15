/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"
#include "informes.h"

#define QTY_CLIENTE 50
#define QTY_PRESTAMO 50

int main(void)
{
	setbuf(stdout,NULL);

	eCliente arrayCliente[QTY_CLIENTE];
	inicializarCliente(arrayCliente,QTY_CLIENTE);

	hardCodeCliente(arrayCliente,QTY_CLIENTE,1,"Nahuel","Barrios","20-42463697-6");
	hardCodeCliente(arrayCliente,QTY_CLIENTE,2,"Candelaria","Scanavino","27-42454456-4");
	hardCodeCliente(arrayCliente,QTY_CLIENTE,3,"Lucas","Gabriel","20-35234565-3");

	ePrestamo arrayPrestamo[QTY_PRESTAMO];
	inicializarPrestamo(arrayPrestamo,QTY_PRESTAMO);

	int opcion = 0;
	int idCliente = 0;
	int idPrestamo = 0;

	while(opcion !=10)
	{
		utn_getUnsignedInt("\n****************************************\nMENU\n1-Alta cliente\n2-Modificar datos de cliente\n3-Baja de cliente\n4-Préstamo\
				\n5-Saldar préstamo\n6-Reanudar préstamo\n7-Imprimir Clientes\n8-Imprimir préstamos\nSeleccione opcion:",
				"\nError\n",1,sizeof(int),1,12,3,&opcion);

		switch(opcion)
		{
		case 1:
			altaCliente(arrayCliente,QTY_CLIENTE,&idCliente);
			break;
		case 2:
			listarCliente(arrayCliente,QTY_CLIENTE);
			modificarCliente(arrayCliente,QTY_CLIENTE);
			break;
		case 3:
			listarCliente(arrayCliente,QTY_CLIENTE);

			break;
		case 4:
			realizarPrestamo(arrayPrestamo,QTY_PRESTAMO,&idPrestamo,arrayCliente,QTY_CLIENTE);
			break;
		case 5:
			saldarPrestamo(arrayPrestamo,QTY_PRESTAMO,arrayCliente,QTY_CLIENTE);
			break;
		case 6:
			reanudarPrestamo(arrayPrestamo,QTY_PRESTAMO,arrayCliente,QTY_CLIENTE);
			break;
		case 7:
			imprimirClientes(arrayPrestamo,QTY_PRESTAMO,arrayCliente,QTY_CLIENTE);
			break;
		case 8:
			imprimirPrestamos(arrayPrestamo,QTY_PRESTAMO,arrayCliente,QTY_CLIENTE);
			break;
		case 9:
			informeClientes(arrayCliente,QTY_CLIENTE);
			break;

		}


	}



	return 0;
}
