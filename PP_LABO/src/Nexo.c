#include "Nexo.h"

int inicializarProcesados(eProcesado listaProcesados[], int tam)
{
	int retorno;
	retorno = -1;

	if(listaProcesados != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			listaProcesados[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

return retorno;
}

int SolicitarIdPedidos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int id;
	int reintentos = 3;
	int retorno = -1;

	do{
			printf("\n\n");
			PrintPedidos(listaClientes, tamClientes, listaPedidos, tamPedidos);

			if(PedirNumero(&id, "\nIngrese id: ") && BuscarPedidoPorId(listaPedidos, tamPedidos, id) >= 0)
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


int PrintPedido(eCliente listaClientes, ePedido listaPedidos)
{
	printf("*  	%-7d %-7d %-10s 	*\n", listaPedidos.id, listaPedidos.kg, listaClientes.nombreEmpresa);

return 0;
}


int PrintPedidos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = 0;
	printf("*****************************************\n*					*\n");
	printf("*  	ID	KG	Cliente		*\n");
	for(int i = 0; i < tamClientes; i++)
	{
		for(int j = 0; j < tamPedidos; j++)
		{
			if(listaClientes[i].isEmpty == FALSE && listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].estado == PENDIENTE)
			{
				PrintPedido(listaClientes[i], listaPedidos[j]);
			}
		}
	}
	printf("*					*\n*****************************************\n");
return retorno;
}

int ProcesarResiduos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, ePlastico listaPlasticos[], int tamPlasticos, eProcesado listaProcesados[])
{
	int retorno = 0;
	int idPedido;
	int indicePedido;
	int hdpe;
	int ldpe;
	int pp;

	idPedido = SolicitarIdPedidos(listaClientes, tamClientes, listaPedidos, tamPedidos);
	indicePedido = BuscarPedidoPorId(listaPedidos, tamPedidos, idPedido);
	printf("\n\nCantidad KG total: %d\n\n", listaPedidos[indicePedido].kg);

	if(PedirNumeroConReintentosConRango(&hdpe, "Ingrese cantidad de kg de HDPE: ", 0, listaPedidos[indicePedido].kg, 3) &&
	PedirNumeroConReintentosConRango(&ldpe, "Ingrese cantidad de kg de LDPE: ", 0, listaPedidos[indicePedido].kg, 3) &&
	PedirNumeroConReintentosConRango(&pp, "Ingrese cantidad de kg de PP: ", 0, listaPedidos[indicePedido].kg, 3))
	{
		if(hdpe+ldpe+pp == listaPedidos[indicePedido].kg)
		{
			listaPedidos[indicePedido].estado = PROCESADO;
			strcpy(listaPedidos[indicePedido].descripcion, "Procesado");

			for(int i = 0; i < tamPedidos; i++)
			{
				if(listaProcesados[i].isEmpty == TRUE)
				{
					listaProcesados[i].idPedido = idPedido;
					listaProcesados[i].hdpe = hdpe;
					listaProcesados[i].ldpe = ldpe;
					listaProcesados[i].pp = pp;
					listaProcesados[i].isEmpty = FALSE;
					break;
				}
			}
			printf("\nPedido procesado\n\n");
			retorno = 0;
		}
		else
		{
			printf("\nError al procesar el pedido. No coincide la cantidad de kg\n\n");
		}
	}

return retorno;
}

int PrintPedidoPendiente(eCliente listaClientes, ePedido listaPedidos)
{
	printf("*  %-16s %-19s %-7d *\n", listaClientes.cuit, listaClientes.direccion, listaPedidos.kg);

return 0;
}

int PrintPedidosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = 0;

	if(listaPedidos != NULL && tamClientes > 0)
		{
			printf("*************************************************\n*						*\n");
			printf("*  	CUIT	    DIRECCION	        KG	*\n");
			for(int i = 0; i < tamClientes; i++)
			{
				for(int j = 0; j < tamPedidos; j++)
				{
					if(listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].isEmpty == FALSE && listaPedidos[j].estado == PENDIENTE)
					{
						PrintPedidoPendiente(listaClientes[i], listaPedidos[j]);
						retorno = 1;
					}
				}
			}
			printf("*						*\n*************************************************\n\n");
		}

return retorno;
}

int PrintPedidoProcesado(eCliente listaClientes, ePedido listaPedidos, eProcesado listaProcesados)
{
	printf("*  %-16s %-19s %-7d %-7d %-7d *\n", listaClientes.cuit, listaClientes.direccion, listaProcesados.hdpe, listaProcesados.ldpe, listaProcesados.pp);

return 0;
}


int PrintPedidosProcesados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eProcesado listaProcesados[])
{
	int retorno = 0;
	int indiceCliente;

	if(listaPedidos != NULL && tamClientes > 0)
		{
			printf("*****************************************************************\n*								*\n");
			printf("*  	CUIT	    DIRECCION	        HDPE	LDPE	PP	*\n");
			for(int i = 0; i<tamPedidos; i++)
				{
					for(int j = 0; j< tamPedidos; j++)
					{
						if(listaPedidos[i].estado == PROCESADO && listaPedidos[i].id == listaProcesados[j].idPedido && listaProcesados[j].isEmpty == FALSE)
						{
							indiceCliente = BuscarClientePorId(listaClientes, tamClientes, listaPedidos[i].idCliente);
							if(indiceCliente >= 0)
							{
								PrintPedidoProcesado(listaClientes[indiceCliente], listaPedidos[i], listaProcesados[j]);
								retorno = 1;
							}
						}
					}
				}
			printf("*								*\n*****************************************************************\n\n");
		}

return retorno;
}

int BuscarLocalidadPorId(eLocalidad localidades[], int tam, int id)
{
	int retorno = -1;

	if(localidades != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(localidades[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

return retorno;
}

int ContarPedidosPendientesLocalidad(ePedido listaPedidos[], int tamPedidos, eLocalidad localidades[], eAuxiliar contador[])
{
	int retorno = 0;

	for(int i = 0; i < 3; i++)
    {
       contador[i].contador = 0;
       contador[i].id = localidades[i].id;
    }

	for(int i = 0; i<tamPedidos; i++)
	{
		for(int j = 0; j< tamPedidos; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				if(listaPedidos[i].estado == PENDIENTE && listaPedidos[i].idLocalidad == contador[j].id && listaPedidos[i].idLocalidad == localidades[k].id)
				{

					contador[k].contador++;
					retorno = 1;
				}
			}
		}
	}
return retorno;
}




