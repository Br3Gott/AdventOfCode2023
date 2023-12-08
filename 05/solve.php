<?php

$segments = explode("\n\n", file_get_contents('input.txt'));

$line1 = explode(": ", $segments[0]);
$seeds = explode(" ", $line1[1]);

for ($i = 1; $i < count($segments); $i++) {
    $toProcess = $seeds;
    unset($seeds);
    $lines = explode("\n", $segments[$i]);
    for ($u = 1; $u < count($lines); $u++) {
        $nums = explode(" ", $lines[$u]);
        $destRange = (int)$nums[0];
        $sourceRange = (int)$nums[1];
        $range = (int)$nums[2];

        foreach ($toProcess as $seed) {
            if ($sourceRange <= (int)$seed && $sourceRange + $range >= (int)$seed) {
                $key = array_search($seed, $toProcess);
                if ($key !== false) {
                    unset($toProcess[$key]);
                }
                $seeds[] = abs($sourceRange - (int)$seed) + $destRange;
            }
        }
    }
    foreach ($toProcess as &$seed) {
        $seeds[] = $seed;
    }
}

sort($seeds);
echo 'Lowest location: ' . $seeds[0] . "\n";