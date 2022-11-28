//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
bool gps_serial()
{
  if (Serial1.available() > 0)
  {
    gps.encode(Serial1.read());
    if (gps.location.isUpdated())
    {
      ///////////////////////////////////////////////////////
      preferences.begin("my-app", false);

      String eeprom_latitud = "lat";
      String eeprom_longitud = "long";
      String eeprom_anio = "anio";
      String eeprom_mes = "mes";
      String eeprom_dia = "dia";
      String eeprom_hora = "horas";
      String eeprom_minuto = "min";
      String eeprom_segundo = "seg";

      gps_neo.latitud = String(gps.location.lat(), 6);
      gps_neo.longitud = String(gps.location.lng(), 6);
      gps_neo.anio = gps.date.year();
      gps_neo.mes = gps.date.month();
      gps_neo.dia = gps.date.day();
      gps_neo.hora = gps.time.hour();
      gps_neo.minuto = gps.time.minute();
      gps_neo.segundo = gps.time.second();
      gps_neo.speed = gps.speed.kmph();

      //  Se cambia la Hora a la zona de mexico
      timeChangeZone();
      // GUARDAR EN EEPROM
      preferences.putDouble(eeprom_latitud.c_str(), (gps.location.lat()));
      preferences.putDouble(eeprom_longitud.c_str(), (gps.location.lng()));
      preferences.putUInt(eeprom_anio.c_str(), (gps.date.year()));
      preferences.putUInt(eeprom_mes.c_str(), (gps.date.month()));
      preferences.putUInt(eeprom_dia.c_str(), (gps.date.day()));
      preferences.putUInt(eeprom_hora.c_str(), (gps.time.hour()));
      preferences.putUInt(eeprom_minuto.c_str(), (gps.time.minute()));
      preferences.putUInt(eeprom_segundo.c_str(), (gps.time.second()));
      
      
      preferences.end();

      delay(900);
      return true;
    }
  }
  return false;
}

/*
 *   FUNCION PARA CAMBIAR LA HORA DE ZONA
 */
void timeChangeZone()
{
  // Funcion que cambia la hora
  // Suma o resta la zona horaria
  gps_neo.hora = gps_neo.hora + TimeZoneHour;
  if (gps_neo.hora >= 0)
  {
    // Guarda los datos Iguales
  }
  else
  {
    // Se resta un dia
    gps_neo.dia = gps_neo.dia - 1;
    gps_neo.hora = 24 + gps_neo.hora; ///  22pm -> 3 /// meridiano 4
    if (gps_neo.dia >= 1)
    {
      // Guarda pero con hora de 24 - (hora negativa)
    }
    else
    {
      // Suponemos que todos los meses tienen 30 dias y le restamos lo que tenia el dia
      gps_neo.dia = 30 + gps_neo.dia;
      gps_neo.mes = gps_neo.mes - 1;
      if (gps_neo.mes == 0)
      {
        // El mes es cero
        gps_neo.mes = 12;
        gps_neo.anio = gps_neo.anio - 1;
      }
    }
  }
}

/*
****************************************************************
*    Funcion para agregar a la HORA CEROS
****************************************************************
*/

String stringHora()
{
  String string_hora;
  String mes;
  String dia;
  String hora;
  String minuto;
  String segundo;

  // mes
  if (String(gps_neo.mes).length() == 1)
  {
    mes = "0" + String(gps_neo.mes);
  }
  else
  {
    mes = String(gps_neo.mes);
  }

  // dia
  if (String(gps_neo.dia).length() == 1)
  {
    dia = "0" + String(gps_neo.dia);
  }
  else
  {
    dia = String(gps_neo.dia);
  }

  // hora
  if (String(gps_neo.hora).length() == 1)
  {
    hora = "0" + String(gps_neo.hora);
  }
  else
  {
    hora = String(gps_neo.hora);
  }

  // minuto
  if (String(gps_neo.minuto).length() == 1)
  {
    minuto = "0" + String(gps_neo.minuto);
  }
  else
  {
    minuto = String(gps_neo.minuto);
  }

  // segundo
  if (String(gps_neo.segundo).length() == 1)
  {
    segundo = "0" + String(gps_neo.segundo);
  }
  else
  {
    segundo = String(gps_neo.segundo);
  }

  //
  string_hora = String(gps_neo.anio) + "-" + mes + "-" + dia + " " + hora + ":" + minuto + ":" + segundo;
  return string_hora;
}
