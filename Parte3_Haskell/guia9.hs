module Main where

-- 1) Escriba un programa que enumere todas las ternas [p,q,r] tal que p, q, r <= 10
ternas :: [[Int]]
ternas = [[p, q, r] | p <- [1..10], q <- [1..10], r <- [1..10]]


-- 2) Supongamos ahora que cada terna representan los lados de un triángulo. 
--    Dentro de las ternas del ej 1, queremos ahora dejar sólo las que representan triángulos rectángulos. 
--    Recuerde que, si llamamos r a la hipotenusa y p y q a los catetos, debe cumplirse el teorema de Pitágoras:
--    p² + q² = r²
ternasRectangulos :: [[Int]]
ternasRectangulos = [[p, q, r] | [p, q, r] <- ternas, p^2 + q^2 == r^2] -- agarra cada terna de la lista ternas y filtra las que cumplen la condición del teorema de Pitágoras poniendolas en una nueva lista de ternas


-- 3) Finalmente, queremos que una terna que represente un triángulo rectángulo tal que su perímetro sea 24.
ternasRectanguloPerimetro24 :: [[Int]]
ternasRectanguloPerimetro24 = [[p,q,r] | [p,q,r] <- ternasRectangulos, p+q+r == 24]


-- 4) El código de César. Rote una lista n lugares hacia la izquierda. 
--    Por ejemplo, la entrada "abcdefghijklmnop" con el parámetro 3 debería dar como resultado "defghijklmnopabc".
rotarIzquierda :: String -> Int -> String
rotarIzquierda [] _ = []
rotarIzquierda xs n = funcAux [] xs n
    where
        funcAux ys xs 0 = xs ++ ys
        funcAux ys (x:xs) n = funcAux  (ys++[x]) xs (n-1)

-- Ejemplo de uso:        
-- [] abcdefghijklmnop 3
-- a bcdefghijklmnop 2
-- ab cdefghijklmnop 1
-- abc defghijklmnop 0 


-- 5) Explique por qué las siguientes fragmentos de código son equivalentes:
{-
    let max1 = max 4 5
    let max2 = (max 4) 5
    En Haskell no existen funciones con multiples argumentos --> CURRYFICATION
    Cuando se le da el primer valor, ej 4, lo que queda es una función que sabe: "yo comparo lo que me den con 4"
    Toma un argumento y DEVUELVE UNA FUNCION que espera el siguiente argumento.
-}


-- 6) Explique a qué llamamos "funciones de orden superior."
{-
    Son funciones que toman otras funciones como argumentos y/o devuelven funciones como resultado.
    Son una característica central del paradigma funcional y permiten un alto nivel de abstracción y reutilización.
    Ejemplos comunes incluyen map, filter y fold.
    Diferencia con curryfication:
    - Una función que toma funciones como argumento → HOF (map, filter)
    - Una función que devuelve funciones → CURRYFICATION

-}


-- 7) ¿Verdadero o falso? 
--    "Una función que toma n parámetros (n>1) en realidad está tomando un parámetro y devolviendo una función de n−1 parámetros."
{-
    Verdadero. En Haskell, todas las funciones toman un solo parametro y devuelven otra funcion para los restantes --> CURRYFICATION
    Es una composicion de funciones donde cada una toma un solo parametro.
-}


-- 8) Implemente una función "myMap" que funcione exactamente como "map". Está prohibido usar "map" en esta implementación.
--    OBS: map recibe una funcion y una lista y aplica la funcion a cada elemento de la lista
myMap :: (a -> b) -> [a] -> [b]  -- (a -> b) porque la funcion recibe un elem de tipo a y devuelve uno de tipo b
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs


-- 8.v2) Implemente una función "myFilter" que funcione exactamente como "filter". Está prohibido usar "filter" en esta implementación.
--       OBS: filter recibe una condición y una lista y revuelve una lista con los elementos que cumplen esa condicion
myFilter :: (a -> Bool) -> [a] -> [a]  -- (a -> Bool) porque la funcion recibe un elem de tipo a y devuelve un Bool
myFilter _ [] = []
myFilter f (x:xs)
    | f x       = x : myFilter f xs  -- si f(x)==true, agrego x a la lista resultante
    | otherwise = myFilter f xs -- sino, sigo con el resto de la lista


-- 9) La secuencia de Collatz. La secuencia de Collatz se define como sigue:
--       collatz 1 = [1]
--       collatz n = n : collatz (n/2) si n es par
--       collatz n = n : collatz (3⋅n+1) si n es impar
--   Queremos una lista de los números del 1 al 100 que tienen una secuencia de Collatz más larga que 10.    
collatz :: Int -> [Int]
collatz 1 = [1]
collatz n 
    | even n    = n : collatz (n `div` 2)
    | otherwise = n : collatz (3*n+1)

myCollatzLongerThan10 :: [Int]
myCollatzLongerThan10 = [n | n <- [1..100], length (collatz n) > 10]  


-- 10) Explique por qué las siguientes expresiones son equivalentes. ¿Cuál preferiría y por qué?
{-
    map (+1) [7, 3, 5, 1]
    map (\x -> x + 1) [7, 3, 5, 1]


    Ambas expresiones aplican la misma operación: sumar 1 a cada elemento de la lista [7, 3, 5, 1].
    - La primera expresión utiliza la función parcial (+1), que es más concisa y legible. Funciona con curryfication.
    - La segunda expresión utiliza una función lambda explícita (\x -> x + 1), es menos clara.
      Define explícitamente la función: “toma un x y devuélvele x + 1”

-}



-- PRUEBAS EJS --

-- Ej 1
main :: IO ()
main = do
    -- Ej 1
    putStrLn "Ternas:" 
    print ternas
    -- Ej 2
    putStrLn "Ternas triangulos rectángulos:"  
    print ternasRectangulos
    -- Ej 3
    putStrLn "Ternas triangulos rectangulos perimetro 24:"
    print ternasRectanguloPerimetro24
    -- Ej 4
    let letritas = "abcdefghijklmnop"
    putStrLn "Rotar abcdefghijklmnop 3 lugares hacia la izquierda:"
    print (rotarIzquierda letritas 3)  -- defghijklmnopabc
    -- Ej 5
    let max1 = max 4 5
    let max2 = (max 4) 5
    putStrLn $ "max1: " ++ show max1
    putStrLn $ "max2: " ++ show max2
    -- Ej 8
    let lista = [1,2,3,4,5]
    let funcion = (*2)
    putStrLn $ "myMap (*2) [1,2,3,4,5]: " ++ show (myMap funcion lista)  
    -- Ej 9
    putStrLn $ "Números del 1 al 100 con secuencia de Collatz más larga que 10: " ++ show myCollatzLongerThan10
