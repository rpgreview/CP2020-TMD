#! /bin/awk -f

BEGIN { sum = 0 }
{
    if($NF <= 3) {
        sum += 0.5 * $NF;
    } else if($NF < 8) {
        sum += $NF - 1.5;
    } else if($NF >= 8) {
        sum += 2*$NF - 8.5;
    }
}
END { print sum }
