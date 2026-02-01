#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <bitset>
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

class BigInt256{
    public:
        unsigned char* chasl256;
        int len256 = 0;
        void BigCh(char* num, int* currentMemory, int* maxMemory)
        {
            len256 = strlen(num);
            chasl256 = new unsigned char[len256];
            *currentMemory = *currentMemory + len256;
            for(size_t i =0; i<len256; i++)
            {
                chasl256[i] = num[i] - 48;
            }
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
        }
        void nullsleva(int* currentMemory, int* maxMemory)
        {
            unsigned char* pr = new unsigned char[len256 + 1];
            *currentMemory = *currentMemory + len256 + 1;
            pr[0] = 0;
            for(size_t i = 1; i<=len256; i++)
            {
                pr[i] = chasl256[i-1];
            }
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            *currentMemory = *currentMemory - len256;
            delete[] chasl256;
            chasl256 = NULL;
            len256 = len256 + 1;
            chasl256 = new unsigned char[len256];
            *currentMemory = *currentMemory + len256;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            for(size_t i = 0; i<len256; i++)
            {
                chasl256[i] = pr[i];
            }
            *currentMemory = *currentMemory - len256 - 1;
            delete[] pr;
            pr = NULL;
        }
        int reallen256()
        {
            int al=0;
            size_t i=0;
            while(chasl256[i]==0)
            {
                al++;
                i++;
            }
            al = len256 - al;
            return al;
        }
        void obnul256(int* currentMemory, int* maxMemory)
        {
            *currentMemory = *currentMemory - len256 + 1;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            len256 = 1;
            chasl256 = new unsigned char[1];
            for(size_t i=0; i<len256; i++)
            {
                chasl256[i]=0;
            }
        }
        void edin256(int* currentMemory, int* maxMemory)
        {
            *currentMemory = *currentMemory - len256 + 1;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            len256 = 1;
            chasl256 = new unsigned char[1];
            for(size_t i=0; i<len256; i++)
            {
                chasl256[i]=1;
            }
        }
        void Urav256(unsigned char* A, int lena, int* currentMemory, int* maxMemory)
        {
            *currentMemory = *currentMemory - len256 + lena;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            len256=lena;
            chasl256 = new unsigned char[lena];
            for(size_t i =0; i<len256; i++)
            {
                chasl256[i] = A[i];
            }
        }
        void UravSl256(unsigned char* A, int lena, int b, int* currentMemory, int* maxMemory)
        {
            *currentMemory = *currentMemory + 1;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            chasl256 = new unsigned char[len256 + 1];
            len256 = lena + 1;
            chasl256[0] = b;
            for(size_t i=1; i<(lena+1); i++)
            {
                chasl256[i] = A[i-1];
            }
        }
        void UravSl(unsigned char* A, int lena, int* currentMemory, int* maxMemory)
        {
            *currentMemory = *currentMemory - len256 + lena;
            if(*currentMemory > *maxMemory)
            {
                *maxMemory = *currentMemory;
            }
            len256=lena;
            chasl256 = new unsigned char[lena];
            chasl256[0]=A[0]/10;
            chasl256[1]=A[0]-10;
            for(size_t i = (lena-2); i>0; i--)
            {
                chasl256[i+1] = A[i];
            }
        }
        void print256()
        {
            printf("\n");
            for(size_t i=0; i<len256; i++)
            {
                printf("%hhu.", chasl256[i]);
            }
            printf("\n");
        }
        void print()
        {
            for(size_t i=0; i<len256; i++)
            {
                printf("%hhu", chasl256[i]);
            }
            printf("\n");
        }
        void clean256(int* currentMemory)
        {
            *currentMemory = *currentMemory - len256;
            delete[] chasl256;
            chasl256 = NULL;
            len256 = 0;
        }

};

unsigned char check256(BigInt256* B, int il)
{
    if((il<0)||(il>=B->len256)) return 0;
    else return B->chasl256[il];
}

void antinull256(BigInt256* C, int* currentMemory, int* maxMemory)
{
    bool pruv=true;
    for(size_t i=0; i < C->len256; i++)
    {
        if(C->chasl256[i]!=0) pruv=false;
    }
    if((C->chasl256[0]==0)&&(C->len256!=1)&&(!pruv))
    {
        int a=0;
        size_t i=0;
        while(C->chasl256[i]==0)
        {
            a++;
            i++;
        }
        i = C->len256;
        a = C->len256 - a;
        *currentMemory = *currentMemory + a;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        unsigned char* B = new unsigned char[a];
        for(size_t im = a; im>0; im--)
        {
            B[im-1] = C->chasl256[i-1];
            i--;
        }
        C->Urav256(B, a, currentMemory, maxMemory);
        *currentMemory = *currentMemory - a;
        delete[] B;
    }
    else if(pruv)
    {
        C->obnul256(currentMemory, maxMemory);
    }
}

