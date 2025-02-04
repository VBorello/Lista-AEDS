#include <iostream> 
using namespace std;

const int lin = 2;
const int col = 2; 

void apresentacao(){
    cout << "\nProduto de matrizes reais" << endl;
}

void lerMatriz(float m1[lin][col], float m2[lin][col]){

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cout << "\nDigite o valor[" << i + 1 << "][" << j + 1 << "] da primeira matriz: ";
            cin >> m1[i][j];
        } 
    }

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cout << "\nDigite o valor[" << i + 1 << "][" << j + 1 << "] da segunda matriz: ";
            cin >> m2[i][j];
        } 
    }
}

void multiplicaMatrizes(float m1[lin][col], float m2[lin][col], float produto[lin][col]){

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            produto[i][j] = m1[i][j] * m2[i][j]; 
        }   
    }
}

void printMatriz(float m[lin][col]){

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cout << m[i][j] << " "; 
        }   
        cout << endl;
    }
}

int main(){
    apresentacao();

    float m1[lin][col];
    float m2[lin][col];

    lerMatriz(m1, m2);

    float produto[lin][col];
    multiplicaMatrizes(m1, m2, produto);
    
    cout << "\nprimeira matriz:\n";
    printMatriz(m1);
    cout << endl;
    cout << "segunda matriz:\n";
    printMatriz(m2);
    cout << endl;
    cout << "produto das duas:\n";
    printMatriz(produto);
    cout << endl;
    
    return 0;
}