#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://untrasonic-3320b-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "HkF1kNygfunBltIerb6He01fKuL853H0CMQeCqdT"
#define WIFI_SSID "AIS 4G Hi-Speed Home WiFi_103923"
#define WIFI_PASSWORD "50103923"
FirebaseData firebaseData;
int Relay1 = D2; 
int A=0;
int analogPin = D1; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1,LOW);
  Serial.begin(9600);
  WiFiConnection();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  if(Firebase.getInt(firebaseData, "/Int_A")){
    if(firebaseData.dataType() == "int"){
      A= firebaseData.intData();
      Serial.print("Int_A = ");
      Serial.println(A); 
      if( A == 1){
        //เมื่อwalkerเอียงจะทำการส่งเสียงไปยังลำโพง    
        PlayMP3();
        Serial.println("start");
      }
    }
  }
   lightsen();
}

void WiFiConnection(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  } 
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void lightsen() {
  int sensorValue = digitalRead(D1);
  val = digitalRead(analogPin); //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ LDR Photoresistor Sensor Module
  Serial.print("val = "); // พิมพ์ข้อความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  if(val == 0) {
    PlayMP3();
    PlayMP3();
    PlayMP3();
  }
}

void PlayMP3() {
  digitalWrite(Relay1,HIGH); //ใช้Relayในการกำหนดเวลาในการเปิดลำโพง
  delay(13500);
  digitalWrite(Relay1,LOW);
  delay(1000);
}
