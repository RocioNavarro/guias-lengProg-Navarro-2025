
import Data.List (words, sort, group, tails, isPrefixOf)
import CodigoCesar (cifrar, descifrar)
import Data.Text.Internal.Fusion.Size (larger)


{-
    EJERCICIO 1

    Investigue las funciones group, sort y words del módulo Data.List. 
    Combínelos para obtener una función que para una cadena de entrada devuelva una lista de tuplas. 
    Cada tupla contiene una palabra y su frecuencia de apariciones.
    Ejemplo: si tenemos "ab aa bb aa cc ab aa", el programa debe devolver [("aa", 3), ("ab", 2), ("bb", 1), ("cc", 1)].
    ¿De qué tipo es la función resultante?


    We use the GROUP function, which lives in Data.List, to group together words that are identical. 
    This function takes a list and groups adjacent elements into sublists if they are equal:
    ghci> group [1,1,1,1,2,2,2,2,3,3,2,2,2,5,6,7]
    [[1,1,1,1],[2,2,2,2],[3,3],[2,2,2],[5],[6],[7]]

    But what happens if the elements that are equal aren’t adjacent in our list?
    ghci> group ["boom","bip","bip","boom","boom"]
    [["boom"],["bip","bip"],["boom","boom"]]

    We get two lists that contain the string "boom", even though we want all
    occurrences of some word to end up in the same list.
    We could SORT our list of words beforehand! For that, we’ll use the sort
    function, which hangs its hat in Data.List. It takes a list of things that can
    be ordered and returns a new list that is like the old one, but ordered from
    smallest to largest:
    ghci> sort [5,4,3,7,2,1]
    [1,2,3,4,5,7]
    ghci> sort ["boom","bip","bip","boom","boom"]
    ["bip","bip","boom","boom","boom"]

    ¿Qué hace WORDS?
    Divide un String en una lista de palabras separadas por espacios en blanco:
        words "Hola mundo esto es Haskell"
        -- Resultado:
        ["Hola","mundo","esto","es","Haskell"]
  
    Combínelos para obtener una función que para una cadena de entrada devuelva una lista de tuplas. 

    1) WORDS para pasar de string a listita de palabras
    2) SORT para que las palabras iguales queden juntas
    3) GROUP para juntar las repetidas en listas separadas
    4) Armar tuplas con (palabra, repeticiones) donde repeticiones es la longitud de la lista de esa palabra
-}

frecuencias :: String -> [(String, Int)]
frecuencias xs =
    let ws = words xs              -- separa en palabras
        st = sort ws                -- ordena las palabras
        grupos = group st           -- agrupa iguales
    in [ (head ys, length ys) | ys <- grupos ] -- List comprehension: produce una nueva lista aplicando la expresión (head ys, length ys) a cada elemento ys tomado de la lista grupos.
    -- in map (\ys -> (head ys, length ys)) grupos  -- arma tuplas (palabra, repeticiones)


{-  
    EJERCICIO 2

    Investigue las funciones tails y isPrefixOf del módulo Data.List. 
    Combínelos para obtener una función que determine si una lista está enteramente contenida en otra.
    Ejemplo: la lista [2, 3] está enteramente contenida en la lista [1, 2, 3, 4, 5]. 
    La lista [1, 3] no está enteramente contenida en la lista [1, 2, 3, 4, 5].

    ¿Qué sucede si utilizamos su función para determinar si la cadena "ove" está contenida en la cadena "Beethoven"? 
    Explique su resultado. ¿De qué tipo es la función?

    ghci> tails "party"
    ["party","arty","rty","ty","y",""]

    ghci> "hawaii" `isPrefixOf` "hawaii joe"
    True
    ghci> "haha" `isPrefixOf` "ha"
    False
-}

contenida :: Eq a => [a] -> [a] -> Bool
contenida xs ys =
    let ts = tails ys  -- obtiene todas las colas de ys
    in any (xs `isPrefixOf`) ts  -- verifica si xs es prefijo de alguna cola de ys  

{-
    OBS:  any :: (a -> Bool) -> [a] -> Bool
    Any recibe: 
    1) una función que toma un elemento de tipo a y devuelve un Bool
    2) una lista de elementos de tipo a
    Y devuelve True si al menos un elemento de la lista hace que la función devuelva True

    En la linea 78, la funcion que recibe any es (xs `isPrefixOf`), que es una función parcial que toma una lista y verifica si xs es prefijo de esa lista.
    Entonces, any aplica esta función a cada cola en ts (las colas de ys) y devuelve True si encuentra al menos una cola donde xs es prefijo.
-}


quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = 
    let smallerOrEquals = [ a | a <- xs, a <= x ]
        larger = [ a | a <- xs, a<x ]
    in quickSort(smallerOrEquals) ++ [x] ++ larger



main :: IO ()
main = do
    -- Ej 1
    let texto = "ab aa bb aa cc ab aa"
    print (frecuencias texto)
    -- Ej 2
    print (contenida [2,3] [1,2,3,4,5])  -- True
    print (contenida [1,3] [1,2,3,4,5])  -- False
    print (contenida "ove" "Beethoven")  -- True   
    -- Ej 3
    let palabra = "casa"
    let desplazamiento = 3
    let cifrada = cifrar desplazamiento palabra
    putStrLn $ "Palabra original: " ++ palabra
    putStrLn $ "Palabra cifrada con desplazamiento " ++ show desplazamiento ++ ": " ++ cifrada
    let descifrada = descifrar desplazamiento cifrada
    putStrLn $ "Palabra descifrada: " ++ descifrada  
