/**********************************************************************
 *   VARIABLES PARA EEPROM
 ***********************************************************************
 */
// 
String ruta = "undefined";
String unidad = "undefined";
String ramal = "undefined";

// VARIABLES DE GEOCERCA
double geocercaLat = 20.011610249112156;
double geocercaLong = -98.80324750258833;
bool tamGeoSerca = 300;  // Geo Serca en METROS
/////////////////////////////////
int TimeZoneHour = -6;
int frecuencia_tiempo_real ;//seg   
int frecuencia_registro_gps ;//seg    
int frecuencia_status;
//int frec_envio = 0;
//int frec_reg = 0;
//int post_status = 0;

//////////////////////////////////
String eeprom_latitud   = "latitud";
String eeprom_longitud  = "longitud";
String eeprom_anio      = "anio";
String eeprom_mes       = "mes";
String eeprom_dia       = "dia";
String eeprom_hora      = "horas";
String eeprom_minuto    = "minuto";
String eeprom_segundo   = "segundo";
String distacia_recorrida             = "dist_act";
String eeprom_distancia_operacion     = "dist_ope";

const char* eeprom_hora_reinicio_contador1   = "hour_save1";
const char* eeprom_minuto_reinicio_contador1 = "min_save1";
const char* eeprom_hora_reinicio_contador2   = "hour_save2";
const char* eeprom_minuto_reinicio_contador2 = "min_save2";
const char* eeprom_TimeZoneHour = "ZoneHour";
// frecuecia de envio
const char* eeprom_frecuencia_tiempo_real = "frec_tim_re";
const char* eeprom_frecuencia_registro_gps = "frec_regis_gps";
const char* eeprom_frecuencia_status = "frec_en_stat";



String eeprom_ruta    = "ruta";
String eeprom_unidad  = "unidad";
String eeprom_ramal    = "ramal";

String ruta2    = "ruta";
String unidad2  = "unidad";
String ramal2    = "ramal";

String eeprom_geocercaLat = "geolat";
String eeprom_geocercaLong = "geolong";
////////////////////////////////////////////////
/**********************************************************************
 *   VARIABLES PERMANENTES
 ***********************************************************************
 */
//  OBJETOS
class ClassGPS {       // The class
  public:             // Access specifier
    String latitud;        
    String longitud;
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    double speed;
    double distancia_operacion = 0;
    double distacia_recorrida = 0;
    String fecha_inicio;
    int contador_gps = 0;
};
// instancia de eeprom
Preferences preferences;
// GPS
TinyGPSPlus gps;
#define RXD1 4
#define TXD1 2

//
ClassGPS gps_neo;

// use only core 1 for demo purpouses
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

//////////////////
WebServer server(80);

/*/////////////////
      VARIABLEES
*/

float Latitude, Longitude;
int year, month, date, hour, minute, second;
String DateString, TimeString, LatitudeString, LongitudeString;

bool statusWifi = false;
