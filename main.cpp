#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funciones.cpp"
#define TAM 150

using namespace std;

int main()
{
  char texto_original[TAM];
  char clave[TAM];
  int dimension_to = 0;
  int dimension_clave = 0;

  vector<char> texto_;
  vector<char> clave_;
  vector<char> abecedario;
  vector<char> texto_cifrado;
  vector<char> texto_descifrado;
  vector<int> espacios_blanco;

  int cont = 0;
  abecedario.resize(26);
  //texto_cifrado.resize(26);


  for(int i=65;i<=90;i++)
  {
    abecedario[cont] = i;
    cont++;
  }

  cout << "Introduzca texto original: ";
  cin.getline(texto_original,TAM);
  int contador = 0;
  while(texto_original[contador] != '\0')
  {
      espacios_blanco.resize(espacios_blanco.size()+1);
      if(texto_original[contador] == ' ')
      {
        espacios_blanco[contador] = true;
      }
      else
      {
        espacios_blanco[contador] = false;
      }
      texto_.resize(texto_.size()+1);
      texto_[contador] = texto_original[contador];
      contador++;

  }

  cout << "Introduzca clave: ";
  cin.getline(clave,TAM);
  int contador1 = 0;
  while(clave[contador1] != '\0')
  {
    clave_.resize(clave_.size()+1);
    clave_[contador1] = clave[contador1];
    contador1++;
  }
  cout << "-------------------" << endl;

  cout << "Informacion introducida: " << endl;
  imprimir(texto_,"Texto original");
  imprimir(clave_,"Clave");

  comprobar(texto_,clave_);
  cout << "-------------------" << endl;
  cout << "Proceso" << endl;
  cout << "1.-Redimensionamos:" << endl;
  texto_ = eliminar_espaciosblanco(texto_);
  clave_ = eliminar_espaciosblanco(clave_);
  dimension_clave = clave_.size();
  redimensionar(clave_,texto_);
  imprimir(texto_,"Texto original");
  imprimir(clave_,"Clave");

  cout << "-------------------" << endl;

  cout << "2.-Ciframos:" << endl;
  texto_cifrado = cifrado(clave_,texto_,abecedario);
  imprimir(texto_cifrado,"Texto cifrado");
  imprimir(clave_,"Clave\t");
  cout << "-------------------" << endl;

  cout << "3.- Descifrar el mensaje:" << endl;
  texto_descifrado = descifrar(clave_,texto_cifrado,abecedario);
  if(comprobar_final(texto_,texto_descifrado) == false)
  {
      cout << "Texto descifrado: " << texto_original << endl;
  }
  else
  {
    cerr << "El mensaje descifrado es distinto que el original. Saliendo del sistema..." << endl;
  }

  //imprimir(texto_descifrado,"Texto descifrado");
  cout << "-------------------" << endl;
  cout << "4.-Modificacion:" << endl;
  modificacion(texto_cifrado,clave_,dimension_clave,abecedario);
  cout << endl;
  return 0;
}
