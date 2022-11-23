#include <iostream>
#include <iomanip> // setprecision
#include <cmath> //biblioteca

#define PRECISION 6 //constante de precision

using namespace std;

double f(double x); 
void imprimePuntos(double a, double b); //mostrara en pantalla

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double a, b, tolerancia; //variables que almecaran los datos
   
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\na = ";
   cin >> a; //guardamos el valor
   
   cout << "b = ";
   cin >> b; //guardamos el valor
   
   imprimePuntos(a, b); 
   
   cout << "\nEscoja el intervalo adecuado" << endl; //valores de a y b
   cout << "\na = ";
   cin >> a; //guardamos datos 
   
   cout << "b = ";
   cin >> b; //guardamos datos
   
   // [a, b]
   float xr; // punto medio
   
   /*
   cout << "\nf(" << a << ") = " << f(a) << endl;
   cout << "f(" << b << ") = " << f(b) << endl;
   */
   
   if (f(a) * f(b) > 0) {  //verificacion de valores 
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
      
   } else {
      cout << "Tolerancia = "; 
      cin >> tolerancia;//guardamos la tolerancia
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {
         xr = (a + b) / 2.0; //punto medio
         cout << a << "\t" << b << "\t" << xr << "\t"; 
         cout << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;

         // Vemos si cumple o no cumple
         if (abs(f(xr)) <= tolerancia) { // xr sería la raiz de f 
         
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << xr << endl;
         
            break;
            
         } else { //proceso de puntos del metodo
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }
         
      } while (1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x) //la funcion se guardara en f
{
   return exp(-1 * x) - cos(3 * x) - 0.5;
}

#define INTERVALOS 10 //para que se muestra 10 valores entre puntos
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1; //numero de intervalos
   
   double ancho = (b - a) / INTERVALOS; 
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {  //bucle 
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
