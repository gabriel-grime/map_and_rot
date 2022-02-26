set terminal png size 900,800 enhanced font "Helvetica Bold,30"
set output '../figures/output.png'

set key off

set xrange [0:1]
set yrange [-2:2]

set xtics 0.5
set mxtics 2

set ytics 1
set mxtics 2

set lmargin 5.7
set bmargin 3.1
set rmargin 2

set format x '%.1f'
set format y '%.f'

set xlabel "x"
set ylabel "y" rotate by 0 offset 0

plot 'map.dat' using 1:2 with points pt 7 lc rgb 'black' ps 0.1
#'rotation.dat' using 1:2 with points pt 7 lc rgb 'black' ps 0.1

