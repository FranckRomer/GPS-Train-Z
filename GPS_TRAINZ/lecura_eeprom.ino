///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void lectura_eeprom()
{
  Serial.println("******** LECTURA DE DATOS GPS ********");
//  const char* eeprom_hora_reinicio_contador1   = "hour_save1";
//  const char* eeprom_minuto_reinicio_contador1 = "min_save1";
//  const char* eeprom_hora_reinicio_contador2   = "hour_save2";
//  const char* eeprom_minuto_reinicio_contador2 = "min_save2";
//  const char* eeprom_TimeZoneHour = "ZoneHour";
//  const char* eeprom_tiempo_envio = "tiempo_envio";
//  const char* eeprom_frecuencia_registro_gps = "frec_regis_gps";
//  
//  String eeprom_latitud   = "latitud";
//  String eeprom_longitud  = "longitud";
//  String eeprom_anio      = "anio";
//  String eeprom_mes       = "mes";
//  String eeprom_dia       = "dia";
//  String eeprom_hora      = "horas";
//  String eeprom_minuto    = "minuto";
//  String eeprom_segundo   = "segundo";
//  String distacia_recorrida             = "dist_act";
//  String eeprom_distancia_operacion     = "dist_operacion";
//  
//  String eeprom_ruta    = "ruta";
//  String eeprom_unidad  = "unidad";
//  String eeprom_ramal    = "ramal";
//  
//  String ruta2    = "ruta";
//  String unidad2  = "unidad";
//  String ramal2    = "ramal";
//  
//  String eeprom_geocercaLat = "geolat";
//  String eeprom_geocercaLong = "geolong";

  // Se lee
  gps_neo.latitud = String(preferences.getDouble(eeprom_latitud.c_str(), 0), 6);
  gps_neo.longitud = String(preferences.getDouble(eeprom_longitud.c_str(), 0), 6);
  gps_neo.anio = (preferences.getUInt(eeprom_anio.c_str(), 2022));
  gps_neo.mes = (preferences.getUInt(eeprom_mes.c_str(), 10));
  gps_neo.dia = (preferences.getUInt(eeprom_dia.c_str(), 10));
  gps_neo.hora = (preferences.getUInt(eeprom_hora.c_str(), 0));
  gps_neo.minuto = (preferences.getUInt(eeprom_minuto.c_str(), 0));
  gps_neo.segundo = (preferences.getUInt(eeprom_segundo.c_str(), 0));

  gps_neo.distancia_operacion = (preferences.getDouble(eeprom_distancia_operacion.c_str(), 0));
  TimeZoneHour   = (preferences.getUInt(eeprom_TimeZoneHour, -6));      
  
  frecuencia_tiempo_real    = (preferences.getUInt(eeprom_frecuencia_tiempo_real, 10));
  frecuencia_registro_gps   = (preferences.getUInt(eeprom_frecuencia_registro_gps, 20));
  frecuencia_status         = (preferences.getUInt(eeprom_frecuencia_status, 20));

  ruta    = (preferences.getString(eeprom_ruta.c_str(), ruta)); 
  unidad  = (preferences.getString(eeprom_unidad.c_str(), unidad)); 
  ramal   = (preferences.getString(eeprom_ramal.c_str(), ramal));

  geocercaLat = (preferences.getDouble(eeprom_geocercaLat.c_str(), geocercaLat));
  geocercaLong = (preferences.getDouble(eeprom_geocercaLong.c_str(), geocercaLong));
  
  //  Se cambia la Hora a la zona de mexico
  timeChangeZone();
  // SE IMPRIME
  Serial.println("latitud:" + String(gps_neo.latitud));
  Serial.println("longitud:" + String(gps_neo.longitud));
//  latitud = gps_neo.latitud.toDouble();
//  longitud = gps_neo.longitud.toDouble(); 
  Serial.println("");
  Serial.println("anio:" + String(gps_neo.anio));
  Serial.println("mes:" + String(gps_neo.mes));
  Serial.println("dia:" + String(gps_neo.dia));
  Serial.println("hora:" + String(gps_neo.hora));
  Serial.println("minuto:" + String(gps_neo.minuto));
  Serial.println("segundo:" + String(gps_neo.segundo));
//  Serial.println("");
//  Serial.println("horaReinicio1:" + String(horaReinicio1));
//  Serial.println("minutoReinicio1:" + String(minutoReinicio1));
//  Serial.println("horaReinicio2:" + String(horaReinicio2));
//  Serial.println("minutoReinicio2:" + String(minutoReinicio2));
  Serial.println("");
  Serial.println("ruta:" + String(ruta));
  Serial.println("unidad:" + String(unidad));
  Serial.println("ramal:" + String(ramal));
  Serial.println("");
  Serial.println("geocercaLat:" + String(geocercaLat));
  Serial.println("geocercaLong:" + String(geocercaLong));
  Serial.println("");
  Serial.println("frecuencia_tiempo_real:" + String(frecuencia_tiempo_real));
  Serial.println("frecuencia_registro_gps:" + String(frecuencia_registro_gps));
  Serial.println("frecuencia_status: " + String(frecuencia_status));
  delay(1000);
}
