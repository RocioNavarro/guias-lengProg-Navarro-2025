
module Main where
import Data.Char (toUpper)


member :: Eq a => a -> [a] -> Bool
member _ [] = False
member x (y:ys)
    | x == y    = True
    | otherwise = member x ys


-- 1) Escriba un programa Haskell que, dados dos conjuntos, nos devuelva su unión.
union :: Eq a => [a] -> [a] -> [a]
union [] ys = ys
union (x:xs) ys
    | member x ys = union xs ys
    | otherwise   = x : union xs ys


-- 2) Escriba un programa Haskell que, dados dos conjuntos, nos devuelva su intersección.
intersection :: Eq a => [a] -> [a] -> [a]
intersection [] _ = []
intersection (x:xs) ys
    | member x ys = x : intersection xs ys
    | otherwise   = intersection xs ys


-- 3) Escriba un programa Haskell que, dados dos conjuntos, nos devuelva su diferencia. 
--    Recuerde que A - B = {x | x ∈ A y x ∉ B}.
difference :: Eq a => [a] -> [a] -> [a]
difference [] _ = []
difference (x:xs) ys
    | member x ys = difference xs ys
    | otherwise   = x : difference xs ys


-- 4) Escriba un programa Haskell que, dados dos conjuntos, nos devuelva su diferencia simétrica. 
--    Recuerde que la diferencia simétrica entre dos conjuntos A y B es (A−B)∪(B−A).
--    OBS: contiene los elementos que están en uno de los conjuntos pero no en ambos.
symmetricDifference :: Eq a => [a] -> [a] -> [a]
symmetricDifference xs ys = union (difference xs ys) (difference ys xs)


-- 5) Tenemos un número octal (en base 8) expresado como una lista donde los exponentes de los dígitos van en sentido ascendente: 
--    primero aparecen los dígitos menos significativos. En otras palabras, el número 127 en base 8 se expresa como [7,2,1]. 
--    Escriba un programa Haskell para obtener el número decimal equivalente (en este caso, sería 7⋅8⁰+2⋅8¹+1⋅8² = 7+16+64 = 87).
octalToDecimalAscendente :: [Int] -> Int
-- Uso esta funcion auxiliar porque el ej me pide revolver el valor a partir de una lista unicamente 
-- pero quiero llevar un control de la posicion del digito ya que es coincide con el exponente
octalToDecimalAscendente xs = convertir xs 0 
  where
    convertir [] _ = 0
    convertir (y:ys) pos = y * 8^pos + convertir ys (pos + 1)


-- Variación ej 5: si el ej recibiera la lista con los elementos en el orden en el que aparecen: 127 en base 8 se 
--                 expresa como [1,2,7] y se resolvería así: 1*8² + 2*8¹ + 7*8⁰
octalToDecimalDescendente :: [Int] -> Int
octalToDecimalDescendente [] = 0
octalToDecimalDescendente (x:xs) = x * 8 ^ (length xs) + octalToDecimalDescendente xs


-- 6) Generalice el programa del ejercicio anterior para obtener el valor decimal de un número expresado en cualquier base 
--    entre 1 y 10. El número se expresa en una lista ascendente como en el ejercicio 5.
convertToDecimalAscendente :: [Int] -> Int -> Int
convertToDecimalAscendente [] _ = 0
convertToDecimalAscendente xs base 
    | base < 1 || base > 10 = error "La base debe estar entre 1 y 10"
    | otherwise = convertir2 xs base 0
  where
      convertir2 [] _ _ = 0
      convertir2 (y:ys) b pos = y * b^pos + convertir2 ys b (pos + 1)


-- Variación ej 6: si el ej recibiera la lista con los elementos en el orden en el que aparecen
convertToDecimalDescendente :: [Int] -> Int -> Int
convertToDecimalDescendente [] _ = 0
convertToDecimalDescendente (x:xs) base
    | base < 1 || base > 10 = error "La base debe estar entre 1 y 10"
    | otherwise = x * base ^ (length xs) + convertToDecimalDescendente xs base


-- 7) Escriba un programa que encuentre el valor decimal de un número hexadecimal. El número se expresa en una lista como en el ejercicio 5.
hexDigitToInt :: Char -> Int
hexDigitToInt c
    | c >= '0' && c <= '9' = fromEnum c - fromEnum '0'
    | c >= 'A' && c <= 'F' = fromEnum c - fromEnum 'A' + 10
    | otherwise            = error "Carácter no válido para un dígito hexadecimal"

hexadecimalToDecimalAscendente :: [Char] -> Int
hexadecimalToDecimalAscendente [] = 0
hexadecimalToDecimalAscendente xs = convertirHex xs 0
  where
    convertirHex [] _ = 0
    convertirHex (y:ys) pos = hexDigitToInt (toUpper y) * 16^pos + convertirHex ys (pos + 1)
    




-- Pruebas de ejs
main :: IO ()
main = do
  let list1 = [1,2,3,4]
  let list2 = [3,4,5,6]
  putStrLn $ "List1: " ++ show list1
  putStrLn $ "List2: " ++ show list2
  putStrLn $ "Union: " ++ show (union list1 list2) -- Ej 1
  putStrLn $ "Intersection: " ++ show (intersection list1 list2) -- Ej 2
  putStrLn $ "Difference (list1 - list2): " ++ show (difference list1 list2) -- Ej 3
  putStrLn $ "Symmetric Difference: " ++ show (symmetricDifference list1 list2) -- Ej 4
  -- Ej 5:
  let numeroOctalAscendente = [7,2,1]  -- representa el número 127 en base 8 ascendente (87 en decimal)
  putStrLn "Número octal ascendente:"
  print numeroOctalAscendente
  putStrLn "Número decimal equivalente:"
  print (octalToDecimalAscendente numeroOctalAscendente)
  -- Ej 5 (variante):
  putStrLn "Número octal descendente:"
  let numeroOctalDescendente = [1,2,7]  -- representa el número 127 en base 8 descendente (87 en decimal)
  print numeroOctalDescendente
  putStrLn "Número decimal equivalente:"
  print (octalToDecimalDescendente numeroOctalDescendente)
  -- Ej 6:
  let numeroBaseAscendente = [3,1,4]  -- representa el número 413 en base 5 ascendente (108 en decimal)
  let base = 5
  putStrLn $ "Número en base " ++ show base ++ " ascendente:"
  print numeroBaseAscendente
  putStrLn "Número decimal equivalente:"
  print (convertToDecimalAscendente numeroBaseAscendente base)
  -- Ej 6 (variante):
  let numeroBaseDescendente = [4,1,3]  -- representa el número
  putStrLn $ "Número en base " ++ show base ++ " descendente:"
  print numeroBaseDescendente
  putStrLn "Número decimal equivalente:"
  print (convertToDecimalDescendente numeroBaseDescendente base)
