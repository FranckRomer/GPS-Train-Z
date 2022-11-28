/*
 **************************************************************** 
*                         POST_JSON_REGISTRO                
 * **************************************************************
*/ 
String POST_REGISTRO(String payload){
  HTTPClient http;
  http.begin(String(server_api) + "registro");
  Serial.println("API: " + String(server_api) + "registro");
  http.addHeader("Content-Type", "application/json");       
  int httpResponseCode = http.POST(payload);

  if(httpResponseCode > 0) {
      Serial.printf("[HTTP] POST... code: %d\n", httpResponseCode);
      if(httpResponseCode == HTTP_CODE_OK) {
          String payload = http.getString();
          Serial.println("Servidor Res:" + String(payload));
          return payload;
//          boolean_SERVER = String(payload);
          //msm_res_api = String(payload);
      }
  } else {
//      boolean_SERVER = false;
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
      return "";
  }

  http.end();
}
/*
 **************************************************************** 
*                         TIEMPO REAL               
 * **************************************************************
*/
//void PATCH_TIEMPO_REAL(uint8_t num ,String payload, String clase_api, String tipo_api ){
//  HTTPClient http;
//  http.begin(String(server_api) + "TIEMPO_REAL");
//  Serial.println("API: " + String(server_api) + "TIEMPO_REAL");
//  http.addHeader("Content-Type", "application/json");   
//    
//
//    int httpResponseCode = http.PATCH(payload);
//
//  if(httpResponseCode > 0) {
//      Serial.printf("[HTTP] PATCH... code: %d\n", httpResponseCode);
//      if(httpResponseCode == HTTP_CODE_OK) {
//          String payload = http.getString();
//          Serial.println("Servidor Res:" + String(payload));
//          boolean_SERVER = String(payload);
//      }
//  } else {
//      boolean_SERVER = false;
//      Serial.printf("[HTTP] PATCH... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
//      
//  }
//  respuestaSERVER(num, payload);
//  http.end();
//}

/*
 **************************************************************** 
*                         PATCH_GPS();               
 * **************************************************************
*/ 
String PATCH_GPS(String payload ){
  HTTPClient http;
  http.begin(String(server_api) + "tiempo_real");
  http.addHeader("Content-Type", "application/json");   
  int httpResponseCode = http.PATCH(payload);

  if(httpResponseCode > 0) {
      Serial.printf("[HTTP] PATCH... code: %d\n", httpResponseCode);
      if(httpResponseCode == HTTP_CODE_OK) {
          String payload = http.getString();
          Serial.println("Servidor Res:" + String(payload));
          return payload;
//          msm_res_api = String(payload);
          //webSocket.sendTXT(num, msm_res_api);
      }
  } else {
//      msm_res_api = http.errorToString(httpResponseCode).c_str();
      Serial.printf("[HTTP] PATCH... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
      return "";
  }
  //webSocket.sendTXT(num, msm_res_api);
  http.end();
  //delay(200);
}

/*
 **************************************************************** 
*                         GET_STATUS               
 * **************************************************************
*/ 
String PATCH_STATUS(String payload ){
  HTTPClient http;
  http.begin(String(server_api) + "status"); //HTTP
  http.addHeader("Content-Type", "application/json");  
  int httpCode = http.POST(payload);

  if(httpCode > 0) {
      Serial.printf("[HTTP] POST_STATUS... code: %d\n", httpCode);
      if(httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
//          status_servidor = payload;
//          msm_res_api = payload;
          Serial.println("_________________________________ RESPUESTA STATUS _________________________________");
          Serial.println(String(payload));     
          return payload;
//          Serial.println(String(payload));        
//          respuestaConfirmadaSTATUS(num, payload);///////////////
//          respuestaConfirmadaSTATUS2(num, payload);
//          webSocket.sendTXT(num, msm_res_api);
//          Serial.println("Servidor Res:" + String(status_servidor));
      }
  } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      return "";
  }
  http.end();
}
