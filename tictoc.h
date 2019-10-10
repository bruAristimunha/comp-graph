#ifndef TICTOC_H
#define TICTOC_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>

namespace Ui {
class tictoc;
}

class tictoc : public QMainWindow
{
    Q_OBJECT

public:
    explicit tictoc(QWidget *parent = nullptr);
    ~tictoc();

    //Definimos aqui que os números pares são O, e os números ímpares são X
    int contador = 0;

    //variável para controlar que não haja dois cliques no mesmo botão
    int botoes[9] = {0,0,0,0,0,0,0,0,0};

    //Inicializando o tabuleiro com valores negativos
    int tabuleiro [3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

    //Segurar jogo
    bool alguemGanhou = false;


    int checkWin(int);
    int clicar(int);
    void printDebug();

private slots:
    void on_toolButton_1_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_resetar_clicked();

private:
    Ui::tictoc *ui;
    //Contador para determinar velha, de quem é a rodada

};



#endif // TICTOC_H
