#! /bin/sh


gnuplot <<EOF
set term png
set output "out.png"
plot [-0.2:25.2][-0.2:25.2] "$1" w l
EOF
gnome-open out.png

