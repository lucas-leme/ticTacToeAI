// Nome Lucas Leme Santos
// Email lucaslssantos99@gmail.com
// Cel 11 98224-1514

#include "Tabuleiro.h"
#include <cstdlib>
#include <limits>

#define PLAYER1 "X"
#define PLAYER2 "O"
#define PLAYERNULO " "


Tabuleiro::Tabuleiro()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            this->tabuleiro[i][j] = PLAYERNULO;
        }
    }
}

Tabuleiro::~Tabuleiro()
{
    //dtor
}

void Tabuleiro::imprimeTabuleiro()
{
    cout << "  1 2 3" << endl;
    int contadorLinha = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (j == 0)
                cout << contadorLinha << " ";

            cout << tabuleiro[i][j];

            if (j != 2)
                cout << "|";
            else
                cout << endl;
        }
        if (i != 2)
            cout << "  -+-+-" << endl;
        contadorLinha++;
    }

}
// Alteracao no tabuleiro entrara num loop ate o usuaria dar a entrada valida
void Tabuleiro::alteracaoNoTabuleiro(string player)
{
    do {
        Movimentacao movimento;
        cout << "Jogador " << player << " insira a posica (X, Y): ";
        cin >> movimento.x;
        cin >> movimento.y;

        if ( tabuleiro[movimento.y - 1][movimento.x - 1] == PLAYERNULO) {
            tabuleiro[movimento.y - 1][movimento.x - 1] = player;
            break;
        }
        else {
            cout << "Posicao invalida" << endl;
        }
    }while (1);


}

bool Tabuleiro::verificacaoDeVitoria(string player)
{
    for (int i = 0; i < 3; i++) {
            // Verificação das horizontais
        if (tabuleiro[i][0] == player && tabuleiro[i][1] == player && tabuleiro[i][2] == player)
                return 1;

        // Verificação das verticais
        if (tabuleiro[0][i] == player && tabuleiro[1][i] == player && tabuleiro[2][i] == player)
                return 1;
    }

        // Verificação das diagonais
        if (tabuleiro[0][0] == player && tabuleiro[1][1] == player && tabuleiro[2][2] == player)
            return 1;

        if (tabuleiro[0][2] == player && tabuleiro[1][1] == player && tabuleiro[2][0] == player)
            return 1;

        return 0; // Caso as outras condições não sejam verdadeiras, retorna-se 0
}

bool Tabuleiro::verificacaoDeEmpate() {
    bool indicadorDePassagem = 1; // se o indicador entrotrar um caracter " ", nao ocorreu empate
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == PLAYERNULO)
                indicadorDePassagem = 0;
        }
    }
    return indicadorDePassagem; // 1 Se empatou
}

void Tabuleiro::zerarTabuleiro()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            this->tabuleiro[i][j] = PLAYERNULO;
        }
    }
}

Movimentacao Tabuleiro::miniMax (){
    int pontuacao = numeric_limits<int>::max();
    Movimentacao movimentacao;

    for (unsigned int i = 0; i < 3; i++){
        for (unsigned int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == PLAYERNULO) {

                tabuleiro[i][j] = PLAYER2;

                int temp = maxProcura ();

                if (temp < pontuacao) {
                    pontuacao = temp;
                    movimentacao.x = i;
                    movimentacao.y = j;
                }

                tabuleiro[i][j] = PLAYERNULO;
            }
        }
    }
    return movimentacao;
}

int Tabuleiro::maxProcura () {
    if (verificacaoDeVitoria(PLAYER1))
        return 10;
    else if (verificacaoDeVitoria(PLAYER2))
        return -10;
    else if (verificacaoDeEmpate())
        return 0;

    int pontuacao = numeric_limits<int>::min ();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == PLAYERNULO){
                tabuleiro[i][j] = PLAYER1;
                pontuacao = max(pontuacao, minProcura());
                tabuleiro[i][j] = PLAYERNULO;
            }
        }
    }
    return pontuacao;
}

int Tabuleiro::minProcura () {
    if (verificacaoDeVitoria(PLAYER1)){
        return 10;
    }
    else if (verificacaoDeVitoria(PLAYER2))
        return -10;
    else if (verificacaoDeEmpate())
        return 0;

    int pontuacao = numeric_limits<int>::max ();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == PLAYERNULO){
                tabuleiro[i][j] = PLAYER2;
                pontuacao = min(pontuacao, maxProcura());
                tabuleiro[i][j] = PLAYERNULO;
            }
        }
    }
    return pontuacao;
}

void Tabuleiro::movimentoAI(){

    Movimentacao movimento = miniMax();

    cout << "Computador movimentou-se " << movimento.x + 1 << " " << movimento.y + 1 << endl;

    tabuleiro[movimento.x][movimento.y] = PLAYER2;
}

void Tabuleiro::movimentoRandon() {

    Movimentacao movimento;

    do {
        movimento.x = rand()%3;
        movimento.y = rand()%3;

        if (tabuleiro[movimento.x][movimento.y] == PLAYERNULO)
            break;
    } while (1);

    cout << "Computador movimentou-se " << movimento.x + 1 << " " << movimento.y + 1 << endl;

    tabuleiro[movimento.x][movimento.y] = PLAYER2;

}

void Tabuleiro::movimentoComAlgoritimo()
{
    Movimentacao movimento;
    bool indicadorDePassagem = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == PLAYERNULO) {
                tabuleiro[i][j] = PLAYER1;

                if (verificacaoDeVitoria(PLAYER1)) {
                    movimento.x = i;
                    movimento.y = j;
                    indicadorDePassagem = 1;
                }

                tabuleiro[i][j] = PLAYERNULO;
            }
        }
    }

    if (indicadorDePassagem == 0)
        movimentoRandon();
    else{
        tabuleiro[movimento.x][movimento.y] = PLAYER2;
    }
}

