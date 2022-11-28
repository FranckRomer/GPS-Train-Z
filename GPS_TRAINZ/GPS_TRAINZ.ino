/*
 ************************************************************************************
 *    TRAIN -  Z
 ************************************************************************************
 */
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <TinyGPS++.h>
#include <Preferences.h>
#include <ArduinoJson.hpp>
#include <ArduinoJson.h>
#include <WebServer.h>
#include <ESPmDNS.h>
//#include <mDash.h>
#include "variables.h"

/***********************************************************************
 *  PARAMETROS  QUE CAMBIAN
 ***********************************************************************
 */
// RED
const char *ssid = "RED ACCESA";
const char *password = "037E32E7"; 
// numero_serial
String MACESP = String(WiFi.macAddress());
String NumSerie = "GPS:" + MACESP + ":A";
//
#define keyMDASH "sin_asignar"
//
const char *server_api = "http://192.168.1.109:3001/disp_train/";
String proyect = "proyectos_sin_asignar";



/*
 * ********************************************************************
                 Setup
 * ********************************************************************
*/
void setup(){
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, RXD1, TXD1); // serial1 pines 4 y 2
  Serial.println("\n \n \n \n \n \n");
  Serial.println();
  Serial.println();
  Serial.println("-----------------------------------");
  // LECTURA DE VARIABLES
  preferences.begin("my-app", false);
  lectura_eeprom();
  preferences.end();

  statusWifi = false;
  setupWiFi();
  statusWifi = true;
  //
  //  Serial.print("Connecting");
  //  WiFi.begin(ssid, password);
  //  while (WiFi.status() != WL_CONNECTED)
  //  {
  //    delay(500);
  //    Serial.print(".");
  //  }
  //  Serial.println("");
  //  Serial.println("WiFi connected");

  // task to run forever
  xTaskCreatePinnedToCore(
      toggleLED,    // Funcion a llamar
      "Toggle LED", // Nombre de la tarea
      8192,         // Bytes de memoria que puede usar la tarea
      NULL,         // Apuntador de memoria (no se usa)
      1,            // Prioridad de la tarea (de 0 a 24, siendo 24 la mayor prioridad)
      NULL,         // Apuntador de tarea
      app_cpu);     // Nucleo o procesador que vamos a usar

  delay(3000);
}

/*
 * ********************************************************************
              Programa principal
 * ********************************************************************
*/

void loop(){
  int unSegundo = 0;
  int reseteo = 0; 
  int frec_tiempo_real = 0;
  int frec_reg = 0;
  int frec_status = 0;
  while(1){
    bool res_gps = gps_serial();
    if (res_gps){
      Serial.println("No hay GPS");
      delay(1000);
      return;
    }
    Serial.println("<<<<<<<<<<<<<< Gps Actualizado >>>>>>>>>>>>>>>>>>>>");
    Serial.println("latitud:" + String(gps_neo.latitud));
    Serial.println("longitud:" + String(gps_neo.longitud));
    Serial.println("Velocidad: " + String(gps_neo.speed));
    Serial.println(stringHora());
    //
      delay(1);
      unSegundo ++;
      reseteo ++;
      if((unSegundo >= 1000)){
//        displayTiempo();
        unSegundo = 0;
        frec_tiempo_real++;
        frec_reg++;
        frec_status++;
        // ENVIO DE GPS 
        //tiempo real
        if(frec_tiempo_real >= frecuencia_tiempo_real){          
          String tiempo_real = json_gps_tiempo_real();
          Serial.println(tiempo_real);
          // Envio POST
          String data = PATCH_GPS(tiempo_real);
          Serial.println(data);
          frec_tiempo_real = 0;
//          post_status++;
        } 
        // registro
        if(frec_reg >= frecuencia_registro_gps){
          String registro =  json_gpsRegistro();
          Serial.println(registro);  
          //Envio
          String data = PATCH_STATUS(registro);
          Serial.println(data);        
          frec_reg = 0;
        }
        // status
        if(frec_status >= frecuencia_tiempo_real){          
          String j_status = json_status();
          Serial.println(j_status);
          //Envio
          String data = PATCH_GPS(j_status);
          Serial.println(data); 
          String json_data = respuestaDesSerializada(data);
          Serial.println(json_data); 
          frec_status = 0;
        }
      } 
    //
    if(reseteo >= 3600000){
      //Se reinicia el ESP_Servidor 
      ESP.restart();
    }
      
  } 
 
}

/*
 ****************************************************************************************
 *            SEGUNDO NUCLEO
 ****************************************************************************************
 */

//
void toggleLED(void *parameter){
  delay(3000);
  Serial.println("Iniciando SEGUNDO NUCLEO");
  //  gps_serial();
//  statusWifi = false;
//  setupWiFi();
//  statusWifi = true;
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;

  //
  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", handleRoot);

  server.on("/can", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  while (1)
  {
    
    unsigned long currentMillis = millis();

    if ((WiFi.status() != WL_CONNECTED))
    {
      statusWifi = false;

      //        Serial.println("..................Reconnecting to WiFi..................");
      WiFi.disconnect();
      while ((WiFi.status() != WL_CONNECTED))
      {
        setupWiFi();
      }
      //        WiFi.reconnect();
      //        delay(1000);
      ////        gps_serial();
    }
    else{
      //
      server.handleClient();
      vTaskDelay(2);
    }
    statusWifi = true;
    //      gps_serial();
    delay(2000);
  }
}
