//tinkercad-link -- https://www.tinkercad.com/things/eBV21szmaui-bodacious-kup

//Definimos variables 

const int luzAmarilla = 13; 
const int luzRoja = 12;   
const int luzVerde = 11;  

//Definimos el estado inicial de las luces (apagadas)

bool estadoLuzAmarilla = false;   
bool estadoLuzRoja = false;      
bool estadoLuzVerde = false;  
bool estadoTodasLasLuces = false; // Nuevo estado para todas las luces


//Configuramos las variables de las luces como salida

void setup() {
  pinMode(luzAmarilla, OUTPUT);  
  pinMode(luzRoja, OUTPUT);     
  pinMode(luzVerde, OUTPUT);   

  Serial.begin(9600); // Iniciamos la comunicación serial a 9600 baudios
}

void loop() {
  if (Serial.available()) {      // Verificamos si hay datos disponibles en el puerto serial
    char opcion = Serial.read(); // Leemos un carácter del puerto serial
    int c = 0;                   // Variable para el número de parpadeos en el modo intermitente

    switch (opcion) {  // Evaluamos la opción recibida
      case '1':
        alternarLuz(luzVerde, estadoLuzVerde);  // Alternamos la luz verde
        break;
      case '2':
        alternarLuz(luzVerde, estadoLuzVerde);  // Alternamos la luz verde
        break;
      case '3':
        alternarLuz(luzRoja, estadoLuzRoja);    // Alternamos la luz roja
        break;
      case '4':
        alternarLuz(luzRoja, estadoLuzRoja);    // Alternamos la luz roja
        break;
      case '5':
        alternarLuz(luzAmarilla, estadoLuzAmarilla);  // Alternamos la luz amarilla
        break;
      case '6':
        alternarLuz(luzAmarilla, estadoLuzAmarilla);  // Alternamos la luz amarilla
        break;
      case '7':
        alternarTodasLasLuces();  // Encendemos todas las luces
        break;
      case '8':
        alternarTodasLasLuces();    // Apagamos todas las luces
        break;
      case '9':
        Serial.println("Ingrese el numero de parpadeos:");  // Solicitamos el número de parpadeos
        while (!Serial.available()); // Esperamos a que se ingrese un valor
        c = Serial.parseInt();       // Leemos el número de parpadeos
        modoIntermitente(c);         // Activamos el modo intermitente
        break;
      default:
        Serial.println("Opción no válida. Introduzca un número del 1 al 9.");  // Mensaje de opción inválida
        break;
    }
  }
}

void alternarLuz(int luz, bool &estadoLuz) {
  if (estadoLuz) {          // Si la luz está encendida
    apagarLuz(luz);         // Apagamos la luz
  } else {                  // Si la luz está apagada
    encenderLuz(luz);       // Encendemos la luz
  }
  estadoLuz = !estadoLuz;   // Alternamos el estado de la luz
}

void encenderLuz(int luz) {
  digitalWrite(luz, HIGH);  // Encendemos la luz (alto voltaje)
  Serial.println("Luz encendida.");  // Indicamos que la luz está encendida
}

void apagarLuz(int luz) {
  digitalWrite(luz, LOW);  // Apagamos la luz (bajo voltaje)
  Serial.println("Luz apagada.");  // Indicamos que la luz está apagada
}

void encenderTodasLasLuces() {
  encenderLuz(luzVerde);    // Encendemos la luz verde
  encenderLuz(luzRoja);     // Encendemos la luz roja
  encenderLuz(luzAmarilla); // Encendemos la luz amarilla
  Serial.println("Todas las luces encendidas.");  // Indicamos que todas las luces están encendidas
}

void apagarTodasLasLuces() {
  apagarLuz(luzVerde);    // Apagamos la luz verde
  apagarLuz(luzRoja);     // Apagamos la luz roja
  apagarLuz(luzAmarilla); // Apagamos la luz amarilla
  Serial.println("Todas las luces apagadas.");  // Indicamos que todas las luces están apagadas
}
void alternarTodasLasLuces() {
  if (estadoTodasLasLuces) {
    apagarTodasLasLuces(); // Si están encendidas, apagarlas
  } else {
    encenderTodasLasLuces(); // Si están apagadas, encenderlas
  }
  estadoTodasLasLuces = !estadoTodasLasLuces;  // Alternar el estado de todas las luces
}

void modoIntermitente(int c) {
  for (int i = 0; i < c; i++) {  // Ciclo para realizar el número de parpadeos
    encenderTodasLasLuces();  // Encendemos todas las luces
    delay(1000);  // Esperamos 1 segundo
    apagarTodasLasLuces();  // Apagamos todas las luces
    delay(1000);  // Esperamos 1 segundo
  }
  Serial.println("Modo intermitente completado.");  // Indicamos que el modo intermitente ha terminado
}
