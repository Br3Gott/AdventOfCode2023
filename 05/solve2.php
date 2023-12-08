<?php

$lowestSeed = 9999999999;

$segments = explode("\n\n", file_get_contents('input.txt'));

$line1 = explode(": ", $segments[0]);
$seedIntervals = explode(" ", $line1[1]);

for ($t = 0; $t < count($seedIntervals); $t++) {
    $seed = (int)$seedIntervals[$t++];
    $seedRange = (int)$seedIntervals[$t];

    echo "Processing interval: " . $t . "\n";

    while ($seedRange > 0) {
        $seed++;
        $seedRange--;
    
        $seedProcess = $seed;
        for ($i = 1; $i < count($segments); $i++) {
            $processed = false;
            $lines = explode("\n", $segments[$i]);
            for ($u = 1; $u < count($lines); $u++) {
                $nums = explode(" ", $lines[$u]);
                $destRange = (int)$nums[0];
                $sourceRange = (int)$nums[1];
                $range = (int)$nums[2];

                if ($sourceRange <= $seedProcess && $sourceRange + $range >= $seedProcess && ! $processed) {
                    $seedProcess = abs($sourceRange - $seedProcess) + $destRange;
                    $processed = true;
                }
                
            }
        }
        if ($seedProcess < $lowestSeed) {
            $lowestSeed = $seedProcess;
        }
    }
}

echo 'Lowest location: ' . $lowestSeed . "\n";