<?php

function merge(array $left, array $right)
{
    $result = [];
    while (count($left) || count($right)) {
        if (count($left) && count($right)) {
            if ($left[0] <= $right[0]) {
                $result[] = $left[0];
                $left = array_slice($left, 1);
            } else {
                $result[] = $right[0];
                $right = array_slice($right, 1);
            }
        } elseif (count($left)) {
            $result[] = $left[0];
            $left = array_slice($left, 1);
        } elseif (count($right)) {
            $result[] = $right[0];
            $right = array_slice($right, 1);
        }
    }

    return $result;
}

function mergeSort(array $data)
{
    if (1 >= count($data)) {
        return $data;
    }

    $middle = count($data) / 2;

    $left = array_slice($data, 0, $middle);
    $right = array_slice($data, $middle);

    $left = mergeSort($left);
    $right = mergeSort($right);

    return merge($left, $right);
}

function printArray(array $data)
{
    print PHP_EOL;
    print implode(' ', $data);
    print PHP_EOL;
}

$testArray = [10, 33, -15, 55, 1001, 23];
print 'Unsorted array';
printArray($testArray);
print 'Sorted array';
printArray(mergeSort($testArray));

