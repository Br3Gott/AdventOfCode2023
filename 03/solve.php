<?php

function getFullNumber ($i, $u, $grid) {
    $strNum = "";

    while (is_numeric($grid[$i][$u])) {
        $strNum .= $grid[$i][$u];
        if ($u < count($grid[$i])-1) {
            $u++;
        } else {
            break;
        }
    }

    return (int) $strNum;
}

$wasGear = false;
$gearI = 0;
$gearU = 0;
$gears = [];

function validateNumber($i, $u, $grid) {
    
    $continue = true;
    while ($continue) {
        // check left 
        if ($u > 0) {
            if (!is_numeric($grid[$i][$u-1]) && $grid[$i][$u-1] !== ".") {
                if ($grid[$i][$u-1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i;
                    $gearU = $u-1;
                }
                return true;
            }
        }

        // check up
        if ($i > 0) {
            if (!is_numeric($grid[$i-1][$u]) && $grid[$i-1][$u] !== ".") {
                if ($grid[$i-1][$u] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i-1;
                    $gearU = $u;
                }
                return true;
            }
        }

        // check diagonal left up
        if ($i > 0 && $u > 0) {
            if (!is_numeric($grid[$i-1][$u-1]) && $grid[$i-1][$u-1] !== ".") {
                if ($grid[$i-1][$u-1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i-1;
                    $gearU = $u-1;
                }
                return true;
            }
        }

        // check down
        if ($i < count($grid)-1) {
            if (!is_numeric($grid[$i+1][$u]) && $grid[$i+1][$u] !== ".") {
                if ($grid[$i+1][$u] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i+1;
                    $gearU = $u;
                }
                return true;
            }
        }

        // check diagonal left down
        if ($i < count($grid)-1 && $u > 0) {
            if (!is_numeric($grid[$i+1][$u-1]) && $grid[$i+1][$u-1] !== ".") {
                if ($grid[$i+1][$u-1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i+1;
                    $gearU = $u-1;
                }
                return true;
            }
        }

        //check right
        if ($u < count($grid[$i])-1) {
            if (!is_numeric($grid[$i][$u+1]) && $grid[$i][$u+1] !== ".") {
                if ($grid[$i][$u+1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i;
                    $gearU = $u+1;
                }
                return true;
            }
            if (is_numeric($grid[$i][$u+1])) {
                $u++;
            } else {
                $continue = false;
            }
        }

        // check diagonal right up
        if ($i > 0 && $u < count($grid[$i])-1) {
            if (!is_numeric($grid[$i-1][$u+1]) && $grid[$i-1][$u+1] !== ".") {
                if ($grid[$i-1][$u+1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i-1;
                    $gearU = $u+1;
                }
                return true;
            }
        }

        // check diagonal right down
        if ($i < count($grid)-1 && $u < count($grid[$i])-1) {
            if (!is_numeric($grid[$i+1][$u+1]) && $grid[$i+1][$u+1] !== ".") {
                if ($grid[$i+1][$u+1] === "*") {
                    global $wasGear, $gearI, $gearU;
                    $wasGear = true;
                    $gearI = $i+1;
                    $gearU = $u+1;
                }
                return true;
            }
        }

        if ($u == count($grid[$i])-1) {
            $continue = false;
        }

    }

    return false;
}

$lines = explode("\n", file_get_contents('input.txt'));

$grid = [];

foreach ($lines as $line) {
    $grid[] = str_split($line);
}

$total = 0;
for ($i = 0; $i < count($lines); $i++) {
    $chars = $grid[$i];
    for ($u = 0; $u < count($chars); $u++) {
        $fullNum = "";
        $char = $grid[$i][$u];
        if (is_numeric($char)) {
            if (validateNumber($i, $u, $grid)) {
                $fullNum = getFullNumber($i, $u, $grid);
                if ($wasGear) {
                    $gears['i'.$gearI.'u'.$gearU][] = $fullNum;
                    $wasGear = false;
                }
                $total += $fullNum;
                $u += strlen((string)getFullNumber($i, $u, $grid));
            }
        }

    }

}

$gearSum = 0;
foreach ($gears as $gear) {
    if (count($gear) === 2) {
        $gearSum += $gear[0] * $gear[1];
    }
} 

echo 'Total: ' . $total . "\n";
echo 'Gear Total: ' . $gearSum . "\n";