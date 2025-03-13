#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // PWM sürücü nesnesi
#define IR_RECEIVE_PIN 12 // IR alıcı sensörün bağlı olduğu pin
int a =4;
#define SERVO_MIN  150 // Servo minimum değeri
#define SERVO_MAX  600 // Servo maksimum değeri

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat
  pwm.begin(); // PWM sürücüsünü başlat
  pwm.setPWMFreq(60); // Servo motorlar için 60 Hz frekansı ayarla
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // IR alıcısını başlat
  Serial.println("Kumanda tuşlarına basın, kodlar burada görünecek:");
  
}
void yumusakHareketEsZamanli(int servo1, int baslangic1, int hedef1, int servo2, int baslangic2, int hedef2,int a) {
  int adim1 = (hedef1 > baslangic1) ? 1 : -1;
  int adim2 = (hedef2 > baslangic2) ? 1 : -1;

  int uzunluk1 = abs(hedef1 - baslangic1);z
  int uzunluk2 = abs(hedef2 - baslangic2);

  int maxUzunluk = max(uzunluk1, uzunluk2);

  for (int i = 0; i <= maxUzunluk; i++) {
     if (i <= uzunluk1) pwm.setPWM(servo1, 0, baslangic1 + i * adim1);
    if (i <= uzunluk2) pwm.setPWM(servo2, 0, baslangic2 + i * adim2);
    delay(a);
  }
}
// Hareket fonksiyonlarında değerler servo aralığına uygun olacak şekilde işlenir
void yumusakHareketEsZamanlidort(int servo1, int baslangic1, int hedef1, int servo2,
 int baslangic2, int hedef2, int servo3, int baslangic3, int hedef3, int servo4, int baslangic4, int hedef4,int a) {
  int adim1 = (hedef1 > baslangic1) ? 1 : -1;
  int adim2 = (hedef2 > baslangic2) ? 1 : -1;
  int adim3 = (hedef3 > baslangic3) ? 1 : -1;
  int adim4 = (hedef4 > baslangic4) ? 1 : -1;

  int uzunluk1 = abs(hedef1 - baslangic1);
  int uzunluk2 = abs(hedef2 - baslangic2);
  int uzunluk3 = abs(hedef3 - baslangic3);
  int uzunluk4 = abs(hedef4 - baslangic4);

  int maxUzunluk = max(max(max(uzunluk1, uzunluk2), uzunluk3), uzunluk4);

  for (int i = 0; i <= maxUzunluk; i++) {
    if (i <= uzunluk1) pwm.setPWM(servo1, 0, baslangic1 + i * adim1);
    if (i <= uzunluk2) pwm.setPWM(servo2, 0, baslangic2 + i * adim2);
    if (i <= uzunluk3) pwm.setPWM(servo3, 0, baslangic3 + i * adim3);
    if (i <= uzunluk4) pwm.setPWM(servo4, 0, baslangic4 + i * adim4);
    delay(a);
  }
}


void yumusakHareketEsZamanlialti(int servo1, int baslangic1, int hedef1, int servo2,
 int baslangic2, int hedef2, int servo3, int baslangic3, int hedef3, int servo4, int baslangic4, int hedef4,int servo5, int baslangic5, 
 int hedef5, int servo6, int baslangic6, int hedef6, int a) {
  int adim1 = (hedef1 > baslangic1) ? 1 : -1;
  int adim2 = (hedef2 > baslangic2) ? 1 : -1;
  int adim3 = (hedef3 > baslangic3) ? 1 : -1;
  int adim4 = (hedef4 > baslangic4) ? 1 : -1;
  int adim5 = (hedef5 > baslangic5) ? 1 : -1;
  int adim6 = (hedef6 > baslangic6) ? 1 : -1;

  int uzunluk1 = abs(hedef1 - baslangic1);
  int uzunluk2 = abs(hedef2 - baslangic2);
  int uzunluk3 = abs(hedef3 - baslangic3);
  int uzunluk4 = abs(hedef4 - baslangic4);
  int uzunluk5 = abs(hedef5 - baslangic5);
  int uzunluk6 = abs(hedef6 - baslangic6);
  int maxUzunluk = max(max(max(max(max(uzunluk1, uzunluk2), uzunluk3), uzunluk4),uzunluk5),uzunluk6);

  for (int i = 0; i <= maxUzunluk; i++) {
    if (i <= uzunluk1) pwm.setPWM(servo1, 0, baslangic1 + i * adim1);
    if (i <= uzunluk2) pwm.setPWM(servo2, 0, baslangic2 + i * adim2);
    if (i <= uzunluk3) pwm.setPWM(servo3, 0, baslangic3 + i * adim3);
    if (i <= uzunluk4) pwm.setPWM(servo4, 0, baslangic4 + i * adim4);
    if (i <= uzunluk5) pwm.setPWM(servo5, 0, baslangic5 + i * adim5);
    if (i <= uzunluk6) pwm.setPWM(servo6, 0, baslangic6 + i * adim6);
    delay(a);
  }
}


