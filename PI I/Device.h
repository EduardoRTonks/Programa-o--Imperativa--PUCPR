#pragma once
#include "Util.h"

using namespace std;

class Device
{
protected:
	string fabricante;
	string modelo;
	string num_serie;
	tipoDevice tipo_device;
public:
	Device()
	{
		tipo_device = TipoDevice::TD_Generico;
	}

	/* Retorna fabricante */
	string obtem_fabricante()
	{
		return fabricante;
	}

	/* Retorna modelo */
	string obtem_modelo()
	{
		return modelo;
	}

	/* Retorna numero de série do dispositivo */
	string obtem_num_serie()
	{
		return num_serie;
	}

	/* retorna o tipo de dispositivo */
	tipoDevice obtem_tipo_device()
	{
		return tipo_device;
	}

	/* retorna o tipo de dispositivo em formato string */
	string tipo_device_as_string()
	{
    /* Retorna o 'tipo_device' em formato string */
	return 0;
	}
};

