# Lig Fikstür Oluşturma Projesi

Bu proje, bir futbol ligi için çift devreli lig usulüne göre fikstür oluşturma uygulamasıdır. Proje, 19 takımdan oluşan bir lig için 38 hafta boyunca adil bir fikstür oluşturmayı amaçlamaktadır. Her takım, diğer takımlarla hem iç saha hem de deplasmanda birer kez karşılaşacaktır. Takım sayısı tek olduğu için her hafta bir takım maç yapmadan haftayı dinlenecektir.

## Proje Özellikleri

*   Takım isimleri `takimlar.txt` dosyasından okunur.
*   Fikstür çift devreli lig usulü ile oluşturulur ve toplamda 38 hafta sürer.
*   Her hafta 18 takım maç yapar ve 9 maç oynanır. Her hafta 1 takım maç yapmaz ve haftayı boş geçer.
*   Fikstür ekrana yazdırılır ve `fikstur.txt` dosyasına kaydedilir.
*   Program başlangıcında mevcut bir fikstür dosyası varsa okunup gösterilir.
*   Hatalı girişler (boş dosya, eksik takım) kontrol edilerek kullanıcıya uyarı verilir.

## Gereksinimler

*   C Programlama Dili
*   `takimlar.txt` dosyası (19 takımlık güncel liste)

## Kurulum

1.  Bu projeyi GitHub'dan klonlayın.
2.  Gerekli derleyici ve araçları kullanarak projeyi derleyin.
3.  `takimlar.txt` dosyasını proje dizinine ekleyin.

## Kullanım

1.  Derlenmiş programı çalıştırın.
2.  Program, fikstür oluşturma işlemini gerçekleştirecek ve sonuçları ekrana yazdıracaktır.
3.  Oluşturulan fikstür, `fikstur.txt` dosyasına kaydedilecektir.

## Dosya Yapısı
lig-fikstur-projesi/
├── kodlar/             # Proje kodları (C dili)
├── takimlar.txt        # 19 takımlık güncel liste
├── fikstur.txt         # Oluşan fikstür
├── gereksinim_analizi.docx # Gereksinim analizi dokümanı
├── ekran_goruntuleri/   # Örnek çalıştırma sonuçları
└── README.md           # Proje açıklaması ve kullanım talimatları

## Teslim Edilecekler

*   GitHub repository (doğru ve erişilebilir olmalıdır).
*   `takimlar.txt` dosyası (19 takımlık güncel liste)
*   Oluşturulan `fikstur.txt` dosyası
*   Proje kodları (C diliyle yazılmış olarak)
*   Gereksinim analizi dokümanı
*   Ekran görüntüleri ve örnek çalıştırma çıktıları
*   README dosyası (proje açıklaması ve kullanım talimatları ile birlikte)
