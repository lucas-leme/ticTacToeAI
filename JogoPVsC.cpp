// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#include "JogoPVsC.h"

#define PLAYER1 "X"
#define PLAYER2 "O"

JogoPVsC::JogoPVsC() : Jogo()
{

}

JogoPVsC::~JogoPVsC()
{
    //dtor
}

bool JogoPVsC::rodadaIA()
{
    bool jogadorDaVez = 1;
    // Variavel booleana, para alternar o jogador da rodada
    //Player 1 sera definido como 1

    while (!tabuleiro->verificacaoDeVitoria(PLAYER1) && !tabuleiro->verificacaoDeVitoria(PLAYER2)){
    // Condição que para o jogo somente em caso de Vitoria de um dos players


        if (jogadorDaVez){
            tabuleiro->imprimeTabuleiro();
            tabuleiro->alteracaoNoTabuleiro(PLAYER1);
        }
        else {
            tabuleiro->movimentoAI();
        }

        jogadorDaVez = !jogadorDaVez;

        if (tabuleiro->verificacaoDeEmpate() && !(tabuleiro->verificacaoDeVitoria(PLAYER1) || tabuleiro->verificacaoDeVitoria(PLAYER2))){
            tabuleiro->imprimeTabuleiro();
            cout << "Ocorreu um empate, a rodada sera reinicializada" << endl;
            tabuleiro->zerarTabuleiro();

            jogadorDaVez = 1;
            // Jogador da vez é reinicializado como 1, pois o Player 1 smepre começa
        }

    }

    jogadorDaVez = !jogadorDaVez;
    // Por logica o jogador da vez tem que ser alterado, para saber o ganhador da rodada

    tabuleiro->imprimeTabuleiro();

    if (jogadorDaVez) {
        cout << "Jogador X ganhou a rodada!!!" << endl;
        return 1;
    }
    else {
        cout << "O computador ganhou a rodada!!!" << endl;
        return 0;
    }
}

bool JogoPVsC::rodada() {

}

bool JogoPVsC::rodadaRandon () {
    bool jogadorDaVez = 1;
    // Variavel booleana, para alternar o jogador da rodada
    //Player 1 sera definido como 1

    while (!tabuleiro->verificacaoDeVitoria(PLAYER1) && !tabuleiro->verificacaoDeVitoria(PLAYER2)){
    // Condição que para o jogo somente em caso de Vitoria de um dos players


        if (jogadorDaVez){
            tabuleiro->imprimeTabuleiro();
            tabuleiro->alteracaoNoTabuleiro(PLAYER1);
        }
        else {
            tabuleiro->movimentoRandon();
        }

        jogadorDaVez = !jogadorDaVez;

        if (tabuleiro->verificacaoDeEmpate() && !(tabuleiro->verificacaoDeVitoria(PLAYER1) || tabuleiro->verificacaoDeVitoria(PLAYER2))){
            tabuleiro->imprimeTabuleiro();
            cout << "Ocorreu um empate, a rodada sera reinicializada" << endl;
            tabuleiro->zerarTabuleiro();

            jogadorDaVez = 1;
            // Jogador da vez é reinicializado como 1, pois o Player 1 smepre começa
        }

    }

    jogadorDaVez = !jogadorDaVez;
    // Por logica o jogador da vez tem que ser alterado, para saber o ganhador da rodada

    tabuleiro->imprimeTabuleiro();

    if (jogadorDaVez) {
        cout << "Jogador X ganhou a partida!!!";
        return 1;
    }
    else {
        cout << "O computador ganhou a partida!!!";
        return 0;
    }
}

bool JogoPVsC::rodadaComAlgoritimo()
{
    bool jogadorDaVez = 1;
    // Variavel booleana, para alternar o jogador da rodada
    //Player 1 sera definido como 1

    while (!tabuleiro->verificacaoDeVitoria(PLAYER1) && !tabuleiro->verificacaoDeVitoria(PLAYER2)){
    // Condição que para o jogo somente em caso de Vitoria de um dos players


        if (jogadorDaVez){
            tabuleiro->imprimeTabuleiro();
            tabuleiro->alteracaoNoTabuleiro(PLAYER1);
        }
        else {
            tabuleiro->movimentoComAlgoritimo();
        }

        jogadorDaVez = !jogadorDaVez;

        if (tabuleiro->verificacaoDeEmpate() && !(tabuleiro->verificacaoDeVitoria(PLAYER1) || tabuleiro->verificacaoDeVitoria(PLAYER2))){
            tabuleiro->imprimeTabuleiro();
            cout << "Ocorreu um empate, a rodada sera reinicializada" << endl;
            tabuleiro->zerarTabuleiro();

            jogadorDaVez = 1;
            // Jogador da vez é reinicializado como 1, pois o Player 1 smepre começa
        }

    }

    jogadorDaVez = !jogadorDaVez;
    // Por logica o jogador da vez tem que ser alterado, para saber o ganhador da rodada

    tabuleiro->imprimeTabuleiro();

    if (jogadorDaVez) {
        cout << "Jogador X ganhou a partida!!!";
        return 1;
    }
    else {
        cout << "O computador ganhou a partida!!!";
        return 0;
    }
}

