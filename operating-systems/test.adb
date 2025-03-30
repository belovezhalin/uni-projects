--

with GNAT.OS_Lib;

package body Rozwiazanie is

task body Synchronizator is
	doStages : constant Positive := 3;

	size : Natural := 0;
	actual : array(0..4) of Integer;
	waiting : Boolean := false;
	stage : Integer := 0;
	current : Natural := 0;
	expected_pon : Integer := 0;
begin

for zzz in 0..4 loop
	accept logowanie(id : Integer) do
		if size = 0 then
			size := 1;
			actual(0) := id;
		else
			declare
				wiek : Integer := 0;
			begin
				while wiek < size loop
					exit when actual(wiek) < id;
					wiek := wiek + 1;
				end loop;
				for i in reverse wiek..size-1 loop
					actual(i+1) := actual(i);
				end loop;
				actual(wiek) := id;
				size := size + 1;
			end;
		end if;
	end logowanie;
end loop;

loop
	select
		when not waiting =>
		accept chcePracowac(id: Integer; zgoda : out Boolean) do
			if waiting then
				zgoda := false;
				expected_pon := expected_pon + 1;
				return;
			end if;
			if id = actual(current) then
				zgoda := true;
				waiting := true;
			else
				zgoda := false;
				expected_pon := expected_pon + 1;
			end if;
		end chcePracowac;
	or
		when expected_pon > 0 or waiting =>
		accept ponownie do
			if expected_pon > 0 then
				expected_pon := expected_pon - 1;
			else
				current := (current + 1);
				if current = size then
					current := 0;
					stage := stage + 1;
				end if;
				if stage = doStages then
					GNAT.OS_Lib.OS_Exit(0);
				end if;
				waiting := false;
			end if;
		end ponownie;
	or
		when waiting =>
		accept koniec do
			-- remove current
			if size = 1 then 
				GNAT.OS_Lib.OS_Exit(0);
			end if;
			if not (current = size - 1) then
				for i in current+1..size-1 loop
					actual(i-1) := actual(i);
				end loop;
			end if;
			size := size - 1;
			if current = size then
				current := 0;
				stage := stage + 1;
			end if;
			if stage = doStages then
				GNAT.OS_Lib.OS_Exit(0);
			end if;
			waiting := false;
		end koniec;
	end select;
end loop;

end Synchronizator;

end Rozwiazanie;