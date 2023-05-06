//Mehmet Samet DURSUN 200201024

#include <stdio.h>
#include <stdlib.h>

struct kayit
{
    int ogrNo;
    int dersKodu;
    int puan;
};

void kayitEkle()
{
    system("cls");
    struct kayit  kyt;
    FILE *bp;
    bp=fopen("proje.bin","ab");
    int i;

    while(1)
    {
        printf("\n\nOgrencinin Numarasini Giriniz:");
        scanf("%d",&kyt.ogrNo);
        printf("\nDers Kodunu Giriniz:");
        scanf("%d",&kyt.dersKodu);
        printf("\nOgrencini Puanini Giriniz:");
        scanf("%d",&kyt.puan);
        fwrite(&kyt,sizeof (struct kayit),1,bp);

        printf("\nYeni Kayit Icin 1'e Basin\n");
        printf("\nMenuye Donmek Icin'0 a Basin\n ");
        scanf("%d",&i);
        if(i==0)
            break;
        else if(i==1)
        {
            system("cls");
            continue;
        }
    }

    fclose(bp);
    indexDosyasiniGuncelle();
    system("cls");
}

void kayitBul()
{
    system("cls");
    FILE *bp;
    bp=fopen("proje.bin","rb");

    struct kayit kyt[100];
    int i=0;
    while(fread(&kyt[i],sizeof(kyt[i]),1,bp))
    {
        i++;
    }

    int no;
    int dersKodu;

    while(1)
    {
        printf("\nGormek Istediginiz Ogrencinin Numarasini Giriniz:");
        scanf("%d",&no);
        printf("\nGormek Istediginiz Ders Kodunu Giriniz:");
        scanf("%d",&dersKodu);
        printf("\nOgrenci No          Ders Kodu           Puan\n");
        printf("----------          ---------           -----\n");

        int j=0;
        for(j ; j<i ; j++)
        {
            if(kyt[j].ogrNo==no && kyt[j].dersKodu==dersKodu)
            {
                printf("   %-20d %-16d %-20d",kyt[j].ogrNo,kyt[j].dersKodu,kyt[j].puan);
                break;
            }
        }
        if(j==i)
        {
            system("cls");
            printf("\nAradiginiz Bilgilerde Bir Ogrenci Bulunmamaktadir Yeniden Yonlendiriliyorsunuz\n\n");
            continue;
        }

        int a;
        printf("\n\nVeri Dosyasindaki %d No'lu Ogrencinin %d No'lu Dersinin Kaydi Gosterilmistir\n\n",no,dersKodu);
        printf("Yeni Arama Yapmak Icin 1'e Basin\n\n");
        printf("Menuye Donmek Icin 0'a Basin\n");
        scanf("%d",&a);
        if(a==1)
        {
            system("cls");
            continue;
        }
        else
            break;
    }

    fclose(bp);
    system("cls");
}

void kayitSil()
{
    system("cls");
    struct kayit kyt[100];
    FILE *bp;
    bp=fopen("proje.bin","rb");
    int i=0;
    while(fread(&kyt[i],sizeof(kyt[i]),1,bp))
    {
        i++;
    }

    fclose(bp);

    int no;
    int dersKodu;

    while(1)
    {
        printf("\nSilmek Istediginiz Ogrencinin Numarasini Giriniz:");
        scanf("%d",&no);
        printf("\nSilmek Istediginiz Dersin Kodunu Giriniz:");
        scanf("%d",&dersKodu);

        int j=0;
        for(j ; j<i ; j++)
        {
            if(kyt[j].ogrNo==no && kyt[j].dersKodu==dersKodu)
                break;
        }

        if(j==i)
        {
            system("cls");
            printf("\nAradiginiz Bilgilerde Bir Ogrenci Bulunmamaktadir Yeniden Yonlendiriliyorsunuz\n\n");
            continue;
        }

        for(int a=j ; a<i ; a++)
        {
            kyt[a].ogrNo=kyt[a+1].ogrNo;
            kyt[a].dersKodu=kyt[a+1].dersKodu;
            kyt[a].puan=kyt[a+1].puan;
        }
        i-=1;

        bp=fopen("proje.bin","wb");

        for(int b=0 ; b<i ; b++)
        {
            fwrite(&kyt[b],sizeof(kyt[b]),1,bp);
        }

        int x;
        printf("\n\nKayit Basariyla Silinmistir\n\n");
        printf("Yeni Kayit Silmek Icin 1'e Basiniz\n\n");
        printf("Menuye Donmek Icin 0'a Basiniz\n");
        scanf("%d",&x);
        if(x==1)
        {
            system("cls");
            continue;
        }
        else
            break;
    }
    fclose(bp);
    indexDosyasiniGuncelle();
    system("cls");
}

