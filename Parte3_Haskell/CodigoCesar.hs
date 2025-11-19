module CodigoCesar (cifrar, descifrar) where

{-
    EJERCICIO 3

    Defina un módulo que implemente el código de César. Esta codificación, que seguramente vio en Análisis y diseño de algoritmos, 
    se basa en un desplazamiento de todas las letras en un número dado. Por ejemplo, la palabra casa codificada con 1 es dbtb; 
    la palabra paz codificada con 3 es rcb. Su módulo debe ofrecer los métodos cifrar, que debe recibir un número y una palabra 
    y devolver la palabra cifrada de acuerdo con ese número, y un método descifrar, que recibe también un número y la palabra 
    cifrada y, como es de esperarse, la descifra.

    Consideraciones:
    - Voy a usar solo letras minúsculas a–z
    - Si una letra se pasa del final del abecedario, debe volver al inicio. Ej: z + 1 → a
    - Para descifrar, desplazaremos en sentido contrario
-}

desplazar :: Int -> Char -> Char
desplazar n c =
    let base = fromEnum 'a'
        pos = fromEnum c - base -- Para "normalizar" el rango de 'a'..'z' entre 0..25 y poder aplicar lo de la siguiente linea
        nuevaPos = (pos + n) `mod` 26 -- Como hay 26 letras en el abecedario, aplicamos mod para obtener el resto de dividir por 26 y saber en que posicion caemos
    in toEnum (base + nuevaPos) -- Convierte a char la posicion nueva   

cifrar :: Int -> String -> String
cifrar n s = [desplazar n c | c <- s]

descifrar :: Int -> String -> String
descifrar n s = [desplazar (-n) c | c <- s]