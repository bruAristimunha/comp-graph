#include "tictoc.h"
#include "ui_tictoc.h"

tictoc::tictoc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tictoc)
{
    ui->setupUi(this);


    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(close()));
}

tictoc::~tictoc()
{
    delete ui;
}

int tictoc::checkWin(int simbolo){

    // Checando por coluna
    if ( (this->tabuleiro[0][0] == simbolo && this->tabuleiro[1][0] == simbolo  && this->tabuleiro[2][0] == simbolo) ||
         (this->tabuleiro[0][1] == simbolo && this->tabuleiro[1][1] == simbolo  && this->tabuleiro[2][1] == simbolo) ||
         (this->tabuleiro[0][2] == simbolo && this->tabuleiro[1][2] == simbolo  && this->tabuleiro[2][2] == simbolo) ){
        this->alguemGanhou = true;
        return 1;
    }else
    // Checando por linha
    if ( (this->tabuleiro[0][0] == simbolo && this->tabuleiro[0][1] == simbolo  && this->tabuleiro[0][2] == simbolo) ||
         (this->tabuleiro[1][0] == simbolo && this->tabuleiro[1][1] == simbolo  && this->tabuleiro[1][2] == simbolo) ||
         (this->tabuleiro[2][0] == simbolo && this->tabuleiro[2][1] == simbolo  && this->tabuleiro[2][2] == simbolo) ){
        this->alguemGanhou = true;

        return 1;
    }else // Checando por diagonais
    if ( (this->tabuleiro[0][0] == simbolo && this->tabuleiro[1][1] == simbolo  && this->tabuleiro[2][2] == simbolo) ||
         (this->tabuleiro[0][2] == simbolo && this->tabuleiro[1][1] == simbolo  && this->tabuleiro[2][0] == simbolo) ){
        this->alguemGanhou = true;

        return 1;
    } if (this->contador == 9) {
         return -1;
    }
    else{
        return 0;
    }

}


void tictoc::printDebug(){
    for(int i = 0; i < 3 ;i++){
        for(int j = 0; j < 3 ;j++){
            printf("%d ",this->tabuleiro[i][j]);
        }
        printf("\n");
    }
}
int tictoc::clicar(int num_botao){

    int linha = int((num_botao-1)/3);
    int coluna = (int((num_botao-1)%3));
    if(!this->alguemGanhou){
        if(this->botoes[num_botao-1] == 0 ){

            this->botoes[num_botao-1] = 1;

            if(this->contador%2 == 0 ){
                this->tabuleiro[linha][coluna] = 0;
                this->contador = this->contador+1;
                int situacao = checkWin(0);
                if(situacao ==1){
                    ui->mensagem->setText("Vencedor é O");
                }else if(situacao == -1){
                    ui->mensagem->setText("Velha");
                }
                return 0;
            }else{
                this->tabuleiro[linha][coluna] = 1;
                this->contador = this->contador+1;
                int situacao = checkWin(1);
                if(situacao ==1){
                    ui->mensagem->setText("Vencedor é X");
                }else if(situacao == -1){
                    ui->mensagem->setText("Velha");
                }
                return 1;
            }

        }
    }
    else{
        return -1;
    }
    return -1;
}

//Primeira Linha
void tictoc::on_toolButton_1_clicked()
{

    int tentativa = clicar(1);
    switch (tentativa) {
        case 0:
            ui->toolButton_1->setText("O");
        break;
        case 1:
            ui->toolButton_1->setText("X");
        break;
    }
}


void tictoc::on_toolButton_2_clicked()
{
    int tentativa = clicar(2);
    switch (tentativa) {
        case 0:
            ui->toolButton_2->setText("O");
        break;
        case 1:
            ui->toolButton_2->setText("X");
        break;
    }
}

void tictoc::on_toolButton_3_clicked()
{
    int tentativa = clicar(3);
    switch (tentativa) {
        case 0:
            ui->toolButton_3->setText("O");
        break;
        case 1:
            ui->toolButton_3->setText("X");
        break;
    }
}

//Segunda Linha

void tictoc::on_toolButton_4_clicked()
{
    int tentativa = clicar(4);
    switch (tentativa) {
        case 0:
            ui->toolButton_4->setText("O");
        break;
        case 1:
            ui->toolButton_4->setText("X");
        break;
    }
}

void tictoc::on_toolButton_5_clicked()
{
    int tentativa = clicar(5);
    switch (tentativa) {
        case 0:
            ui->toolButton_5->setText("O");
        break;
        case 1:
            ui->toolButton_5->setText("X");
        break;
    }
}

void tictoc::on_toolButton_6_clicked()
{
    int tentativa = clicar(6);
    switch (tentativa) {
        case 0:
            ui->toolButton_6->setText("O");
        break;
        case 1:
            ui->toolButton_6->setText("X");
        break;
    }
}


//Terceira Linha

void tictoc::on_toolButton_7_clicked()
{
    int tentativa = clicar(7);
    switch (tentativa) {
        case 0:
            ui->toolButton_7->setText("O");
        break;
        case 1:
            ui->toolButton_7->setText("X");
        break;
    }
}


void tictoc::on_toolButton_8_clicked()
{
    int tentativa = clicar(8);
    switch (tentativa) {
        case 0:
            ui->toolButton_8->setText("O");
        break;
        case 1:
            ui->toolButton_8->setText("X");
        break;
    }
}

void tictoc::on_toolButton_9_clicked()
{
    int tentativa = clicar(9);
    switch (tentativa) {
        case 0:
            ui->toolButton_9->setText("O");
        break;
        case 1:
            ui->toolButton_9->setText("X");
        break;
    }
}




void tictoc::on_resetar_clicked()
{
    this->contador = 0;
    this->alguemGanhou = false;
    for (int i = 0; i < 9 ; i++){ this->botoes[i] = 0; }

    ui->toolButton_1->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    for (int i = 0; i  <3; i++){
        for (int j = 0; j < 3; j++){
            this->tabuleiro[i][j] = -1;
        }
    }
    ui->mensagem->setText("Vamos lá");
}