void slojenie256(BigInt256* C, BigInt256* A, int* currentMemory, int* maxMemory)
{
    int bt=0;
    if(C->len256 >= A->len256)
    {
        int a;
        a=C->len256;
        *currentMemory = *currentMemory + a + 1;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        unsigned char* B = new unsigned char[a+1];
        for(int i=(C->len256-1); i>=0; i--) //1111 - 999
        {
            int temp = C->chasl256[i] + bt + check256(A, i - (C->len256 - A->len256));
            if ((temp > 255)&&(i!=0))
            {
                B[i] = temp - 256;
                bt = 1;
            }
            else if((temp > 255)&&(i==0))
            {
                B[i] = temp - 256;
                bt = 1;
                C->UravSl256(B, a, bt, maxMemory, currentMemory);
            }
            else if(i==0)
            {
                B[i] = temp;
                bt = 0;
                C->Urav256(B, a, maxMemory, currentMemory);
            }
            else
            {
                B[i] = temp;
                bt = 0;
            }

        }
        *currentMemory = *currentMemory - a - 1;
        delete[] B;
        B == NULL;
    }
    else
    {
        int a;
        a=A->len256;
        *currentMemory = *currentMemory + a;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        unsigned char* B = new unsigned char[a];
        for(int i=(A->len256 - 1); i>=0; i--) //1111 - 999
        {
            int temp = A->chasl256[i] + bt + check256(C, i - (A->len256 - C->len256));
            if ((temp > 255)&&(i!=0))
            {
                B[i] = temp - 256;
                bt = 1;
            }
            else if((temp > 255)&&(i==0))
            {
                B[i] = temp - 256;
                bt = 1;
                C->UravSl256(B, a, bt, currentMemory, maxMemory);
            }
            else if(i==0)
            {
                B[i] = temp;
                bt = 0;
                C->Urav256(B, a, currentMemory, maxMemory);
            }
            else
            {
                B[i] = temp;
                bt = 0;
            }

        }
        *currentMemory = *currentMemory - a;
        delete[] B;
        B == NULL;
    }
}

void vichitanie256(BigInt256* C, BigInt256* B, int* currentMemory, int* maxMemory) //!!!!!!!!!!! only if C->chasl >= B->chasl
{
    int bt = 0;
    unsigned char* A;
    int a = C->len256;
    *currentMemory = *currentMemory + C->len256;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    A = new unsigned char[C->len256];
    for(size_t i=0; i<C->len256; i++)
    {
        A[i]=0;
    }
    for(int im = (C->len256 - 1); im>=0; im--)
    {
        int temp = C->chasl256[im] - bt - check256(B, im - (C->len256 - B->len256));
        if (temp < 0)
        {
            temp = temp + 256;
            bt = 1;
        }
        else
        {
            bt = 0;
        }

        A[im]= temp;
    }
    C->Urav256(A, C->len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - C->len256;
    delete[] A;
    A = NULL;
}

void umnojnac256(BigInt256* C, int f, int* currentMemory, int* maxMemory)
{
    unsigned char* Pr;
    int a = C->len256 + 1;
    *currentMemory = *currentMemory + a;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    Pr = new unsigned char[C->len256 + 1];
    for(size_t i=0; i<(C->len256+1); i++)
    {
        Pr[i]=0;
    }
    size_t im = C->len256 + 1;
    for(size_t i=(C->len256); i>0; i--)
    {
        int y = Pr[im-1] + (C->chasl256[i - 1] * f)%256;
        Pr[im-1] = y;
        Pr[im-2] = y/256;
        if((im - 2)>=0)
        {
            int r = Pr[im-2] + (C->chasl256[i - 1] * f)/256;
            Pr[im-2] = r;
        }
        im--;
    }
    C->Urav256(Pr, C->len256 + 1, currentMemory, maxMemory);
    if(C->chasl256[0]==0)
    {
        antinull256(C, currentMemory, maxMemory);
    }
    *currentMemory = *currentMemory - a;
    delete[] Pr;
    Pr == NULL;
}

void umnojna256(BigInt256* C, int f, int* currentMemory, int* maxMemory)
{
    unsigned char* Pr;
    int im = C->len256 + f;
    *currentMemory = *currentMemory + im;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    Pr = new unsigned char[im];
    for(size_t i=0; i<(im); i++)
    {
        Pr[i]=0;
    }
    for(size_t i=0; i<(C->len256); i++)
    {
        if(i<im) Pr[i]=C->chasl256[i];
        else i=C->len256;
    }
    C->Urav256(Pr, C->len256 + f, currentMemory, maxMemory);
    *currentMemory = *currentMemory - im;
    delete[] Pr;
    Pr = NULL;
}

void umnoj256(BigInt256* C, BigInt256* A, int* currentMemory, int* maxMemory)
{
    int a;
    a=C->len256 + A->len256;
    *currentMemory = *currentMemory + 4;
    BigInt256 B;
    B.len256 = a;
    B.obnul256(currentMemory, maxMemory);
    *currentMemory = *currentMemory + 4;
    BigInt256 Pr;
    int st = -1;

    for(int i=A->len256-1; i>=0; i--)
    {
        int f = A->chasl256[i];
        st++;
        Pr.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);
        umnojnac256(&Pr, f, currentMemory, maxMemory);
        umnojna256(&Pr, st, currentMemory, maxMemory);
        slojenie256(&B, &Pr, currentMemory, maxMemory);
    }
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    C->Urav256(B.chasl256, B.len256, currentMemory, maxMemory);
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    B.clean256(currentMemory);
    *currentMemory = *currentMemory - 8;
    Pr.clean256(currentMemory);
}

void udvoenie256(BigInt256* C, int* currentMemory, int* maxMemory)
{
    umnojnac256(C, 2, currentMemory, maxMemory);
}

void Polovina256(BigInt256* A, int* currentMemory, int* maxMemory)
{
    unsigned char* B;
    int a = A->len256;
    *currentMemory = *currentMemory + a;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    B = new unsigned char[A->len256];
    for(size_t i=0; i<A->len256; i++)
    {
        B[i]=0;
    }
    for(int im = (A->len256 - 1); im>=0; im--)
    {
        int temp = A->chasl256[im]/2;
        B[im]= temp;
        if(((im+1)!=A->len256)&&(A->chasl256[im]%2==1))
        {
            B[im+1]=B[im + 1] + 128;
        }
    }

    A->Urav256(B, A->len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - a;
    delete[] B;
    B == NULL;
}

bool ravenstv256(BigInt256* A, BigInt256* B)
{
    int al=0;
    int ad=0;
    int bl=0;
    int bd=0;
    size_t i=0;
    while(A->chasl256[i]==0)
    {
        ad++;
        al++;
        i++;
    }
    al = A->len256 - al;
    i=0;
    while(B->chasl256[i]==0)
    {
        bd++;
        bl++;
        i++;
    }
    bl = B->len256 - bl;
    if(al > bl) return false;
    else if(al < bl) return false;
    for(size_t i=0; i<al; i++)
    {
        if(A->chasl256[i+ad] > B->chasl256[i+bd])
        {
            return false;
        }
        if(A->chasl256[i+ad] < B->chasl256[i+bd])
        {
            return false;
        }

    }
    return true;
}

bool sravnenie1256(BigInt256* A, BigInt256* B)
{
    int al=0;
    int ad=0;
    int bl=0;
    int bd=0;
    size_t i=0;
    while(A->chasl256[i]==0)
    {
        ad++;
        al++;
        i++;
    }
    al = A->len256 - al;
    i=0;
    while(B->chasl256[i]==0)
    {
        bd++;
        bl++;
        i++;
    }
    bl = B->len256 - bl;
    if(al > bl) return false;
    else if(al < bl) return true;
    for(size_t i=0; i<al; i++)
    {
        if(A->chasl256[i+ad] > B->chasl256[i+bd])
        {
            return false;
        }
        if(A->chasl256[i+ad] < B->chasl256[i+bd])
        {
            return true;
        }

    }
    return true;
}

bool sravnenie2256(BigInt256* A, BigInt256* B, int* currentMemory, int* maxMemory)
{
    BigInt256 Ad;
    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    Ad.Urav256(A->chasl256, A->len256, currentMemory, maxMemory);
    udvoenie256(&Ad, currentMemory, maxMemory);
    int al=0;
    int an=0;
    int bl=0;
    int bd=0;
    size_t i=0;
    while(Ad.chasl256[i]==0)
    {
        al++;
        an++;
        i++;
    }
    al = Ad.len256 - al;
    i=0;
    while(B->chasl256[i]==0)
    {
        bl++;
        bd++;
        i++;
    }
    bl = B->len256 - bl;
    if((al < bl))
    {
        Ad.clean256(currentMemory);
        *currentMemory = *currentMemory - 4;
        return true;

    }
    else if((al > bl))
    {
        Ad.clean256(currentMemory);
        *currentMemory = *currentMemory - 4;
        return false;
    }
    for(size_t i=0; i < al; i++)
    {
        if(Ad.chasl256[i+an] > B->chasl256[i+bd])
        {
            Ad.clean256(currentMemory);
            *currentMemory = *currentMemory - 4;
            return false;
        }
        if(Ad.chasl256[i+an] < B->chasl256[i+bd])
        {
            Ad.clean256(currentMemory);
            *currentMemory = *currentMemory - 4;
            return true;
        }
    }
    Ad.clean256(currentMemory);
    *currentMemory = *currentMemory - 4;
    return true;
}

bool sravnenie3256(BigInt256* A, BigInt256* B)
{
    int al=0;
    int ad=0;
    int bl=0;
    int bd=0;
    size_t i=0;
    while(A->chasl256[i]==0)
    {
        ad++;
        al++;
        i++;
    }
    al = A->len256 - al;
    i=0;
    while(B->chasl256[i]==0)
    {
        bd++;
        bl++;
        i++;
    }
    bl = B->len256 - bl;
    if((al > bl))
    {
        return true;
    }
    else if((al < bl))
    {
        return false;
    }
    for(size_t i=0; i < al; i++)
    {
        if((A->chasl256[i+ad] < B->chasl256[i+bd]))
        {
            return false;
        }
        if(A->chasl256[i+ad] > B->chasl256[i+bd])
        {
            return true;
        }
    }

    return true;
}

void ost256(BigInt256* BigA, BigInt256* BigB, int* currentMemory, int* maxMemory)
{

    int chas=0;
    int step=0;

    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 BigD;

    do
    {
        BigD.Urav256(BigB->chasl256, BigB->len256, currentMemory, maxMemory);
        int raz = ((BigA->reallen256())*log2(10) - (BigD.reallen256())*log2(10));
        if(raz!=1)
        {
            for(int i=0; i<raz; i++)
            {
                if(sravnenie2256(&BigD, BigA, currentMemory, maxMemory))
                {
                    udvoenie256(&BigD, currentMemory, maxMemory);
                }
            }
        }
        while((sravnenie1256(&BigD, BigA))&&(sravnenie2256(&BigD, BigA, currentMemory, maxMemory)))
        {
            udvoenie256(&BigD, currentMemory, maxMemory);
        }
        vichitanie256(BigA, &BigD, currentMemory, maxMemory);
    } while(sravnenie3256(BigA, BigB));
    *currentMemory = *currentMemory - 4;
    BigD.clean256(currentMemory);
}

void umnojpomod256(BigInt256* C, BigInt256* A, BigInt256* B, int* currentMemory, int* maxMemory)
{
    umnoj256(C, A, currentMemory, maxMemory);
    if(!sravnenie1256(C, B))
    {
        ost256(C, B, currentMemory, maxMemory);
    }
    if(C->chasl256[0]==0)
    {
        antinull256(C, currentMemory, maxMemory);
    }
}

void Sred256(BigInt256* A, BigInt256* B, BigInt256* Sredn, int* currentMemory, int* maxMemory)
{
    Sredn->Urav256(A->chasl256, A->len256, currentMemory, maxMemory);

    slojenie256(Sredn, B, currentMemory, maxMemory);

    Polovina256(Sredn, currentMemory, maxMemory);

}

void Kvad256(BigInt256* C, int* currentMemory, int* maxMemory)
{
    int a;
    a=2*C->len256;
    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 B;
    B.len256 = a;
    B.obnul256(currentMemory, maxMemory);
    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 Pr;
    int st = -1;

    for(int i=C->len256-1; i>=0; i--)
    {
        int f = C->chasl256[i];
        st++;
        Pr.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);
        umnojnac256(&Pr, f, currentMemory, maxMemory);
        umnojna256(&Pr, st, currentMemory, maxMemory);
        slojenie256(&B, &Pr, currentMemory, maxMemory);
    }
    C->Urav256(B.chasl256, B.len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - 8;
    B.clean256(currentMemory);
    Pr.clean256(currentMemory);
}

int stepenpomod256(BigInt256* C, BigInt256* A, BigInt256* B, int* currentMemory, int* maxMemory)
{
    *currentMemory = *currentMemory + 8;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 D;
    BigInt256 odin;
    odin.edin256(currentMemory, maxMemory);
    D.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);
    if((A->chasl256[A->len256 - 1]%2==0)&&(A->reallen256()!=0))
    {
        umnojpomod256(&D, C, B, currentMemory, maxMemory);
        Polovina256(A, currentMemory, maxMemory);
        C->Urav256(D.chasl256, D.len256, currentMemory, maxMemory);
        if((A->reallen256()==1)&&(A->chasl256[A->len256 - 1]==1))
        {
            return 0;
        }
        while(!((A->reallen256()==1)&&(A->chasl256[A->len256 - 1]==1)))
        {
            umnojpomod256(C, &D, B, currentMemory, maxMemory);
            vichitanie256(A, &odin, currentMemory, maxMemory);
        }
    }
    else if(A->chasl256[A->len256 - 1]%2==1)
    {
        *currentMemory = *currentMemory + 4;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        BigInt256 Rez;
        Rez.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);
        umnojpomod256(&D, C, B, currentMemory, maxMemory);
        Polovina256(A, currentMemory, maxMemory);
        C->Urav256(D.chasl256, D.len256, currentMemory, maxMemory);
        while(!((A->reallen256()==1)&&(A->chasl256[A->len256 - 1]==1)))
        {
            umnojpomod256(C, &D, B, currentMemory, maxMemory);
            vichitanie256(A, &odin, currentMemory, maxMemory);
        }
        umnojpomod256(C, &Rez, B, currentMemory, maxMemory);
        *currentMemory = *currentMemory - 4;
        Rez.clean256(currentMemory);
    }
    *currentMemory = *currentMemory - 8;
    D.clean256(currentMemory);
    odin.clean256(currentMemory);
}

