// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>

using namespace std;

/*
Classe Tabuleiro contem todas as funcoes relacionadas a alterações no
Tabueliro do Jodo da Velha
*/


// Stuct para armazenar o movimento em uma unica variavel
struct Movimentacao {
    int x;
    int y;

};

class Tabuleiro
{
    public:
        Tabuleiro();
        // Construtor de Tabuleiro, que prepara o Tabuleiro para o Jgoo
        // Preencendo-o com " "

        virtual ~Tabuleiro();

        void imprimeTabuleiro();
        // Imprime o atual Tabuleiro

        void alteracaoNoTabuleiro (string player);
        // Altera o tabuleiro, colocando nele a jogada (X ou O)
        // Utlizado por Players

        void movimentoAI ();
        // Função que faz uma jogada do computador, com Inteligência Artificial

        void movimentoRandon();
        // Função que faz uma jogada do computador aleatoriamente

        void movimentoComAlgoritimo ();

        Movimentacao miniMax();
        // Funcao recursiva, que simula todas possiveis jogadas
        // e atribui uma pontução para as jogadas
        // E retorna a melhor movimentação

        int minProcura();// Função auxiliar de miniMax
        int maxProcura();// Função auxiliar de miniMax

        bool verificacaoDeVitoria (string player);
        //Verefica se houve vitoria de determinado Player, dado na entrada

        bool verificacaoDeEmpate ();
        //Verifica o empate

        void zerarTabuleiro ();
        // Zera o tabuleiro, caso necessario (quando há empate)

    protected:

    private:

        string tabuleiro[3][3];

};

#endif // TABULEIRO_H
