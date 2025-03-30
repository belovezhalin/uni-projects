--Anhelina Belavezha

with GNAT.OS_Lib;

package body Rozwiazanie is
task body Synchronizator is
   tab : array(0..4) of Integer;
	size : Natural := 0;
   cur : Natural := 0;
	stage : Integer := 0;
	exp : Integer := 0;
   wait : Boolean := false;

begin

for j in 0..4 loop
	accept logowanie(id : Integer) do
		if size = 0 then
			size := 1;
			tab(0) := id;
		else
			declare liczba : Integer := 0;
			begin
				while liczba < size loop
					exit 
                  when tab(liczba) < id;
					liczba := liczba + 1;
				end loop;

				for i in reverse liczba..size-1 loop
					tab(i+1) := tab(i);
				end loop;

				tab(liczba) := id;
				size := size + 1;
			end;
		end if;
	end logowanie;
end loop;

loop
	select
		when not wait => accept chcePracowac(id: Integer; zgoda : out Boolean) do
		  if wait then
        zgoda := false;
        exp := exp + 1;
        return;
        end if;

        zgoda := id = tab(cur);
        
        if zgoda then
           wait := true;
        else
           exp := exp + 1;
        end if;
		end chcePracowac;
	or
		when exp > 0 or wait => accept ponownie do
			if exp > 0 then
				exp := exp - 1;
			else
				cur := (cur + 1);
				if cur = size then
					cur := 0;
					stage := stage + 1;
				end if;
				if stage = 3 then
					GNAT.OS_Lib.OS_Exit(0);
				end if;
				wait := false;
			end if;
		end ponownie;
	or
		when wait => accept koniec do
			if size = 1 then 
				GNAT.OS_Lib.OS_Exit(0);
			end if;

			if not (cur = size - 1) then
				for i in cur+1..size-1 loop
					tab(i-1) := tab(i);
				end loop;
			end if;

			size := size - 1;
			if cur = size then
				cur := 0;
				stage := stage + 1;
			end if;

			if stage = 3 then
				GNAT.OS_Lib.OS_Exit(0);
			end if;
			wait := false;
		end koniec;
	end select;
end loop;

end Synchronizator;
end Rozwiazanie;