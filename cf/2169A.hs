import Control.Monad (replicateM_)
import Data.List (sort)
import Data.Array

solve :: [Int] -> Int -> Int
solve xs a =
  let ys = filter (/= a) xs
      small = length $ filter (< a) ys
      large = length $ filter (> a) ys
  in if null ys
    then 114514
    else if large > small then a + 1 else a - 1

wrap :: IO ()
wrap = do
  [_, a] <- map read . words <$> getLine :: IO [Int]
  xs <- map read . words <$> getLine :: IO [Int]
  print $ solve xs a

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
