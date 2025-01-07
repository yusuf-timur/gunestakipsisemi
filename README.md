# gunestakipsisemi
Bu proje, ışık yoğunluğunu algılayarak servo motorları hareket ettiren bir sistemin Arduino ile nasıl çalıştığını gösterir. Sistem, dört adet LDR (Light Dependent Resistor) kullanarak ışık algılaması yapar ve servo motorları buna göre kontrol eder.

## Gereksinimler

- Arduino Uno veya benzer bir mikrodenetleyici kartı
- 2 adet Servo motor
- 4 adet LDR (Light Dependent Resistor)
- 4 adet 10kΩ direnç
- Jumper kabloları
- Breadboard

## Pin Bağlantıları

Bu projede kullanılan pin bağlantıları aşağıdaki gibi yapılandırılmıştır:

### Servo Motor Bağlantıları
- **Yatay Servo Motor (horizontal)**  
  - Servo motorun **kontrol kablosu**: Arduino'nun **9. pini**'ne bağlanır.
  - **GND** ve **VCC** bağlantıları uygun şekilde Arduino'ya bağlanmalıdır.

- **Dikey Servo Motor (vertical)**  
  - Servo motorun **kontrol kablosu**: Arduino'nun **10. pini**'ne bağlanır.
  - **GND** ve **VCC** bağlantıları uygun şekilde Arduino'ya bağlanmalıdır.

### LDR (Işık Algılama) Bağlantıları
LDR'ler analog pinlere bağlanarak ışık seviyelerini algılar.

- **Sol Üst LDR (ldrlt)**  
  - LDR'nin bir ucunu **5V**'a, diğer ucunu **Arduino'nun A0 pinine** bağlayın.

- **Sağ Üst LDR (ldrrt)**  
  - LDR'nin bir ucunu **5V**'a, diğer ucunu **Arduino'nun A1 pinine** bağlayın.

- **Sol Alt LDR (ldrld)**  
  - LDR'nin bir ucunu **5V**'a, diğer ucunu **Arduino'nun A2 pinine** bağlayın.

- **Sağ Alt LDR (ldrrd)**  
  - LDR'nin bir ucunu **5V**'a, diğer ucunu **Arduino'nun A3 pinine** bağlayın.

           +-----------------+
          |     Arduino     |
          |                 |
 +--------+--------+--------+--------+
 |        |        |        |        |
(9)      (10)      (A0)     (A1)     (A2)     (A3)

1. **Servo Motor Bağlantıları:**  
   Yatay ve dikey servo motorlar, 9. ve 10. pinlere bağlanmıştır. Bu motorlar, LDR'lerden alınan verilere göre hareket eder.

2. **LDR Bağlantıları:**  
   LDR'ler, ışık yoğunluğunu algılamak için analog pinlere bağlanmıştır. Bu sensörler, çevredeki ışığın yönünü tespit ederek servo motorları yönlendiren sinyalleri oluşturur.

## Kod Açıklamaları

- **Servo Motorlar:**  
  İki servo motor, ışık algılama sonucu yatay ve dikey hareketler yapar. Bu hareketler, üst ve alt sensörler arasındaki farklara göre ayarlanır.

- **LDR Sensörleri:**  
  LDR'ler, ışığın yoğunluğunu ölçer. Her bir LDR, bir yönü algılar (üst, alt, sağ, sol). Bu veriler, servo motorları doğru yönlere hareket ettirmek için kullanılır.

## Projeyi Çalıştırmak

1. Arduino IDE'yi açın.
2. Bu projeye ait Arduino kodunu yükleyin.
3. Bağlantıları yukarıdaki şemaya göre yapın.
4. Arduino'yu bilgisayarınıza bağlayın ve programı yükleyin.
5. Proje, ışık algılamasına göre servo motorları hareket ettirecektir.

## İletişim
Fırat ORHAN ve Yusuf TİMUR


