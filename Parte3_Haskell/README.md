# Ejecutar archivos Haskell — Parte3_Haskell

Breve resumen de comandos para comprobar instalaciones y ejecutar archivos Haskell en Linux (VS Code).

## Verificar instalados
```bash
ghc --version
ghci --version
cabal --version
stack --version
haskell-language-server --version   # puede no estar instalado
```

## Ejecutar un archivo (sin compilar)
Ir al directorio que contiene los .hs y ejecutar:
```bash
cd ~/Austral/Lenguajes\ 2C\ 2025/guias-lengProg-Navarro-2025/Parte3_Haskell
runghc Hello.hs
# o con ruta completa y espacios:
# runghc "/home/rocio/Austral/Lenguajes 2C 2025/guias-lengProg-Navarro-2025/Parte3_Haskell/Hello.hs"
```

## Interactivo con GHCi
```bash
cd ~/Austral/Lenguajes\ 2C\ 2025/guias-lengProg-Navarro-2025/Parte3_Haskell
ghci Hello.hs
# dentro de GHCi:
# :main   -> ejecuta main
# :t <expr> -> muestra tipo
# :reload -> recarga
# :quit   -> salir
```

## Compilar y ejecutar binario
```bash
cd ~/Austral/Lenguajes\ 2C\ 2025/guias-lengProg-Navarro-2025/Parte3_Haskell
ghc -o hello Hello.hs
./hello
# limpieza:
# rm hello Hello.hi Hello.o
```

