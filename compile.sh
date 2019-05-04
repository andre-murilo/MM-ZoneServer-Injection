#!/bin/sh

echo "Compilando VMO MixMaster MOD"
gcc -shared -w -m32 -pthread -Wall -static Injection.cpp Script.cpp CScriptManager.cpp CMemory.cpp CHookManager.cpp CEventsHandler.cpp liblua52.a -ldl -o ../Injection.so -masm=intel
