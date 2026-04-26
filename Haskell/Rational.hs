module Main where

import Data.Ratio (numerator, denominator)

-- Convert positive Double to mixed rational I + A/B
toMixedRational :: Double -> (Integer, Integer, Integer)
toMixedRational x =
    let r        = toRational x        -- convert Double to exact Rational
        (i, f)   = properFraction r    -- i = whole part, f = fractional part
        a        = numerator f         -- A (already co-prime, Haskell does it)
        b        = denominator f       -- B
    in (i, a, b)

-- Display the result nicely
display :: Double -> String
display x
    | x <= 0    = "Error: Please enter a positive number!"
    | a == 0    = "Result: " ++ show i ++ " (whole number, no fraction)"
    | otherwise = "Result: " ++ show i ++ " + " ++ show a ++ "/" ++ show b ++
                  "\n  Where I=" ++ show i ++
                  ", A=" ++ show a ++
                  ", B=" ++ show b ++
                  "\n  A and B are co-prime (GCD = 1)"
    where
        (i, a, b) = toMixedRational x

main :: IO ()
main = do
    putStrLn "======================================="
    putStrLn "   Mixed Rational Representation       "
    putStrLn "   Format: I + A/B                     "
    putStrLn "======================================="
    putStrLn "Enter a positive number:"
    line <- getLine
    let x = read line :: Double
    putStrLn "---------------------------------------"
    putStrLn $ "Input Number : " ++ show x
    putStrLn (display x)
    putStrLn "======================================="