void kayitGuncelle()
{
    system("cls");
    FILE *bp;
    bp=fopen("proje.bin","rb");
    struct kayit kyt[100];
    int i=0;

    while(fread(&kyt[i],sizeof(kyt[i]),1,bp))
    {
        i++;
    }

    fclose(bp);

    int no;
    int dersKodu;
    int puan;

    while(1)
    {
        printf("\nNotunu Degistirmek Istediginiz Ogrencinin Numarasini Giriniz:");
        scanf("%d",&no);
        printf("\nDegistirmek Istediginiz Dersin Kodunu Giriniz:");
        scanf("%d",&dersKodu);

        int j=0;
        for(j ; j<i ; j++)
        {
            if(kyt[j].ogrNo==no && kyt[j].dersKodu==dersKodu)
            {
                printf("\nYeni Notu Giriniz:");
                scanf("%d",&puan);
                kyt[j].puan=puan;
                break;
            }
        }

        if(j==i)
        {
            system("cls");
            printf("\nAradiginiz Bilgilerde Bir Ogrenci Bulunmamaktadir Yeniden Yonlendiriliyorsunuz\n\n");
            continue;
        }

        bp=fopen("proje.bin","wb");

        for(int j=0 ; j<i ; j++)
        {
            fwrite(&kyt[j],sizeof(kyt[j]),1,bp);
        }

        int a;
        printf("\n\nNot Basariyla Degistirilmistir\n\n");
        printf("Yeni Not Guncellemek Icin 1'e Basiniz\n\n");
        printf("Menuye Donmek Icin 0'a Basiniz\n");
        scanf("%d",&a);
        if(a==1)
        {
            system("cls");
            continue;
        }
        else
            break;
    }

    fclose(bp);
    indexDosyasiniGuncelle();
    system("cls");
}

void indexDosyasiOlustur()
{
    system("cls");
    struct kayit kyt[100];
    FILE *bp;
    bp=fopen("proje.bin","rb");

    int i=0;
    while(fread(&kyt[i],sizeof(struct kayit),1,bp))
    {
        i++;
    }

    fclose(bp);

    for(int a=0 ; a<i ; a++)
    {
        for(int b=0 ; b<i-1 ; b++)
        {
            if(kyt[b].ogrNo>kyt[b+1].ogrNo)
            {
                int temp1=kyt[b].ogrNo;
                kyt[b].ogrNo=kyt[b+1].ogrNo;
                kyt[b+1].ogrNo=temp1;

                int temp2=kyt[b].dersKodu;
                kyt[b].dersKodu=kyt[b+1].dersKodu;
                kyt[b+1].dersKodu=temp2;

                int temp3=kyt[b].puan;
                kyt[b].puan=kyt[b+1].puan;
                kyt[b+1].puan=temp3;
            }

            if(kyt[b].ogrNo==kyt[b+1].ogrNo)
            {
                if(kyt[b].dersKodu>kyt[b+1].dersKodu)
                {
                    int temp1=kyt[b].dersKodu;
                    kyt[b].dersKodu=kyt[b+1].dersKodu;
                    kyt[b+1].dersKodu=temp1;

                    int temp2=kyt[b].puan;
                    kyt[b].puan=kyt[b+1].puan;
                    kyt[b+1].puan=temp2;
                }
            }
        }
    }

    FILE *fp;
    fp=fopen("proje.txt","w");

    for(int j=0 ; j<i ; j++)
    {
        fwrite(&kyt[j],sizeof(kyt[j]),1,fp);
    }

    fclose(fp);

    printf("\n\nIndex Dosyaniz Olusturulmustur\n\n");
    system("pause");
    system("cls");
}

