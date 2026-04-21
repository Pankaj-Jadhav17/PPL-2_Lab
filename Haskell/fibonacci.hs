module Main where

fibonacci :: Integer -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n - 1) + fibonacci (n - 2)

main :: IO ()
main = do
    putStrLn "Enter a number:"
    line <- getLine
    let n = (read line :: Integer)
    print (fibonacci n)