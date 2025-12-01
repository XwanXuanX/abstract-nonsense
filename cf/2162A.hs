import Control.Monad (replicateM_)
import Data.List (sort)
import Data.Array

solve :: [Int] -> Int
solve xs =
  maximum [ avg i j | i <- [1..n], j <- [i..n] ]
  where
    n = length xs
    prefix :: Array Int Int
    prefix = listArray (0, n) $ scanl (+) 0 xs
    avg i j = (prefix ! j - prefix ! (i - 1)) `div` (j - i + 1)

wrap :: IO ()
wrap = do
  a <- read <$> getLine :: IO Int
  xs <- map read . words <$> getLine :: IO [Int]
  print $ solve xs

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
