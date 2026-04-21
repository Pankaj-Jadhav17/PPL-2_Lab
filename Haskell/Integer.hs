module Main where

printOnedigitNum :: Int -> IO ()
printOnedigitNum n =
    if n < 10
        then print n
        else putStrLn "not a single digit number"

main :: IO ()
main = do
    putStrLn "Enter a positive integer"
    line <- getLine
    let number = (read line :: Int)
    printOnedigitNum number