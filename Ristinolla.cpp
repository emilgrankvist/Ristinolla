// Standardikirjastojen käyttö
#include <iostream>
#include <string>
using namespace std;


class Ristinolla
{
   private:
   char lauta[3][3]; // lauta on 3x3 taulukko

   public:
   Ristinolla() {}

   // Pelilaudan asetelma

   void SetLauta()
   {
      int n = 1;
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ )
      {
         for ( j = 0; j < 3; j++ )
         {
            lauta[i][j] = '0' + n;
            n++;
         }
      }
   }

   // Pelilaudan asetelmat loppuu

   // Pelilaudan tulostaminen alkaa

   void PrintLauta()
   {
      int i = 0;
      int j = 0;

      for ( i = 0; i < 3; i++ )
      {
         for ( j = 0; j < 3; j++ )
         {
            if ( j < 2 )
            {
               cout << lauta[i][j] << "  ||  ";
            }
               else
               {
                  cout << lauta[i][j] << endl;
               }
         }
      }
   }

   // Pelilaudan tulostaminen loppuu

   // Pelaajien liikkeiden tarkistus alkaa

   void PeliVuoro(char num, char Pelaaja)
   {
      int i = 0;
      int j = 0;

      bool VaaraLiike = true; //Jos true, niin pelaaja on toiminut väärin
      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         {
            if(lauta[i][j] == num)
            {
               lauta[i][j] = Pelaaja;
               VaaraLiike = false;
            }
         }
      }
      if(VaaraLiike == true) { cout << "Et voi valita valittuja numeroita!\n"; }
   }

   // Pelaajien liikkeiden tarkistus loppuu

   // Tasapelin tarkistus alkaa

   bool Tasapeli(bool PeliGG)
   {
      int n = 1;
      int i = 0;
      int j = 0;
      int counter = 0;

      for( i = 0; i < 3; i++ )
      {
         for( j = 0; j < 3; j++ )
         {
            //Tarkistaa onko lauta täynnä
            if(lauta[i][j] == '0' + n)
            {
               counter++;
            }
            n++;
         }
      }
      if( counter < 1 )
      {
         cout << "TASAPELI!\n\n";
         PeliGG = true;
      }
      return PeliGG;
   }

   // Tasapelin tarkistus loppuu

   // Pelin tilanteen tarkistus: jos voittajia niin päätä peli, jos ei niin jatka peliä.

   bool Tulokset(char Pelaaja, bool PeliGG)
   {
      for(int i = 0; i < 3; i++)
      {
         if(lauta[i][0] == lauta[i][1] && lauta[i][1] ==
         lauta[i][2]) PeliGG = true;
      }
      for(int i = 0; i < 3; i++)
      {
         if(lauta[0][i] == lauta[1][i] && lauta[1][i] ==
         lauta[2][i]) PeliGG = true;
      }
      if(lauta[0][0] == lauta[1][1] && lauta[1][1] == lauta[2][2])
      {
         PeliGG = true;
      }
      if(lauta[0][2] == lauta[1][1] && lauta[1][1] == lauta[2][0])
      {
         PeliGG = true;
      }
      if(PeliGG == true)
      {
         cout << "Pelaaja " <<Pelaaja << " voitti!\n\n";

         cout << "  Onnittelut! \n\n";

      }
         return PeliGG;
   }

   // Pelin tilanteen tarkistus loppuu.

};

int main()
{
    bool valmis     = false, PeliGG      = false;
    char Pelaaja   = 'O', num;

    cout << "RISTINOLLA PELI\n";
    cout << "Pelaaja X ja Pelaaja Y\n";
    cout << "===============\n"<< endl;

    Ristinolla uusPeli;
    uusPeli.SetLauta();
    do
    {
        if( Pelaaja == 'X' )
        {
           Pelaaja = 'O';
        }
           else
           {
              Pelaaja = 'X';
           }
        uusPeli.PrintLauta();
        cout << "\nPelaaja \"" << Pelaaja << "\", nyt on sinun vuorosi: ";
        cin >> num;
        cout << "\n";

        uusPeli.PeliVuoro(num, Pelaaja);
        PeliGG = uusPeli.Tulokset(Pelaaja, PeliGG);
        PeliGG = uusPeli.Tasapeli(PeliGG);

        //jos peli loppui, niin uudelleen aloitus

        if(PeliGG == true)
        {   uusPeli.SetLauta();
            PeliGG = false;
        }

    } while(!valmis);

    system("tauko");
    return 0;
}
