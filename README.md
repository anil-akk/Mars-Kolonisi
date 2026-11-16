🚀 Mars Kolonisi Yaşam Destek Simülatörü

C programlama dilinin temel kontrol yapıları, döngü mekanizmaları, aritmetik ve mantıksal operatörleri kullanılarak geliştirilmiş metin tabanlı bir hayatta kalma simülasyonudur.

📖 Proje Hakkında

Oyuncu, Mars'taki küçük bir araştırma istasyonunda tek başına mahsur kalmış bir mühendisi yönetir. Temel amaç; kurtarma ekibi ulaşana kadar geçen 15 gün boyunca istasyonun sağlık, enerji, oksijen, su, yedek parça ve modül hasarı dengesini koruyarak hayatta kalmaktır.

⚙️ Özellikler ve Oyun Mekanikleri

Zorluk Seviyeleri: Kolay (K), Normal (N) ve Zor (Z) seçenekleriyle başlangıç kaynakları ve olay zorlukları dinamik olarak değişir.

Dinamik Olasılık Sistemi: srand(time(NULL)) ve rand() % 100 altyapısı ile her keşif ve fırtına olayında üretilen zar değerleri eşik değerlerle karşılaştırılarak ekranda raporlanır.

Zaman ve Gün Döngüsü: Geçerli her 3 hamlede bir (tur % 3 == 0) yeni bir güne geçilir; gün başlarında oksijen tüketilir ve yüksek modül hasarı sağlığı olumsuz etkiler.

Sınırlandırma Koruması: Sağlık, enerji, oksijen ve modül hasarı değerleri her işlem sonrasında 0 ile 100 aralığında tutulur.

🎮 Komut Listesi

Simülasyon büyük/küçük harf duyarsız tek karakterli komutlarla yönetilir:

Komut

İşlev

Açıklama

G

Keşif Görevi

Enerji ve oksijen harcayarak dışarıda su veya yedek parça arar.

O

Oksijen Üretimi

Mod (%) kontrolü ile çift birimli suları oksijene dönüştürür.

T

Tamir

Yedek parça kullanarak hasar seviyesine (hafif, orta, ağır) göre onarım yapar.

D

Durum Raporu

Mevcut kaynakları ve kritik uyarıları listeler (tur harcamaz).

U

Dinlenme

Oksijen tüketerek enerji yeniler; düşük oksijende sağlık kaybı riski taşır.

K

Kum Fırtınası

Zorluğa göre 3, 5 veya 7 tur süren for döngülü fırtına simülasyonunu başlatır.

H

Hava Kilidi Şifresi

Gün sayısına bağlı türetilen harfi 3 deneme hakkıyla çözmeye dayalı do-while bulmacasıdır.

Q

Çıkış

Simülasyonu sonlandırır ve final puan raporunu ekrana basar.

🛠️ Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda derlemek ve çalıştırmak için GCC (veya herhangi bir C derleyicisi) kullanabilirsiniz:

# 1. Depoyu klonlayın
git clone https://github.com/kullanici-adiniz/mars-kolonisi-simulatoru.git

# 2. Proje dizinine geçin
cd mars-kolonisi-simulatoru

# 3. Kodu derleyin
gcc main.c -o mars_simulator

# 4. Programı çalıştırın
./mars_simulator


📊 Puanlama Formülü

Oyun tamamlandığında, kaybedildiğinde veya çıkış yapıldığında performansınız aşağıdaki formülle hesaplanır:


$$\text{Puan} = (\text{Gün} \times 100) + \text{Sağlık} + \text{Oksijen} - \text{Modül Hasarı}$$

📄 Lisans

Bu proje Algoritma ve Programlama dersi kapsamında eğitim amacıyla geliştirilmiştir.
