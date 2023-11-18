
#include "DHT.h"
#include <Wire.h>  //Biblioteca para Comunicação I2C
#include <LiquidCrystal_I2C.h>  //Biblioteca com as funções do display
#include <SoftwareSerial.h>

#define DHTPIN A2  


#define DHTTYPE DHT11   // DHT 11

SoftwareSerial bluetooth(8,9); // Portas para o serial do bluetooth (RX, TX)
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2); 
//int valordobluetooth; // Variável que vai ler o valor enviado pelo bluetooth 


void setup() {
  bluetooth.begin(9600); //Início da serial do bluetooth
  Serial.println(F("Testando DHT11!"));
  Serial.begin(9600);
  lcd.init(); 
  dht.begin();
}

void loop() {
  //Aguardar alguns segundos entre as medições.
  delay(2000);

  // A leitura da temperatura ou umidade leva cerca de 250 milissegundos!
  //As leituras do sensor também podem ter até 2 segundos
  float h = dht.readHumidity();
  // leitura da temperatura em Celsius (the default)
  float t = dht.readTemperature();
  // leitura da temperatura em Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  //  Calcule e retorne o índice de calor em Fahrenheit (padrao)
  float hif = dht.computeHeatIndex(f, h);
  // Calcule e retorne o índice de calor em graus Celsius
  float hic = dht.computeHeatIndex(t, h, false);


  // Verifique se alguma leitura falhou e retornar a falha
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Falha na leitura do sensor!"));
    return;
  }else
  
  
  /*if (serialdobluetooth.available()) //Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
  {
    valordobluetooth = serialdobluetooth.read();
  }*/
  /*if (valordobluetooth == 'A'){
    Serial.print(F("Umidade: "));
    Serial.print(h);
    Serial.print(F("%  Temperatura: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Índice de calor: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
    serialdobluetooth.print(F("%  Temperatura: "));
    serialdobluetooth.print(t);
 // }*/

  /*if (valordobluetooth== 'a')
  {
    lcd.setBacklight(HIGH);// luz
    lcd.setCursor(0,0);
    lcd.clear(); //Apaga todos os caracteres do Display
    lcd.setCursor(0,0);//Marca o cursor na posição coluna 0, linha 0
    lcd.print("Desligando o acesso ao bluetooth");
  }*/
  // Bluetooth
  // Temperatura
    bluetooth.print(t);
    bluetooth.print(",");

    // Umidade
    bluetooth.print(h);
    bluetooth.print(",");

    // Temperatura em Farenheit
    bluetooth.print(f);
    bluetooth.print(",");
    bluetooth.println();

  // LCD 
  /*lcd.setBacklight(HIGH);// luz
  lcd.setCursor(0,0);
  lcd.clear(); //Apaga todos os caracteres do Display
  lcd.setCursor(0,0);//Marca o cursor na posição coluna 0, linha 0
  lcd.print(F("Umidade: "));
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(F("Temp: "));
  lcd.print(t);
  lcd.print((char)223);
  lcd.print(F("C "));
  delay(3000);
  lcd.clear(); //Apaga todos os caracteres do Display
  lcd.setCursor(0,0);
  lcd.print(F("Indice de calor: "));// índice de calor é a medida de quão quente é com base na temperatura e umidade
  lcd.setCursor(0,1);
  lcd.print(hic);
  lcd.print((char)223);
  lcd.print(F("C "));
  lcd.print(hif);
  lcd.print((char)223);
  lcd.print(F("F"));
  //delay(3000);
  //lcd.clear(); 
  //lcd.setCursor(3,1);
  //lcd.print("Obrigada :)");
  //delay(2000);*/
}
