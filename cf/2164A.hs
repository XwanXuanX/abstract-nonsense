import Control.Monad (replicateM_)

solve :: [Int] -> Int -> Bool
solve xs b = minimum xs <= b && b <= maximum xs

wrap :: IO ()
wrap = do
  a <- read <$> getLine :: IO Int
  xs <- map read . words <$> getLine :: IO [Int]
  b <- read <$> getLine :: IO Int
  putStrLn (if solve xs b then "YES" else "NO")

main :: IO ()
main = do
  tc <- read <$> getLine :: IO Int
  replicateM_ tc wrap
