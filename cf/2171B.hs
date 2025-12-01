import Control.Monad (replicateM_)
import Data.List (sort)
import Data.Array

solve :: [Int] -> (Int, [Int])
solve xs =
  let (a1, mid, an) = (head xs, init (tail xs), last xs)
      (a1', an') = case (a1, an) of
        (-1, -1) -> (0, 0)
        (-1, r) -> (r, r)
        (l, -1) -> (l, l)
        (l, r) -> (l, r)
      mid' = map (\x -> if x == -1 then 0 else x) mid
      ans = abs $ an' - a1'
  in (ans, a1' : mid' ++ [an'])

wrap :: IO ()
wrap = do
  a <- read <$> getLine :: IO Int
  xs <- map read . words <$> getLine :: IO [Int]
  let (ans, arr) = solve xs
  print ans
  putStrLn $ unwords (map show arr)

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
