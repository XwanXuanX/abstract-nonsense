import Control.Monad (replicateM_)
import Data.List (sort)

check :: [Int] -> Bool
check (x:y:xs) = x == y && check xs
check _        = True

solve :: Int -> [Int] -> Bool
solve a xs = check $ drop 1 (sort xs)

wrap :: IO ()
wrap = do
  a <- read <$> getLine :: IO Int
  xs <- map read . words <$> getLine :: IO [Int]
  putStrLn (if solve a xs then "YES" else "NO")

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
