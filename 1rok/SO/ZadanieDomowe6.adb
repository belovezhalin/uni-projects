--Anhelina Belavezha 

with Ada.Text_IO; use Ada.Text_IO;

procedure MergeSort is
   type IntArray is array (Positive range <>) of Integer;                     --deklaracja tablicy liczb calkowitych nieujemnych

   procedure Sort (A : in out IntArray) is
      procedure Merge (A : in out IntArray; Left, Right : Integer) is
         Mid, I, J, K : Integer;
         Temp : IntArray (1..Right);
      begin
         Mid := (Left + Right) / 2;
         I := Left;
         J := Mid + 1;
         K := Left;
         while I <= Mid and J <= Right loop
            if A(I) < A(J) then
               Temp(K) := A(I);
               I := I + 1;
            else
               Temp(K) := A(J);
               J := J + 1;
            end if;
            K := K + 1;
         end loop;
         while I <= Mid loop
            Temp(K) := A(I);
            I := I + 1;
            K := K + 1;
         end loop;
         while J <= Right loop
            Temp(K) := A(J);
            J := J + 1;
            K := K + 1;
         end loop;
         for L in Left..Right loop
            A(L) := Temp(L);
         end loop;
      end Merge;

      procedure MergeSort_Recursive (A : in out IntArray; Left, Right : Integer) is
         Mid : Integer;
      begin
         if Left < Right then
            Mid := (Left + Right) / 2;
            MergeSort_Recursive (A, Left, Mid);
            MergeSort_Recursive (A, Mid + 1, Right);
            Merge (A, Left, Right);
         end if;
      end MergeSort_Recursive;

   begin
      MergeSort_Recursive (A, A'First, A'Last);
   end Sort;

   A : IntArray (1..10) := (9, 4, 6, 2, 1, 8, 7, 10, 3, 5);

begin
   Ada.Text_IO.Put ("Original array: ");
   for I in A'Range loop
      Ada.Text_IO.Put (Integer'Image (A(I)) & " ");
   end loop;
   Ada.Text_IO.New_Line;

   Sort (A);

   Ada.Text_IO.Put ("Sorted array: ");
   for I in A'Range loop
      Ada.Text_IO.Put (Integer'Image (A(I)) & " ");
   end loop;
   Ada.Text_IO.New_Line;
end MergeSort;
