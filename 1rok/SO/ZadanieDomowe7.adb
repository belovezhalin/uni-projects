--Anhelina Belavezha

with Ada.Text_IO; 
use Ada.Text_IO;

with Ada.Numerics.Float_Random;

procedure CzytPis1 is

  ----- watek monitora - biblioteki -----
  task Biblioteka is
    entry init(rozmiar: Positive);
    entry chceWejsc(jestPisarzem: Boolean);
    entry koniecPisania;
    entry koniecCzytania;
  end Biblioteka;

  task body Biblioteka is

  ------- dodane zmienne pomocnicze ----------
    maxreaders: Positive;                                                 --maksymalna liczba czytelnikow
    readers: Natural := 0;                                                --liczba obecnie znajdujacych sie w bibliotece czytelnikow
    writer: Boolean := False;                                             --flaga informujaca pisarz jest w bibliotece

  begin
    accept init(rozmiar: Positive) do
      maxreaders := rozmiar;
    end init;

    loop
      select
        accept chceWejsc(jestPisarzem: Boolean) do
          if jestPisarzem then                                            --rozwiazanie problemu czytelnikow i pisarzy
            loop
                exit when not writer and readers = 0;
                delay 1.0;
            end loop;
            writer := True;
          else
            loop
                exit when not writer and readers /= maxreaders;
                delay 1.0;
            end loop;
            readers := readers + 1;
          end if;
        end chceWejsc;
      or
        accept koniecPisania do
          writer := False;
        end koniecPisania;
      or
        accept koniecCzytania do
          readers := readers - 1;
        end koniecCzytania;
      end select;
    end loop;
  end Biblioteka; 
  ----- koniec monitora -----

  ----- pomocnicze - do losowania -----
  Gen: Ada.Numerics.Float_Random.Generator;

  function random(max: Float:= 1.0; min: Float:= 0.0) return Duration is -- funkcja zwracajaca losowy czas w sekundach (typ Duration)
  begin
    return Duration(min+(max-min)*Ada.Numerics.Float_Random.Random(Gen));
  end random;
  ----- do losowania -----

  ----- typ i kod watku czytelnika -----
  task type Czytelnik(id: Integer);

  task body Czytelnik is
  begin
    loop
      Put_Line("Czytelnik" & Integer'Image(id) & " chce wejsc...");
      Biblioteka.chceWejsc(False);
      Put_Line("Czytelnik" & Integer'Image(id) & " jest w czytelni.");
      delay random(1.0); -- czytanie przez maks. 1s
      Put_Line("Czytelnik" & Integer'Image(id) & " wychodzi.");
      delay random(0.5);
      Biblioteka.koniecCzytania;
    end loop;
  end Czytelnik;
  ----- koniec czytelnika -----

  ----- typ i kod watku pisarza -----
  task type Pisarz(id: Integer);

  task body Pisarz is
  begin
    loop
      Put_Line("Pisarz" & Integer'Image(id) & " chce wejsc...");
      Biblioteka.chceWejsc(True);
      Put_Line("Pisarz" & Integer'Image(id) & " jest w czytelni.");
      delay random(2.0); -- pisanie przez maks. 2s
      Put_Line("Pisarz" & Integer'Image(id) & " wychodzi.");
      delay random(0.5);
      Biblioteka.koniecPisania;
    end loop;
  end Pisarz;
  ----- koniec pisarza -----

   -- przykladowa inicjalizacja watkow czytelnikow i pisarzy -----
   a: Czytelnik(1);
   b: Czytelnik(2);
   c: Czytelnik(3);

   d: Pisarz(1);
   e: Pisarz(2);

begin 
  Biblioteka.init(2); -- ustalenie pojemnosci biblioteki (maksymalna liczba czytelnikow)
end CzytPis1;