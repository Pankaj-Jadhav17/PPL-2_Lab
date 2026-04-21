module Main where

factorial :: Integer -> Integer
factorial n = if 0 == n
    then 1
    else n * factorial (n - 1)

main :: IO ()
main = do
    putStrLn "Enter a number:"
    line <- getLine
    let n = (read line :: Integer)
    print (factorial n)