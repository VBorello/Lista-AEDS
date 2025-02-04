#include <iostream>

using namespace std;;

void apresentacao(){
    cout << "\nMinMax Class" << endl;
}

#define MAX_COL 3
#define MAX_LIN 3

void leia(double M[MAX_LIN][MAX_COL]){
    for(int i = 0; i < MAX_LIN; i++){
        for(int j = 0; j < MAX_COL; j++){
            cout << "\nDigite o termo " << "[" << i << "][" << j << "]: ";
            cin >> M[i][j];  
        }   
    }
}

class myMatrizes{
    
    public:
        static double minmax(double M[MAX_LIN][MAX_COL]){
                double menor = M[0][0];
                int lin = 0;

                for(int i = 0; i < MAX_LIN; i++){
                    for(int j = 0; j < MAX_COL; j++){
                        if(M[i][j] < menor){
                            menor = M[i][j];
                            lin = i;
                        }
                    }   
                }

            double MinMax = M[lin][0];
            for(int j = 1; j < MAX_COL; j++){
                if (M[lin][j] > MinMax) {
                        MinMax = M[lin][j];
                }       
            }   

            return MinMax;
        }
};


int main(){
    apresentacao();
    double M[MAX_LIN][MAX_COL];
    
    leia(M);
    cout << "\nMinMax é igual a" << myMatrizes::minmax(M);

    return 0;

}