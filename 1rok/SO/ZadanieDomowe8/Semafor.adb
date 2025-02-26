--Anhelina Belavezha
with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package Semafor is
   protected type Semaphore is
      entry Init(Value : Integer);
      entry P;
      entry V;
      function Wartosc return Integer;
   private
      Count : Integer := 0;
      Waiting : Integer := 0;
   end Semaphore;
end Semafor;

package body Semafor is
   protected body Semaphore is
      entry Init(Value : Integer) when Count = 0 is
      begin
         Count := Value;
      end Init;

      entry P when Count > 0 is
      begin
         Count := Count - 1;
      end P;

      entry V is
      begin
         if Waiting > 0 then
            Waiting := Waiting - 1;
         else
            Count := Count + 1;
         end if;
      end V;

      function Wartosc return Integer is
      begin
         return Count;
      end Wartosc;
   end Semaphore;
end Semafor;
