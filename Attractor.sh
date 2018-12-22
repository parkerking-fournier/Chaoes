#!/bin/bash

start='0.50057'
end='0.50077'
step='0.00001'
LENGTH=720

echo ""

for i in `seq 57 $LENGTH`;
 do
         VAR='-f king_fournier -s -i 38500 -t 0.002 -o '$start' -e '$end' -w 0.00002 finished_attractors/attractor_frame_ply_files/frame_'$i'.ply'
         ./attractors $VAR
         echo "	Done."
         
         echo "Writing obj file $i"
         VAR=' ply2obj.py finished_attractors/attractor_frame_ply_files/frame_'$i'.ply finished_attractors/attractor_frame_obj_files/frame_'$i'.obj'
         python $VAR 
         echo "	Done."
        
         echo ""
         start=`echo "$start + $step" | bc`
         end=`echo "$end + $step" | bc`
 done
