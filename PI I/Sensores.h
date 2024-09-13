#pragma once
#include "Util.h"
#include "Device.h"
#include "EstacaoBase.h"

using namespace std;

/* ------------------------------------------ Tipos de Sensores -------------------------------------------- */

class Sensor : public Device
{
protected:
	vector<Dados> dados;
	tipoSensor tipo_sensor;
	unidade_medida u_m;
	int meu_id;
	float lim_min, lim_max;

public:
	Sensor() {
		/* Inicializar o atributo 'tipo_device' */
		meu_id = id;
		id++;
	}

	// Métodos de atribuição de valores
	void atribui_fabricante(string Fabric) {
		fabricante = Fabric;
	}

	void atribui_modelo(string Model) {
		modelo = Model;
	}

	void atribui_num_serie(string NumS) {
		num_serie = NumS;
	}

	/* Retorna o ID do Sensor */
	int obtem_id() {
		return meu_id;
	}

	/* Apaga os dados sensoriais armazenados */
	void limpa_dados() {
		dados.clear(); // Apaga todos os dados do vector 'dados'
	}

	/* Imprime os dados sensoriais armazenados no Sensor */
	void imprime_dados() {
		// Implementação para imprimir os dados
	}

	/* Gera valores aleatórios para o Sensor armazenar como dados Sensoriais */
	void le_dado_do_sensor() {
		Dados dado;

		int qtdade_dados = random(MAX_DADOS);

		for (int i = 0; i < qtdade_dados; i++) {
			dado.timestamp = data_hora();
			dado.info = random(lim_min, lim_max);
			dado.id = meu_id;

			// Verifica se o dado está fora dos limites ideais
			if (dado.info < lim_min || dado.info > lim_max)
				dado.alarme = true;
			else
				dado.alarme = false;

			dado.tipo_sensor = tipo_sensor_as_string();
			dado.unidade_medida = u_m;
			dado.fab = fabricante;
			dado.mod = modelo;
			dado.num_serie = num_serie;

			dados.push_back(dado);
		}
	}

	/* Copia todos os dados sensoriais armazenados no vector para a Estação Base */
	void transmite_dados(EstacaoBase* base) {
		// Transmite os dados do vetor 'dados' local para a estação base
		base->recebe_dados_do_sensor(dados);
    
		// Limpa todos os dados locais do sensor
		dados.clear();
	}

	/* Converte o tipo de sensor para string e retorna */
	string tipo_sensor_as_string() {
		switch (tipo_sensor) {
			case TipoSensor::TS_Generico:
				return "Generico";
			case TipoSensor::Umidade:
				return "Umidade";
			case TipoSensor::IndicePH:
				return "IndicePH";
			case TipoSensor::Temperatura:
				return "Temperatura";
			default:
				return "Desconhecido";
		}
	}

	static unsigned int id;
};

/* ID único para cada Sensor criado */
unsigned int Sensor::id = 1;

/* ------------------------------------------ Tipos de Sensores -------------------------------------------- */

/*
	Os limites para os valores de dados sensoriais de temperatura do solo podem variar dependendo da cultura específica,
	do estágio de crescimento das plantas e das condições climáticas locais. No entanto, em geral, os limites típicos
	para valores de temperatura do solo em contextos de plantio são os seguintes:

	- Mínimo Aceitável: Geralmente acima de 5°C para evitar danos às raízes e retardar o crescimento das plantas.
	- Ideal para Germinação de Sementes: Entre 10°C e 25°C para promover uma germinação saudável.
	- Máximo Tolerável: Abaixo de 35°C para evitar danos às raízes e redução na absorção de água e nutrientes.
*/

class SensorTemperatura : public Sensor {
private:
public:
	SensorTemperatura() {
		tipo_sensor = TipoSensor::Temperatura; // Inicializa o atributo 'tipo_sensor' com o enum correspondente a Temperatura
		u_m = "celcius"; // Inicializa o atributo 'u_m' com a unidade de medida correspondente a Celsius (você pode definir o valor de UNIDADE_CELSIUS no Util.h)
		lim_min = MIN_TEMP; // Inicializa o atributo 'lim_min' com o valor mínimo de temperatura definido em Util.h
		lim_max = MAX_TEMP; // Inicializa o atributo 'lim_max' com o valor máximo de temperatura definido em Util.h
	}
};

/*
Para os sensores de umidade do solo, os limites ideais podem variar dependendo do tipo de planta, das condições
climáticas e do estágio de crescimento da cultura. No entanto, em geral, os seguintes limites são considerados:

- Mínimo Aceitável: O solo deve ter uma umidade mínima para garantir que as plantas tenham acesso adequado à água.
  Isso pode variar dependendo da tolerância à seca da cultura, mas geralmente é superior a 10% da capacidade de campo.
- Ideal para o Crescimento: Uma faixa de umidade ideal para muitas culturas está entre 50% e 75% da capacidade de campo.
  Isso proporciona um equilíbrio adequado entre o acesso à água e a aeração do solo.
- Máximo Tolerável: Umidades muito altas podem levar à falta de oxigênio nas raízes e promover o desenvolvimento de
  doenças fúngicas. Geralmente, valores acima de 90% da capacidade de campo podem ser considerados muito elevados e podem
  ser prejudiciais às plantas.
*/

class SensorUmidade : public Sensor {
private:
public:
	SensorUmidade() {
		tipo_sensor = TipoSensor::Umidade; // Inicializa o atributo 'tipo_sensor' com o enum correspondente a Umidade
		u_m = "%"; // Inicializa o atributo 'u_m' com a unidade de medida correspondente a Porcentagem (você deve definir o valor de UNIDADE_PORCENTAGEM no Util.h)
		lim_min = MIN_UMIDADE; // Inicializa o atributo 'lim_min' com o valor mínimo de umidade definido em Util.h
		lim_max = MAX_UMIDADE; // Inicializa o atributo 'lim_max' com o valor máximo de umidade definido em Util.h
	}
};

/*
Para sensores de pH do solo, os valores ideais também variam de acordo com a planta cultivada e as preferências de pH
específicas da cultura. No entanto, aqui estão algumas diretrizes gerais:

- Faixa Ideal de pH: Geralmente entre 6,0 e 7,5 para a maioria das plantas.
- Valores Mínimos Toleráveis: Acima de 5,5 para evitar acidez excessiva que pode prejudicar a disponibilidade de nutrientes.
- Valores Máximos Toleráveis: Abaixo de 7,5 para evitar alcalinidade excessiva que também pode afetar a disponibilidade de nutrientes.
*/

class SensorIndicePH : public Sensor {
private:
public:
	SensorIndicePH() {
		tipo_sensor = TipoSensor::IndicePH; // Inicializa o atributo 'tipo_sensor' com o enum correspondente a IndicePH
		u_m = "pH"; // Inicializa o atributo 'u_m' com a unidade de medida correspondente a pH (você deve definir o valor de UNIDADE_PH no Util.h)
		lim_min = MIN_PH; // Inicializa o atributo 'lim_min' com o valor mínimo de pH definido em Util.h
		lim_max = MAX_PH; // Inicializa o atributo 'lim_max' com o valor máximo de pH definido em Util.h
	}
};
