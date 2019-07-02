// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#ifndef JOGO_H
#define JOGO_H
#include "Tabuleiro.h"
/*
Classe Jogo � uma classe abstrata, que tem como heran�a duas classes
para os modos Player vs Player e Player vs Computer
*/

class Jogo
{
    public:
        Jogo();
        // Construtor de Jogo, que cria uma instancia de tabuleirp

        virtual ~Jogo();

        virtual bool rodada() = 0;
        // Funcao abstrada da simula��o de rodadas PvP ou PvC


    protected:
        Tabuleiro *tabuleiro;

    private:
};

#endif // JOGO_H
