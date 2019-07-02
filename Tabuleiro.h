// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <string>

using namespace std;

/*
Classe Tabuleiro contem todas as funcoes relacionadas a altera��es no
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
        // Fun��o que faz uma jogada do computador, com Intelig�ncia Artificial

        void movimentoRandon();
        // Fun��o que faz uma jogada do computador aleatoriamente

        void movimentoComAlgoritimo ();

        Movimentacao miniMax();
        // Funcao recursiva, que simula todas possiveis jogadas
        // e atribui uma pontu��o para as jogadas
        // E retorna a melhor movimenta��o

        int minProcura();// Fun��o auxiliar de miniMax
        int maxProcura();// Fun��o auxiliar de miniMax

        bool verificacaoDeVitoria (string player);
        //Verefica se houve vitoria de determinado Player, dado na entrada

        bool verificacaoDeEmpate ();
        //Verifica o empate

        void zerarTabuleiro ();
        // Zera o tabuleiro, caso necessario (quando h� empate)

    protected:

    private:

        string tabuleiro[3][3];

};

#endif // TABULEIRO_H
