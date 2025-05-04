module Main where

import Data.Maybe
import Text.Read
import Data.List


readInput :: IO [Int]
readInput = do
  input <- getLine
  let numbers = mapMaybe readMaybe (words input)
  return numbers


maxIndex :: [Int] -> [Int]
maxIndex xs = aux xs mx 1 where
  mx = maximum xs
  aux xs mx i
    | xs == [] = []
    | head xs == mx = i : aux (tail xs) mx (i + 1)
    | otherwise = aux (tail xs) mx (i + 1)


hasOdd :: [Int] -> Bool
hasOdd [] = False
hasOdd (x:xs) = if x `mod` 2 == 1 then True else hasOdd xs


solve :: [Int] -> Int
solve xs
  | ln `mod` 2 == 0 = mx + (ln `div` 2) -- when the length is even
  | otherwise = let idx = maxIndex xs
                    half = ln `div` 2
                in if hasOdd idx then mx + half + 1 else mx + half
    where mx = maximum xs
          ln = length xs


wrapper :: Int -> Int -> IO ()
wrapper tot cur = do
    if tot == cur then
      return ()
    else do
      sz <- getLine -- the size of the list is not used
      buf <- readInput
      print $ solve buf
      wrapper tot $ cur + 1


main :: IO ()
main = do
  testCase <- getLine
  let tc = read testCase :: Int
  wrapper tc 0


{---------------------------------------
-- function that get the length of a list
getLen :: [Int] -> Int
getLen xs = aux xs 0 where
  aux xs acc
    | xs == []  = acc
    | otherwise = aux (tail xs) (acc + 1)

-- return the max between two numbers
mMax :: Int -> Int -> Int
mMax a b = if a >= b then a else b

-- function that find the max number in a list
getMax :: [Int] -> Int
getMax [] = 0
getMax (x:xs) = mMax x (getMax xs)
---------------------------------------}