void hareket1() {//trot yürüyüş modeli
  Serial.println("Hareket 1 başladı...");
  while (true) {
   pwm.setPWM(0, 0, 300);
   pwm.setPWM(1, 0, 280);
   pwm.setPWM(2, 0, 350);
   pwm.setPWM(3, 0, 280);
    yumusakHareketEsZamanli(8, 300, 360, 11, 290, 210,a);
    yumusakHareketEsZamanlidort(5, 250, 300, 6, 270, 230, 4, 250, 310, 7, 390, 330,a);
    yumusakHareketEsZamanli(8, 360, 300, 11, 210, 290,a);
    yumusakHareketEsZamanli(15, 310, 220, 10, 310, 400,a);
    yumusakHareketEsZamanlidort(4, 310, 250, 7, 330, 390, 5, 300, 250, 6, 230, 270,a);
    yumusakHareketEsZamanli(15, 220, 310, 10, 400, 310,a);
    if (IrReceiver.decode()) {
      uint32_t irKodu = IrReceiver.decodedIRData.decodedRawData;

      if (irKodu == 0xE916FF00) { 
        IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
        hareket4(); 
        return; 
      } else if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
  a++;
   IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
} else if (IrReceiver.decodedIRData.decodedRawData == 0xB946FF00) {
  a--;
   IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
}
      IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
    }
  }
}





void hareket2() {//oturma pozisyonundan ayağa kalkma 
   pwm.setPWM(0, 0, 300);
   pwm.setPWM(1, 0, 290);
   pwm.setPWM(2, 0, 350);
   pwm.setPWM(3, 0, 280);
   
    yumusakHareketEsZamanlidort(4, 150, 300, 5, 390, 250, 6, 180, 260, 7, 450, 360,a);
    yumusakHareketEsZamanlidort(8, 450, 280, 15, 160, 300, 10, 450, 310, 11, 150, 260,a);
 
}
void hareket3() {//oturma pozisyonu
  
  pwm.setPWM(10, 0, 450);
  pwm.setPWM(11, 0, 150);
  pwm.setPWM(8, 0, 450);
  pwm.setPWM(15, 0, 160);
  pwm.setPWM(0, 0, 300);
  pwm.setPWM(1, 0, 290);
  pwm.setPWM(2, 0, 350);
  pwm.setPWM(3, 0, 280);
  pwm.setPWM(4, 0, 150);
  pwm.setPWM(5, 0, 390);
  pwm.setPWM(6, 0, 180);
  pwm.setPWM(7, 0, 450);
}

void hareket4() {//ayakta  duruş
  
  pwm.setPWM(10, 0, 310);
  pwm.setPWM(11, 0, 260);
  delay(500);
  pwm.setPWM(8, 0, 280);
  pwm.setPWM(15, 0, 300);
  delay(500);
  pwm.setPWM(0, 0, 300);
  pwm.setPWM(1, 0, 290);
  pwm.setPWM(2, 0, 350);
  pwm.setPWM(3, 0, 280);
  pwm.setPWM(4, 0, 300);
  pwm.setPWM(5, 0, 250);
  pwm.setPWM(6, 0, 260);
  pwm.setPWM(7, 0, 360);
}

void hareket5() {//adım adım yürüyüş (walk) modeli 
  Serial.println("Hareket 5 başladı...");
  
  while (true) {
   pwm.setPWM(0, 0, 300);
   pwm.setPWM(1, 0, 280);
   pwm.setPWM(2, 0, 350);
   pwm.setPWM(3, 0, 280);
    yumusakHareketEsZamanlialti(15, 310, 220, 5, 250, 190, 15, 220, 310, 4, 310, 290,6, 260, 240, 7, 360, 380,a);
    yumusakHareketEsZamanlialti(10, 310, 400, 6, 240, 300, 10, 400, 310, 4, 290,270, 5, 190, 210, 7, 380, 400,a);
    yumusakHareketEsZamanlialti(8, 280, 370, 4, 270, 330, 8, 370, 280, 5, 210, 230,6, 300, 280, 7, 400, 420,a);
    yumusakHareketEsZamanlialti(11, 260, 170, 7, 420, 360, 11, 170, 260, 4, 330, 310,5, 230, 250, 6, 280, 260,a);
    if (IrReceiver.decode()) {
      uint32_t irKodu = IrReceiver.decodedIRData.decodedRawData;

      if (irKodu == 0xE916FF00) { 
        IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
        hareket4(); 
        return; 
      } else if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
  a++;
   IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
} else if (IrReceiver.decodedIRData.decodedRawData == 0xB946FF00) {
  a--;
   IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
}
      IrReceiver.resume(); // Yeni IR sinyali için IR alıcıyı hazırlayın
    }
  }
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Tuş Kodu: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // IR kodlarına göre hareket fonksiyonlarını çağır
    if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) { 
     Serial.println("Hareket 1 başlatılıyor...");
     hareket1();
    } else if (IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00) { 
     Serial.println("Hareket 2 başlatılıyor...");
      hareket2();
    }
    else if (IrReceiver.decodedIRData.decodedRawData == 0xE619FF00) { 
     Serial.println("Hareket 3 başlatılıyor...");
      hareket3();
    }
    else if (IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) { 
     Serial.println("Hareket 4 başlatılıyor...");
      hareket4();
    }
    else if (IrReceiver.decodedIRData.decodedRawData == 0xF20DFF00) { 
     Serial.println("Hareket 5 başlatılıyor...");
      hareket5();
    }

    IrReceiver.resume(); // Yeni bir IR sinyali almak için hazırla
  }
}
