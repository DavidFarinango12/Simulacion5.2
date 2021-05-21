/*
 *CAPITULO V: FUNCIONES ESPECIALES 
 *CODIGO 20: FUNCIONES PUT Y GET DE EEPROM
 *ONJETIVO: APLICACION DE GET Y PUT EN UN CONTADOR CADA 2 SEG
 *NOMBRE: RAFAEL FARINANGO
 *FUNCIONES:    EEMPROM.put(dir,valor);
 *              EEPROM.get(dir,valor); dir = 0-1023
 */

#include <EEPROM.h>

int var = 0;

void setup() {
  Serial.begin(9600);
  EEPROM.get(0,var);    //lee el dato en la EEPROM en la variable var
  Serial.println(String("Valor: ")+String(var));
}


void loop() {
  var++;
  if(var < 255)         //condicion de contador
    EEPROM.put(0,var);  //actualiza el valor
  else
    var = 0;
  Serial.println(String("Valor: ")+String(var));
  delay(100);
  
}
