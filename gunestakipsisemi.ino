#include <Servo.h> // Servo kütüphanesi yükleniyor, servoları kontrol etmek için gerekli.

// Servo motor değişkenleri
Servo horizontal; // Yatay servo motor tanımlanıyor.
int servoh = 180; // Yatay servo başlangıç açısı.

int servohLimitHigh = 180; // Yatay servo için maksimum açı sınırı.
int servohLimitLow = 65;   // Yatay servo için minimum açı sınırı.

Servo vertical; // Dikey servo motor tanımlanıyor.
int servov = 45; // Dikey servo başlangıç açısı.

int servovLimitHigh = 80; // Dikey servo için maksimum açı sınırı.
int servovLimitLow = 15;  // Dikey servo için minimum açı sınırı.

// LDR (ışık algılayıcı direnç) pin bağlantıları
// Analog pinler tanımlanıyor.
int ldrlt = 0; // Sol üst LDR.
int ldrrt = 1; // Sağ üst LDR.
int ldrld = 2; // Sol alt LDR.
int ldrrd = 3; // Sağ alt LDR.

void setup() {
    Serial.begin(9600); // Seri iletişim başlatılıyor, iletişim hızı 9600 baud.

    // Servo motorlar Arduino pinlerine atanıyor.
    horizontal.attach(9); // Yatay servo 9. pine bağlanıyor.
    vertical.attach(10);  // Dikey servo 10. pine bağlanıyor.

    // Servo başlangıç pozisyonları ayarlanıyor.
    horizontal.write(180); // Yatay servo maksimum açıda başlatılıyor.
    vertical.write(45);    // Dikey servo orta açıda başlatılıyor.
    delay(3000); // Başlangıç pozisyonuna gitmek için bekleme süresi.
}

void loop() {
    // LDR'den okunan analog değerler alınıyor.
    int lt = analogRead(ldrlt); // Sol üst LDR'den veri okunuyor.
    int rt = analogRead(ldrrt); // Sağ üst LDR'den veri okunuyor.
    int ld = analogRead(ldrld); // Sol alt LDR'den veri okunuyor.
    int rd = analogRead(ldrrd); // Sağ alt LDR'den veri okunuyor.

    // Zamanlama ve tolerans değerleri (opsiyonel olarak potansiyometreden alınabilir).
    int dtime = 10; // Hareket sonrası bekleme süresi (ms).
    int tol = 50;   // Tolerans değeri, algılanan farkın ne kadar büyük olması gerektiği.

    // LDR'lerden alınan değerlerin ortalaması hesaplanıyor.
    int avt = (lt + rt) / 2; // Üst sensörlerin ortalama değeri.
    int avd = (ld + rd) / 2; // Alt sensörlerin ortalama değeri.
    int avl = (lt + ld) / 2; // Sol sensörlerin ortalama değeri.
    int avr = (rt + rd) / 2; // Sağ sensörlerin ortalama değeri.

    // Yukarı-aşağı ve sol-sağ arasındaki farklar hesaplanıyor.
    int dvert = avt - avd; // Yukarı ve aşağı arasındaki fark.
    int dhoriz = avl - avr; // Sol ve sağ arasındaki fark.

    // Değerler seri monitöre yazdırılıyor.
    Serial.print(avt);
    Serial.print(" ");
    Serial.print(avd);
    Serial.print(" ");
    Serial.print(avl);
    Serial.print(" ");
    Serial.print(avr);
    Serial.print(" ");
    Serial.print(dtime);
    Serial.print(" ");
    Serial.print(tol);
    Serial.println(" ");

    // Yukarı-aşağı farkı tolerans değerinden büyükse dikey hareket kontrol edilir.
    if (-1 * tol > dvert || dvert > tol) {
        if (avt > avd) {
            // Yukarı sensörlerin ışığı daha fazla algıladığı durumda servo yukarı hareket eder.
            servov = ++servov;
            if (servov > servovLimitHigh) { // Açı sınırını aşmaması kontrol edilir.
                servov = servovLimitHigh;
            }
        } else if (avt < avd) {
            // Aşağı sensörlerin ışığı daha fazla algıladığı durumda servo aşağı hareket eder.
            servov = --servov;
            if (servov < servovLimitLow) { // Açı sınırını aşmaması kontrol edilir.
                servov = servovLimitLow;
            }
        }
        vertical.write(servov); // Dikey servoya yeni açı gönderilir.
    }

    // Sol-sağ farkı tolerans değerinden büyükse yatay hareket kontrol edilir.
    if (-1 * tol > dhoriz || dhoriz > tol) {
        if (avl > avr) {
            // Sol sensörlerin ışığı daha fazla algıladığı durumda servo sola hareket eder.
            servoh = --servoh;
            if (servoh < servohLimitLow) { // Açı sınırını aşmaması kontrol edilir.
                servoh = servohLimitLow;
            }
        } else if (avl < avr) {
            // Sağ sensörlerin ışığı daha fazla algıladığı durumda servo sağa hareket eder.
            servoh = ++servoh;
            if (servoh > servohLimitHigh) { // Açı sınırını aşmaması kontrol edilir.
                servoh = servohLimitHigh;
            }
        }
        horizontal.write(servoh); // Yatay servoya yeni açı gönderilir.
    }

    delay(dtime); // Hareket sonrası bir süre beklenir.
}