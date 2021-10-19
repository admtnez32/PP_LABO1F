#include "Clientes.h"

int InicializarClientes(eCliente listaClientes[], int tam)
{
	int retorno;
	retorno = -1;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			listaClientes[i].isEmpty = TRUE;
		}

		retorno = 0;
	}

return retorno;
}

int BuscarLugarLibre(eCliente listaClientes[], int tam)
{
	int retorno = -1;

	for(int i = 0; i < tam; i++)
	{
		if(listaClientes[i].isEmpty == TRUE)
		{
			retorno = i;
			break;
		}
	}

return retorno;
}

int AltaCliente(eCliente listaClientes[], int tamClientes, int* id)
{
	int retorno = 0;
	int auxId;
	int indice;
	int localidad;
	char cuit[TAM_CUIT];
	char nombre[TAM_EMPRESA];
	char direccion[TAM_DIRECCION];


	indice = BuscarLugarLibre(listaClientes, tamClientes);

	if(indice >= 0){

		if(PedirCaracteresConReintentos(nombre, TAM_EMPRESA, "Ingrese nombre de la empresa: ", 3) &&
		   PedirCaracteresConReintentos(cuit, TAM_CUIT, "Ingrese cuit sin guiones: ", 3) &&
		   PedirCaracteresConReintentos(direccion, TAM_DIRECCION, "Ingrese direccion: ", 3) &&
		   PedirNumeroConReintentosConRango(&localidad, "Ingrese localidad:\n\n 1) Lanus\n2) Avella\n3) Caba\n Opcion: ", 1, 3, 3)
		   )
		{
			strcpy(listaClientes[indice].nombreEmpresa, nombre);
			strcpy(listaClientes[indice].cuit, cuit);
			strcpy(listaClientes[indice].direccion, direccion);
			listaClientes[indice].localidad = localidad;
			auxId = *id;
			listaClientes[indice].id = auxId;
			*id = auxId+1;
			listaClientes[indice].isEmpty = FALSE;
			retorno = 1;
			printf("\nID generado: %d\n--- ALTA EXITOSA ---\n\n", listaClientes[indice].id);
		}
	}
	else
	{
		printf("\n--- No hay mas lugar en el array ---\n\n");
	}

return retorno;
}

int PrintCliente(eCliente listaCliente, eAuxiliar contador, eLocalidad localidad)
{
	printf("*  %-5d %-15s %-15s %-22s %-15s %d   		*\n", listaCliente.id, listaCliente.nombreEmpresa, listaCliente.cuit, listaCliente.direccion, localidad.descripcion, contador.contador);

return 0;
}

int ContarPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eAuxiliar contador[])
{
	int retorno = 0;

    for(int i = 0; i < tamClientes; i++)
    {
       contador[i].contador = 0;
       contador[i].id = listaClientes[i].id;
    }

	for(int i = 0; i<tamClientes; i++)
	{
		for(int j = 0; j< tamPedidos; j++)
		{
			for(int k = 0; k < tamClientes; k++)
			{
				if(listaClientes[i].id == listaPedidos[j].idCliente && listaClientes[i].id == contador[k].id && listaPedidos[j].estado == PENDIENTE)
				{
					contador[k].contador++;
					retorno = 1;
				}
			}
		}
	}
return retorno;
}

int PrintClientes(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[])
{
	eAuxiliar contador[tam];
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		ContarPedidosPendientes(listaClientes, tam, listaPedidos, tamPedidos, contador);
		printf("*************************************************************************************************\n*									  		        *\n");
		printf("*  ID  	 NOMBRE		 CUIT	 	 DIRECCION		LOCALIDAD	C.P.PENDIENTES  *\n");
		for(int i = 0; i < tam; i++)
		{
			for(int j = 0; j < tam; j++)
			{
				for(int k = 0; k<3; k++)
				{
					if(listaClientes[i].isEmpty == FALSE && listaClientes[i].id == contador[j].id && localidades[k].id == listaClientes[i].localidad)
					{
						PrintCliente(listaClientes[i], contador[i], localidades[k]);
						retorno = 1;
					}
				}
			}
		}
		printf("*								 	 			*\n*************************************************************************************************\n");
	}

return retorno;
}

