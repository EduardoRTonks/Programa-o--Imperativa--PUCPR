#include "Util.h"
#include "Sensores.h"
#include "EstacaoBase.h"

using namespace std;

int main()
{
	/* Semente gerar gerar números aleatórios */
    srand(time(nullptr));

    /* Instancia a Estação Base */
    EstacaoBase* base = new EstacaoBase();

    /* Vectores para cada tipo de Sensor */
    vector<SensorTemperatura*> sensoresTemperatura;
    vector<SensorUmidade*> sensoresUmidade;
    vector<SensorIndicePH*> sensoresIndicePH;

    /* Instancia MAX_SENSORES unidades de cada tipo de Sensor */
    for (int i = 0; i < MAX_SENSORES; i++)
    {
        sensoresTemperatura.push_back(new SensorTemperatura());
        sensoresUmidade.push_back(new SensorUmidade());
        sensoresIndicePH.push_back(new SensorIndicePH());
    }
    /* Insere informações de fabricante, modelo, num_serie e e gera dados para cada Sensor */
    for (int i = 0; i < MAX_SENSORES; i++)
    {
        sensoresTemperatura[i]->atribui_fabricante("PlugField");
        sensoresTemperatura[i]->atribui_num_serie("NS11420A/N2");
        sensoresTemperatura[i]->atribui_modelo("WS32");
        sensoresTemperatura[i]->le_dado_do_sensor();
        sensoresUmidade[i]->atribui_fabricante("PlugField");
        sensoresUmidade[i]->atribui_modelo("WS32");
        sensoresUmidade[i]->atribui_num_serie("NS11220A/N3");
        sensoresUmidade[i]->le_dado_do_sensor();
        sensoresIndicePH[i]->atribui_fabricante("PlugField");
        sensoresIndicePH[i]->atribui_modelo("WS52");
        sensoresIndicePH[i]->atribui_num_serie("NS12220A/N1");
        sensoresIndicePH[i]->le_dado_do_sensor();
    }
    /* Cada Sensor transmite seus dados para a Estação Base */
    for (int i = 0; i < MAX_SENSORES; i++)
    {
        sensoresTemperatura[i]->transmite_dados(base);
        sensoresUmidade[i]->transmite_dados(base);
        sensoresIndicePH[i]->transmite_dados(base);
    }
/* Estação Base imprime relatório na tela para o usuário */
    base->imprime_dados();
}
