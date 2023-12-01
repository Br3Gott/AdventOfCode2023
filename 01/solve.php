<?php

function strpos_all($haystack, $needle) {
    $offset = 0;
    $allpos = array();
    while (($pos = strpos($haystack, $needle, $offset)) !== FALSE) {
        $offset   = $pos + 1;
        $allpos[] = $pos;
    }
    return $allpos;
}

$lines = explode("\n", file_get_contents('input.txt'));
$numbers = [];

foreach ($lines as $line) {
    $found = [];

    $one = strpos_all($line, 'one');
    foreach ($one as $pos) {
        $found[$pos] = 1;
    }
    $two = strpos_all($line, 'two');
    foreach ($two as $pos) {
        $found[$pos] = 2;
    }
    $three = strpos_all($line, 'three');
    foreach ($three as $pos) {
        $found[$pos] = 3;
    }
    $four = strpos_all($line, 'four');
    foreach ($four as $pos) {
        $found[$pos] = 4;
    }
    $five = strpos_all($line, 'five');
    foreach ($five as $pos) {
        $found[$pos] = 5;
    }
    $six = strpos_all($line, 'six');
    foreach ($six as $pos) {
        $found[$pos] = 6;
    }
    $seven = strpos_all($line, 'seven');
    foreach ($seven as $pos) {
        $found[$pos] = 7;
    }
    $eight = strpos_all($line, 'eight');
    foreach ($eight as $pos) {
        $found[$pos] = 8;
    }
    $nine = strpos_all($line, 'nine');
    foreach ($nine as $pos) {
        $found[$pos] = 9;
    }
    
    $chars = str_split($line);
    for ($i = 0; $i < count($chars); $i++) {
        if (is_numeric($chars[$i])) {
            $found[$i] = $chars[$i];
        }
    }
    $numbers[] = '' . $found[min(array_keys($found))] . $found[max(array_keys($found))];
}

$total = 0;
foreach ($numbers as $number) {
    $total += $number;
}

echo $total;