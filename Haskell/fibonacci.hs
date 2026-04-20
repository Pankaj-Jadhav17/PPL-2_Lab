fibbonacci::Integral a => a -> a
fibbonacci 0 = 0
fibbonacci 1 = 1
fibbonacci n = fibbonacci(n-1) + fibbonacci(n-2)
main :: IO ()
main = print (fibbonacci 20)