bool prov1256(BigInt256* Maxx, BigInt256* Minn, int* currentMemory, int* maxMemory)
{
    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 Pr;
    Pr.Urav256(Maxx->chasl256, Maxx->len256, currentMemory, maxMemory);
    vichitanie256(&Pr, Minn, currentMemory, maxMemory);

    antinull256(&Pr, currentMemory, maxMemory);
    if((Pr.len256==1)&&(Pr.chasl256[0]==1))
    {
        *currentMemory = *currentMemory - 4;
        Pr.clean256(currentMemory);
        return 1;
    }
    else
    {
        *currentMemory = *currentMemory - 4;
        Pr.clean256(currentMemory);
        return 0;
    }
}

void KvadKor256(BigInt256* C, int* currentMemory, int* maxMemory)
{
    *currentMemory = *currentMemory + 16;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 Maxx;
    BigInt256 Minn;
    BigInt256 Sr;
    BigInt256 Srpr;

    Minn.obnul256(currentMemory, maxMemory);
    Maxx.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);

    while(!prov1256(&Maxx, &Minn, currentMemory, maxMemory))
    {
        Sr.obnul256(currentMemory, maxMemory);
        Sred256(&Maxx, &Minn, &Sr, currentMemory, maxMemory);

        Srpr.Urav256(Sr.chasl256, Sr.len256, currentMemory, maxMemory);
        Kvad256(&Srpr, currentMemory, maxMemory);
        bool a = sravnenie1256(&Srpr, C);
        if(a) Minn.Urav256(Sr.chasl256, Sr.len256, currentMemory, maxMemory);
        else Maxx.Urav256(Sr.chasl256, Sr.len256, currentMemory, maxMemory);


    }
    C->Urav256(Minn.chasl256, Minn.len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - 16;
    Maxx.clean256(currentMemory);
    Minn.clean256(currentMemory);
    Sr.clean256(currentMemory);
    Srpr.clean256(currentMemory);
}

