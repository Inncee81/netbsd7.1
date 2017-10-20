 drop function if exists deptable_trig() cascade;
 create or replace function deptable_trig() returns trigger as $_$
 begin
         if TG_WHEN = 'AFTER' then
                 if TG_OP = 'DELETE' then
                         return OLD;
                 end if;
                 return NEW;
         end if;
         if TG_OP = 'DELETE' then
                 return OLD;
         end if;
	 if EXISTS (select 1 from deptable where os_version=NEW.os_version and pkgid=NEW.pkgid and pkgdep=NEW.pkgdep)
	 then
		return NULL;
	 end if;
         return NEW;
 end;
 $_$
 language plpgsql;
 
 create trigger t1 before insert or delete or update on deptable
     for each row execute procedure deptable_trig();
 create trigger t2 after insert or delete or update on  deptable
     for each row execute procedure deptable_trig();
