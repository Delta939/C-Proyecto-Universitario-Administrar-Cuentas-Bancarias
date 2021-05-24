#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h> 
struct banco {
    char nombre[50];
    int id; 
    char pass[4];  //
    char telefono[90];
    char domicilio[60];
    int edad;
    float saldo;
    float saldod;
    float saldor;
    char curp[50];
    char rfc[50];
    char email[50];
    
      
  struct banco *sig;
};typedef struct banco cuenta;

void menu();
void  guardarListaTexto(cuenta *inicio);
void password(cuenta *inicio);
void passwordparamodificar(cuenta *inicio);
cuenta* menu2(cuenta *inicio);
void id(cuenta *inicio);//cuenta* id(cuenta *inicio);
cuenta* Deposito(cuenta *inicio);
cuenta* Retiro(cuenta *inicio);
void modificar(cuenta *inicio);         
cuenta* Alta(cuenta *inicio);
cuenta* leerListaTexto(cuenta *inicio);
cuenta* buscarNodoAnterior(int dato, cuenta *inicio);
cuenta *borrarNodo(cuenta *inicio);
void buscarpornombre(cuenta *inicio);
void listarContactos(cuenta *inicio );
void menuparamodificar();
void menudetransacciones();
void ConsultarSaldo(cuenta *inicio);
void Reporte(cuenta *inicio);
void ConsultarSaldo(cuenta *inicio);
void menudeposito();

