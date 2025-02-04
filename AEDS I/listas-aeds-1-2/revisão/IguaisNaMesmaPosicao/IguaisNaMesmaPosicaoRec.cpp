#include <iostream>
#include <locale>

using namespace std;

const int tam = 4;

void apresentacao(){
    cout << "\nValores iguais entre dois vetores na mesma posicao\n\n";
}

void lerVetor(int v[tam]){

    for(int i = 0; i < tam; i++){
        cout << "\nDigite o " << i + 1 << " valor: ";
        cin >> v[i];
    }
}

int identificarIguais(int v[tam], int v2[tam], int tam){

    if(tam <= 0){
        return 0;
    }

    int contador = 0;
    if(v[tam - 1] == v2[tam - 1]){
        contador = 1;
    }

    return contador + identificarIguais(v, v2, tam - 1);
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    apresentacao();

    int *v1 = (int *)malloc(tam * sizeof(int));
    int *v2 = (int *)malloc(tam * sizeof(int));

    cout << "\nVetor 1:" << endl;
    lerVetor(v1);
    cout << "\nVetor 2:" << endl;
    lerVetor(v2);

    int iguais = identificarIguais(v1, v2, tam);

    cout << "\nsao: " << iguais << " valores iguais nos dois vetores na mesma posicao";

    return 0;
}
