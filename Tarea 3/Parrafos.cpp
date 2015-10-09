//
//  Parrafos.cpp
//  Tarea 3
//
//  Created by Yoco Hernández on 08/10/15.
//  Copyright © 2015 Yoco. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

/*
 
 Complejidad: O(n) porque solamente se utiliza un for para revisar el espacio que se está ocupando. No se toma en cuenta
 el for de la impresión del texto ya que es para fines de comprobación visual de la solución obtenida.
 Técnica: Algoritmo ávido
 
 */

float costoRed(float red, float amplitudIdeal, int j, int i);
float costoAmp(float amp, float amplitudIdeal, int j, int i);

int main(int argc, const char * argv[]) {
  
  //texto que se desea justificar
  std::vector<std::string> texto = {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur","adipiscing", "elit"};
  std::vector<int> tamPalabras;
  std::vector<std::string> linea;
  
  //longitud 'L' de las líneas
  float tamLinea = 25;
  float tamPalComp = 0;
  float tamPalEsp = 0;
  
  //amplitud ideal de los espacios en las líneas
  float amplitudIdeal = 1;
  float sobrante;
  
  int i = 0;
  int j;
  
  float red;
  float amp;
  
  bool mostrado = true;
  
  for (int i = 0; i < texto.size(); i++) {
    tamPalabras.push_back( int(texto[i].length()) );
  }
  
  for (j = 0; j < texto.size(); j++) {
    
    if (mostrado) {
      i = j;
      mostrado = false;
      linea.clear();
      tamPalComp = 0;
    }
    
    tamPalComp += tamPalabras[j];
    tamPalEsp = tamPalComp + ((j - i) * amplitudIdeal);
    
    if (tamPalEsp > tamLinea) {
      sobrante = tamPalEsp - tamLinea;
      red = amplitudIdeal - (sobrante / (j - i));
      amp = amplitudIdeal + (tamLinea - ( (tamPalComp - tamPalabras[j]) + (amplitudIdeal * (j - i - 1) ) ) ) / (j - i - 1);
      
      if ( costoAmp(amp,amplitudIdeal,j,i) > costoRed(red, amplitudIdeal,j,i) && red > 0 ) {
        linea.push_back(texto[j]);
        
        for (int i = 0; i < linea.size(); i++) {
          std::cout << linea[i] << " ";
        }
        
        std::cout << " " <<  "-> reducción en la línea de: " << red << " mm.";
        std::cout << std::endl;
        mostrado = true;
      }//cierre del segundo if
      else {
        for (int i = 0; i < linea.size(); i++) {
          std::cout << linea[i] << " ";
        }
        
        std::cout << " " << "-> ampliación en la línea de: " << amp << " mm.";
        std::cout << std::endl;
        j--;
        mostrado = true;
      }//cierre del else
      
    }//cierre del primer if
    
    linea.push_back(texto[j]);
    
  }//cierre del for
  
  
  for (int i = 0; i < linea.size(); i++) {
    std::cout << linea[i] << " ";
  }
  
  std::cout << std::endl;
  
}//cierre del main



float costoRed(float red, float amplitudIdeal, int j, int i) {
  //valor absoluto
  return ( fabs(red - amplitudIdeal) * (j - i) );
}

float costoAmp(float amp, float amplitudIdeal, int j, int i) {
  //valor absoluto
  return ( fabs(amp - amplitudIdeal) * (j - i - 1) );
}








