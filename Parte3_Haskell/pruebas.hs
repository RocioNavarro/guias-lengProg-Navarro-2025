module Main where
import Distribution.Simple.Utils (xargs)

oranges :: (String, Int, Float)
oranges = ("Oranges", 10, 0.25)
price :: (String, Int, Float) -> Float
price (_, _, p) = p


quadratic :: Double -> Double -> Double -> Double
quadratic a b c 
        | r < 0     = error "Not real roots"
        | otherwise = (-b + sq) / (2 * a)
    where 
        r   = b^2 - 4 * a * c 
        sq  = sqrt r


member:: (Eq a) => a -> [a] -> Bool
member _ []      = False
member e (x:xs)  = e == x || member e xs

union :: [Int] -> [Int] -> [Int]
union [] ys     = ys
union (x:xs) ys
      | member x ys = rest
      | otherwise   = x : rest
    where 
        rest = union xs ys


myEven :: Int -> Bool
myEven a = a `mod` 2 == 0

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs)
  | f x = x : myFilter f xs
  | otherwise = myFilter f xs


main :: IO ()
main =  do
  print (price oranges)
  print (quadratic 1 (-3) 2)
  print (union [1,2,3] [3,4,5])
  print (myFilter myEven [1,2,3,4,5]) -- [2,4]

