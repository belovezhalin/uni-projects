--Anhelina Belavezha 
with Ada.Text_IO; use Ada.Text_IO;
with Semafor; use Semafor;

procedure Producent_Konsument is
   package TS is new Semafor;
   package body Producent is new TS.Semaphore;
   package body Konsument is new TS.Semaphore;

   Bufor : Integer := 0;

   task Producent_Task is
   begin
      loop
         Producent.P;
         Put_Line("Producent: Wyprodukowano element");
         Konsument.V;
      end loop;
   end Producent_Task;

   task Konsument_Task is
   begin
      loop
         Konsument.P;
         Put_Line("Konsument: Skonsumowano element");
         Producent.V;
      end loop;
   end Konsument_Task;

begin
   Producent.Init(1);
   Konsument.Init(0);

   task Producent_Task;
   task Konsument_Task;

   delay 5.0;
   Producent.V;
   Konsument.V;

   task.terminate(Producent_Task);
   task.terminate(Konsument_Task);
end Producent_Konsument;
