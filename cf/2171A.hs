import Control.Monad (replicateM_)
import Data.List (sort)
import Data.Array

solve :: Int -> Int
solve n =
  foldl (+) 0 [ chk i j | i <- [0..n], j <- [0..n] ]
  where
    chk i j = if (2 * i + 4 * j == n) then 1 else 0

wrap :: IO ()
wrap = do
  n <- read <$> getLine :: IO Int
  print $ solve n

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