int BuscarClientePorId(eCliente listaClientes[], int tam, int id)
{
	int retorno;
	retorno = -1;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaClientes[i].isEmpty == FALSE && listaClientes[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

return retorno;
}

int SolicitarId(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[])
{
	int id;
	int reintentos = 3;
	int retorno = -1;

	do{
			printf("\n\n");
			PrintClientes(listaClientes, tam, listaPedidos, tamPedidos, localidades);

			if(PedirNumero(&id, "\nIngrese id: ") && BuscarClientePorId(listaClientes, tam, id) >= 0)
			{
				printf("\n---- Id correcto ---\n");
				retorno = id;
				reintentos = 0;
			}
			else
			{
				printf("\n\n--- Id incorrecto ---\n--- Le quedan %d reintento/s ---\n\n", reintentos-1);
			}
		reintentos--;
	}while(reintentos > 0);

return retorno;
}

int ModificarCliente(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[])
{
	int retorno = 1;
	int id;
	int indice;
	int opcion;
	int localidad;
	char direccion[51];

	id = SolicitarId(listaClientes, tam, listaPedidos, tamPedidos, localidades);
	indice = BuscarClientePorId(listaClientes, tam, id);
	if(id != -1 && indice != -1)
	{
		do{
			printf("\n\n");
			PrintMenu(MODIFICAR);

			if(PedirNumero(&opcion, "Ingrese opcion: "))
			{
				switch(opcion)
				{
				case 1:
					if(PedirCaracteresConReintentos(direccion, TAM_DIRECCION, "Ingrese direccion: ", 3))
					{
						strcpy(listaClientes[indice].direccion, direccion);
						printf("\n\n--- Direccion modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 2:
					if(PedirNumeroConReintentosConRango(&localidad, "Ingrese localidad:\n\n 1) Lanus\n2) Avella\n3) Caba\n Opcion: ", 1, 3, 3))
					{
						listaClientes[indice].localidad = localidad;
						printf("\n\n--- Localidad modificado con exito ---\n\n");
					}
					else
					{
						retorno = 0;
						opcion = 0;
					}
					break;

				case 0:
					printf("\n--- Volviendo al menu principal ---\n\n");
					break;

				default:
					printf("\n--- Opcion no valida ---\n\n");
					break;
				}
			}
		}while(opcion != 0);
	}
	else
	{
		retorno = 0;
	}

return retorno;
}

int BajarCliente(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[])
{
	int retorno = 0;
	int id;
	int opcion;

	if(listaClientes != NULL && tam > 0)
	{
		id = SolicitarId(listaClientes, tam, listaPedidos, tamPedidos, localidades);

		if(id != -1)
		{
			for(int i = 0; i < tam; i++)
			{
				if(listaClientes[i].id == id && PedirNumeroConReintentosConRango(&opcion, "\nConfirma la baja del cliente?\n\n1)Si\n2)No\nOpcion: ", 1, 2, 3) && opcion == 1)
				{
					listaClientes[i].isEmpty = TRUE;
					printf("\n--- Baja exitosa ---\n\n");
					retorno = 1;
					break;
				}
			}
		}
	}
return retorno;
}

/*	Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un cliente existente
	y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y el mismo quedará en estado “Pendiente”
	hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
*/
int CrearPedido(eCliente listaClientes[], int tam, ePedido listaPedidos[], int tamPedidos, int* idPedido, eLocalidad localidades[])
{
	int retorno = 0;
	int idCliente;
	int auxIdPedido;
	int kg;
	int indiceCliente;

		idCliente = SolicitarId(listaClientes, tam, listaPedidos, tamPedidos, localidades);

		if(idCliente != -1 && PedirNumeroConReintentos(&kg, "Ingrese kilos a recoletar: ", 3))
		{
			for(int i = 0; i < tamPedidos; i++)
			{
				if(listaPedidos[i].isEmpty == TRUE)
				{
					indiceCliente = BuscarClientePorId(listaClientes, tam, idCliente);

					listaPedidos[i].idCliente = listaClientes[indiceCliente].id;
					listaPedidos[i].idLocalidad = listaClientes[indiceCliente].localidad;
					listaPedidos[i].kg = kg;
					listaPedidos[i].isEmpty = FALSE;
					listaPedidos[i].estado = PENDIENTE;
					strcpy(listaPedidos[i].descripcion, "Pendiente");
					auxIdPedido = *idPedido;
					listaPedidos[i].id = auxIdPedido;
					*idPedido = auxIdPedido+1;
					retorno = 1;
					printf("\n--- Pedido cargado ---\n\n");
					break;
				}
			}
		}

return retorno;
}

