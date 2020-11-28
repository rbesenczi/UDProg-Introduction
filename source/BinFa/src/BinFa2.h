#ifndef UD_BINFA_H
#define UD_BINFA_H

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Usage_error {};

class BinFa {

public:
    BinFa()
    {
        gyoker = new Csomopont();
        fa = gyoker;
    }
    
    BinFa (const BinFa& eredeti) 
    { 
        gyoker = masol(eredeti.gyoker, eredeti.fa);
    }
    
    BinFa& operator= (const BinFa& eredeti)
    {
        BinFa temp (eredeti);
        swap(*this, temp);
        return *this;
    }

    BinFa (BinFa&& eredeti)
    {
        gyoker = nullptr;
        *this = move(eredeti);
    }

    BinFa& operator= (BinFa&& eredeti)
    {
        swap(eredeti.gyoker, gyoker);
        swap(eredeti.fa, fa);
    }

    ~BinFa()
    {
        if (gyoker)
        {
            szabadit (gyoker->egyesGyermek ());
            szabadit (gyoker->nullasGyermek ());
            delete gyoker;
        }
    }

    void kiir (std::ostream & os)
    {
        melyseg = 0;
        kiir (gyoker, os);
    }

    void operator<< (char);
    
    int getMelyseg (void);
    double getAtlag (void);
    double getSzoras (void);
        
private:
    class Csomopont {
    public:
        Csomopont(char b = '/'):betu (b), balNulla (0), jobbEgy (0) {}

        Csomopont *nullasGyermek () const { return balNulla; }
        Csomopont *egyesGyermek () const { return jobbEgy; }
        void ujNullasGyermek (Csomopont * gy) { balNulla = gy; }
        void ujEgyesGyermek (Csomopont * gy) { jobbEgy = gy; }
        char getBetu () const { return betu; }
    private:
        char betu;
        Csomopont *balNulla;
        Csomopont *jobbEgy;
    };

    Csomopont* fa;
    Csomopont* gyoker;
    
    int melyseg, atlagosszeg, atlagdb, maxMelyseg;
    double szorasosszeg, atlag, szoras;

    Csomopont* masol (Csomopont* csp, Csomopont* fa_ptr);    
    void kiir (Csomopont * elem, std::ostream & os);
    
    void rmelyseg (Csomopont * elem);
    void ratlag (Csomopont * elem);
    void rszoras (Csomopont * elem);
   
    void szabadit (Csomopont * elem)
    {
        if (elem != NULL)
        {
            szabadit (elem->egyesGyermek ());
            szabadit (elem->nullasGyermek ());
            delete elem;
        }
    }
};

ostream& operator<< (ostream& os, BinFa& bf);

#endif