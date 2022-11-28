/*
 * ************************************************************************************************
 *                                          SETUP`S
 * ************************************************************************************************
 */
void setupWiFi()
{
  IPAddress local_IP(192, 168, 1, 55);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8); //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional
  
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  //  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("..................Connecting to WiFi..................");
  while (WiFi.status() != WL_CONNECTED)
  {
    //    Serial.println("..................");
    statusWifi = false;
    delay(1000);
    //    gps_serial();
  }
//  Serial.println(WiFi.localIP());
  //
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());
}
