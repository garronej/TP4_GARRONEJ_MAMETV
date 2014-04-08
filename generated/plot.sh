#! /bin/sh


gnuplot <<EOF
set term png
set output "out.png"
plot [-0.3:20][-0.3:20] "$1" w l
EOF
gnome-open out.png

