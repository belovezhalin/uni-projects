--Anhelina Belavezha

--In a certain system, threads perform computations, but they can only do so after obtaining permission from a supervisory program called the synchronizer. 
--The task is to implement the functionality of the synchronizer as a task in Ada, exposing the following entries:
-- - logowanie(id: Integer) – A thread joins the system by calling this entry, passing its identifier as a parameter.
-- - chcePracowac(id: Integer; zgoda: out Boolean) – A thread requests permission to perform computations by calling this entry with its identifier. 
--   The synchronizer responds through the zgoda output parameter, indicating whether the thread is granted permission (True) or not (False). 
--   If permission is granted, the thread starts its computations.
-- - ponownie – If a thread did not receive permission, it calls this entry to wait and try again later.
-- - koniec – If a thread has completed its computations and does not need to request permission again, it calls this entry to leave the system permanently.

--Rules for Granting Permission:
-- - Permissions are granted in rounds (turns). Each thread in the system must receive permission exactly once per turn unless it has called koniec.
-- - Permissions within a turn are granted in descending order of thread IDs. 
--   A thread can only receive permission if all threads with higher IDs have already completed their computations or exited the system.
-- - A turn is considered complete when all threads in the system have either executed their computations or called koniec. 
--   No thread can execute computations in a new turn while any remaining threads from the current turn have not yet finished.
-- - A thread that calls ponownie remains in the system and can later call chcePracowac again to request permission in a new turn.

--Task Implementation:
-- - The task is to implement the Synchronizer task in the Rozwiazanie package.
-- - The synchronizer must correctly manage five threads for three turns. 
--   The thread identifiers will be provided through five calls to logowanie, and permission distribution will begin only after receiving all five identifiers.

--Once the three turns are completed (or earlier if all threads have called koniec), the program should terminate, for example, by calling GNAT.OS_Lib.OS_Exit(0).

with GNAT.OS_Lib;

package body Synchronizer is
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
end Synchronizer;
