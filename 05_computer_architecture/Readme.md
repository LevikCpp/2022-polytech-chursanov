PS C:\Users\CLA> tasklist
Имя образа                     PID Имя сессии          № сеанса       Память
========================= ======== ================ =========== ============
System Idle Process              0 Services                   0         8 КБ - наименьший
System                           4 Services                   0     1 540 КБ
Registry                       148 Services                   0    76 348 КБ
smss.exe                       564 Services                   0       580 КБ
csrss.exe                      616 Services                   0     4 812 КБ
wininit.exe                   1152 Services                   0     6 092 КБ
...


powershell.exe               12016 Console                    1    67 860 КБ

PS C:\Users\CLA> Get-Process powershell
Handles  NPM(K)    PM(K)      WS(K)     CPU(s)     Id  SI ProcessName
-------  ------    -----      -----     ------     --  -- -----------
    632      31    66352      80836       1,67  11300   1 powershell
    461      27    64764      62080       1,28  12016   1 powershell
