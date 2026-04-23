module Main where

import Text.Printf

angle :: Double -> Double -> Double -> Double
angle a b c = acos ((b*b + c*c - a*a) / (2*b*c)) * 180 / pi

main :: IO ()
main = do
    putStrLn "Enter side a:"
    a <- readLn :: IO Double
    putStrLn "Enter side b:"
    b <- readLn :: IO Double
    putStrLn "Enter side c:"
    c <- readLn :: IO Double
    if (a + b > c) && (a + c > b) && (b + c > a)
        then do
            let angleA = angle a b c
                angleB = angle b a c
                angleC = angle c a b
            printf "Angle A: %.2f degrees\n" angleA
            printf "Angle B: %.2f degrees\n" angleB
            printf "Angle C: %.2f degrees\n" angleC
        else
            putStrLn "Invalid Triangle!"