#pragma once
#include "Util.h"
#include "Device.h"
#include <string>

using namespace std;

class EstacaoBase : public Device
{
private:
	vector<Dados> dados;
public:
	EstacaoBase()
	{
		/* Inicializar o atributo 'tipo_device' com base no enum TipoDevice */
		tipo_device = TipoDevice::Sensor;
	}

	/* M�todo respons�vel por receber dados do Sensor */
	void recebe_dados_do_sensor(const vector<Dados>& _dados)
	{
		for (int i = 0; i < _dados.size(); i++)
            dados.push_back(_dados[i]);
    }

        /* M�todo respons�vel por imprimir na tela os dados sensoriais */
	void imprime_dados()
	{
    	 if (dados.empty())
    	{
       		 cout << endl << "N�o h� dados para serem exibidos na Esta��o Base" << endl << endl;
   		}
    	else
   		{
        // Itera sobre o vetor de dados e imprime cada registro na tela
		int op;
	
		while(true){printf("Escolha 1 para Temperatura, 2 para Umidade e 3 para pH E qualquer outro valor para SAIR\n");
		scanf("%d",&op);
		
			switch (op) {
    case 1:
		for (const auto& dado : dados)
			{	
				if(dado.tipo_sensor=="Temperatura"){
					cout << "Tipo do Sensor: " << dado.tipo_sensor << ", Dado: " << std::fixed << std::setprecision(2) << dado.info << " " << dado.unidade_medida << ", Data e Hora: " << dado.timestamp << endl;
					if(dado.alarme) printf("ALERTA VALOR COLETADO NO SENSOR ESTA FORA DO IDEAL FAVOR VERIFICAR\n");
			}
			}
        break;
    case 2:
        
		for (const auto& dado : dados)
			{	
				if(dado.tipo_sensor=="Umidade"){
					cout << "Tipo do Sensor: " << dado.tipo_sensor << ", Dado: " << std::fixed << std::setprecision(2) << dado.info << " " << dado.unidade_medida << ", Data e Hora: " << dado.timestamp << endl;
					if(dado.alarme) printf("ALERTA VALOR COLETADO NO SENSOR ESTA FORA DO IDEAL FAVOR VERIFICAR\n");
			}
			}
        break;
    case 3:
        
		for (const auto& dado : dados)
			{	
				if(dado.tipo_sensor=="IndicePH"){
					cout << "Tipo do Sensor: " << dado.tipo_sensor << ", Dado: " << std::fixed << std::setprecision(2) << dado.info << " " << dado.unidade_medida << ", Data e Hora: " << dado.timestamp << endl;
					if(dado.alarme) printf("ALERTA VALOR COLETADO NO SENSOR ESTA FORA DO IDEAL FAVOR VERIFICAR\n");
			}
			}
        break;
    default:
        exit(0); // Ou outra a��o adequada para tratar o caso padr�o
}			
        	
			}
			}
		
    }
	
};