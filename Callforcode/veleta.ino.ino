#include<math.h>
boolean c1,c2,c3,c4;
//double YValue,XValue;//si no disponemos de los sensores, descomentar esta linea y sustituir las lineas 13 y 14 por lo comentado
void setup(){
  Serial.begin(9600);
}  
 
void loop(){ 
  c1=false;
  c2=false;
  c3=false;
  c4=false;
  double YValue =analogRead(0);//YValue = random(219, 866);
  double XValue =analogRead(1);//XValue = random(231, 837);
  double y = map(YValue, 219, 866, -100, 100);
  double x = map(XValue, 231, 837, -100, 100);
  if (y >= 0 && x >= 0){c1=true;} // y+ x+
  if (y < 0 && x >= 0 ){c2=true;} // y- x+
  if (y < 0 && x < 0){c3=true;} // y- x-
  if (y >= 0 && x < 0){c4=true;} // y+ x-
   Serial.print("YValue: ");Serial.print(YValue);Serial.print("  Y: ");Serial.println(y);//descomentar estas dos lineas para ver los valores 
   Serial.print("XValue: ");Serial.print(XValue);Serial.print("  X: ");Serial.println(x);//arrojados por el sensor Hall 49E y comentar la siguiente
// descomentar la siguiente linea para ver los valores ya mapeados y comentar las dos anteriores
// Serial.print("X: ");Serial.print(x);Serial.print("  Y: ");Serial.println(y); 
   double formula = 180*(double)(atan((double)(x/y))/PI);
   if (c1){Serial.println(formula);} // imprime grados igual al componente del viento
   if (c2 || c3){Serial.println(180+formula);}// imprime grados igual al componente del viento
   if (c4){Serial.println(360+formula);}// imprime grados igual al componente del viento
   Serial.println();
  delay(200);
}
