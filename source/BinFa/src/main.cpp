#include "BinFa2.h"

int main (int argc, char *argv[])
try {
    
    if (argc != 4) throw Usage_error();

    char *inFile = argv[1];

    if (argv[2][1] != 'o') throw Usage_error();

    fstream beFile (inFile, ios_base::in);

    if (!beFile) cout << inFile << " does not exists!\n";

    fstream kiFile (argv[3], ios_base::out);

    unsigned char b;
    BinFa binFa;

    while (beFile.read ((char*) &b, sizeof (unsigned char)))
    {
        for (int i = 0; i < 8; ++i)
        {
            if (b & 0x80)
                binFa << '1';
            else
                binFa << '0';
            b <<= 1;
        }
    }

    kiFile << binFa;
    kiFile << "depth = " << binFa.getMelyseg () << endl;
    kiFile << "mean = " << binFa.getAtlag () << endl;
    kiFile << "var = " << binFa.getSzoras () << endl;

    BinFa binFa2 (binFa);

    kiFile << "binFa2\n";
    kiFile << binFa2;
    kiFile << "depth = " << binFa2.getMelyseg () << endl;
    kiFile << "mean = " << binFa2.getAtlag () << endl;
    kiFile << "var = " << binFa2.getSzoras () << endl;

    BinFa binFa3;
    binFa3 << '1';
    binFa3 << '0';
    binFa3 << '1';

    binFa3 = binFa;

    kiFile << "binFa3\n";
    kiFile << binFa3;
    kiFile << "depth = " << binFa3.getMelyseg () << endl;
    kiFile << "mean = " << binFa3.getAtlag () << endl;
    kiFile << "var = " << binFa3.getSzoras () << endl;

    BinFa binFa4 = move(binFa);

    kiFile << "binFa4\n";
    kiFile << binFa4;
    kiFile << "depth = " << binFa4.getMelyseg () << endl;
    kiFile << "mean = " << binFa4.getAtlag () << endl;
    kiFile << "var = " << binFa4.getSzoras () << endl;

    kiFile.close ();
    beFile.close ();

    return 0;

} catch (Usage_error) {
    cout << "Usage: BinFa in_file -o out_file" << endl;
    return 1;
} catch (exception& e) {
    cout << e.what() << endl;
    return 2;
}