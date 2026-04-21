module Main where

import Data.Char (intToDigit, toUpper)

toHex :: Int -> String
toHex n = map toUpper (reverse (recurse n))
    where
        recurse n
            | n < 16    = [intToDigit n]
            | otherwise = let (q, r) = n `divMod` 16
                          in (intToDigit r) : recurse q

main :: IO ()
main = do
    putStrLn "Enter a decimal number:"
    line <- getLine
    let n = (read line :: Int)
    putStrLn ("Hex = " ++ toHex n)