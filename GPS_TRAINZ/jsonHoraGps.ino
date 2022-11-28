/*
 * ************************************************************************************************
 *                                          Serializacion - JSON
 * ************************************************************************************************
*/
//Serializacion
String jsonHoraGps() {
    char buffer[1024];
    StaticJsonDocument<1024> doc;
    doc["ano"]        = String(gps_neo.anio);
    doc["mes"]        = String(gps_neo.mes);
    doc["dia"]        = String(gps_neo.dia);
    doc["hora"]       = String(gps_neo.hora);
    doc["minuto"]     = String(gps_neo.minuto);
    doc["segundo"]    = String(gps_neo.segundo);
    doc["latitud"]    = String(gps_neo.latitud);
    doc["longitud"]   = String(gps_neo.longitud);
    
    size_t n = serializeJson(doc, buffer);
    return buffer;
}


/*
 * 
*/
String json_gpsRegistro(){
  Serial.println("-------------- Envio GPS_REGISTRO --------------");
  char buffer[4096];
  DynamicJsonDocument doc (4096);
  String string_hora = stringHora();
  
//  doc["longitud"] = longitud_sim [i] ;
  doc["latitud"] = gps_neo.latitud  ;
  doc["longitud"] = gps_neo.longitud ;
  doc["Fecha_hora"] = string_hora; 
  doc["velocidad_kmh"] = gps_neo.speed   ;    
  doc["ruta"]        = ruta;
  doc["unidad"]      = unidad;
  doc["ramal"]       = ramal;
//  doc["busid"]  = busid;
//  doc["distancia_respecto_central"] = gps_neo.distancia_operacion / 1000;
//  doc["distacia_recorrida"] = gps_neo.distacia_recorrida / 1000;
  doc["clase"] = "GPS";
  doc["Tipo"] = "REGISTRO_RECORRIDO";   
  
  size_t n = serializeJson(doc, buffer);
  return buffer;
}

/*
 * 
 */

String json_gps_tiempo_real(){
  Serial.println("-------------- Envio GPS_TIEMPO_REAL --------------");
    char buffer[4096];
    DynamicJsonDocument doc (4096);
    String string_hora = stringHora();
    
//    doc["longitud"] = longitud_sim [i] ;
    doc["numero_serial"]  = NumSerie;
    doc["proyect"]  = proyect;
    doc["latitud"] = gps_neo.latitud  ;
    doc["longitud"] = gps_neo.longitud ;
    doc["Fecha_hora"] = string_hora; 
    doc["velocidad_kmh"] = gps_neo.speed   ;    
    doc["ruta"]        = ruta;
    doc["unidad"]      = unidad;
    doc["ramal"]       = ramal;
//    doc["busid"]  = busid;
//    doc["distancia_respecto_central"] = gps_neo.distancia_operacion / 1000;
//    doc["distacia_recorrida"] = gps_neo.distacia_recorrida / 1000;
    
    ///
    doc["clase"] = "GPS";
    doc["Tipo"] = "TIEMPO_REAL";   
    size_t n = serializeJson(doc, buffer);
    return buffer;
}

/*
  
*/

String json_status(){
//  Serial.println(" ---------------- ENVIO DE STATUS ---------------- ");
  char buffer[4096];
  DynamicJsonDocument doc (4096);
//  doc["busid"] = busid;
  doc["numero_serial"]  = NumSerie;
  doc["proyect"]  = proyect;
  doc["key_servidor"] = keyMDASH;
  doc["status_online"] = true;
  doc["status"] = 1;
  doc["status_wifi"] = statusWifi;
//  doc["hora_reinicio_contador1"]    = horaReinicio1;
//  doc["minuto_reinicio_contador1"]  = minutoReinicio1;
//  doc["hora_reinicio_contador2"]    = horaReinicio2;
//  doc["minuto_reinicio_contador2"]  = minutoReinicio2;
  doc["tiempo_envio"]               = frecuencia_tiempo_real;
  doc["frecuencia_registro_gps"]    = frecuencia_registro_gps;
  doc["frecuencia_status"]          = frecuencia_status;      
  doc["zona_horaria"]               = TimeZoneHour;
  doc["ruta"]        = ruta;
  doc["unidad"]      = unidad;
  doc["ramal"]       = ramal;
  doc["Time_reset"]  = 30; 
     
  size_t n = serializeJson(doc, buffer);
  return buffer;
}
