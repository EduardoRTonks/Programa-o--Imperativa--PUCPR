#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include<ctime>

/* Máximo de dados que um Sensor pode gerar por leitura */
#define MAX_DADOS 50

/* Maximo de Sensores que serão instanciados (para cada tipo) */
#define MAX_SENSORES 10

/* Valores máximos e mínimos que podem ser gerados pelo Sensor */
#define MIN_PH 6
#define MAX_PH 7.5
#define MIN_UMIDADE 50
#define MAX_UMIDADE 75
#define MIN_TEMP 10
#define MAX_TEMP 25

using namespace std;

/* Tipos e Estruturas de Dados Globais */
using tipoSensor = int;
using tipoDevice = int;
using dadosSensor = float;
using SensorID = int;
using unidade_medida = string;

enum TipoDevice
{
    TD_Generico,
    Estacao_Base,
    Sensor,
};

enum TipoSensor
{
    TS_Generico,
    Temperatura,
    Umidade,
    IndicePH,
};

/* Estrutura dos Dados Sensoriais */
struct Dados
{
    SensorID id;
    dadosSensor info;
    string timestamp;
    string tipo_sensor;
    string unidade_medida;
    string fab;
    string mod;
    string num_serie;
    bool alarme;
};

/* Funcao que pausa a tela */
void pausa_tela()
{
    cout << endl << endl << "Pressione uma tecla qualquer para continuar ... " << endl << endl;
    system("pause > nul");
}

/* Função que limpa a tela */
void limpa_tela()
{
    system("cls");
}

/* Função gera um número aleatório entre 0 e 'max' */
int random(int max)
{
    return (rand() % (max + 1));
}

/* Função que gera um valor aleatório tipo float entre min e max */
float random(float min, float max)
{
    float random_num = (float)rand() / RAND_MAX;

    /* Adiciona uma margem de 3% para o resultado */
    float resultado = min + random_num * (max - min) * 1.03;

    /* Limita o número de casas decimais para 2 */
    ostringstream stream;
    stream << fixed << setprecision(2) << resultado;

    istringstream iss(stream.str());
    iss >> resultado;

    return (resultado);
}

/* Retorna data e hora em formato string */
string data_hora()
{
     time_t agora = time(nullptr); // Obt?m o tempo atual em segundos desde 01/01/1970
    tm *tempoLocal = localtime(&agora); // Converte o tempo atual para o tempo local

    // Extrai os componentes da data e hora
    int dia = tempoLocal->tm_mday;
    int mes = tempoLocal->tm_mon + 1;
    int ano = tempoLocal->tm_year + 1900;
    int hora = tempoLocal->tm_hour;
    int minuto = tempoLocal->tm_min;
    int segundo = tempoLocal->tm_sec;

    /* Ajuste da formata??o para sempre apresentar dois d?gitos ex: 2 --> 02 */
    stringstream ss;
    ss << setfill('0') << setw(2) << dia << "/"
        << setw(2) << mes << "/"
        << setw(2) << ano << " "
        << setw(2) << hora << ":"
        << setw(2) << minuto << ":"
        << setw(2) << segundo;

    return ss.str(); // Retorna a string formatada contendo a data e hora
}