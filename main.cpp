// Este case foi implementado integralmente
// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#include <iostream>
#include "Jogo.h"
#include "JogoPVsC.h"
#include "JogoPVsP.h"
#include "Tabuleiro.h"

using namespace std;

void impressaoDasInstrucoes ();

int impressaoDosModos ();

void modoPvsP (int numeroDeRodadas);

void modoPvsCRandon (int numeroDeRodadas);

void modoPvsCAlgoritimo (int numeroDeRoddas);

void modoPvsCIA (int numeroDeRodadas);

int main()
{
    impressaoDasInstrucoes();

    int escolhaDoModo;
    escolhaDoModo = impressaoDosModos();

    int numeroDeRodadas;
    cout << "Escolha o numero de rodadas: ";
    do{
        cin >> numeroDeRodadas;
        if (numeroDeRodadas > 0)
            break;
        else
            cout << "Escolha invalida, insira novamente: " ;
    }while (1);

    if (escolhaDoModo == 1)
        modoPvsP(numeroDeRodadas);
    if (escolhaDoModo == 2)
        modoPvsCRandon(numeroDeRodadas);
    if (escolhaDoModo == 3)
        modoPvsCAlgoritimo(numeroDeRodadas);
    if (escolhaDoModo == 4)
        modoPvsCIA(numeroDeRodadas);

    return 0;
}

void impressaoDasInstrucoes () {
    cout << "Bem vindo ao Jogo da Velha" << endl;
    cout << "A Jogabilidade deste jogo e' baseada em coordenadas X e Y" << endl;
    cout << "Onde X e' a Coordenada Horinzontal -->" << endl;
    cout << "E a coordenada Y e' vertical ^^^" << endl;
    cout << "Voce podera escolher dentre 4 modos de jogo, sendo 1 PvsP e 3 PvsP (Com dificuldades variadas)" << endl;
    cout << "E em cada modo de jogo, voce podera escolher o numero de rodadas que ira jogar" << endl;
    cout << "Sendo que quando houver empate, a mesma rodada sera reinicializada" << endl;
    cout << "Vamos a escolha de Modo: " << endl << endl;
}


int impressaoDosModos() {

    int escolhaDoModo = 0;
    cout << "Escolha o modo de Jogo" << endl;
    cout << "1 Modo PvsP (Multiplayer)" << endl;
    cout << "2 Modo PvsC Easy (Aleatorio)" << endl;
    cout << "3 Modo PvsC Medium (Algorotimizado)" << endl;
    cout << "4 Modo PvsC Hard (Com Inteligencia Artificial)" << endl;

    cout << "Escolha: ";

    do{
        cin >> escolhaDoModo;
        if (escolhaDoModo > 0 && escolhaDoModo < 5)
            break;
        else
            cout << "Escolha invalida, insira novamente: " ;
    }while (1);

    return escolhaDoModo;
}

void modoPvsP (int numeroDeRodadas) {
    cout << "Partida PvsP" << endl;

    int placarP1 = 0;
    int placarP2 = 0;
    int placarParcial;
    for (int i = 0; i < numeroDeRodadas; i++) {
        JogoPVsP *jogoPvsP = new JogoPVsP();
        placarParcial = jogoPvsP->rodada();

        if (placarParcial)
            placarP1++;
        else
            placarP2++;

        delete jogoPvsP;
    }
    if (placarP1 > placarP2){
        cout << "Player X Ganhou!!!" << endl;
        cout << "Placar: " << placarP1 << " a " << placarP2 << endl;
    }
    else {
        cout << "Player O Ganhou!!!" << endl;
        cout << "Placar: " << placarP2 << " a " << placarP1 << endl;
    }
}

void modoPvsCRandon(int numeroDeRodadas) {
    cout << "Partida PvsC" << endl;

    int placarP1 = 0;
    int placarP2 = 0;
    int placarParcial;
    for (int i = 0; i < numeroDeRodadas; i++) {
        JogoPVsC *jogoPvsC = new JogoPVsC();
        placarParcial = jogoPvsC->rodadaRandon();

        if (placarParcial)
            placarP1++;
        else
            placarP2++;

        delete jogoPvsC;
    }
    if (placarP1 > placarP2){
        cout << "Player X Ganhou!!!" << endl;
        cout << "Placar: " << placarP1 << " a " << placarP2 << endl;
    }
    else {
        cout << "Player O Ganhou!!!" << endl;
        cout << "Placar: " << placarP2 << " a " << placarP1 << endl;
    }
}

void modoPvsCAlgoritimo(int numeroDeRodadas) {
    cout << "Partida PvsC" << endl;

    int placarP1 = 0;
    int placarP2 = 0;
    int placarParcial;
    for (int i = 0; i < numeroDeRodadas; i++) {
        JogoPVsC *jogoPvsC = new JogoPVsC();
        placarParcial = jogoPvsC->rodadaComAlgoritimo();

        if (placarParcial)
            placarP1++;
        else
            placarP2++;

        delete jogoPvsC;
    }
    if (placarP1 > placarP2){
        cout << "Player X Ganhou!!!" << endl;
        cout << "Placar: " << placarP1 << " a " << placarP2 << endl;
    }
    else {
        cout << "Player O Ganhou!!!" << endl;
        cout << "Placar: " << placarP2 << " a " << placarP1 << endl;
    }
}

void modoPvsCIA(int numeroDeRodadas) {
    cout << "Partida PvsC" << endl;

    int placarP1 = 0;
    int placarP2 = 0;
    int placarParcial;
    for (int i = 0; i < numeroDeRodadas; i++) {
        JogoPVsC *jogoPvsC = new JogoPVsC();
        placarParcial = jogoPvsC->rodadaIA();

        if (placarParcial)
            placarP1++;
        else
            placarP2++;

        delete jogoPvsC;
    }
    if (placarP1 > placarP2){
        cout << "Player X Ganhou!!!" << endl;
        cout << "Placar: " << placarP1 << " a " << placarP2 << endl;
    }
    else {
        cout << "Player O Ganhou!!!" << endl;
        cout << "Placar: " << placarP2 << " a " << placarP1 << endl;
    }
}
