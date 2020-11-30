#include "BinFa2.h"

void BinFa::operator<< (char b)
{
    if (b == '0')
    {
        if (!fa->nullasGyermek ())
        {
            Csomopont *uj = new Csomopont ('0');
            fa->ujNullasGyermek (uj);
            fa = gyoker;
        }
        else
        {
            fa = fa->nullasGyermek ();
        }
    }
    else
    {
        if (!fa->egyesGyermek ())
        {
            Csomopont *uj = new Csomopont ('1');
            fa->ujEgyesGyermek (uj);
            fa = gyoker;
        }
        else
        {
            fa = fa->egyesGyermek ();
        }
    }
}

BinFa::Csomopont* BinFa::masol (BinFa::Csomopont* csp, BinFa::Csomopont* fa_ptr)
{
    Csomopont* uj_csomopont = nullptr;

    if (csp)
    {
        uj_csomopont = new Csomopont(csp->getBetu());

        uj_csomopont->ujNullasGyermek(masol(csp->nullasGyermek(), fa_ptr));
        uj_csomopont->ujEgyesGyermek(masol(csp->egyesGyermek(), fa_ptr));

        if (csp == fa_ptr)
            this->fa = uj_csomopont;
    }

    return uj_csomopont;
}

void BinFa::kiir (Csomopont * elem, std::ostream & os)
{
    if (elem != NULL)
    {
        ++melyseg;
        kiir (elem->egyesGyermek (), os);

        for (int i = 0; i < melyseg; ++i)
            os << "---";
        os << elem->getBetu () << "(" << melyseg - 1 << ")" << std::endl;

        kiir (elem->nullasGyermek (), os);
        --melyseg;
    }
}

int
BinFa::getMelyseg (void)
{
    melyseg = maxMelyseg = 0;
    rmelyseg (gyoker);
    return maxMelyseg - 1;
}

double
BinFa::getAtlag (void)
{
    melyseg = atlagosszeg = atlagdb = 0;
    ratlag (gyoker);
    atlag = ((double) atlagosszeg) / atlagdb;
    return atlag;
}

double
BinFa::getSzoras (void)
{
    atlag = getAtlag ();
    szorasosszeg = 0.0;
    melyseg = atlagdb = 0;

    rszoras (gyoker);

    if (atlagdb - 1 > 0)
        szoras = std::sqrt (szorasosszeg / (atlagdb - 1));
    else
        szoras = std::sqrt (szorasosszeg);

    return szoras;
}

void
BinFa::rmelyseg (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        if (melyseg > maxMelyseg)
            maxMelyseg = melyseg;
        rmelyseg (elem->egyesGyermek ());
        rmelyseg (elem->nullasGyermek ());
        --melyseg;
    }
}

void
BinFa::ratlag (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        ratlag (elem->egyesGyermek ());
        ratlag (elem->nullasGyermek ());
        --melyseg;
        if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
        {
            ++atlagdb;
            atlagosszeg += melyseg;
        }
    }
}

void
BinFa::rszoras (Csomopont * elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        rszoras (elem->egyesGyermek ());
        rszoras (elem->nullasGyermek ());
        --melyseg;
        if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
        {
            ++atlagdb;
            szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
        }
    }
}

ostream& operator<< (ostream& os, BinFa& bf)
{
    bf.kiir(os);
    return os;
}