void indexDosyasiniGuncelle()
{
    struct kayit kyt[100];
    FILE *bp;
    bp=fopen("proje.bin","rb");
    FILE *fp;
    fp=fopen("proje.txt","w");
    int i=0;
    while(fread(&kyt[i],sizeof(struct kayit),1,bp))
    {
        i++;
    }

    for(int a=0 ; a<i ; a++)
    {
        for(int b=0 ; b<i-1 ; b++)
        {
            if(kyt[b].ogrNo>kyt[b+1].ogrNo)
            {
                int temp1=kyt[b].ogrNo;
                kyt[b].ogrNo=kyt[b+1].ogrNo;
                kyt[b+1].ogrNo=temp1;

                int temp2=kyt[b].dersKodu;
                kyt[b].dersKodu=kyt[b+1].dersKodu;
                kyt[b+1].dersKodu=temp2;

                int temp3=kyt[b].puan;
                kyt[b].puan=kyt[b+1].puan;
                kyt[b+1].puan=temp3;
            }

            if(kyt[b].ogrNo==kyt[b+1].ogrNo)
            {
                if(kyt[b].dersKodu>kyt[b+1].dersKodu)
                {
                    int temp1=kyt[b].dersKodu;
                    kyt[b].dersKodu=kyt[b+1].dersKodu;
                    kyt[b+1].dersKodu=temp1;

                    int temp2=kyt[b].puan;
                    kyt[b].puan=kyt[b+1].puan;
                    kyt[b+1].puan=temp2;
                }
            }
        }
    }

    for(int j=0 ; j<i ; j++)
    {
        fwrite(&kyt[j],sizeof(kyt[j]),1,fp);
    }

    fclose(bp);
    fclose(fp);

}

void indexDosyasiniGoster()
{
    system("cls");
    printf("\n OGRENCILER NUMARA SIRASINA GORE GOSTERILIYOR\n\n");
    struct kayit  kyt;
    FILE *fp;
    fp=fopen("proje.txt","r");

    printf("Ogrenci No          Ders Kodu           Puan\n");
    printf("----------          ---------           -----\n");

    while(fread(&kyt,sizeof(kyt),1,fp))
    {
        printf("   %-20d %-16d %-20d\n",kyt.ogrNo,kyt.dersKodu,kyt.puan);
    }

    printf("\n\n");
    system("pause");
    system("cls");
}

void indexDosyasiniSil()
{
    system("cls");
    remove("proje.txt");
    printf("\n\nIndex Dosyasi Silinmistir\n\n\n");
    system("pause");
    system("cls");
}

void veriDosyasiniGoster()
{
    system("cls");
    printf("\n OGRENCILER SISTEME GIRIS SIRASINA GORE GOSTERILIYOR\n\n");
    struct kayit  kyt;
    FILE *bp;
    bp=fopen("proje.bin","rb");

    printf("Ogrenci No          Ders Kodu           Puan\n");
    printf("----------          ---------           -----\n");

    while(fread(&kyt,sizeof(kyt),1,bp))
    {
        printf("   %-20d %-16d %-20d\n",kyt.ogrNo,kyt.dersKodu,kyt.puan);
    }
    bp=fclose(bp);
    printf("\n\n");
    system("pause");
    system("cls");
}

void menu()
{
    system("cls");
    int a;
    while(1)
    {
        printf("\n                                  *******MENU******* \n");
        printf("\n                                     1- Kayit Ekle \n\n");
        printf("                                     2- Kayit Bul\n\n");
        printf("                                     3- Kayit Sil\n\n");
        printf("                                     4- Kayit Guncelle \n\n");
        printf("                                     5- Index Dosyasi Olustur \n\n");
        printf("                                     6- Index Dosyasini Goster \n\n");
        printf("                                     7- Index Dosyasini Sil \n\n");
        printf("                                     8- Veri Dosyasini Goster \n\n");
        printf("                                     0- Islemi Sonlandir \n\n");
        printf("\n                              Yapmak Istediginiz Islemi Seciniz:");
        scanf("%d",&a);
        if(a==0)
        {
            printf("\nIsleminiz Sonlanmistir Tesekkur Ederiz.\n");
            break;
        }
        else if(a==1)
            kayitEkle();
        else if(a==2)
            kayitBul();
        else if(a==3)
            kayitSil();
        else if(a==4)
            kayitGuncelle();
        else if(a==5)
            indexDosyasiOlustur();
        else if(a==6)
            indexDosyasiniGoster();
        else if(a==7)
            indexDosyasiniSil();
        else if(a==8)
            veriDosyasiniGoster();
        else
        {
            printf("\n\n                Gecersiz Sayi Girdiniz Menuye Donmek Icin Herhangi Bir Tusa Basiniz\n\n");
            system("pause");
            system("cls");
        }

    }
}

int main()
{
    menu();
    return 0;
}
