/*
 * 
*/

String respuestaDesSerializada(String payload){
  DynamicJsonDocument doc (4096);
  DeserializationError error = deserializeJson(doc, payload);
  if (error) { return "FALLO"; }

  bool actualizacion_firmware_servidor_esp          = doc["actualizacion_firmware_servidor_esp"];
  
  String ruta2                             = doc["ruta"];       
  String unidad2                           = doc["unidad"];   
  String ramal2                            = doc["ramal"];   
 
//  horaReinicio1                     = doc["hora_reinicio_contador1"];
//  minutoReinicio1                   = doc["minuto_reinicio_contador1"];
//  horaReinicio2                     = doc["hora_reinicio_contador2"];
//  minutoReinicio2                   = doc["minuto_reinicio_contador2"];
  frecuencia_tiempo_real            = doc["frecuencia_tiempo_real"];
  frecuencia_registro_gps           = doc["frecuencia_registro_gps"];
  frecuencia_status                 = doc["frecuencia_status"];
  
  TimeZoneHour                      = doc["zona_horaria"];\   

  geocercaLat     = doc["geocercaLat"];    
  geocercaLong     = doc["geocercaLong"];  
  //

  ruta = ruta2;
  unidad = unidad2;
  ramal = ramal2;
  
//  saveDataStatus();
  
  
  
//    dataSnd_string = String(json);
//  doc["latitud"] = gps_neo.latitud   ;
//  doc["longitud"] = gps_neo.longitud  ;
  
  // Condicional  para activar el wifi de los distintos dispositivos 
//  if(actualizacion_firmware_alcancia || actualizacion_firmware_contador1 || actualizacion_firmware_contador2){
//    doc["statusWifi"] = statusWifi;
//  } else{
//    doc["statusWifi"] = 0;
//  }
  
  if(actualizacion_firmware_servidor_esp){
    Serial.println("!!!!!!!!!!! ESTOY LISTO PARA LA ACTUALIZACION PATRON !!!!!!!!!!!");
    delay(1500);      
    // ACUALIZACION DE M-DASH
    actualizacionMDASH();
  }


  payload = "";
  size_t n = serializeJson(doc, payload);
//  msm_res_api = payload;
  Serial.println("___________________________ ACUALIZACION REALIZADA ___________________________");
//    Serial.println(msm_res_api);


 return "RETURN EXITOSO";
}


/*
 * saveDataStatus
*/
void saveDataStatus(){
    

//    preferences.begin("my-app", false);
    

    preferences.putUInt(eeprom_TimeZoneHour, (TimeZoneHour)); 
    preferences.putUInt(eeprom_frecuencia_tiempo_real, (frecuencia_tiempo_real));  
    preferences.putUInt(eeprom_frecuencia_registro_gps, (frecuencia_registro_gps)); 
    preferences.putUInt(eeprom_frecuencia_status, (frecuencia_status));  
    preferences.putString(eeprom_ruta.c_str(), (ruta));
    preferences.putString(eeprom_unidad.c_str(), (unidad));
    preferences.putString(eeprom_ramal.c_str(), (ramal));
//    preferences.end();
}

void actualizacionMDASH(){
  // SE ACTUALIZA EL M-DASH
  //  mDashBegin(keyMDASH);
}