unsigned long long int perevodvstan256(BigInt256* C)
{
    unsigned long long int f = 0;
    unsigned long long int it = 1;
    for(int i = C->len256 - 1; i>=0; i--)
    {
        f = f + C->chasl256[i]*it;
        it = it*256;
    }
    return f;
}

void writeArrayToFile(const unsigned char* A, int lena, std::ofstream& outFile)
{
    for (size_t i = 0; i < lena; ++i)
    {
        outFile << std::setw(3) << std::setfill('0') << static_cast<int>(A[i]);
    }
    outFile << std::endl;
}

bool readArrayFromFile(std::ifstream& inFile, unsigned char* A, int* lena)
{
    std::string line;

    if (std::getline(inFile, line))
    {
        *lena = line.length() / 3;
        for (size_t i = 0; i < *lena; ++i)
        {
            std::string numberStr = line.substr(i * 3, 3);
            int number = std::stoi(numberStr);
            A[i] = static_cast<unsigned char>(number);
        }
        return true;
    }

    *lena = 0;
    return false;
}

void incr256(BigInt256* A, int* currentMemory, int* maxMemory)
{
    int bt = 1;
    int a;
    a=A->len256;


    for(int i=(a-1); i>=0; i--) //1111 - 999
    {
        int temp = A->chasl256[i] + bt;
        if ((temp > 255)&&(i!=0))
        {
            A->chasl256[i] = temp - 256;
            bt = 1;
        }
        else if((temp > 255)&&(i==0))
        {
            A->chasl256[i] = temp - 256;
            bt = 1;
            A->UravSl256(A->chasl256, a, bt, maxMemory, currentMemory);
        }
        else if(i==0)
        {
            A->chasl256[i] = temp;
            bt = 0;
        }
        else
        {
            A->chasl256[i] = temp;
            bt = 0;
        }
    }
}

