#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"
#include "informe.h"

// La gran mayoria lo hice en esta biblioteca, porque se me hacia mas facil realizarlo asi. Espero no me juegue en contra! Anda todo 100% probado.

//***********************************************************************************************************************************
int bajaCliente(eCliente arrayCliente[],int sizeCliente,ePrestamo arrayPrestamo[], int sizePrestamo)
{
	int retorno = -1;
	int bufferIdCliente;
	int i,j;
	int posicion;
	int option;

	if(arrayCliente != NULL && sizeCliente>0 && arrayPrestamo!= NULL && sizePrestamo>0)
	{
		utn_getUnsignedInt("\nIngrese el id Cliente: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&bufferIdCliente);
		if(buscarIdCliente(arrayCliente,sizeCliente,bufferIdCliente,&posicion)==-1)
		{
			printf("\nNo Existe ese Id\n");
		}
		else
		{
			for(i=0;i<sizePrestamo;i++)
			{
				if(arrayPrestamo[i].isEmptyPrestamo == 1)
					continue;
				if(arrayPrestamo[i].idCliente == bufferIdCliente)
				{
					printf("\n****************************************************\nId Prestamo: %d\nid Cliente: %d\nImporte: %.2f\nCant de cuotas: %d\nEstado de prestamo: %s\n",
					            		arrayPrestamo[posicion].idPrestamo,arrayPrestamo[posicion].idCliente,arrayPrestamo[posicion].importePrestamo,
										arrayPrestamo[posicion].cuotasPrestamo,arrayPrestamo[posicion].estadoPrestamo);
				}

			}

			utn_getUnsignedInt("\nDesea eliminar este cliente?.Implicar� la eliminaci�n del mismo con  todos los pr�stamos.\n1-Si\n2-No\nElija una opcion: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&option);
			switch(option)
			{
				case 1:
					for(i=0;i<sizePrestamo;i++)
					{
						if(arrayPrestamo[i].isEmptyPrestamo == 1)
							continue;
						if(arrayPrestamo[i].idCliente == bufferIdCliente)
						{
							arrayPrestamo[i].idPrestamo = 0;
							arrayPrestamo[i].idCliente = 0;
							arrayPrestamo[i].importePrestamo = 0;
							arrayPrestamo[i].cuotasPrestamo = 0;
							strcpy(arrayPrestamo[i].estadoPrestamo,"");
							arrayPrestamo[i].isEmptyPrestamo = 1;

						}
					}

					for(j=0;j<sizeCliente;j++)
					{
						if(arrayCliente[i].isEmptyCliente == 1)
							continue;
						if(arrayCliente[j].idCliente == bufferIdCliente)
						{
							arrayCliente[j].idCliente = 0;
							strcpy(arrayCliente[j].nombreCliente,"");
							strcpy(arrayCliente[j].apellidoCliente,"");
							strcpy(arrayCliente[j].cuilCliente,"");
							arrayCliente[j].masPrestamoActivo = 0;
							arrayCliente[j].masPrestamoSaldo = 0;
							arrayCliente[j].isEmptyCliente = 1;
						}
					}

					break;
				case 2:
					printf("\nEliji� No.\n");
					break;
				default: printf("\nIngrese la opcion 1 o 2.\n");
			}

		}
		retorno = 0;
	}

	return retorno;
}

//***********************************************************************************************************************************
int realizarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo, int* contadorID,eCliente arrayCliente[],int sizeCliente)
{
    int retorno=-1;
    int posicion;
    int bufferIdCliente;
    int posicion2;

    if(arrayPrestamo!=NULL && sizePrestamo>0 && contadorID!=NULL && arrayCliente!=NULL && sizeCliente>0)
    {
        if(buscarEmptyPrestamo(arrayPrestamo,sizePrestamo,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	utn_getUnsignedInt("\nIngrese el id Cliente: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&bufferIdCliente);
        	if(buscarIdCliente(arrayCliente,sizeCliente,bufferIdCliente,&posicion2)==-1)
        	{
        		printf("\nNo Existe ese Id\n");
        	}

        	else
        	{
        	// Si existe Cargo lo siguiente
            (*contadorID)++;
            arrayPrestamo[posicion].idPrestamo=*contadorID;
            arrayPrestamo[posicion].isEmptyPrestamo=0;
            arrayPrestamo[posicion].idCliente=bufferIdCliente;
            strcpy(arrayPrestamo[posicion].estadoPrestamo,"DEBE ACTIVAR EL PRESTAMO");
            utn_getFloat("\nImporte: ","\nError",1,100000,1,100000,3,&arrayPrestamo[posicion].importePrestamo);
            utn_getUnsignedInt("\nCantidad de cuotas: ","\nError",1,sizeof(int),1,10000,3,&arrayPrestamo[posicion].cuotasPrestamo);
            printf("\n***********************************\nId Prestamo: %d\nid Cliente: %d\nImporte: %.2f\nCant de cuotas: %d\nEstado: %s",
            		arrayPrestamo[posicion].idPrestamo,arrayPrestamo[posicion].idCliente,arrayPrestamo[posicion].importePrestamo,
					arrayPrestamo[posicion].cuotasPrestamo,arrayPrestamo[posicion].estadoPrestamo);
            retorno=0;
        	}
        }
    }
    return retorno;
}
//***********************************************************************************************************************************

int saldarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente)
{
	int retorno = -1;
	int idPrestamo;
	int posicion;
	int i;
	int option;
	int acumuladorSaldo = 0;
	int auxIdCliente = 0;
	int auxDecrementar = 0;

	if(arrayPrestamo != NULL && sizePrestamo>0 && arrayCliente != NULL && sizeCliente>0)
	{
		utn_getUnsignedInt("\nIngrese el id de prestamo: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&idPrestamo);
		if(buscarIdPrestamo(arrayPrestamo,sizePrestamo,idPrestamo,&posicion)==-1)
		{
			printf("\nNo Existe ese Id\n");
		}
		else
		{
			for(i=0;i<sizeCliente;i++)
			{
				if(arrayCliente[i].isEmptyCliente==0 && arrayCliente[i].idCliente == arrayPrestamo[posicion].idCliente)
				{
					printf("\n*********************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\n*********************************************",
								arrayCliente[i].idCliente,arrayCliente[i].nombreCliente,arrayCliente[i].apellidoCliente,arrayCliente[i].cuilCliente);
					auxIdCliente= arrayCliente[i].idCliente;
				}
			}


			utn_getUnsignedInt("\nSu estado esta: \n1-Saldado\n2-Salir\nIngrese opcion: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&option);
			switch(option)
			{
			case 1:

				if(strcmp(arrayPrestamo[posicion].estadoPrestamo,"SALDADO")==0)
				{
					printf("\nEste prestamo ya esta saldado.\n");
					break;
				}

				if(strcmp(arrayPrestamo[posicion].estadoPrestamo,"ACTIVO")==0)
				{
					auxDecrementar = arrayCliente[auxIdCliente].masPrestamoActivo - 1;
					arrayCliente[auxIdCliente].masPrestamoActivo = auxDecrementar;
				}

				strcpy(arrayPrestamo[posicion].estadoPrestamo,"SALDADO");
				printf("\nSu prestamo se encuentra: %s",arrayPrestamo[posicion].estadoPrestamo);
				acumuladorSaldo = arrayCliente[auxIdCliente].masPrestamoSaldo + 1;
				arrayCliente[auxIdCliente].masPrestamoSaldo = acumuladorSaldo;
				printf("\nCant Saldos de ese cliente: %d",arrayCliente[auxIdCliente].masPrestamoSaldo);
				break;
			case 2:
				break;
			default: printf("\nIngrese la opcion entre 1 o 2\n");

			}
		}

		retorno = 0;
	}

	return retorno;
}
//***********************************************************************************************************************************
int reanudarPrestamo(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente)
{
	int retorno = -1;
	int idPrestamo;
	int posicion;
	int i;
	int option;
	int acumuladorActivos = 0;
	int auxIdCliente = 0;

	if(arrayPrestamo != NULL && sizePrestamo>0 && arrayCliente != NULL && sizeCliente>0)
	{
		utn_getUnsignedInt("\nIngrese el id de prestamo: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&idPrestamo);
		if(buscarIdPrestamo(arrayPrestamo,sizePrestamo,idPrestamo,&posicion)==-1)
		{
			printf("\nNo Existe ese Id\n");
		}

		else
		{
			for(i=0;i<sizeCliente;i++)
			{
				if(arrayCliente[i].isEmptyCliente==0 && arrayCliente[i].idCliente == arrayPrestamo[posicion].idCliente)
				{
					printf("\n*********************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\n*********************************************",
							arrayCliente[i].idCliente,arrayCliente[i].nombreCliente,arrayCliente[i].apellidoCliente,arrayCliente[i].cuilCliente);
					auxIdCliente= arrayCliente[i].idCliente;
				}
			}

			utn_getUnsignedInt("\nSu estado esta: \n1-ACTIVO\n2-Salir\nIngrese opcion: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&option);
			switch(option)
			{
			case 1:
				if(strcmp(arrayPrestamo[posicion].estadoPrestamo,"SALDADO")==0)
				{
					printf("\nEste prestamo ya esta saldado.\n");
					break;
				}
				if(strcmp(arrayPrestamo[posicion].estadoPrestamo,"ACTIVO")==0)
				{
					printf("\nEste prestamo ya esta activo.\n");
					break;
				}

				strcpy(arrayPrestamo[posicion].estadoPrestamo,"ACTIVO");
				printf("\nSu prestamo se encuentra: %s",arrayPrestamo[posicion].estadoPrestamo);
				acumuladorActivos = arrayCliente[auxIdCliente].masPrestamoActivo + 1;
				arrayCliente[auxIdCliente].masPrestamoActivo = acumuladorActivos;
				printf("\nCant de renaudo: %d\n",arrayCliente[auxIdCliente].masPrestamoActivo);
				break;
			case 2:
				break;
			default: printf("\nIngrese la opcion entre 1 o 2\n");
			}


		}
		retorno = 0;
	}
	return retorno;
}
//***********************************************************************************************************************************

int imprimirClientes(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente)
{
	int retorno = -1;
	int i,j;

	if(arrayPrestamo != NULL && sizePrestamo>0 && arrayCliente != NULL && sizeCliente>0)
	{
		for(i=0;i<sizePrestamo;i++)
		{
			if(arrayPrestamo[i].isEmptyPrestamo == 1)
				continue;
			if(strcmp(arrayPrestamo[i].estadoPrestamo,"ACTIVO") == 0)
			{
				for(j=0;j<sizeCliente;j++)
				{
					if( arrayCliente[j].isEmptyCliente == 1)
						continue;
					if(arrayPrestamo[i].idCliente == arrayCliente[j].idCliente)
					{
						printf("\n*********************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\nid Prestamo: %d\nPrestamo: %s\n*********************************************",
								arrayCliente[j].idCliente,arrayCliente[j].nombreCliente,arrayCliente[j].apellidoCliente,arrayCliente[j].cuilCliente,arrayPrestamo[i].idPrestamo,arrayPrestamo[i].estadoPrestamo);

					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

//***********************************************************************************************************************************

int imprimirPrestamos(ePrestamo arrayPrestamo[], int sizePrestamo,eCliente arrayCliente[],int sizeCliente)
{
	int retorno = -1;
	int i,j;

	if(arrayPrestamo != NULL && sizePrestamo>0 && arrayCliente != NULL && sizeCliente>0)
	{
		for(i=0;i<sizePrestamo;i++)
		{
			if(arrayPrestamo[i].isEmptyPrestamo == 1)
				continue;
			if(strcmp(arrayPrestamo[i].estadoPrestamo,"ACTIVO") == 0)
			{
				for(j=0;j<sizeCliente;j++)
				{
					if( arrayCliente[j].isEmptyCliente == 1)
						continue;
					if(arrayPrestamo[i].idCliente == arrayCliente[j].idCliente)
					{
						printf("\n****************************************\nId Prestamo: %d\nId Cliente: %d\nImporte: %.2f\nCant Cuotas: %d\nEstado: %s\nCuil de cliente: %s\n*********************************************",
								arrayPrestamo[i].idPrestamo,arrayPrestamo[i].idCliente,arrayPrestamo[i].importePrestamo,arrayPrestamo[i].cuotasPrestamo,arrayPrestamo[i].estadoPrestamo,arrayCliente[j].cuilCliente);

					}
				}

			}
		}
		retorno = 0;
	}

	return retorno;
}

//***********************************************************************************************************************************

int informeClientes(eCliente arrayCliente[],int sizeCliente)
{
	int retorno = -1;
	int option = 0;
	int j;
	int mayorCliente = 0;
	char nombre[51];
	char apellido[51];
	int idCliente;
	char cuil[51];

	if(arrayCliente != NULL && sizeCliente>0)
	{
		utn_getUnsignedInt("\nSu estado esta: \n1-Cliente con m�s pr�stamos activos.\n2-Cliente con m�s pr�stamos saldados.\n3-Cliente con m�s pr�stamos.\n4-Salir\nIngrese opcion: ","\nError.",1,sizeof(int),1,sizeCliente,3,&option);
		switch(option)
		{
		case 1:
			for(j=0;j<sizeCliente;j++)
			{
				if( arrayCliente[j].isEmptyCliente == 1)
					continue;
				if(arrayCliente[j].masPrestamoActivo > mayorCliente)
				{
					mayorCliente = arrayCliente[j].masPrestamoActivo;
					idCliente = arrayCliente[j].idCliente;
					strcpy(nombre,arrayCliente[j].nombreCliente);
					strcpy(apellido,arrayCliente[j].apellidoCliente);
					strcpy(cuil,arrayCliente[j].cuilCliente);

				}
			}
			printf("\n***************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\nCliente con m�s pr�stamos activos: %d",
			            	                   idCliente,nombre,apellido,cuil,mayorCliente);
			retorno = 0;
			break;
		case 2:
			for(j=0;j<sizeCliente;j++)
			{
				if( arrayCliente[j].isEmptyCliente == 1)
					continue;
				if(arrayCliente[j].masPrestamoSaldo > mayorCliente)
				{
					mayorCliente = arrayCliente[j].masPrestamoSaldo;
					idCliente = arrayCliente[j].idCliente;
					strcpy(nombre,arrayCliente[j].nombreCliente);
					strcpy(apellido,arrayCliente[j].apellidoCliente);
					strcpy(cuil,arrayCliente[j].cuilCliente);

				}
			}
			printf("\n***************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\nCliente con m�s pr�stamos saldados: %d",
					idCliente,nombre,apellido,cuil,mayorCliente);
			retorno = 0;
			break;
		case 3://c) Cliente con m�s pr�stamos.
			for(j=0;j<sizeCliente;j++)
			{
				if( arrayCliente[j].isEmptyCliente == 1)
				continue;

				arrayCliente[j].prestamosTotales = arrayCliente[j].masPrestamoSaldo + arrayCliente[j].masPrestamoActivo;

				if(arrayCliente[j].prestamosTotales > mayorCliente)
				{
					mayorCliente = arrayCliente[j].prestamosTotales;
					idCliente = arrayCliente[j].idCliente;
					strcpy(nombre,arrayCliente[j].nombreCliente);
					strcpy(apellido,arrayCliente[j].apellidoCliente);
					strcpy(cuil,arrayCliente[j].cuilCliente);
				}

			}

			printf("\n***************************************\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s\nCliente con m�s pr�stamos: %d",
					idCliente,nombre,apellido,cuil,mayorCliente);
			break;
		case 4:
			printf("\nSali�.\n");
			break;
		default: printf("\nIngrese un numero entre el 1 y el 4\n");
		}

		retorno = 0;
	}
	return retorno;
}

//***********************************************************************************************************************************

int informePrestamo(ePrestamo arrayPrestamo[], int sizePrestamo)
{
	int retorno = -1;
	int i;
	float importe;
	int option = 0;
	int auxCantCuotas;

/*b) Pr�stamos de 12 cuotas saldados.
 *
 */


	if(arrayPrestamo != NULL && sizePrestamo > 0)
	{
		utn_getUnsignedInt("\n1-Cantidad de pr�stamos de importe mayor a 1000\n2-Prestamos de 12 cuotas saldados.\n3-Prestamos por cuota\n4-Salir\nIngrese opcion: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&option);

		switch(option)
		{
		case 1:
		utn_getFloat("\nIngrese un Importe mayor a 1000: ","\nError",1,100000,1,100000,3,&importe);
		while(importe<1000)
		{
			utn_getFloat("\nIngrese un Importe mayor a 1000: ","\nError",1,100000,1,100000,3,&importe);
		}

		for(i=0;i<sizePrestamo;i++)
		{
			if(arrayPrestamo[i].isEmptyPrestamo == 1)
				continue;
			if(arrayPrestamo[i].importePrestamo== importe && strcmp(arrayPrestamo[i].estadoPrestamo,"ACTIVO") == 0)
			{
				printf("\n*******************************************\nid Prestamo: %d\nImporte: %.2f",arrayPrestamo[i].idPrestamo,arrayPrestamo[i].importePrestamo);
			}

		}
		break;
		case 2:
			for(i=0;i<sizePrestamo;i++)
			{
				if(arrayPrestamo[i].isEmptyPrestamo == 1)
					continue;
				if(arrayPrestamo[i].cuotasPrestamo == 12 && strcmp(arrayPrestamo[i].estadoPrestamo,"SALDADO")==0)
				{
					printf("\n***********************\nid Prestamo: %d\nid Cliente: %d\nCant Cuotas: %d\nEstado: %s",arrayPrestamo[i].idPrestamo,arrayPrestamo[i].idCliente,arrayPrestamo[i].cuotasPrestamo,arrayPrestamo[i].estadoPrestamo);
				}

			}
			break;
		case 3://c) Pr�stamos por cuotas: Se ingresar� la cantidad de cuotas y se imprimir�n la
			//cantidad de pr�stamos activos con esa cantidad de cuotas.
			utn_getUnsignedInt("\nCantidad de cuotas: ","\nError.",1,sizeof(int),1,sizePrestamo,3,&auxCantCuotas);
			for(i=0;i<sizePrestamo;i++)
			{
				if(arrayPrestamo[i].isEmptyPrestamo == 1)
					continue;
				if(arrayPrestamo[i].cuotasPrestamo == auxCantCuotas && strcmp(arrayPrestamo[i].estadoPrestamo,"ACTIVO")== 0)
				{
					printf("\n***********************\nid Prestamo: %d\nid Cliente: %d\nCant Cuotas: %d\nEstado: %s",arrayPrestamo[i].idPrestamo,arrayPrestamo[i].idCliente,arrayPrestamo[i].cuotasPrestamo,arrayPrestamo[i].estadoPrestamo);
				}
			}
			break;
		case 4:
			printf("\nSali�.\n");
			break;
		default: printf("\nIngrese un numero del 1 al 4.\n");
		}


		retorno = 0;
	}
	return retorno;
}
