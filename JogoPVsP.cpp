// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#include "JogoPVsP.h"
#include "Tabuleiro.h"
#include "Jogo.h"

#define PLAYER1 "X"
#define PLAYER2 "O"

JogoPVsP::JogoPVsP() : Jogo()
{

}

JogoPVsP::~JogoPVsP()
{
    //dtor
}

bool JogoPVsP::rodada()
{
    bool jogadorDaVez = 1;
    // Variavel booleana, para alternar o jogador da rodada
    //Player 1 sera definido como 1

    //Caso ocorra um empate, o jogo continuara no mesmo loop
    while (!tabuleiro->verificacaoDeVitoria(PLAYER1) && !tabuleiro->verificacaoDeVitoria(PLAYER2)) {

        tabuleiro->imprimeTabuleiro();

        if (jogadorDaVez)
            tabuleiro->alteracaoNoTabuleiro(PLAYER1);
        else
            tabuleiro->alteracaoNoTabuleiro(PLAYER2);

        jogadorDaVez = !jogadorDaVez;

        if (tabuleiro->verificacaoDeEmpate()){
            tabuleiro->imprimeTabuleiro();
            cout << "Ocorreu um empate, a rodada sera reinicializada" << endl;
            tabuleiro->zerarTabuleiro();
            jogadorDaVez = 1;
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
        cout << "Jogador O ganhou a rodada!!!" << endl;
        return 0;
    }
}