bool gelshen256(BigInt256* A, BigInt256* B, BigInt256* P, bool* otv, int* currentMemory, int* maxMemory)
{
    std::ofstream outFile("output.txt", std::ios::trunc);
    if (!outFile)
    {
        std::cerr << "Error of file opening!" << std::endl;
        return 1;
    }

    *currentMemory = *currentMemory + 12;
    BigInt256 M;
    BigInt256 K;
    BigInt256 Ed;
    Ed.edin256(currentMemory, maxMemory);
    M.Urav256(P->chasl256, P->len256, currentMemory, maxMemory);
    KvadKor256(&M, currentMemory, maxMemory);
    slojenie256(&M, &Ed, currentMemory, maxMemory);
    if(M.chasl256[0]==0)
    {
        antinull256(&M, currentMemory, maxMemory);
    }
    K.Urav256(M.chasl256, M.len256, currentMemory, maxMemory);

    unsigned long long int f = perevodvstan256(&M);
    *currentMemory = *currentMemory + 4;
    BigInt256 fsch;
    fsch.edin256(currentMemory, maxMemory);

    *currentMemory = *currentMemory + 4;
    BigInt256 Isch;
    Isch.obnul256(currentMemory, maxMemory);

    *currentMemory = *currentMemory + 4;
    BigInt256 Jsch;
    Jsch.obnul256(currentMemory, maxMemory);

    *currentMemory = *currentMemory + 4;
    BigInt256 Rad;
    Rad.Urav256(B->chasl256, B->len256, currentMemory, maxMemory);

    while(!ravenstv256(&fsch, &M))
    {
        umnojpomod256(&Rad, A, P, currentMemory, maxMemory);
        writeArrayToFile(Rad.chasl256, Rad.len256, outFile);
        slojenie256(&fsch, &Ed, currentMemory, maxMemory);
    }

    Rad.obnul256(currentMemory, maxMemory);

    *currentMemory = *currentMemory + 4;
    BigInt256 Ast;
    Ast.Urav256(A->chasl256, A->len256, currentMemory, maxMemory);
    if(M.chasl256[0]==0)
    {
        antinull256(&M, currentMemory, maxMemory);
    }
    *currentMemory = *currentMemory +4;
    BigInt256 Mpr;
    Mpr.Urav256(M.chasl256, M.len256, currentMemory, maxMemory);

    stepenpomod256(&Ast, &Mpr, P, currentMemory, maxMemory);

    *currentMemory = *currentMemory + 4;
    BigInt256 Arad;
    Arad.edin256(currentMemory, maxMemory);

    bool bo = FALSE;

    outFile.close();
    std::ifstream inFile("output.txt");
    if (!inFile)
    {
        std::cerr << "Error of file opening!" << std::endl;
        return 1;
    }

    while(!ravenstv256(&Isch, &M))
    {
        umnojpomod256(&Arad, &Ast, P, currentMemory, maxMemory);
        Sleep(0);

        inFile.clear();
        inFile.seekg(0);

        while(!ravenstv256(&Jsch, &M))
        {

            readArrayFromFile(inFile, Rad.chasl256, &Rad.len256);
            bo = ravenstv256(&Arad, &Rad);
            if(bo == TRUE)
            {
                incr256(&Isch, currentMemory, maxMemory);
                incr256(&Jsch, currentMemory, maxMemory);

                umnoj256(&Isch, &M, currentMemory, maxMemory);
                vichitanie256(&Isch, &Jsch, currentMemory, maxMemory);
                A->Urav256(Isch.chasl256, Isch.len256, currentMemory, maxMemory);
                *currentMemory = *currentMemory - 40;
                M.clean256(currentMemory);
                K.clean256(currentMemory);
                Ed.clean256(currentMemory);
                Rad.clean256(currentMemory);
                Ast.clean256(currentMemory);
                Arad.clean256(currentMemory);
                fsch.clean256(currentMemory);
                Isch.clean256(currentMemory);
                Jsch.clean256(currentMemory);
                Mpr.clean256(currentMemory);
                inFile.close();
                return 0;
            }
            incr256(&Jsch, currentMemory, maxMemory);
            Rad.obnul256(currentMemory, maxMemory);

        }
        Jsch.obnul256(currentMemory, maxMemory);
        incr256(&Isch, currentMemory, maxMemory);

    }

    inFile.close();
    printf("Nope");
    *currentMemory = *currentMemory - 40;
    M.clean256(currentMemory);
    K.clean256(currentMemory);
    Ed.clean256(currentMemory);
    Rad.clean256(currentMemory);
    Ast.clean256(currentMemory);
    Arad.clean256(currentMemory);
    fsch.clean256(currentMemory);
    Isch.clean256(currentMemory);
    Jsch.clean256(currentMemory);
    Mpr.clean256(currentMemory);
    *otv = FALSE;
    return 0;
}

void umnojnades(BigInt256* C, int f, int* currentMemory, int* maxMemory)
{
    unsigned char* Pr;
    int im = C->len256 + f;
    *currentMemory = *currentMemory + im;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    Pr = new unsigned char[im];
    for(size_t i=0; i<(im); i++)
    {
        Pr[i]=0;
    }
    for(size_t i=0; i<(C->len256); i++)
    {
        if(i<im) Pr[i]=C->chasl256[i];
        else i=C->len256;
    }
    C->Urav256(Pr, C->len256 + f, currentMemory, maxMemory);
    *currentMemory = *currentMemory - im;
    delete[] Pr;
    Pr = NULL;
}

