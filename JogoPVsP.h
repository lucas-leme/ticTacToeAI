// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#ifndef JOGOPVSP_H
#define JOGOPVSP_H
#include "Jogo.h"

/*
Classe Jogo Player vs Player, que contem a funcao rodada, que simula
uma rodada PvP, sendo o Player 1 "X" e o Player 2 "O"
*/

class JogoPVsP : public Jogo
{
    public:
        JogoPVsP();
        virtual ~JogoPVsP();

        virtual bool rodada();
        // Simulação de rodada PvP
        // Retorna 1 se o Player 1 ganhou, e 0 se O Player 2

    protected:

    private:

};

#endif // JOGOPVSP_H
