explode() is important for a lot of templating systems
<?php
$test = <<< EOM
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/bin/sh
bin:x:2:2:bin:/bin:/bin/sh
sys:x:3:3:sys:/dev:/bin/sh
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/bin/sh
man:x:6:12:man:/var/cache/man:/bin/sh
lp:x:7:7:lp:/var/spool/lpd:/bin/sh
mail:x:8:8:mail:/var/mail:/bin/sh
news:x:9:9:news:/var/spool/news:/bin/sh
uucp:x:10:10:uucp:/var/spool/uucp:/bin/sh
proxy:x:13:13:proxy:/bin:/bin/sh
www-data:x:33:33:www-data:/var/www:/bin/sh
backup:x:34:34:backup:/var/backups:/bin/sh
list:x:38:38:Mailing List Manager:/var/list:/bin/sh
irc:x:39:39:ircd:/var/run/ircd:/bin/sh
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/bin/sh
nobody:x:65534:65534:nobody:/nonexistent:/bin/sh
Debian-exim:x:102:102::/var/spool/exim4:/bin/false
tim:x:1000:1000:tim,,,:/home/tim:/bin/bash
identd:x:100:65534::/var/run/identd:/bin/false
sshd:x:101:65534::/var/run/sshd:/bin/false
bind:x:103:104::/var/cache/bind:/bin/false
messagebus:x:104:105::/var/run/dbus:/bin/false
gdm:x:105:106:Gnome Display Manager:/var/lib/gdm:/bin/false
hal:x:108:108:Hardware abstraction layer,,,:/var/run/hal:/bin/false
saned:x:109:109::/home/saned:/bin/false
mysql:x:106:112:MySQL Server,,,:/var/lib/mysql:/bin/false
testuser:x:1001:1001:,,,:/home/testuser:/bin/bash
distccd:x:107:65534::/:/bin/false
postgres:x:110:113:PostgreSQL administrator,,,:/var/lib/postgres:/bin/bash
EOM;

for($i=0; $i<10000; $i++) {
    if (count(explode(":", $test)) != 187) {
        die("error!");
    } 
}
// print count(explode(":",$test));

?>