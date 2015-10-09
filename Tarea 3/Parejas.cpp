//
//  Parejas.cpp
//  Tarea 3
//
//  Created by Yoco Hernández on 08/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//
#include <iostream>
#include <vector>

/*
 
 Complejidad: O(n^2) porque se recorre la matriz para actualizar la pareja de cada hombre y mujer n veces.
 Técnica: Backtracking

*/

bool checaMejorHombre(std::vector<std::vector<int>> pref, int hombre, int mujer, int hombre1, int n);

void asignarParejas(std::vector<std::vector<int>> pref, int columnas);

int main() {
  
  //tam de columnas y columnas de las matrices de hombres y mujeres
  int columnas = 4;
  
  //matriz de preferencias de hombres y mujeres
  std::vector<std::vector<int>> pref(2 * columnas, std::vector<int>(columnas));
  
  //se llena la matriz con las preferencias
  pref =
  {
    //hombres
    { 4, 5, 6, 7 }, //hombre 0
    { 5, 6, 7, 4 }, //hombre 1
    { 6, 7, 4, 5 }, //hombre 2
    { 7, 4, 5, 6 }, //hombre 3
    
    //mujeres
    { 0, 1, 2, 3 }, //mujer 4
    { 1, 2, 3, 0 }, //mujer 5
    { 2, 3, 0, 1 }, //mujer 6
    { 3, 0, 1, 2 }, //mujer 7
    
  };
  
  asignarParejas(pref, columnas);
  
}//cierre del main


void asignarParejas(std::vector<std::vector<int>> pref, int columnas) {
  
  std::vector<int> parejaMujeres;
  std::vector<bool> asignadosH;
  
  //se ponen a todas las mujeres y hombres disponibles
  for (int i = 0; i < columnas; i++) {
    
    parejaMujeres.push_back(-1);
    asignadosH.push_back(false);
    
  }//cierre del for
  
  int solteros = columnas;
  
  while (solteros > 0) {
    
    int hombre;
    
    for (int i = 0; i < columnas; i++) {
      
      if (asignadosH[i] == false) {
        hombre = i;
        i = columnas;
      }//cierre del if
      
    }//cierre del for
    
    for (int i = 0; (i < columnas) && (asignadosH[hombre] == false); i++) {
      
      int mujer = pref[hombre][i];
      
      if (parejaMujeres[mujer - columnas] == -1) {
        parejaMujeres[mujer - columnas] = hombre;
        asignadosH[hombre] = true;
        solteros--;
      }
      
      else {
        
        int otroHombre = parejaMujeres[mujer - columnas];
        
        if (checaMejorHombre(pref, hombre, mujer, otroHombre, columnas) == false) {
          parejaMujeres[mujer - columnas] = hombre;
          asignadosH[hombre] = true;
          asignadosH[otroHombre] = false;
        }
        
      }//cierre del else
      
    }//cierre del for
    
  }//cierre del while
  
  for (int i = 0; i < columnas; i++) {
    std::cout << "La mujer no." << i + columnas << " fue asignada al hombre no." << parejaMujeres[i] << std::endl;
  }
  
}//cierre de asignarParejas


bool checaMejorHombre(std::vector<std::vector<int>> pref, int hombre, int mujer, int otroHombre, int columnas) {
  
  for (int i = 0; i < columnas; i++) {
    
    if (pref[mujer][i] == otroHombre) {
      return true;
    }
    if (pref[mujer][i] == hombre) {
      return false;
    }
    
  }//cierre del for
  
  return false;
  
}//cierre de checaMejorHombre






