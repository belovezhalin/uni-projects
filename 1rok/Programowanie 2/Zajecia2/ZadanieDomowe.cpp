#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>
using namespace std;

int count(string file) {                                                              //funkcja zwracajaca liczbe wierszy
   int lines;
   fstream f;
   f.open(file.c_str(), fstream::in);
   string temp;
   while (getline(f, temp)) lines++;
   return lines;}

void rozdzielNaHex(string plikWejscie, int liczbaWyjsc, string plikWyjscie1, ...) {
   int lines = count(plikWejscie);

   va_list ap;
   va_start(ap, plikWyjscie1);
   fstream infile;
   infile.open(plikWejscie.c_str(), fstream::in);

   std::fstream outfiles[liczbaWyjsc];
   outfiles[0].open(plikWyjscie1.c_str(), fstream::app);

   for (int i = 1; i < liczbaWyjsc; i++) {
      char *fileName = va_arg(ap, char *);
      outfiles[i].open(fileName, fstream::app);}                                     //otwieranie plikow wyjsciowych

   for (int i = 0, j = 0; i < lines; i++, j++) {                                     //przepisanie z input do outputow korzystajac z buferu
      int num;
      infile >> num;
      std::streambuf *coutbuf = std::cout.rdbuf();        
      std::cout.rdbuf(outfiles[j % liczbaWyjsc].rdbuf()); 

      bool isHex = (std::cout.flags() & std::ios_base::hex);                         //flaga do heksodycemalnych liczb
      bool isUpper = (std::cout.flags() & std::ios_base::uppercase);                 //flaga do wielkosci liczb 
      cout << hex << uppercase << num;

      if (liczbaWyjsc < lines - i) cout << endl;                                     
      
      std::cout.rdbuf(coutbuf);
      if (!isHex) cout.unsetf(ios::hex);
      if (!isUpper) cout.unsetf(ios::uppercase);
   }

   for (int i = 0; i < liczbaWyjsc; i++) {
      outfiles[i].unsetf(ios::uppercase);
      outfiles[i].unsetf(ios::hex);
      outfiles[i].close();}

   va_end(ap);
   infile.close();}

void polaczNaDec(string plikWyjscie, int liczbaWejsc, string plikWejscie1, ...) {
   fstream outfile;

   va_list ap;
   va_start(ap, plikWejscie1);
   outfile.open(plikWyjscie.c_str(), fstream::out);                      //otwarcie wyjsciowego
   std::fstream infiles[liczbaWejsc];
   infiles[0].open(plikWejscie1.c_str(), fstream::in);
   for (int i = 1; i < liczbaWejsc; i++) {
      char *fileName = va_arg(ap, char *);
      infiles[i].open(fileName, fstream::in);}

   int i = 0;
   while (!infiles[i].eof()) {                                           //eof - end of file
      int num = 0;
      infiles[i] >> hex >> uppercase >> num;
      outfile << num << endl;
      ++i;
      if (i == liczbaWejsc) i = 0;}

   for (int i = 0; i < liczbaWejsc; i++) infiles[i].close();             //zamkniecie wejsciowych

   va_end(ap);
   outfile.close();}                                                     //zamkniecie wysciowego

int main() {
    //rozdzielNaHex("PlikWejscie.txt", 3, "PlikWyjscie1.txt", "PlikWyjscie2.txt", "PlikWyjscie3.txt");
    polaczNaDec("PlikWyjscie0.txt", 3, "plikWyjscie1.txt", "plikWyjscie2.txt", "plikWyjscie3.txt");
    return 0;
}

   