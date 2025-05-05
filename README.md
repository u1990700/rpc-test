El codi adjuntat ha estat compilat i executat des del Codespacede GitHub.
Si per fer la proba es fa desde el reposotory seguir les intruccions següents.

Enllaç: https://github.com/u1990700/rpc-test

El primer que s’ha fet és crear un directori GitHub, tot seguit, s’ha anat a l'apartat code i creat un codespace:

Un cop generat, tindrem una màquina virtual en línia per poder fer les proves. Podem adjuntar els fitxers c(rpc-client.c, rpc-server.c) del nostre programa.

Un cop adjuntats els compilem a la consola amb les següents comandes:
gcc rpc-client.c -o rpc-client
gcc rpc-server.c -o rpc-server

Això hauria de generar 2 arxius, un client i un servidor.

Ara executem el servidor des del mateix terminal amb la comanda ./rpc-server

Es quedarà esperant una connexió, aquesta la farem amb el client.

Obrim un nou terminal


En aquest terminal executem ./rpc-client

Aquest ens preguntarà que volem fer, indiquem suma. Li indiquem com mostrem a continuació i li podem observar la resposta.


Podem observar com al servidor li ha arribat la resposta:


