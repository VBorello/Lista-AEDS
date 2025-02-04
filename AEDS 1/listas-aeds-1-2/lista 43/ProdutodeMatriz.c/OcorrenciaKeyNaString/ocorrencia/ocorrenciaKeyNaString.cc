#include <iostream>

using namespace std;


void apresentacao(){

    cout << "\nocorrencia da Chave na String\n\n" << endl;
}


void lerString(char *string){
    
    cout << "digite uma string: ";
    cin.ignore();
    cin.getline(string, 100);

}

void lerKey(char &key){

    cout << "\nDigite uma key: ";
    cin >> key;

    
}

int pegarTam(char* string){

    int tam = 0;
    while(string[tam] != '\0'){
        tam++;
    }

    return tam;
}

int qtdDeOcorrencias(char *string, char key, int tam){

    int quantidade = 0;
    for(int i = 0; i < tam; i++){
        if(string[i] == key){
            quantidade++;
        }   
    }

    return quantidade;
}

int main(){
    apresentacao();
    
    char string[100];
    char key;
    
    lerString(string);
    lerKey(key);

    int tamanho = pegarTam(string);

    int quantidade = qtdDeOcorrencias(string, key, tamanho);

    cout << "\nA quantidade de ocorrencias da key: '" << key << "' foram: " << quantidade << " vezes" << endl;


    return 0;
}