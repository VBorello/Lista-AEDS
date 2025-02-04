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

    if(tam < 0){
        return 0;
    }
    
    int quantidade = (string[tam] == key) ? 1 : 0;

    return quantidade + qtdDeOcorrencias(string, key, tam -1); 
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