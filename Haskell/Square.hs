module Main where

e :: Double
e = exp 1.0

square :: Double -> Double
square x = x ** 2

main :: IO ()
main = do
    putStrLn "Enter a number to square:"
    line <- getLine
    let x = (read line :: Double)
    putStrLn ("Square = " ++ show (square x))
    putStrLn ("Value of e = " ++ show e)