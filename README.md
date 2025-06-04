# Otomatik Yemleme Sistemi

Bu proje, Arduino tabanlı otomatik bir evcil hayvan yemleme sistemidir. Sistem, belirli aralıklarla balıkları otomatik olarak besler ve yem seviyesini kontrol eder.

## Özellikler

- Belirli aralıklarla otomatik yemleme
- Yem seviyesi kontrolü
- LCD ekranda saat ve yemleme sayısı gösterimi
- Yem bittiğinde sesli uyarı
- RTC (Gerçek Zaman Saati) entegrasyonu

## Gerekli Malzemeler

- Arduino Uno/Nano
- LCD 16x2
- HC-SR04 Ultrasonik Mesafe Sensörü
- Servo Motor
- DS3231 RTC Modülü
- Buzzer
- Bağlantı kabloları
- Breadboard

## Bağlantılar

### LCD Bağlantıları
- RS: Pin 7
- E: Pin 8
- D4: Pin 9
- D5: Pin 10
- D6: Pin 11
- D7: Pin 12

### Diğer Bağlantılar
- TRIG_PIN: Pin 4
- ECHO_PIN: Pin 3
- BUZZER_PIN: Pin 2
- SERVO_PIN: Pin 6

## Gerekli Kütüphaneler

- Wire.h
- LiquidCrystal.h
- Servo.h
- RTClib.h

## Kurulum

1. Arduino IDE'yi yükleyin
2. Gerekli kütüphaneleri Arduino IDE üzerinden yükleyin
3. Kodu Arduino'ya yükleyin
4. Bağlantıları şemaya göre yapın

## Kullanım

Sistem otomatik olarak çalışmaya başlayacaktır. LCD ekranda:

- Üst satırda saat gösterilir
- Alt satırda yapılan yemleme sayısı gösterilir
- Yem seviyesi düşük olduğunda (13 cm'den fazla mesafe) sistem sesli uyarı verir.

## Özelleştirme

- Yemleme aralığını değiştirmek için `interval` değişkenini düzenleyebilirsiniz
- Servo motor açısını `feedFish()` fonksiyonunda ayarlayabilirsiniz
- Yem seviyesi uyarı mesafesini `getDistance()` fonksiyonunun kullanıldığı yerde değiştirebilirsiniz

## Lisans

Bu proje MIT lisansı altında lisanslanmıştır.

## İletişim

Sorularınız veya önerileriniz için GitHub üzerinden iletişime geçebilirsiniz.

## Ekran Görüntüsü

![Ekran Görüntüsü](https://github.com/meryemnurpala/Automatic-feeding-project/blob/main/ekran_goruntusu.jpg)
