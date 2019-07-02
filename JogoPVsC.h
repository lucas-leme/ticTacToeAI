// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#ifndef JOGOPVSC_H
#define JOGOPVSC_H
#include "Jogo.h"

/*
Classe Jogo Player vs Computer, que contem a funcao rodada, que simula
rodada contra o computador, com inteligencia artificial
*/

class JogoPVsC : public Jogo
{
    public:
        JogoPVsC();
        virtual ~JogoPVsC();

        bool rodadaIA();
        // Simulação de rodada PvC
        // Retorna 1 se o Player 1 ganhou, e 0 se O Computador

        bool rodada();

        bool rodadaRandon ();

        bool rodadaComAlgoritimo ();

    protected:

    private:

};

#endif // JOGOPVSC_H
