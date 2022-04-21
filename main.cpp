#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>


#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define FQ5 5
#define FQ6 6

using namespace std;

int tabla[7][6] = {{1,3,4,0,5,0},{0,0,0,2,5,0},{0,0,0,0,6,0},{0,0,0,2,5,0},{0,0,0,2,5,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

int funTran (int q, char a){

  int p = 0;

  if (a == 'a'){
    p=0;
  }
  else if(a == 'e'){
    p = 1;
  }
  else if(a == 'i'){
    p = 2;
  }
  else if(a == 'r'){
    p = 3;
  }
  else if(a == ' '){
    p = 4;
  }
  else{
    p = 5;
  }
    return tabla[q][p];
}

int main()
{

    ios::sync_with_stdio(0); cin.tie(0);
    string namearchivo = "file.txt";
    ifstream archivo(namearchivo.c_str());
    int contverbs = 0;
    int contpalbs = 0;
    int estadoActual = Q0;
    string linea;
    while(getline(archivo,linea)){
            cin>>linea;
    }
    cout <<"Estado actual: "<<estadoActual<<endl;

    for(int i=0;i<linea.size();i++){
        estadoActual=funTran(estadoActual, linea[i]);

        cout <<"Estado actual: "<<estadoActual<<endl;
        if(estadoActual == FQ5){
            contpalbs+=1;
        }
        else if(estadoActual == FQ6){
            contverbs+=1;
            contpalbs+=1;
        }
    }

    contpalbs+=1;

    cout<< "Tu oracion tiene: "<<contpalbs<< " palabras y tiene: "<<contverbs<< " verbos."<<endl;
    return 0;
}