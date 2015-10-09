//
//  Subsecuencia.cpp
//  Tarea 3
//
//  Created by Yoco Hernández on 07/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//
#include <iostream>
#include <vector>

/*
 
 Complejidad para crear la matriz: O(nxm) porque se recorren 'n' columnas por 'm' filas de la matriz para inicializarla y asignar
 cada valor de la matriz.
 Complejidad para recorrer la matriz: O(n+m)
 Técnica: Algoritmo dinámico
 
*/

int** crearMatrizSubsecuencia(std::vector<char> &x, std::vector<char> &y, int &m, int &n);
void obtenerSubsecuencia(int** matriz, std::vector<char> &x, std::vector<char> &y);
void borrarMatriz(int** matriz, int &m);
//void imprimirMatriz(int** matriz, int &m, int &n);

int main(int argc, const char * argv[]) {
  
  //vectores de chars que se desean analizar
  std::vector<char> x = {'g','a','c','g','g','a','t','t','a','g'};
  std::vector<char> y = {'g','a','t','c','g','g','a','a','t','a','g'};

  int m = int(x.size()+1);
  int n = int(y.size()+1);
  
  //matriz con las subsecuencias
  int** matriz = crearMatrizSubsecuencia(x, y, m, n);
  
  //imprimirMatriz(matriz, m, n);

  std::cout << "La subsecuencia más larga encontrada es: ";
  obtenerSubsecuencia(matriz, x, y);
  
  std::cout << std::endl;
  
  borrarMatriz(matriz, m);
  
  return 0;
  
}//cierre del main

int** crearMatrizSubsecuencia(std::vector<char> &x, std::vector<char> &y, int &m, int &n) {
  
  int** matriz = 0;
  matriz = new int*[m];
  
  //se inicializa la matriz en ceros
  for (int i = 0; i < m; i++) {
    matriz[i] = new int [m];
    for (int j = 0; j < n; j++) {
      matriz[i][j] = 0;
    }
  }
  
  //se construye la matriz con las subsecuencias
  for(int i = 1; i <= m-1; i++) {
    for(int j = 1; j <= n-1; j++) {
      
      if(x[i-1] == y[j-1]) {
        matriz[i][j] = matriz[i-1][j-1] + 1;
      }
      else{
        matriz[i][j] = std::max(matriz[i-1][j], matriz[i][j-1]);
      }
      
    }
  }
  
  return matriz;
  
}//cierre de crearMatrizSubsecuencia

void obtenerSubsecuencia(int** matriz, std::vector<char> &x, std::vector<char> &y) {
  
  std::vector<char> subsecuencia;
  int m = int(x.size());
  int n = int(y.size());
  
  //se obtiene la subsecuencia más larga
  while(m != 0 && n != 0) {
    
    if(x[m-1] == y[n-1]) {
      subsecuencia.push_back(x[m-1]);
      m-=1;
      n-=1;
    }
    else {
      
      if(matriz[m-1][n] > matriz[m][n-1]) {
        m--;
      }
      else {
        n--;
      }
      
    }
    
  }
  
  //se imprimen los chars que conforman la subsecuencia más larga
  for (int i = int(subsecuencia.size()-1); i > 0; i--) {
    std::cout << subsecuencia[i] << " ";
  }
  
  std::cout << std::endl;
  
}//cierre de obtenerSubsecuencia

void borrarMatriz(int** matriz, int &m) {
  
  //se libera la memoria de la matriz creada
  for (int i = 0; i < m; i++) {
    delete [] matriz[i];
  }
  delete [] matriz;
  
}//cierre de borrarMatriz

//void imprimirMatriz(int** matriz, int &m, int &n) {
//
//  for (int i = 0; i<m; i++) {
//    for (int j = 0; j<n; j++) {
//      std::cout << matriz[i][j] << " ";
//    }
//    std::cout << std::endl;
//  }
//
//}




