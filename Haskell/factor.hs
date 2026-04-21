module Main where

getFactorList :: Int -> [Int]
getFactorList n = [x | x <- [1..n], 0 == n `mod` x]

main :: IO ()
main = do
    putStrLn "Enter a positive integer n"
    line <- getLine
    let n = (read line :: Int)
    let xs = getFactorList n
    print xs