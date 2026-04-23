module Main where
import System.Exit (exitFailure)

isValidTriangle :: Double -> Double -> Double -> Bool
isValidTriangle a b c = a + b > c && b + c > a && a + c > b

toDegrees :: Double -> Double
toDegrees r = r * 180.0 / pi

angleA :: Double -> Double -> Double -> Double
angleA a b c = toDegrees $ acos ((b*b + c*c - a*a) / (2.0 * b * c))

angleB :: Double -> Double -> Double -> Double
angleB a b c = toDegrees $ acos ((a*a + c*c - b*b) / (2.0 * a * c))

angleC :: Double -> Double -> Double -> Double
angleC a b c = toDegrees $ acos ((a*a + b*b - c*c) / (2.0 * a * b))

main :: IO ()
main = do
    putStrLn "Enter side a:"
    aStr <- getLine
    putStrLn "Enter side b:"
    bStr <- getLine
    putStrLn "Enter side c:"
    cStr <- getLine

    let a = read aStr :: Double
        b = read bStr :: Double
        c = read cStr :: Double

    if a <= 0 || b <= 0 || c <= 0
        then do
            putStrLn "Error: All sides must be positive numbers."
            exitFailure
        else if not (isValidTriangle a b c)
            then do
                putStrLn "Error: These sides do not form a valid triangle."
                exitFailure
            else do
                let alpha = angleA a b c
                    beta  = angleB a b c
                    gamma = angleC a b c
                putStrLn "\n--- Triangle Angles ---"
                putStrLn $ "Angle A (opposite side a): " ++ show alpha ++ " degrees"
                putStrLn $ "Angle B (opposite side b): " ++ show beta  ++ " degrees"
                putStrLn $ "Angle C (opposite side c): " ++ show gamma ++ " degrees"
                putStrLn $ "Sum of angles: " ++ show (alpha + beta + gamma) ++ " degrees"