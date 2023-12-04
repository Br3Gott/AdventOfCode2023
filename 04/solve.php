<?php

$lines = explode("\n", file_get_contents('input.txt'));

$total = 0;
foreach ($lines as $line) {
    $first = false;
    $value = 1;
    $split = explode(" | ", $line);
    $init = explode(": ", $split[0]);
    $winning = explode(" ", $init[1]);
    $have = explode(" ", $split[1]);
    $winning = array_filter($winning,  function($value) { return $value !== ""; });
    $have = array_filter($have,  function($value) { return $value !== ""; });

    foreach ($have as $number) {
        if (in_array($number, $winning)) {
            if (! $first) {
                $first = true;
            } else {
                $value = $value * 2;
            }
        }
    }
    if ($first) {
        $total += $value;
    }

}

echo 'Total val: ' . $total . "\n";
