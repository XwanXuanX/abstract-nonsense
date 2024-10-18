module Main where

import qualified Data.Maybe as Maybe (mapMaybe, fromJust)
import qualified Text.Read as Read (readMaybe)
import Data.List

-- | Read multiple lines of stdin as [String]
readMat :: Int -> IO [String]
readMat 0 = do return []
readMat it = do line <- getLine
                rest <- readMat $ it - 1
                return (line : rest)

-- | Now finally do some real work...
-- | we want to make each String to an Int map :: (String -> Int) -> [String] -> [Int]
-- | CP in Haskell, EZPZ
solve :: [String] -> [Int]
solve = reverse . map (\x -> (Maybe.fromJust $ elemIndex '#' x) + 1)

-- | Parse input and invoke solve
wrapper :: Int -> IO ()
wrapper 0 = do return ()
wrapper it = do n <- readLn :: IO Int
                mat <- readMat n
                putStrLn . unwords . map show $ solve mat
                wrapper $ it - 1

-- | Read in # of test cases and run solve on each
main :: IO ()
main = do
  tc <- readLn :: IO Int
  wrapper tc
