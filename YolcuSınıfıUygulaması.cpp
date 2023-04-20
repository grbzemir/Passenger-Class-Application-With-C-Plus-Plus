#include<iostream>
#include<string>

using namespace std;

// Yolcu Sınıfı tanımlaması

class Yolcu

{
   
   public:

    string ad;
    string soyad;
    int koltukNo;

    public:

    void yolcuBilgiGir();
    void yolcuBilgiYazdir();
    int  koltukNumarasi();

};

// Yolcu Bilgileri Giriş Fonksiyonu


void Yolcu::yolcuBilgiGir()

 {

    cout<<"Yolcu Ad: ";
    cin>>ad;
    cout<<"Yolcu Soyad:";
    cin>>soyad;
    cout<<"Koltuk Numarasi: ";
    cin>>koltukNo;



 }


// Yolcu Bilgileri Yazdırma Fonksiyonu

 void Yolcu::yolcuBilgiYazdir()

 {

    cout<<"Yolcu Ad: "<<ad<<endl;
    cout<<"Yolcu Soyad: "<<soyad<<endl;
    cout<<"Koltuk Numarasi: "<<koltukNo<<endl;

 }

// Koltuk Numarası Fonksiyonu

 int Yolcu::koltukNumarasi()

  {

    return koltukNo;

  }

// Bilet Sınıfı Uygulaması

 class Bilet

 {

    private:

    int koltukSayisi;
    Yolcu *yolcular; // Yolcu Sınıfından Nesne Oluşturduk

    public:
      
      Bilet(int koltukSayisi);
        ~Bilet();

        bool biletSat(int koltukNo);
        bool biletIptal(int koltukNo);
        void biletSorgula(int koltukNo);


 };

// Bilet Sınıfı Yapıcı Fonksiyonu

  Bilet::Bilet(int koltukSayisi)

  {

    this->koltukSayisi = koltukSayisi;
    yolcular = new Yolcu[koltukSayisi];


  }

// Bilet Sınıfı Yıkıcı Fonksiyonu

    Bilet::~Bilet()
    
    {
    
        delete [] yolcular;
    
    }

// Bilet Satma Fonksiyonu
   
    bool Bilet::biletSat(int koltukNo)
     
     {
            
            if (koltukNo < 1 || koltukNo > koltukSayisi)

            {

                return false;
                
            }

            if (yolcular[koltukNo-1].koltukNumarasi() !=0) // koltuk numarasi 0 a eşit olamaz!

            {

                return false;
                
            }

            yolcular[koltukNo-1].yolcuBilgiGir();

            return true;

     }

// Bilet İptal Fonksiyonu

   bool Bilet::biletIptal(int koltukNo)

    {
        if (koltukNo < 1 || koltukNo > koltukSayisi)

        {

            return false;
            
            
        }

        if (yolcular[koltukNo-1].koltukNumarasi() == 0) // koltuk numarasi 0 a eşit olamaz!

        {

            return false;
            
        }
          
         yolcular[koltukNo-1].yolcuBilgiYazdir();
          yolcular[koltukNo-1] = Yolcu();

        return true;

    }

    // Bilet Sorgulama Fonksiyonu
    

    void Bilet::biletSorgula(int koltukNo)

    {
        cout<<"Koltuklar: "<<endl;

        int i;

        for ( i = 0; i < koltukSayisi; i++) // KAC TANE KOLTUK SAYISI VARSA O KADAR DÖNGÜ İÇİNDE DEVAM ETSİN!

        {

            if (yolcular[i].koltukNumarasi() != 0) // 0 diye koltuk numarasi olamaz !

            {

                cout<<i+1<<".Koltuk-"<<yolcular[i].ad<<" "<<yolcular[i].soyad<<endl;
                
            }

            else

            {

                cout<<i+1<<".Koltuk-Bos"<<endl;
                
            }
            
            
        }
    }

    // Yolcular Trende seyahet edeceği icin bir tren sınıfı oluşturalım.

    class Tren

    {

      private:

      Bilet* bilet; // Bilet Sınıfından Nesne Oluşturduk
      int koltukSayisi;
      int km;

      public:

      Tren(int koltukSayisi, int km);
        ~Tren();

        void biletIslemi();
        void seyahatSonucu();


    };

    // Tren Sınıfı Yapıcı Fonksiyonu

    Tren::Tren(int koltukSayisi , int km)

    {
            
            this->koltukSayisi = koltukSayisi;
            this->km = km;
            bilet = new Bilet(koltukSayisi);
    
    }

    // Tren Sınıfı Yıkıcı Fonksiyonu

    Tren::~Tren()

    {
            
            delete bilet;
    
    }

    // Bilet İşlemleri Fonksiyonu

    void Tren::biletIslemi()

    {
        int secim;
        int koltukNo;

        while(true)

        {
            cout<<"[1]-Bilet Sat"<<endl;
            cout<<"[2]-Bilet Iptal"<<endl;
            cout<<"[3]-Bilet Sorgula"<<endl;
            cout<<"[4]-Cikis"<<endl;
            cout<<"Secim: ";
            cin>>secim;

            if(secim == 1)

            {
                cout<<"Merhabalar Hosgeldiniz Hangi Koltuk Icin Bilet Almak Istersiniz?";
                cin>>koltukNo;

                if (!bilet->biletSat(koltukNo))

                {
                    cout<<"Gecersiz Koltuk Numarasi veya Koltuk Dolu!"<<endl;
                    
                }

            }

                else if (secim == 2)

                {
                    cout<<"Merhabalar Hosgeldiniz Hangi Koltuk Icin Bilet Iptal Etmek Istersiniz?";
                    cin>>koltukNo;

                    if (!bilet->biletIptal(koltukNo))

                    {
                        cout<<"Gecersiz Koltuk Numarasi veya Koltuk Bos!"<<endl;
                        
                        
                    }

                }

                    else if (secim == 3)

                    {
                        bilet->biletSorgula(koltukNo);
                        
                    }

                    else if (secim == 4)

                    {
                        break;
                        
                    }

                    else

                    {
                        cout<<"Gecersiz Secim!"<<endl;
                        
                    }
                    
                }
            }

        
    // Seyehat Sonucu Fonksiyonu

    void Tren::seyahatSonucu()
    
    {
        int toplamKM = km * koltukSayisi;
        cout<<"Seyahat Sonucu Toplam KM: "<<toplamKM<<endl;

    }

    // Main Fonksiyonu

    int main()

    {

        system("color B");
        Tren tren(10, 450); // 10 Koltuklu 450 KMlik bir tren oluşturduk.
        tren.biletIslemi();
        tren.seyahatSonucu();

        return 0;

    }
 