
using namespace std;

void imprimir(vector<char> v, string nombre)
{
  int i = 0;
  cout << nombre << ":\t";
  for(i=0;i<v.size();i++)
  {
    cout << v[i];
  }
  cout << endl;
  cout << "Dimension: " << v.size() << endl;
}

void comprobar(vector<char> to, vector<char> clave)
{
  if(to.size() < clave.size())
  {
      cerr << "La longitud del mensaje es menor que la longitud de la clave..." << endl;
      exit(-1);
  }
}

vector<char> eliminar_espaciosblanco(vector<char> v)
{
    int i=0;

    int contador = 0;
    vector<char> auxiliar;
    while(i<v.size())
    {
      if(v[i] == 32)
      {
          i++;
      }
      else
      {
        auxiliar.resize(auxiliar.size()+1);
        auxiliar[contador] = v[i];
        contador++;
        i++;
      }
    }
    return auxiliar;
}

void redimensionar(vector<char> &clave, vector<char> &texto)
{
  int contador = 0;
  int i = clave.size();
  int auxiliar = i;
  clave.resize(texto.size());
  while(i < clave.size())
  {
    clave[i] = clave[contador];
    i++;
    contador++;
    if(contador == auxiliar)
    {
      contador = 0;
    }
  }
}

int posicion_vector(char letra,vector<char> abc)
{
  int contador = 0;
  int resultado = 0;
  while(contador < abc.size())
  {
    if(abc[contador] == letra)
    {
      //cout << "Contador->" << contador << endl;
      resultado = contador;
      break;
    }
    contador++;
  }
  return resultado;
}

vector<char> cifrado(vector<char> clave,vector<char> texto, vector<char> abc)
{

  vector<char> cifrado_auxiliar;
  cifrado_auxiliar.resize(clave.size());

  for(int i=0;i<clave.size();i++)
  {
    int pos_a = posicion_vector(clave[i],abc);
    int pos_b = posicion_vector(texto[i],abc);
    int pos_c = (pos_a+pos_b)%26;

    /*cout << "La letra " << clave[i] << " de clave en posicion " << pos_a << " en abecedario" << endl;;
    cout << "La letra " << texto[i] << " de texto en posicion " << pos_b << " en abecedario" << endl;
    cout << "La letra resultante " << abc[pos_c] << "en posicion " << pos_c << " en abecedario" << endl;*/

    cifrado_auxiliar[i] = abc[pos_c];
  }
  return cifrado_auxiliar;
}

int actualizo(int pos_c) {
  while(pos_c < 0)
  {
    pos_c = pos_c + 26;
  }
  return pos_c;
}

vector<char> descifrar(vector<char> clave,vector<char> cifrado, vector<char> abc)
{
  vector<char> descifrado_auxiliar;
  descifrado_auxiliar.resize(cifrado.size());

  for(int i=0;i<descifrado_auxiliar.size();i++)
  {


    int pos_a = posicion_vector(clave[i],abc);
    int pos_b = posicion_vector(cifrado[i],abc);
    int pos_c = (pos_b-pos_a)%26;

    /*cout << "La letra " << cifrado[i] << " de cifrado en posicion " << pos_b << " en abecedario" << endl;;
    cout << "La letra " << clave[i] << " de clave en posicion " << pos_a << " en abecedario" << endl;
    cout << "La letra resultante " << abc[pos_c] << "en posicion " << pos_c << " en abecedario" << endl;*/

    if(pos_c < 0)
    {
      pos_c = actualizo(pos_c);
    }
    descifrado_auxiliar[i] = abc[pos_c];
  }
  return descifrado_auxiliar;
}

bool comprobar_final(vector<char> original,vector<char> descifrado)
{
  //Compruebo si el texto_descifrado es igual al original
  bool control = false;
  int i=0;

  while(i<original.size() && i<descifrado.size())
  {
      if(descifrado[i] == original[i])
      {
          control = false;
      }
      else
      {
          control = true;
          break;
      }
      i++;
  }
  return control;
}

void modificacion(vector<char> cif, vector<char> cla, int d_cla, vector<char> abc)
{
  int i=0;
  int j=0;
  int x = 0;
  while(i < d_cla)
  {
    vector<char> pos_aux;
    j = i;
    while(j<cif.size())
    {
        pos_aux.resize(pos_aux.size()+1);
        pos_aux[x] = cif[j];
        j = j+d_cla;
        x++;
    }
    cout << "La letra de la clave->" << cla[i] << " cifra: ";
    for(int z=0;z<pos_aux.size();z++)
    {
      cout << pos_aux[z];
    }
    cout << endl;
    x = 0;
    i++;
  }
}
