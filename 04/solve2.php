<?php

$lines = explode("\n", file_get_contents('input.txt'));

$total = 0;
$linesToProcess = [];
for ($i = 0; $i < count($lines); $i++) {
    $linesToProcess[] = $i;
    $total++;
}

while (count($linesToProcess) > 0) {
    $i = array_shift($linesToProcess);
    echo 'Processing ' . $i . ' in queue: ' . count($linesToProcess) . "\n";
    $line = $lines[$i];
    $found = 0;
    $split = explode(" | ", $line);
    $init = explode(": ", $split[0]);
    $winning = explode(" ", $init[1]);
    $have = explode(" ", $split[1]);
    $winning = array_filter($winning,  function($value) { return $value !== ""; });
    $have = array_filter($have,  function($value) { return $value !== ""; });

    foreach ($have as $number) {
        if (in_array($number, $winning)) {
            $found++;
        }
    }

    $temp = $i;
    for ($u = 0; $u < $found; $u++) {
        $temp++;
        $linesToProcess[] = $temp;
        $total++;
    }
    
}

echo 'Total val: ' . $total . "\n";
