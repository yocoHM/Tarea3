//
//  Camionero.cpp
//  Tarea 3
//
//  Created by Yoco Hernández on 07/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#include <iostream>
#include <vector>

/*
 
 Complejidad: O(n) porque recorre las 'n' distancias indicadas en el vector "distancias".
 Técnica: Algoritmo ávido
 
*/

std::vector<int> calcularRecorrido(int kmMaximos, std::vector<int> distancias);

int main(int argc, const char * argv[]) {
  
  //se toma en cuenta que las gasolinerias se encuentran entre cada distancia (cada "coma" seria una gasolineria)
  std::vector<int> distancias = {150, 50, 30, 70, 120, 80};
  
  //"n" kilometros que puede recorrer el camión sin parar
  int kmMaximos = 200;
  
  std::vector<int> paradas = calcularRecorrido(kmMaximos, distancias);
  int tamParadas = int(paradas.size());
  
  if (paradas.empty()) {
    std::cout << "El camión no necesita hacer paradas" << std::endl;
  }
  else if(paradas[0] == -1) {
    std::cout << "El recorrido no puede ser completado debido al número máximo de km. del camión y las distancias a recorrer" << std::endl;
  }
  else {
    std::cout << "El camión debe hacer " << tamParadas << " parada(s) en su recorrido." << std::endl;
    for(int i = 0; i < tamParadas; i++) {
      std::cout << "- Debe cargar gasolina en la gasolinería no." << paradas[i]+1 << std::endl;
    }
    
  }
  
  return 0;
  
}//cierre del main

std::vector<int> calcularRecorrido(int kmMaximos, std::vector<int> distancias) {
  
  std::vector<int> paradas;//vector solución
  int kmRecorridos = 0;
  int pos = -1;
  int tamDistancias = int(distancias.size()-1);
  
  while(pos != tamDistancias) {
    
    //cuando la suma de KmRecorridos con la siguiente distancia a recorrer es más grande que maxKilometros, se necesita "cargar gas"
    if(kmRecorridos + distancias[pos+1] > kmMaximos) {
      //se agrega la parada al vector paradas
      paradas.push_back(pos);
      //se reinician KmRecorridos porque se "cargó gas"
      kmRecorridos = 0;
      
      //checar si el recorrido es posible para el camión
      if (paradas[pos] != 0 && paradas[pos] == paradas[pos+1]) {
        pos = tamDistancias;
        paradas[0] = -1;
      }
      
    }
    //cuando no se necesita "cargar gas" se entra al else
    else {
      //se pasa a la siguiente distancia a recorrer
      pos++;
      //se suma la distancia actual recorrida a kmRecorridos
      kmRecorridos += distancias[pos];
    }
    
  }
  
  return paradas;
  
}//cierre de calcularRecorrido




