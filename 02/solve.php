<?php

$lines = explode("\n", file_get_contents('input.txt'));

$validSum = 0;
$powerSum = 0;
foreach ($lines as $line) {
    $valid = true;
    $red = 0;
    $green = 0;
    $blue = 0;
    $game = explode(": ", $line);
    $rounds = explode(";", $game[1]);
    foreach ($rounds as $round) {
        $colors = explode(",", $round);
        foreach ($colors as $color) {
            $value = 0;
            $value = (int ) $color;
            if (str_contains($color, 'red')) {
                if ($value > $red) {
                    $red = $value;
                }
                if ($value > 12) {
                    $valid = false;
                }
            }
            if (str_contains($color, 'green')) {
                if ($value > $green) {
                    $green = $value;
                }
                if ($value > 13) {
                    $valid = false;
                }
            }
            if (str_contains($color, 'blue')) {
                if ($value > $blue) {
                    $blue = $value;
                }
                if ($value > 14) {
                    $valid = false;
                }
            }
        }
    }
    $power = $red * $green * $blue;
    $powerSum += $power;
    if ($valid) {
        $validSum += (int) substr($game[0], 5);
    }
}
echo 'Final sum: ' . $validSum . "\n";
echo 'Power sum: ' . $powerSum . "\n";