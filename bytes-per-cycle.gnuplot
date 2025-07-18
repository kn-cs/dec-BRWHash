set terminal pngcairo background 'white'
set output 'bytes-per-cycle.png'
set title 'Hash Speed (higher is faster)'
set xlabel 'Number of blocks (1 block = 16 bytes)'
set ylabel 'Bytes per cycle'
unset logscale x
unset logscale y
unset xrange
set yrange [0:25]
set xrange[1:500]
plot './halftimehash/avx2/test/test_files/halftime_speed_records.txt' using 1:(1/column(2)) with lines title 'HalftimeHash40 AVX2' ,'./halftimehash/avx2/test/test_files/halftime_speed_records.txt' using 1:(1/column(4)) with lines title 'HalftimeHash40 AVX-512', './dec-BRWHash1305/intel64-avx2-maax-decbrwhash1305-t5/test/test_files/decbrwhash1305_t5_speed_records.txt' using 1:(1/column(3)) with lines title 'decbrwhash1305\_t5 AVX2'