void Polovina(BigInt256* A, int* currentMemory, int* maxMemory)
{
    unsigned char* B;
    int a = A->len256;
    *currentMemory = *currentMemory + a;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    B = new unsigned char[A->len256];
    for(size_t i=0; i<A->len256; i++)
    {
        B[i]=0;
    }
    for(int im = (A->len256 - 1); im>=0; im--)
    {
        int temp = A->chasl256[im]/2;
        B[im]= temp;
        if(((im+1)!=A->len256)&&(A->chasl256[im]%2==1))
        {
            B[im+1]=B[im + 1] + 5;
        }
    }

    A->Urav256(B, A->len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - a;
    delete[] B;
    B == NULL;
}

int deleniedesna256(BigInt256* A, int* currentMemory, int* maxMemory)
{
    int ostat = 0;
    for(int i=0; i<8; i++)
    {
        ostat = ostat + ((A->chasl256[A->len256 - 1]%2) * pow(2, i));
        Polovina(A, currentMemory, maxMemory);
    }
    return ostat;
}

void perevodv256(BigInt256* A, int* currentMemory, int* maxMemory)
{
    if(A->len256%2==1)
    {
        A->nullsleva(currentMemory, maxMemory);
    }
    *currentMemory = *currentMemory + 4 + 1;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 B;
    B.chasl256 = new unsigned char[1];
    B.len256 = 1;
    B.chasl256[B.len256-1] = A->chasl256[A->len256 - 1] + (A->chasl256[A->len256 - 2] * 10);
    *currentMemory = *currentMemory + 4;
    if(*currentMemory > *maxMemory)
    {
        *maxMemory = *currentMemory;
    }
    BigInt256 Pr;
    for(int i=3; i<(A->len256+1); i=i+2)
    {
        Pr.len256 = 2;
        *currentMemory = *currentMemory + 2;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        Pr.chasl256 = new unsigned char[2];
        Pr.chasl256[1] = A->chasl256[A->len256 - i];
        Pr.chasl256[0] = A->chasl256[A->len256 - i - 1];
        umnojnades(&Pr, i-1, currentMemory, maxMemory);
        int raz;
        if((Pr.chasl256[1] + Pr.chasl256[0]*10)>=3) raz = (i-1)/2;
        else raz = ((i-1)/2)-1;
        *currentMemory = *currentMemory + 1;
        if(*currentMemory > *maxMemory)
        {
            *maxMemory = *currentMemory;
        }
        unsigned char* rez = new unsigned char[raz+1];
        for(int it=0; it<raz; it++)
        {
            int t = deleniedesna256(&Pr, currentMemory, maxMemory);
            rez[raz-it] = t;
        }
        antinull256(&Pr, currentMemory, maxMemory);
        rez[0] = check256(&Pr, Pr.len256-1) + check256(&Pr, Pr.len256-2)*10 + check256(&Pr, Pr.len256-3)*100;
        Pr.Urav256(rez, raz+1, currentMemory, maxMemory);
        slojenie256(&B, &Pr, currentMemory, maxMemory);
        Pr.clean256(currentMemory);
        *currentMemory = *currentMemory - 1;
        delete[] rez;
        rez == NULL;
    }
    A->Urav256(B.chasl256, B.len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - B.len256;
    B.clean256(currentMemory);
}


void slojenie(BigInt256* C, BigInt256* A, int* currentMemory, int* maxMemory)
{
    int bt=0;
    if(C->len256 >= A->len256)
    {
        int a;
        a=C->len256;
        *currentMemory = *currentMemory + a;
        unsigned char* B = new unsigned char[a];
        for(int i=(C->len256 - 1), ia=(A->len256 - 1); i>=0; i--, ia--) //1111 - 999
        {
            int temp = C->chasl256[i] + bt + check256(A, i - (C->len256 - A->len256));
            if ((temp > 9)&&(i!=0))
            {
                B[i] = temp - 10;
                bt = 1;
            }
            else
            {
                B[i] = temp;
                bt = 0;

            }

        }
        if(B[0]>9) C->UravSl(B, a+1, currentMemory, maxMemory);
        else C->Urav256(B, a, currentMemory, maxMemory);
        *currentMemory = *currentMemory - a;
        delete[] B;
        B == NULL;
    }
    else
    {
        int a;
        a=A->len256;
        *currentMemory = *currentMemory + a;
        unsigned char* B = new unsigned char[a];
        for(int i=(A->len256 - 1), ia=(C->len256 - 1); i>=0; i--, ia--) //1111 - 999
        {
            int temp = A->chasl256[i] + bt + check256(C, i - (A->len256 - C->len256));
            if ((temp > 9)&&(i!=0))
            {
                B[i] = temp - 10;
                bt = 1;
            }
            else
            {
                B[i] = temp;
                bt = 0;
            }

        }
        if(B[0]>9) C->UravSl(B, a+1, currentMemory, maxMemory);
        else C->Urav256(B, a, currentMemory, maxMemory);
        *currentMemory = *currentMemory - a;
        delete[] B;
        B == NULL;
    }
}


void umnojnac(BigInt256* C, int f, int* currentMemory, int* maxMemory)
{
    unsigned char* Pr;
    int a = C->len256 + 1;
    *currentMemory = *currentMemory + C->len256 + 1;
    Pr = new unsigned char[C->len256 + 1];
    for(size_t i=0; i<(C->len256+1); i++)
    {
        Pr[i]=0;
    }
    size_t im = C->len256 + 1;
    for(size_t i=(C->len256); i>0; i--)
    {
        Pr[im-1] = Pr[im-1] + (C->chasl256[i - 1] * f)%10;
        if((im - 2)>=0) Pr[im-2] = Pr[im-2] + (C->chasl256[i - 1] * f)/10;
        im--;
    }
    C->Urav256(Pr, C->len256 + 1, currentMemory, maxMemory);
    if(C->chasl256[0]==0)
    {
        antinull256(C, currentMemory, maxMemory);
    }
    *currentMemory = *currentMemory - C->len256 - 1;
    delete[] Pr;
    Pr == NULL;
}

void umnoj(BigInt256* C, BigInt256* A, int* currentMemory, int* maxMemory)
{
    int a;
    a=C->len256 + A->len256;
    *currentMemory = *currentMemory + 4;
    BigInt256 B;
    B.len256 = a;
    B.obnul256(currentMemory, maxMemory);
    *currentMemory = *currentMemory + 4;
    BigInt256 Pr;
    int st = -1;

    for(int i=A->len256-1; i>=0; i--)
    {
        int f = A->chasl256[i];
        st++;
        Pr.Urav256(C->chasl256, C->len256, currentMemory, maxMemory);
        umnojnac(&Pr, f, currentMemory, maxMemory);
        umnojnades(&Pr, st, currentMemory, maxMemory);
        slojenie(&B, &Pr, currentMemory, maxMemory);
    }
    C->Urav256(B.chasl256, B.len256, currentMemory, maxMemory);
    *currentMemory = *currentMemory - 8;
    B.clean256(currentMemory);
    Pr.clean256(currentMemory);
}

void perevodv10(BigInt256* A, int* currentMemory, int* maxMemory)
{
    *currentMemory = *currentMemory + 16;
    BigInt256 Summ;
    BigInt256 Pr;
    BigInt256 Step256;
    BigInt256 DPSH;

    *currentMemory = *currentMemory + 3;
    Summ.chasl256 = new unsigned char(3);
    Summ.len256 = 3;

    Summ.chasl256[0] = 0;
    Summ.chasl256[1] = 0;
    Summ.chasl256[2] = 0;

    Summ.chasl256[2] = Summ.chasl256[2] + A->chasl256[A->len256 - 1]%10;
    Summ.chasl256[1] = Summ.chasl256[1] + (((A->chasl256[A->len256 - 1] - (A->chasl256[A->len256 - 1]%10))%100)/10);
    Summ.chasl256[0] = Summ.chasl256[0] + A->chasl256[A->len256 - 1]/100;

    *currentMemory = *currentMemory + 3;
    Step256.chasl256 = new unsigned char(3);
    Step256.len256 = 3;
    Step256.chasl256[0] = 2;
    Step256.chasl256[1] = 5;
    Step256.chasl256[2] = 6;
    DPSH.Urav256(Step256.chasl256, Step256.len256, currentMemory, maxMemory);

    for(int i=1; i<A->len256; i++)
    {
        *currentMemory = *currentMemory + 3;
        Pr.chasl256 = new unsigned char(3);
        Pr.len256 = 3;

        Pr.chasl256[0] = 0;
        Pr.chasl256[1] = 0;
        Pr.chasl256[2] = 0;

        Pr.chasl256[2] = Pr.chasl256[2] + (A->chasl256[A->len256 - 1 - i]%10);
        Pr.chasl256[1] = Pr.chasl256[1] + ((A->chasl256[A->len256 - 1 - i] - ((A->chasl256[A->len256 - 1 - i]%10))%100)/10);
        Pr.chasl256[0] = Pr.chasl256[0] + (A->chasl256[A->len256 - 1 - i]/100);

        umnoj(&Pr, &Step256, currentMemory, maxMemory);
        slojenie(&Summ, &Pr, currentMemory, maxMemory);

        *currentMemory = *currentMemory - Pr.len256;
        Pr.clean256(currentMemory);
        umnoj(&Step256, &DPSH, currentMemory, maxMemory);
    }
    A->Urav256(Summ.chasl256, Summ.len256, currentMemory, maxMemory);
}

bool isOnlyDigits(char* str)
{
    for(int i = 0; i<strlen(str); i++)
    {
        char ch = str[i];
        if ((ch < '0')||(ch > '9'))
        {
            return false;
        }
    }
    return true;
}

int generateRandomDigit() {
    return rand() % 10;
}

int main()
{

    int currentMemory = 0;
    int maxMemory = 0;
    printf("A^x = B (mod P)\n\n");
    currentMemory = currentMemory + 12;
    BigInt256 A;
    bool prov=true;
    do
    {
        if(!prov) printf("!Oshibka vvoda, poprobuy echo raz!\n");
        char numA[100];
        printf("A = ");
        scanf("%s", numA);
        prov = isOnlyDigits(numA);
        if(prov) A.BigCh(numA, &currentMemory, &maxMemory);
    }while(!prov);
    perevodv256(&A, &currentMemory, &maxMemory);
    BigInt256 B;
    prov=true;
    do
    {
        if(!prov) printf("!Oshibka vvoda, poprobuy echo raz!\n");
        char numB[100];
        printf("B = ");
        scanf("%s", numB);
        prov = isOnlyDigits(numB);
        if(prov) B.BigCh(numB, &currentMemory, &maxMemory);
    }while(!prov);
    perevodv256(&B, &currentMemory, &maxMemory);
    BigInt256 P;
    prov=true;
    do
    {
        if(!prov) printf("!Oshibka vvoda, poprobuy echo raz!\n");
        char numP[100];
        printf("mod P = ");
        scanf("%s", numP);
        prov = isOnlyDigits(numP);
        if(prov) P.BigCh(numP, &currentMemory, &maxMemory);
    }while(!prov);
    perevodv256(&P, &currentMemory, &maxMemory);
    bool otv = TRUE;
    gelshen256(&A, &B, &P, &otv, &currentMemory, &maxMemory);
    if(otv==true)
    {
        perevodv10(&A, &currentMemory, &maxMemory);
        if(A.chasl256[0]==0)
        {
            antinull256(&A, &currentMemory, &maxMemory);
        }
        printf("x = ");
        A.print();
    }
    currentMemory = currentMemory - 12;
    printf("\nmaxMemory = %d", maxMemory);
    A.clean256(&currentMemory);
    B.clean256(&currentMemory);
    P.clean256(&currentMemory);
    return 0;
}
