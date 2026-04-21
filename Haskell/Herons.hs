module Main where

-- Heron's formula: Area of triangle given 3 sides a, b, c
heronArea :: Double -> Double -> Double -> Double
heronArea a b c =
    let s = (a + b + c) / 2
    in sqrt (s * (s - a) * (s - b) * (s - c))

main :: IO ()
main = do
    putStrLn "Enter side a:"
    a <- readLn :: IO Double
    putStrLn "Enter side b:"
    b <- readLn :: IO Double
    putStrLn "Enter side c:"
    c <- readLn :: IO Double
    putStrLn ("Area = " ++ show (heronArea a b c))