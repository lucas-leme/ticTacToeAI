// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#define PLAYER1 "X"
#define PLAYER2 "O"

#include "Jogo.h"
#include "Tabuleiro.h"

Jogo::Jogo()
{
    tabuleiro = new Tabuleiro();
}

Jogo::~Jogo()
{
    //dtor
}
