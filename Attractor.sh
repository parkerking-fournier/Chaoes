#!/bin/bash

start='0.5000'
end='0.5002'
step='0.00001'
LENGTH=12

for i in `seq 0 $LENGTH`;
 do
         VAR='-f king_fournier -s -i 38500 -t 0.002 -o '$start' -e '$end' -w 0.00002 attractors/finished/attractor_frame_ply_files/frame_'$i'.ply'
         ./attractors/src/attractors $VAR
         
         VAR=' attractors/src/ply2obj.py attractors/finished/attractor_frame_ply_files/frame_'$i'.ply attractors/finished/attractor_frame_obj_files/frame_'$i'.obj'
         python $VAR 
        
         start=`echo "$start + $step" | bc`
         end=`echo "$end + $step" | bc`
 done
