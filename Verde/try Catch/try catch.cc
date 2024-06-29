#include <iostream>
#include <exception>

using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    double a;
    system("pause");

    try{
        a = 10;
        cout << "\nEntrei no Bloco Try" << endl;
        if(a == 10) throw a;
        cout << "\n não serei executado" << endl;
    }

    catch(int x){
        cout << "\n Entrei no bloco Catch de inteiro com a = " << a << endl;
    }

    catch(double x){
        cout <<"entrei no bloco Catch real" << endl;
    }

    catch(...){
        cout <<"\nEntrei no padrão" << endl;
    }

    cout << "\nSai da instrucao Try" << endl;

    return 0;
}
