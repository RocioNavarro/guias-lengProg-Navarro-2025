
module Main where 

import Data.List (words, sort, group, tails, isPrefixOf)
import CodigoCesar (cifrar, descifrar)
import Data.Text.Internal.Fusion.Size (larger)
import Data.Bool (Bool(True))
import Data.Binary.Get (isEmpty)

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
frecuencias xs =  -- "ab aa bb aa cc ab aa"
    let ws = words xs              -- separa en palabras ["ab", "aa", "bb", "aa", "cc", "ab", "aa"]
        st = sort ws                -- ordena las palabras ["aa", "aa", "aa", "ab", "ab", "bb", "cc"]
        grupos = group st           -- agrupa iguales [["aa","aa","aa"],["ab","ab"],["bb"],["cc"]]
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
    tails [1,2,3,4,5]
    [[1,2,3,4,5],[2,3,4,5],[3,4,5],[4,5],[5],[]]
    tails "Beethoven"
    ["Beethoven","eethoven","ethoven","thoven","hoven","oven","ven","en","n",""]

    ghci> "hawaii" `isPrefixOf` "hawaii joe"
    True
    ghci> "haha" `isPrefixOf` "ha"
    False
-}

contenida :: Eq a => [a] -> [a] -> Bool
contenida xs ys =
    let ts = tails ys  -- obtiene todas las colas de ys
    in any (xs `isPrefixOf`) ts  -- verifica si xs es prefijo de alguna cola de ys

contenida2 :: Eq a => [a] -> [a] -> Bool
contenida2 xs ys  =
    let ts = tails ys
    in myAny (xs `isPrefixOf`) ts  
        where
            myAny :: (a -> Bool) -> [a] -> Bool
            myAny _ [] = False
            myAny f (z:zs)
                | f z       = True
                | otherwise = myAny f zs

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
    let smallerOrEquals = [ a | a <- xs, a <= x ] -- toma el primer elemento como pivote
        larger = [ a | a <- xs, a > x ]
    in quickSort(smallerOrEquals) ++ [x] ++ quickSort(larger)


{-
Defina un tipo de datos Stack que representa una pila. Este tipo de datos permite las siguientes operaciones: 
    - top, que devuelve el primer elemento de la pila o Nothing si la pila está vacía; 
    - emptyStack que devuelve true o false dependiendo de que la pila esté o no vacía; 
    - pop que elimina y devuelve el tope de la pila (si la pila está vacía, devuelve Nothing); 
    - y push, que agrega un elemento a la pila (es innecesario decir que lo coloca en el tope. Es una pila, ¿no?)
-}

-- Definimos el tipo de datos Stack
data Stack a = Stack [a]  deriving (Show)

top :: Stack a -> Maybe a   
top (Stack [])    = Nothing
top (Stack (x:_)) = Just x

emptyStack :: Stack a -> Bool
emptyStack (Stack [])    = True
emptyStack (Stack xs) = False

pop :: Stack a -> Maybe (a, Stack a)
pop (Stack []) = Nothing
pop (Stack (x:xs)) = Just (x, Stack xs) -- Por ser una pila, sacamos elementos de adelante que es lo ultimo que entro

push :: a -> Stack a -> Stack a
push a (Stack []) = Stack [a]
push a (Stack xs) = Stack(a:xs)  -- Por ser una pila, agregamos elementos adelante
-- IDEM: push a (Stack(x:xs)) = Stack(a:x:xs)



{-
Vamos a implementar una cola (queue) en Haskell, con las operaciones básicas:
    emptyQueue → crear cola vacía
    isEmpty → saber si está vacía
    enqueue → agregar al final
    dequeue → sacar el primero
    first → ver el primero sin sacarlo
-}

data Queue a = Queue [a] deriving (Show)

emptyQueue :: Queue a
emptyQueue = Queue []

myIsEmpty :: Queue a -> Bool
myIsEmpty (Queue []) = True
myIsEmpty (Queue xs) = False

enqueue :: a -> Queue a -> Queue a
enqueue e (Queue []) = Queue [e]
enqueue e (Queue xs) = Queue (xs ++ [e]) -- Por ser una cola, agregamos elementos atras

dequeue :: Queue a -> Maybe (a, Queue a)
dequeue (Queue []) = Nothing
dequeue (Queue (x:xs)) = Just (x, Queue xs) -- Por ser una cola, saco de adelante que es lo primero que entro

first :: Queue a -> Maybe a
first (Queue [])     = Nothing
first (Queue (x:_)) = Just x




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
    -- Ej 4
    let listaDesordenada = [3,6,1,8,4,5,2,7]
    putStrLn $ "Lista desordenada: " ++ show listaDesordenada
    let listaOrdenada = quickSort listaDesordenada
    putStrLn $ "Lista ordenada: " ++ show listaOrdenada 

    putStrLn "=== Probando STACK ==="

    let s0 :: Stack Int
        s0 = Stack []                 -- pila vacía
    print s0
    print (emptyStack s0)

    let s1 = push 10 s0
    let s2 = push 20 s1
    let s3 = push 30 s2
    print s3                          -- Stack [30,20,10]

    print (top s3)                    -- Just 30

    print (pop s3)                    -- Just (30, Stack [20,10])

    putStrLn "\n=== Probando QUEUE ==="

    let q0 :: Queue Int
        q0 = emptyQueue
    print q0
    print (myIsEmpty q0)

    let q1 = enqueue 1 q0
    let q2 = enqueue 2 q1
    let q3 = enqueue 3 q2
    print q3                          -- Queue [1,2,3]

    print (first q3)                  -- Just 1
    
    print (dequeue q3)                -- Just (1, Queue [2,3])

    putStrLn "\nFin de pruebas."
